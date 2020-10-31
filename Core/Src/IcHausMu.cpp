
#include "IcHausMu.hpp"


// ############################### Constructors ###############################

IcHausMu::IcHausMu(const unsigned char hwRev)
//  : _address(0x00) // can be used to initialize as list method
{
    debugVal = 0;
    _tmpBuff64.dwords.msb.dword = 0x00000000;
    _tmpBuff64.dwords.lsb.dword = 0x00000000;
    _address = 0x00;
    _hardRev = hwRev;
    _csFct_ptr = NULL;
    _streamFct_ptr = NULL;
    _initStatus = RET_W_UNINIT;
    _sdadOutMsb = 0;
    _sdadOutLsb = 0;
    _sdadOutSize = 1;
}

// ############################### Public Methods ###############################

// ---------------- low level functions ----------------

void IcHausMu::csFunctionAttach(void (*fct_ptr)(const bool)) {
    _csFct_ptr = fct_ptr;
}

void IcHausMu::streamFunctionAttach(void (*fct_ptr)(unsigned char* const, unsigned char*, const unsigned int)) {
    _streamFct_ptr = fct_ptr;
}

unsigned char IcHausMu::getIcMuAddress(const icMuRegister_t reg) {
    return _icMuRegisterAddress[reg];
}

unsigned char IcHausMu::getIcMuMask(const icMuRegister_t reg) {
    return _icMuRegisterMask[reg];
}

unsigned char IcHausMu::icMuRegSize(const icMuRegister_t reg) {
    unsigned char tmpVal = 0;

    tmpVal = _icMuRegisterMask[reg];                    // this tab contains masks and register unions size (x), identified by 0x8x (x!=0, mask must be contiguous by definition)
    if (0x80<tmpVal && 0x90>tmpVal) {tmpVal &= 0x0F;}   // the union size is returned.
    else {tmpVal = 1;}                                  // single register, size = 1
    return tmpVal;
}

unsigned char IcHausMu::getLastByteValue(void) {
    return _tmpBuff64.bytes_le.lsb;
}

uint16_u IcHausMu::getLastUint_16Value(void) {
    uint16_u tmp;
    tmp.bytes.msb = _tmpBuff64.bytes_le.byte1;
    tmp.bytes.lsb = _tmpBuff64.bytes_le.lsb;
    return tmp;
}

uint32_u IcHausMu::getLastUint_32Value(void) {
    uint32_u tmp;
    tmp.bytes.msb   = _tmpBuff64.bytes_le.byte3;
    tmp.bytes.byte2 = _tmpBuff64.bytes_le.byte2;
    tmp.bytes.byte1 = _tmpBuff64.bytes_le.byte1;
    tmp.bytes.lsb   = _tmpBuff64.bytes_le.lsb;
    return tmp;
}

fctStatus IcHausMu::readIcMuRegister(const icMuRegister_t reg) {
    // trig a reading. Value can be accessed through the getLastValue functions
    fctStatus retVal = RET_OK;

    _tmpBuff64.dwords.msb.dword = 0x00000000;
    _tmpBuff64.dwords.lsb.dword = 0x00000000;

    retVal = readIcMuRegister_leu(reg, &_tmpBuff64);

    return retVal;
}

fctStatus IcHausMu::readIcMuRegister_leu(const icMuRegister_t reg, uint64_leu* buffPtr) {
    unsigned char regSize = 0;
    unsigned char tmpRegAddr = 0;
    fctStatus retVal = RET_OK;

    regSize = icMuRegSize(reg);
    if (1 < regSize) {
        // The icMuRegister is an union. Point to the 1st union element (LSB).
        tmpRegAddr = reg+1;
    }
    else {
        tmpRegAddr = reg;
    }
    retVal = _readRegister(_icMuRegisterAddress[tmpRegAddr], regSize, buffPtr->tab);
    // Apply the mask on MSB & LSB
    if (1 < regSize) {
        regSize--;
        *(buffPtr->tab+regSize) &= _icMuRegisterMask[tmpRegAddr+regSize];
    }
    *(buffPtr->tab) &= _icMuRegisterMask[tmpRegAddr];

    return retVal;
}

fctStatus IcHausMu::writeIcMuRegister(const icMuRegister_t reg, const unsigned char val) {
    _tmpBuff64.dwords.msb.dword = 0x00000000;
    _tmpBuff64.dwords.lsb.dword = 0x00000000;
    _tmpBuff64.bytes_le.lsb = val;

    return writeIcMuRegister_leu(reg, &_tmpBuff64);
}

fctStatus IcHausMu::writeIcMuRegister_leu(const icMuRegister_t reg, uint64_leu* buffPtr) {
    unsigned char regSize = 0x00;
    unsigned char tmpRegAddr = 0x00;
    unsigned char tmpData = 0x00;
    fctStatus retVal = RET_OK;

    regSize = icMuRegSize(reg);
    if (1 < regSize) {
        // The icMuRegister is an union.
        // Do mask for MSB
        tmpRegAddr = reg+regSize;
        retVal = _readRegister(_icMuRegisterAddress[tmpRegAddr], 1, &tmpData);
        tmpData &= ~_icMuRegisterMask[tmpRegAddr];
        *(buffPtr->tab+regSize-1) &= _icMuRegisterMask[tmpRegAddr];
        *(buffPtr->tab+regSize-1) |= tmpData;
        // Point to the 1st union element (LSB).
        tmpRegAddr = reg+1;
    }
    else {
        tmpRegAddr = reg;
    }
    // Do mask for LSB
    if (RET_OK == retVal) {
        tmpData = 0x00;
        retVal = _readRegister(_icMuRegisterAddress[tmpRegAddr], 1, &tmpData);
        tmpData &= ~_icMuRegisterMask[tmpRegAddr];
        *(buffPtr->tab) &= _icMuRegisterMask[tmpRegAddr];
        *(buffPtr->tab) |= tmpData;
    }

    // Write the data
    if (RET_OK == retVal) {
        retVal = _writeRegister(_icMuRegisterAddress[tmpRegAddr], regSize, buffPtr->tab);
    }

    return retVal;
}

fctStatus IcHausMu::readArray(const unsigned char startAddress, const unsigned int nbBytes, unsigned char* buffPtr) {
    return _readRegister(startAddress, nbBytes, buffPtr);
}

fctStatus IcHausMu::writeArray(const unsigned char startAddress, const unsigned int nbBytes, unsigned char* buffPtr) {
    return _writeRegister(startAddress, nbBytes, buffPtr);
}

// ---------------- user level functions ----------------

fctStatus IcHausMu::init(void) {
    // function to call before using the sensor

    // Check if the interface function has been linked.
    if (NULL!=_csFct_ptr && NULL!=_streamFct_ptr) {
        _initStatus = RET_OK;
    }
    else {
        _initStatus = RET_E_NULLPTR;
    }

    // Check the communication by reading the HARD_REV number
    if (RET_OK == _initStatus) {
        _initStatus = readIcMuRegister(HARD_REV);
    }
    if (RET_OK == _initStatus) {
        if(getLastByteValue() != _hardRev) {    // compare the value read.
            _initStatus = RET_E_DATA;
        }
    }
    return _initStatus;
}

void IcHausMu::uninit(void) {
    _initStatus = RET_W_UNINIT;
}

fctStatus IcHausMu::setAutomaticGain(const unsigned char autoGainEnabled) {
    // enable the automatic gain amplitude
    // Values applied by the automatic unit can be read through the ACGAIN_x & AFGAIN_x registers. See p.22
    // Configuration can be checked through PORTB pins in mode 0x04 & 0x05
    fctStatus retVal = RET_E_NOK;
    unsigned char tmpBuff = 0x00;

    // The gain of both amplification stages is automatically controlled when
    // the bit ENAC is set to ’1’. The register bits GC_x and GF_x have no effect. (p.20).
    if (0x00 != autoGainEnabled) {tmpBuff = 0x80;}
    retVal = writeIcMuRegister(ENAC, tmpBuff);

    return retVal;
}

fctStatus IcHausMu::readRegStatus(void) {
    fctStatus retVal = RET_OK;

    if (RET_OK == _initStatus) {
        // select the device
        _csFct_ptr(true);

        // read the status
        retVal = _readRegStatus();

        // unselect the device
        _csFct_ptr(false);
    }
    else {
        retVal = _initStatus;
    }
    return retVal;
}

fctStatus IcHausMu::readSdadStatus(void) {
    fctStatus retVal = RET_OK;
    unsigned char tmpBuff = 0;

    retVal = _readSdadStatus(1, &tmpBuff);
    debugVal = tmpBuff;
    if (RET_OK==retVal && 0x80!=tmpBuff) {retVal = RET_E_SENSORFAIL;}

    return retVal;
}

fctStatus IcHausMu::readPos(uint16_u* posPtr) {
    fctStatus retVal = RET_E_SENSORFAIL;
    retVal = _readSdad(_sdadOutSize, (unsigned char*)&_tmpBuff64);
    if (RET_OK == retVal) { *(posPtr)= getLastUint_16Value(); }
    return retVal;
}

fctStatus IcHausMu::switchRegisterBank(const unsigned char bankIndex) {
    fctStatus retVal = RET_OK;

    if (32>bankIndex) {
        retVal = writeIcMuRegister(BANKSEL, bankIndex);
    }
    else {
        retVal = RET_E_PARAMETER;
    }
    return retVal;
}

fctStatus IcHausMu::changeSdadMode(unsigned char stMode, unsigned char sdadMsb, unsigned char sdadLsb) {
    fctStatus retVal = RET_OK;

    if(3>stMode && 38>sdadMsb && 12<sdadMsb && 16>sdadLsb && sdadLsb<sdadMsb) {

        retVal = writeIcMuRegister(MODE_ST, stMode<<4);

        if (RET_OK == retVal) {
            retVal = writeIcMuRegister(OUT_LSB, sdadLsb);
            _sdadOutLsb = sdadLsb;
        }
        if (RET_OK == retVal) {
            sdadLsb = 1+sdadMsb-sdadLsb;        // reuse sdadLsb variable for SDAD length and OUT_ZERO computing
            _sdadOutSize = (sdadLsb+7)/8;       // SDAD length in bytes
            sdadLsb = 7-(0x07&(sdadLsb-1));     // nb of zeros to reach a complete byte format for SDAD
            retVal = writeIcMuRegister(OUT_ZERO, sdadLsb<<5);   // alignment with datasheet
        }
        if (RET_OK == retVal) {
            sdadMsb -= 13;                      // offset defined in datasheet
            retVal = writeIcMuRegister(OUT_MSB, sdadMsb);
            _sdadOutMsb = sdadMsb;
        }
    }
    else {
        retVal = RET_E_PARAMETER;
    }

    return retVal;
}

// ############################### Private Methods ###############################

fctStatus IcHausMu::_readRegStatus(void) {
    fctStatus retVal = RET_OK;
    unsigned char internalBuffer[2] = {STATUS_DATA, 0x00};

    // Do the transfert and get the STATUS register
    _streamFct_ptr((unsigned char*)&internalBuffer, (unsigned char*)&internalBuffer, 2);

    if (STATUS_DATA == internalBuffer[0]) {
       // Register is correctly addressed
       // Decode the status byte
       if (0x80 <= internalBuffer[1]) {retVal = RET_E_SENSORERROR;}
       else if (0x08 <= internalBuffer[1]) {retVal = RET_W_SENSORDISMISS;}
       else if (0x04 <= internalBuffer[1]) {retVal = RET_E_SENSORFAIL;}
       else if (0x02 <= internalBuffer[1]) {retVal = RET_W_SENSORBUSY;}
       else if (0x00 == internalBuffer[1]) {retVal = RET_E_NOK;}
       else { /* data is valid. retVal=RET_OK */ }
    }
    else {
        retVal = RET_E_OPCODE;
    }
    return retVal;
}

fctStatus IcHausMu::_readRegister(const unsigned char registerToRead, const unsigned int bytesToRead, unsigned char* buffPtr) {
    fctStatus retVal = RET_OK;
    unsigned char internalBuffer[2] = {0x00};           // incoming word from the SPI

    // check if the functions are available
    if (RET_OK==_initStatus && NULL!=buffPtr) {
        // select the device
        _csFct_ptr(true);

        // send the read command with the register address to read:
        internalBuffer[0] = READ_REG;
        internalBuffer[1] = registerToRead;
        _streamFct_ptr((unsigned char *)&internalBuffer, (unsigned char *)&internalBuffer, 2);
        // Check if the register read command has been sent as expected
        if ( READ_REG!=internalBuffer[0] || registerToRead!=internalBuffer[1] ) {
            retVal = RET_E_OPCODE;
        }

        // unselect the device
        _csFct_ptr(false);

        if (RET_OK == retVal) {
            // select the device
            _csFct_ptr(true);

            retVal = _readRegStatus();    // same function is used to read status and data
            if (RET_OK == retVal) {
                _streamFct_ptr(buffPtr, buffPtr, bytesToRead);
            }

            // unselect the device
            _csFct_ptr(false);
        }
    }
    else {
        retVal = _initStatus;
    }

    // return the function status:
    return retVal;
}

fctStatus IcHausMu::_writeRegister(const unsigned char registerToWrite, const unsigned int bytesToWrite, unsigned char* buffPtr) {
    fctStatus retVal = RET_OK;
    unsigned char internalBuffer[2] = {0x00};           // incoming word from the SPI

    // check if the functions are available
    if (RET_OK==_initStatus && NULL!=buffPtr) {
      // select the device
      _csFct_ptr(true);

      // send the read command with the register address to read:
      internalBuffer[0] = WRITE_REG;
      internalBuffer[1] = registerToWrite;

      _streamFct_ptr((unsigned char *)&internalBuffer, (unsigned char *)&internalBuffer, 2);
      // Check if the register write command has been sent as expected
      if ( WRITE_REG!=internalBuffer[0] || registerToWrite!=internalBuffer[1] ) {
        retVal = RET_E_OPCODE;
      }
      if (RET_OK == retVal) {
          _streamFct_ptr(buffPtr, buffPtr, bytesToWrite);
          // unselect the device
          _csFct_ptr(false);
          // select the device
          _csFct_ptr(true);
          retVal = _readRegStatus();          // check the validity of the writing operation
      }

      // unselect the device
      _csFct_ptr(false);

    }
    else {
      retVal = _initStatus;
    }

    // return the result:
    return retVal;
}

fctStatus IcHausMu::_readSdad(const unsigned int bytesToRead, unsigned char* buffPtr) {
    fctStatus retVal = RET_OK;
    unsigned char internalBuffer = 0x00;           // incoming byte from the SPI

    // check if the functions are available
    if (RET_OK==_initStatus && NULL!=buffPtr) {
        // select the device
        _csFct_ptr(true);

        // send the read command with the register address to read:
        internalBuffer = SDAD_TRANSMIT;
        _streamFct_ptr((unsigned char *)&internalBuffer, (unsigned char *)&internalBuffer, 1);
        // Check if the register read command has been sent as expected
        if (SDAD_TRANSMIT != internalBuffer) {
            retVal = RET_E_OPCODE;
        }
        else {
            _streamFct_ptr(buffPtr, buffPtr, bytesToRead);
        }
        // unselect the device
        _csFct_ptr(false);
    }
    else {
        retVal = _initStatus;
    }

    // return the function status:
    return retVal;
}

fctStatus IcHausMu::_readSdadStatus(const unsigned int bytesToRead, unsigned char* buffPtr) {
    fctStatus retVal = RET_OK;
    unsigned char internalBuffer = 0x00;           // incoming byte from the SPI

    // check if the functions are available
    if (RET_OK==_initStatus && NULL!=buffPtr) {
        // select the device
        _csFct_ptr(true);

        // send the read command with the register address to read:
        internalBuffer = SDAD_STATUS;
        _streamFct_ptr((unsigned char *)&internalBuffer, (unsigned char *)&internalBuffer, 1);
        // Check if the register read command has been sent as expected
        if (SDAD_STATUS != internalBuffer) {
            retVal = RET_E_OPCODE;
        }
        else {
            _streamFct_ptr(buffPtr, buffPtr, bytesToRead);
        }
        // unselect the device
        _csFct_ptr(false);
    }
    else {
        retVal = _initStatus;
    }

    // return the function status:
    return retVal;
}

