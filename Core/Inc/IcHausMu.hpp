#ifndef ICHAUSMU_h
#define ICHAUSMU_h

#include <stddef.h>
//#include <Arduino.h>

#define ICHAUSMU_HW_REV 0x07

typedef union {
    unsigned char tab[2];
    unsigned short word;
    struct {
        unsigned char msb;
        unsigned char lsb;
    } bytes;
} uint16_u;

typedef union {
    unsigned char tab[4];
    unsigned long dword;
    struct {
        uint16_u msb;
        uint16_u lsb;
    } words;
    struct {
        unsigned char msb;
        unsigned char byte2;
        unsigned char byte1;
        unsigned char lsb;
    } bytes;
} uint32_u;

typedef union {
    unsigned char tab[8];
    //unsigned long long qword;
    struct {
        uint32_u msb;
        uint32_u lsb;
    } dwords;
    struct {
        unsigned char msb;
        unsigned char byte6;
        unsigned char byte5;
        unsigned char byte4;
        unsigned char byte3;
        unsigned char byte2;
        unsigned char byte1;
        unsigned char lsb;
    } bytes;
} uint64_u;

typedef union {
    unsigned char tab[2];
    unsigned short word;
    struct {
        unsigned char lsb;
        unsigned char msb;
    } bytes_le;
} uint16_leu;   // little endian union format

typedef union {
    unsigned char tab[4];
    unsigned long dword;
    struct {
        uint16_leu lsb;
        uint16_leu msb;
    } words;
    struct {
        unsigned char lsb;
        unsigned char byte1;
        unsigned char byte2;
        unsigned char msb;
    } bytes_le;
} uint32_leu;   // little endian union format

typedef union {
    unsigned char tab[8];
    //unsigned long long qword;
    struct {
        uint32_leu lsb;
        uint32_leu msb;
    } dwords;
    struct {
        unsigned char lsb;
        unsigned char byte1;
        unsigned char byte2;
        unsigned char byte3;
        unsigned char byte4;
        unsigned char byte5;
        unsigned char byte6;
        unsigned char msb;
    } bytes_le;
} uint64_leu;   // little endian union format

typedef enum fctStatus {
    RET_OK            = 0x00,
    RET_SENSORVALID   = 0x00,
    RET_E_NOK         = 0x01,
    RET_E_SENSORERROR = 0x01,
    RET_W_SENSORBUSY, //0x02
    RET_E_SENSORFAIL,
    RET_W_SENSORDISMISS,
    RET_E_OPCODE,
    RET_E_PARAMETER,
    RET_E_DATA,
    RET_E_DATALENGTH,
    RET_E_NULLPTR,
    RET_W_UNINIT
} fctStatus;

/*
typedef enum icMuRegister {
/// Analog parameters (valid for all channels)
CIBM              = 0x05,   // (b3-0) Bias current settings (p. 20)
ENAC              = 0x05,   // (b7) Amplitude control unit activation (p. 21)

/// Signal conditioning
ACGAIN_M          = 0x2B,   // (b4-3) Master coarse gain adjustment (p.21)
ACGAIN_N          = 0x2F,   // (b4-3) Nonius coarse gain adjustment (p.21)
AFGAIN_M          = 0x2B,   // (b2-0) Master fine gain adjustment (p.21)
AFGAIN_N          = 0x2F,   // (b2-0) Nonius fine gain adjustment (p.21)
GC_M              = 0x00,   // (b8-7) Master gain range selection (p. 20)
GF_M              = 0x00,   // (b6-0) Master gain (p. 20)
GX_M              = 0x01,   // Master cosine signal gain adjustment (p. 20)
VOSS_M            = 0x02,   // Master sine offset adjustment (p. 21)
VOSC_M            = 0x03,   // Master cosine offset adjustment (p. 21)
PH_M              = 0x04,   // Master phase adjustment (p. 21)
GC_N              = 0x06,   // (b8-7) Nonius gain range selection (p. 20)
GF_N              = 0x06,   // (b6-0) Nonius gain (p. 20)
GX_N              = 0x07,   // Nonius cosine signal gain adjustment (p. 20)
VOSS_N            = 0x08,   // Nonius sine offset adjustment (p. 21)
VOSC_N            = 0x09,   // Nonius cosine offset adjustment (p. 21)
PH_N              = 0x0A,   // Nonius phase adjustment (p. 21)

/// Digital parameters
TEST              = 0x18,   // Adjustment modes/iC-Haus test modes (p. 22)
CRC16_LSB         = 0x80,   // EEPROM configuration data checksum (p. 24)
CRC16_MSB         = 0x81,   // EEPROM configuration data checksum (p. 24)
CRC8              = 0x82,   // EEPROM offset and preset data checksum (p. 24)
NCHK_CRC          = 0x0D,   // (b6) Cyclic check of CRC16 and CRC8 (p. 24)
BANKSEL           = 0x40,   // (b4-0)Serial Access: Bankregister (p. 49)
RPL               = 0x17,   // (b7-6) Register Access Control (p. 53)
RPL_RESET         = 0x5A,   // Serial Access: Register for reset register access restriction (p. 53)
RPL_RESET         = 0x5A,   // Serial Access: Register for reset register access restriction (p. 53)
EVENT_COUNT       = 0x73,   // Serial Access: Eventcounter (p. 58)
HARD_REV          = 0x74,   // serial address: revision code (p. 52)

/// Configurable I/O interface
MODEA             = 0x0B,   // (b2-0) I/O port A configuration (p. 27)
MODEB             = 0x0B,   // (b6-4) I/O port B configuration (p. 27)
PA0_CONF          = 0x25,   // Configurable commands to pin PA0 A (p. 59)
ROT               = 0x15,   // (b7) Direction of rotation (p. 48)
OUT_MSB           = 0x11,   // (b4-0) Output shift register configuration: MSB used bits (p. 29)
OUT_LSB           = 0x12,   // (b3-0) Output shift register configuration: LSB used bits (p. 29)
OUT_ZERO          = 0x11,   // (b7-5) Output shift register configuration: number of zeros inserted after the used bits and before an error/warning (p. 29)
MODE_ST           = 0x12,   // (b5-4) Data output (p. 28)
GSSI              = 0x12,   // (b7) Gray/binary data format (p. 32)
RSSI              = 0x12,   // (b6) Ring operation (p. 32)

/// Multiturn interface
MODE_MT           = 0x10,   // (b3-0) Multiturn mode (p. 41)
SBL_MT            = 0x10,   // (b5-4) Multiturn synchronization bit length (p. 41)
CHK_MT            = 0x10,   // (b6) Cyclic check of the multiturn value (p. 42)
GET_MT            = 0x10,   // (b7) MT interface daisy chain (S. 44)
ROT_MT            = 0x0E,   // (b5) Direction of rotation external multiturn (p. 42)
ESSI_MT           = 0x0E,   // (b7-6) Error Bit external multiturn (p. 42)
SPO_MT            = 0x0F,   // (b7-4) Offset external multiturn (p. 42)

/// Converter and nonius calculation
FILT              = 0x0E,   // (b2-0) Digital filter settings (p. 38)
MPC               = 0x0F,   // (b3-0) Master period count (p. 38)
LIN               = 0x0E,   // (b4) Linear scanning (p. 39)
SPO_BASE          = 0x52,   // (b3-0) Offset of nonius to master (x=BASE,0-14) (p. 39)
SPO_0             = 0x52,   // (b7-4) Offset of nonius to master (x=BASE,0-14) (p. 39)
SPO_1             = 0x53,   // (b3-0) Offset of nonius to master (x=BASE,0-14) (p. 39)
SPO_2             = 0x53,   // (b7-4) Offset of nonius to master (x=BASE,0-14) (p. 39)
SPO_3             = 0x54,   // (b3-0) Offset of nonius to master (x=BASE,0-14) (p. 39)
SPO_4             = 0x54,   // (b7-4) Offset of nonius to master (x=BASE,0-14) (p. 39)
SPO_5             = 0x55,   // (b3-0) Offset of nonius to master (x=BASE,0-14) (p. 39)
SPO_6             = 0x55,   // (b7-4) Offset of nonius to master (x=BASE,0-14) (p. 39)
SPO_7             = 0x56,   // (b3-0) Offset of nonius to master (x=BASE,0-14) (p. 39)
SPO_8             = 0x56,   // (b7-4) Offset of nonius to master (x=BASE,0-14) (p. 39)
SPO_9             = 0x57,   // (b3-0) Offset of nonius to master (x=BASE,0-14) (p. 39)
SPO_10            = 0x57,   // (b7-4) Offset of nonius to master (x=BASE,0-14) (p. 39)
SPO_11            = 0x58,   // (b3-0) Offset of nonius to master (x=BASE,0-14) (p. 39)
SPO_12            = 0x58,   // (b7-4) Offset of nonius to master (x=BASE,0-14) (p. 39)
SPO_13            = 0x59,   // (b3-0) Offset of nonius to master (x=BASE,0-14) (p. 39)
SPO_14            = 0x59,   // (b7-4) Offset of nonius to master (x=BASE,0-14) (p. 39)
NCHK_NON          = 0x0D,   // (b5) Cyclic check of the nonius value (low active) (p. 40)

/// Incremental output ABZ, STEP/DIR and CW/CCW
RESABZ_LSB        = 0x13,   // Incremental interface resolution ABZ,STEP-DIR,CW/CCW (p. 45)
RESABZ_MSB        = 0x14,   // Incremental interface resolution ABZ,STEP-DIR,CW/CCW (p. 45)
LENZ              = 0x16,   // (b7-6) Index pulse length (p. 46)
INV_ABZ           = 0x16,   // (b2-0) ABZ signal inversion (p. 45)
INV_A             = 0x16,   // (b2) A/STEP/CW signal inversion (p. 45)
INV_B             = 0x16,   // (b1) B/DIR/CCW signal inversion (p. 45)
INV_Z             = 0x16,   // (b0) Z/NCLR signal inversion (p. 45)
SS_AB             = 0x15,   // (b5-4) System AB step size (p. 46)
FRQAB             = 0x15,   // (b2-0) AB output frequency (p. 46)
CHYS_AB           = 0x16,   // (b5-4)Converter hysteresis (p. 47)
ENIF_AUTO         = 0x15,   // (b3) Incremental interface enable (p. 47)

/// UVW commutation signals
PPUVW             = 0x17,   // (b5-0) Number of commutation signal pole pairs (p. 48)
PP60UVW           = 0x16,   // (b3) Commutation signal phase position (p. 48)
OFF_UVW_LSB       = 0x4B,   // (b7-4) Commutation signal start angle (p. 48)
OFF_UVW_MSB       = 0x4C,   // Commutation signal start angle (p. 48)
OFF_COM_LSB       = 0x23,   // (b7-4) serial address: absolute position offset for UVW calculation engine changed by nonius (S. 48)
OFF_COM_MSB       = 0x24,   // serial address: absolute position offset for UVW calculation engine changed by nonius (S. 48)

/// Status/command registers and error monitoring
CMD_MU            = 0x75,   // serial address: command register (p. 57)
STATUS0           = 0x76,   // serial address: status register 0 (p. 55)
STATUS1           = 0x77,   // serial address: status register 1 (p. 55)
CFGEW             = 0x0C,   // Error and warning bit configuration (p. 55)
EMTD              = 0x0D,   // (b2-0) Minimum error message duration (p. 56)
ACC_STAT          = 0x0D,   // (b7) Output configuration status register (S. 55)
ACRM_RES          = 0x0D,   // (b4) Automatic reset with master track amplitude errors (p. 40)

///BiSS spezific IDs
DEV_ID0_LSB       = 0x78,   // Device ID (p. 19)
DEV_ID1           = 0x79,   // Device ID (p. 19)
DEV_ID2           = 0x7A,   // Device ID (p. 19)
DEV_ID3           = 0x7B,   // Device ID (p. 19)
DEV_ID4           = 0x7C,   // Device ID (p. 19)
DEV_ID5_MSB       = 0x7D,   // Device ID (p. 19)
MFG_ID_LSB        = 0x7E,   // Manufacturer ID (p. 19)
MFG_ID_MSB        = 0x7F,   // Manufacturer ID (p. 19)
EDSBANK           = 0x41,   // EDSBANK (p. 19)
PROFILE_ID_LSB    = 0x42,   // Profile ID (p. 19)
PROFILE_ID_MSB    = 0x43,   // Profile ID (p. 19)
SERIAL0_LSB       = 0x44,   // Serial number (p. 19)
SERIAL1           = 0x45,   // Serial number (p. 19)
SERIAL2           = 0x46,   // Serial number (p. 19)
SERIAL3_MSB       = 0x47,   // Serial number (p. 19)

/// Preset function
OFF_ABZ0_LSB      = 0x1E,   // (b7-4) Offset Absolute position offset for ABZ calculation engine (p. 61)
OFF_ABZ1          = 0x1F,   // Offset Absolute position offset for ABZ calculation engine (p. 61)
OFF_ABZ2          = 0x48,   // Offset Absolute position offset for ABZ calculation engine (p. 61)
OFF_ABZ3          = 0x49,   // Offset Absolute position offset for ABZ calculation engine (p. 61)
OFF_ABZ4_MSB      = 0x4A,   // Offset Absolute position offset for ABZ calculation engine (p. 61)
OFF_POS0_LSB      = 0x20,   // (b7-4) serial address: absolute position offset for ABZ calculation engine changed by nonius/multiturn (p. 61)
OFF_POS1          = 0x21,   // serial address: absolute position offset for ABZ calculation engine changed by nonius/multiturn (p. 61)
OFF_POS2_MSB      = 0x22,   // serial address: absolute position offset for ABZ calculation engine changed by nonius/multiturn (p. 61)
PRES_POS0_LSB     = 0x4D,   // (b7-4) Preset position for ABZ section (p. 61)
PRES_POS1         = 0x4E,   // Preset position for ABZ section (p. 61)
PRES_POS2         = 0x4F,   // Preset position for ABZ section (p. 61)
PRES_POS3         = 0x50,   // Preset position for ABZ section (p. 61)
PRES_POS4_MSB     = 0x51    // Preset position for ABZ section (p. 61)
} icMuRegister; */

typedef enum icMuRegister {
    /// Analog parameters (valid for all channels)
    CIBM          ,
    ENAC          ,

    /// Signal conditioning
    ACGAIN_M      ,
    ACGAIN_N      ,
    AFGAIN_M      ,
    AFGAIN_N      ,
    GC_M          ,
    GF_M          ,
    GX_M          ,
    VOSS_M        ,
    VOSC_M        ,
    PH_M          ,
    GC_N          ,
    GF_N          ,
    GX_N          ,
    VOSS_N        ,
    VOSC_N        ,
    PH_N          ,

    /// Digital parameters
    TEST          ,
    CRC16_U       ,
    CRC16_LSB     ,
    CRC16_MSB     ,
    CRC8          ,
    NCHK_CRC      ,
    BANKSEL       ,
    RPL           ,
    RPL_RESET     ,
    EVENT_COUNT   ,
    HARD_REV      ,

    /// Configurable I/O interface
    MODEA         ,
    MODEB         ,
    PA0_CONF      ,
    ROT           ,
    OUT_MSB       ,
    OUT_LSB       ,
    OUT_ZERO      ,
    MODE_ST       ,
    GSSI          ,
    RSSI          ,

    /// Multiturn interface
    MODE_MT       ,
    SBL_MT        ,
    CHK_MT        ,
    GET_MT        ,
    ROT_MT        ,
    ESSI_MT       ,
    SPO_MT        ,

    /// Converter and nonius calculation
    FILT          ,
    MPC           ,
    LIN           ,
    SPO_BASE      ,
    SPO_0         ,
    SPO_1         ,
    SPO_2         ,
    SPO_3         ,
    SPO_4         ,
    SPO_5         ,
    SPO_6         ,
    SPO_7         ,
    SPO_8         ,
    SPO_9         ,
    SPO_10        ,
    SPO_11        ,
    SPO_12        ,
    SPO_13        ,
    SPO_14        ,
    NCHK_NON      ,

    /// Incremental output ABZ, STEP/DIR and CW/CCW
    RESABZ_U      ,
    RESABZ_LSB    ,
    RESABZ_MSB    ,
    LENZ          ,
    INV_ABZ       ,
    INV_A         ,
    INV_B         ,
    INV_Z         ,
    SS_AB         ,
    FRQAB         ,
    CHYS_AB       ,
    ENIF_AUTO     ,

    /// UVW commutation signals
    PPUVW         ,
    PP60UVW       ,
    OFF_UVW_U     ,
    OFF_UVW_LSB   ,
    OFF_UVW_MSB   ,
    OFF_COM_U     ,
    OFF_COM_LSB   ,
    OFF_COM_MSB   ,

    /// Status/command registers and error monitoring
    CMD_MU        ,
    STATUS0       ,
    STATUS1       ,
    CFGEW         ,
    EMTD          ,
    ACC_STAT      ,
    ACRM_RES      ,

    ///BiSS spezific IDs
    DEV_ID_U      ,
    DEV_ID0_LSB   ,
    DEV_ID1       ,
    DEV_ID2       ,
    DEV_ID3       ,
    DEV_ID4       ,
    DEV_ID5_MSB   ,
    MFG_ID_U      ,
    MFG_ID_LSB    ,
    MFG_ID_MSB    ,
    EDSBANK       ,
    PROFILE_ID_U  ,
    PROFILE_ID_LSB,
    PROFILE_ID_MSB,
    SERIAL_U      ,
    SERIAL0_LSB   ,
    SERIAL1       ,
    SERIAL2       ,
    SERIAL3_MSB   ,

    /// Preset function
    OFF_ABZ0_LSB  ,
    OFF_ABZ1      ,
    OFF_ABZ2      ,
    OFF_ABZ3      ,
    OFF_ABZ4_MSB  ,
    OFF_POS_U     ,
    OFF_POS0_LSB  ,
    OFF_POS1      ,
    OFF_POS2_MSB  ,
    PRES_POS_U    ,
    PRES_POS0_LSB ,
    PRES_POS1     ,
    PRES_POS2     ,
    PRES_POS3     ,
    PRES_POS4_MSB
} icMuRegister_t;

enum icMuTestMode {
    TEST_DEFAULT       = 0x00,
    TEST_ANALOG_MASTER = 0x01,  // PB0-3:  PSM   ||  NSM   ||  PCM   ||  NCM   ||
    TEST_ANALOG_CNV_M  = 0x03,  // PB0-3: PSIN_M || NSIN_M || PCOS_M || NCOS_M ||
    TEST_ANALOG_NONIUS = 0x11,  // PB0-3:  PSN   ||  NSN   ||  PCN   ||  NCN   ||
    TEST_ANALOG_CNV_N  = 0x13,  // PB0-3: PSIN_N || NSIN_N || PCOS_N || NCOS_N ||
    TEST_ANALOG_REG    = 0x1F,  // PB0-3:  VREF  ||  VBG   ||  CIBM  ||        ||
    TEST_DIGITAL_CLK   = 0x26   // PB0-3:        ||        ||        ||  CLK   ||
};


class IcHausMu
{
    public:
        enum opCode {
            ACTIVATE      = 0xB0,
            SDAD_TRANSMIT = 0xA6,
            SDAD_STATUS   = 0xF5,
            READ_REG      = 0x97,
            WRITE_REG     = 0xD2,
            STATUS_DATA   = 0xAD
        };

        unsigned char debugVal;
        IcHausMu(const unsigned char hwRev);            // constructor
        void csFunctionAttach(void (*_csFct_ptr)(const bool csEnable));
        void streamFunctionAttach(void (*_streamFct_ptr)(unsigned char* const txBuffer, unsigned char* rxBuffer, const unsigned int bufferLen));
        unsigned char getIcMuAddress(const icMuRegister_t reg);
        unsigned char getIcMuMask(const icMuRegister_t reg);
        unsigned char icMuRegSize(const icMuRegister_t reg);
        unsigned char getLastByteValue(void);
        uint16_u getLastUint_16Value(void);
        uint32_u getLastUint_32Value(void);
        fctStatus readIcMuRegister(const icMuRegister_t reg);
        fctStatus readIcMuRegister_leu(const icMuRegister_t reg, uint64_leu* buffPtr);
        fctStatus writeIcMuRegister(const icMuRegister_t reg, const unsigned char val);
        fctStatus writeIcMuRegister_leu(const icMuRegister_t reg, uint64_leu* buffPtr);
        fctStatus readArray(const unsigned char startAddress, const unsigned int nbBytes, unsigned char* buffPtr);
        fctStatus writeArray(const unsigned char startAddress, const unsigned int nbBytes, unsigned char* buffPtr);
        fctStatus init(void);
        void uninit(void);
        fctStatus setAutomaticGain(unsigned char autoGainEnabled);
        fctStatus readRegStatus(void);
        fctStatus readSdadStatus(void);
        fctStatus readPos(uint16_u* posPtr);
        fctStatus switchRegisterBank(const unsigned char bankIndex);
        fctStatus changeSdadMode(unsigned char stMode, unsigned char sdadMsb, unsigned char sdadLsb);
    private:
        const unsigned char _icMuRegisterAddress[127] = {
            /// Analog parameters (valid for all channels)
            0x05,   // CIBM              (b3-0) Bias current settings (p. 20)
            0x05,   // ENAC              (b7) Amplitude control unit activation (p. 21)

            /// Signal conditioning
            0x2B,   // ACGAIN_M          (b4-3) Master coarse gain adjustment (p.21)
            0x2F,   // ACGAIN_N          (b4-3) Nonius coarse gain adjustment (p.21)
            0x2B,   // AFGAIN_M          (b2-0) Master fine gain adjustment (p.21)
            0x2F,   // AFGAIN_N          (b2-0) Nonius fine gain adjustment (p.21)
            0x00,   // GC_M              (b8-7) Master gain range selection (p. 20)
            0x00,   // GF_M              (b6-0) Master gain (p. 20)
            0x01,   // GX_M              Master cosine signal gain adjustment (p. 20)
            0x02,   // VOSS_M            Master sine offset adjustment (p. 21)
            0x03,   // VOSC_M            Master cosine offset adjustment (p. 21)
            0x04,   // PH_M              Master phase adjustment (p. 21)
            0x06,   // GC_N              (b8-7) Nonius gain range selection (p. 20)
            0x06,   // GF_N              (b6-0) Nonius gain (p. 20)
            0x07,   // GX_N              Nonius cosine signal gain adjustment (p. 20)
            0x08,   // VOSS_N            Nonius sine offset adjustment (p. 21)
            0x09,   // VOSC_N            Nonius cosine offset adjustment (p. 21)
            0x0A,   // PH_N              Nonius phase adjustment (p. 21)

            /// Digital parameters
            0x18,   // TEST              Adjustment modes/iC-Haus test modes (p. 22)
            0x80,   // CRC16_U           union
            0x80,   // CRC16_LSB         EEPROM configuration data checksum (p. 24)
            0x81,   // CRC16_MSB         EEPROM configuration data checksum (p. 24)
            0x82,   // CRC8              EEPROM offset and preset data checksum (p. 24)
            0x0D,   // NCHK_CRC          (b6) Cyclic check of CRC16 and CRC8 (p. 24)
            0x40,   // BANKSEL           (b4-0) Serial Access: Bankregister (p. 49)
            0x17,   // RPL               (b7-6) Register Access Control (p. 53)
            0x5A,   // RPL_RESET         Serial Access: Register for reset register access restriction (p. 53)
            0x73,   // EVENT_COUNT       Serial Access: Eventcounter (p. 58)
            0x74,   // HARD_REV          serial address: revision code (p. 52)

            /// Configurable I/O interface
            0x0B,   // MODEA             (b2-0) I/O port A configuration (p. 27)
            0x0B,   // MODEB             (b6-4) I/O port B configuration (p. 27)
            0x25,   // PA0_CONF          Configurable commands to pin PA0 A (p. 59)
            0x15,   // ROT               (b7) Direction of rotation (p. 48)
            0x11,   // OUT_MSB           (b4-0) Output shift register configuration: MSB used bits (p. 29)
            0x12,   // OUT_LSB           (b3-0) Output shift register configuration: LSB used bits (p. 29)
            0x11,   // OUT_ZERO          (b7-5) Output shift register configuration: number of zeros inserted after the used bits and before an error/warning (p. 29)
            0x12,   // MODE_ST           (b5-4) Data output (p. 28)
            0x12,   // GSSI              (b7) Gray/binary data format (p. 32)
            0x12,   // RSSI              (b6) Ring operation (p. 32)

            /// Multiturn interface
            0x10,   // MODE_MT           (b3-0) Multiturn mode (p. 41)
            0x10,   // SBL_MT            (b5-4) Multiturn synchronization bit length (p. 41)
            0x10,   // CHK_MT            (b6) Cyclic check of the multiturn value (p. 42)
            0x10,   // GET_MT            (b7) MT interface daisy chain (S. 44)
            0x0E,   // ROT_MT            (b5) Direction of rotation external multiturn (p. 42)
            0x0E,   // ESSI_MT           (b7-6) Error Bit external multiturn (p. 42)
            0x0F,   // SPO_MT            (b7-4) Offset external multiturn (p. 42)

            /// Converter and nonius calculation
            0x0E,   // FILT              (b2-0) Digital filter settings (p. 38)
            0x0F,   // MPC               (b3-0) Master period count (p. 38)
            0x0E,   // LIN               (b4) Linear scanning (p. 39)
            0x52,   // SPO_BASE          (b3-0) Offset of nonius to master (x=BASE,0-14) (p. 39)
            0x52,   // SPO_0             (b7-4) Offset of nonius to master (x=BASE,0-14) (p. 39)
            0x53,   // SPO_1             (b3-0) Offset of nonius to master (x=BASE,0-14) (p. 39)
            0x53,   // SPO_2             (b7-4) Offset of nonius to master (x=BASE,0-14) (p. 39)
            0x54,   // SPO_3             (b3-0) Offset of nonius to master (x=BASE,0-14) (p. 39)
            0x54,   // SPO_4             (b7-4) Offset of nonius to master (x=BASE,0-14) (p. 39)
            0x55,   // SPO_5             (b3-0) Offset of nonius to master (x=BASE,0-14) (p. 39)
            0x55,   // SPO_6             (b7-4) Offset of nonius to master (x=BASE,0-14) (p. 39)
            0x56,   // SPO_7             (b3-0) Offset of nonius to master (x=BASE,0-14) (p. 39)
            0x56,   // SPO_8             (b7-4) Offset of nonius to master (x=BASE,0-14) (p. 39)
            0x57,   // SPO_9             (b3-0) Offset of nonius to master (x=BASE,0-14) (p. 39)
            0x57,   // SPO_10            (b7-4) Offset of nonius to master (x=BASE,0-14) (p. 39)
            0x58,   // SPO_11            (b3-0) Offset of nonius to master (x=BASE,0-14) (p. 39)
            0x58,   // SPO_12            (b7-4) Offset of nonius to master (x=BASE,0-14) (p. 39)
            0x59,   // SPO_13            (b3-0) Offset of nonius to master (x=BASE,0-14) (p. 39)
            0x59,   // SPO_14            (b7-4) Offset of nonius to master (x=BASE,0-14) (p. 39)
            0x0D,   // NCHK_NON          (b5) Cyclic check of the nonius value (low active) (p. 40)

            /// Incremental output ABZ, STEP/DIR and CW/CCW
            0x13,   // RESABZ_U          union
            0x13,   // RESABZ_LSB        Incremental interface resolution ABZ,STEP-DIR,CW/CCW (p. 45)
            0x14,   // RESABZ_MSB        Incremental interface resolution ABZ,STEP-DIR,CW/CCW (p. 45)
            0x16,   // LENZ              (b7-6) Index pulse length (p. 46)
            0x16,   // INV_ABZ           (b2-0) ABZ signal inversion (p. 45)
            0x16,   // INV_A             (b2) A/STEP/CW signal inversion (p. 45)
            0x16,   // INV_B             (b1) B/DIR/CCW signal inversion (p. 45)
            0x16,   // INV_Z             (b0) Z/NCLR signal inversion (p. 45)
            0x15,   // SS_AB             (b5-4) System AB step size (p. 46)
            0x15,   // FRQAB             (b2-0) AB output frequency (p. 46)
            0x16,   // CHYS_AB           (b5-4) Converter hysteresis (p. 47)
            0x15,   // ENIF_AUTO         (b3) Incremental interface enable (p. 47)

            /// UVW commutation signals
            0x17,   // PPUVW             (b5-0) Number of commutation signal pole pairs (p. 48)
            0x16,   // PP60UVW           (b3) Commutation signal phase position (p. 48)
            0x4B,   // OFF_UVW_U         union
            0x4B,   // OFF_UVW_LSB       (b7-4) Commutation signal start angle (p. 48)
            0x4C,   // OFF_UVW_MSB       Commutation signal start angle (p. 48)
            0x23,   // OFF_COM_U         union
            0x23,   // OFF_COM_LSB       (b7-4) serial address: absolute position offset for UVW calculation engine changed by nonius (S. 48)
            0x24,   // OFF_COM_MSB       serial address: absolute position offset for UVW calculation engine changed by nonius (S. 48)

            /// Status/command registers and error monitoring
            0x75,   // CMD_MU            serial address: command register (p. 57)
            0x76,   // STATUS0           serial address: status register 0 (p. 55)
            0x77,   // STATUS1           serial address: status register 1 (p. 55)
            0x0C,   // CFGEW             Error and warning bit configuration (p. 55)
            0x0D,   // EMTD              (b2-0) Minimum error message duration (p. 56)
            0x0D,   // ACC_STAT          (b7) Output configuration status register (S. 55)
            0x0D,   // ACRM_RES          (b4) Automatic reset with master track amplitude errors (p. 40)

            ///BiSS spezific IDs
            0x78,   // DEV_ID_U          union
            0x78,   // DEV_ID0_LSB       Device ID (p. 19)
            0x79,   // DEV_ID1           Device ID (p. 19)
            0x7A,   // DEV_ID2           Device ID (p. 19)
            0x7B,   // DEV_ID3           Device ID (p. 19)
            0x7C,   // DEV_ID4           Device ID (p. 19)
            0x7D,   // DEV_ID5_MSB       Device ID (p. 19)
            0x7E,   // MFG_ID_U          union
            0x7E,   // MFG_ID_LSB        Manufacturer ID (p. 19)
            0x7F,   // MFG_ID_MSB        Manufacturer ID (p. 19)
            0x41,   // EDSBANK           EDSBANK (p. 19)
            0x42,   // PROFILE_ID_U      union
            0x42,   // PROFILE_ID_LSB    Profile ID (p. 19)
            0x43,   // PROFILE_ID_MSB    Profile ID (p. 19)
            0x44,   // SERIAL_U          union
            0x44,   // SERIAL0_LSB       Serial number (p. 19)
            0x45,   // SERIAL1           Serial number (p. 19)
            0x46,   // SERIAL2           Serial number (p. 19)
            0x47,   // SERIAL3_MSB       Serial number (p. 19)

            /// Preset function
            0x1E,   // OFF_ABZ0_LSB      (b7-4) Offset Absolute position offset for ABZ calculation engine (p. 61)
            0x1F,   // OFF_ABZ1          Offset Absolute position offset for ABZ calculation engine (p. 61)
            0x48,   // OFF_ABZ2          Offset Absolute position offset for ABZ calculation engine (p. 61)
            0x49,   // OFF_ABZ3          Offset Absolute position offset for ABZ calculation engine (p. 61)
            0x4A,   // OFF_ABZ4_MSB      Offset Absolute position offset for ABZ calculation engine (p. 61)
            0x20,   // OFF_POS_U         union
            0x20,   // OFF_POS0_LSB      serial address: absolute position offset for ABZ calculation engine changed by nonius/multiturn (p. 61)
            0x21,   // OFF_POS1          serial address: absolute position offset for ABZ calculation engine changed by nonius/multiturn (p. 61)
            0x22,   // OFF_POS2_MSB      serial address: absolute position offset for ABZ calculation engine changed by nonius/multiturn (p. 61)
            0x4D,   // PRES_POS_U        union
            0x4D,   // PRES_POS0_LSB     (b7-4) Preset position for ABZ section (p. 61)
            0x4E,   // PRES_POS1         Preset position for ABZ section (p. 61)
            0x4F,   // PRES_POS2         Preset position for ABZ section (p. 61)
            0x50,   // PRES_POS3         Preset position for ABZ section (p. 61)
            0x51    // PRES_POS4_MSB     Preset position for ABZ section (p. 61)
        };

        const unsigned char _icMuRegisterMask[127] = {
            /// Warning - this tab contains masks and register unions size (x), identified by 0x8x (x!=0, mask must be contiguous by definition)

            /// Analog parameters (valid for all channels)
            0x0F,   // CIBM         (b3-0)
            0x80,   // ENAC         (b7)

            /// Signal conditioning
            0x18,   // ACGAIN_M     (b4-3)
            0x18,   // ACGAIN_N     (b4-3)
            0x07,   // AFGAIN_M     (b2-0)
            0x07,   // AFGAIN_N     (b2-0)
            0xC0,   // GC_M         (b7-6)
            0x3F,   // GF_M         (b5-0)
            0xFF,   // GX_M
            0xFF,   // VOSS_M
            0xFF,   // VOSC_M
            0xFF,   // PH_M
            0xC0,   // GC_N         (b7-6)
            0x3F,   // GF_N         (b5-0)
            0xFF,   // GX_N
            0xFF,   // VOSS_N
            0xFF,   // VOSC_N
            0xFF,   // PH_N

            /// Digital parameters
            0xFF,   // TEST
            0x82,   // CRC16_U      union
            0xFF,   // CRC16_LSB
            0xFF,   // CRC16_MSB
            0xFF,   // CRC8
            0x40,   // NCHK_CRC     (b6)
            0x1F,   // BANKSEL      (b4-0)
            0xC0,   // RPL          (b7-6)
            0xFF,   // RPL_RESET
            0xFF,   // EVENT_COUNT
            0xFF,   // HARD_REV

            /// Configurable I/O interface
            0x07,   // MODEA        (b2-0)
            0x07,   // MODEB        (b6-4)
            0xFF,   // PA0_CONF
            0x80,   // ROT          (b7)
            0x1F,   // OUT_MSB      (b4-0)
            0x0F,   // OUT_LSB      (b3-0)
            0xE0,   // OUT_ZERO     (b7-5)
            0x30,   // MODE_ST      (b5-4)
            0x80,   // GSSI         (b7)
            0x40,   // RSSI         (b6)

            /// Multiturn interface
            0x0F,   // MODE_MT      (b3-0)
            0x30,   // SBL_MT       (b5-4)
            0x40,   // CHK_MT       (b6)
            0x80,   // GET_MT       (b7)
            0x20,   // ROT_MT       (b5)
            0xC0,   // ESSI_MT      (b7-6)
            0xF0,   // SPO_MT       (b7-4)

            /// Converter and nonius calculation
            0x07,   // FILT         (b2-0)
            0x0F,   // MPC          (b3-0)
            0x10,   // LIN          (b4)
            0x0F,   // SPO_BASE     (b3-0)
            0xF0,   // SPO_0        (b7-4)
            0x0F,   // SPO_1        (b3-0)
            0xF0,   // SPO_2        (b7-4)
            0x0F,   // SPO_3        (b3-0)
            0xF0,   // SPO_4        (b7-4)
            0x0F,   // SPO_5        (b3-0)
            0xF0,   // SPO_6        (b7-4)
            0x0F,   // SPO_7        (b3-0)
            0xF0,   // SPO_8        (b7-4)
            0x0F,   // SPO_9        (b3-0)
            0xF0,   // SPO_10       (b7-4)
            0x0F,   // SPO_11       (b3-0)
            0xF0,   // SPO_12       (b7-4)
            0x0F,   // SPO_13       (b3-0)
            0xF0,   // SPO_14       (b7-4)
            0x20,   // NCHK_NON     (b5)

            /// Incremental output ABZ, STEP/DIR and CW/CCW
            0x82,   // RESABZ_U     union
            0xFF,   // RESABZ_LSB
            0xFF,   // RESABZ_MSB
            0xC0,   // LENZ         (b7-6)
            0x07,   // INV_ABZ      (b2-0)
            0x04,   // INV_A        (b2)
            0x02,   // INV_B        (b1)
            0x01,   // INV_Z        (b0)
            0x30,   // SS_AB        (b5-4)
            0x07,   // FRQAB        (b2-0)
            0x30,   // CHYS_AB      (b5-4)
            0x08,   // ENIF_AUTO    (b3)

            /// UVW commutation signals
            0x3F,   // PPUVW        (b5-0)
            0x08,   // PP60UVW      (b3)
            0x82,   // OFF_UVW_U    union
            0xF0,   // OFF_UVW_LSB  (b7-4)
            0xFF,   // OFF_UVW_MSB
            0x82,   // OFF_COM_U    union
            0xF0,   // OFF_COM_LSB  (b7-4)
            0xFF,   // OFF_COM_MSB

            /// Status/command registers and error monitoring
            0xFF,   // CMD_MU
            0xFF,   // STATUS0
            0xFF,   // STATUS1
            0xFF,   // CFGEW
            0x07,   // EMTD     (b2-0)
            0x80,   // ACC_STAT (b7)
            0x10,   // ACRM_RES (b4)

            ///BiSS spezific IDs
            0x86,   // DEV_ID_U         union
            0xFF,   // DEV_ID0_LSB
            0xFF,   // DEV_ID1
            0xFF,   // DEV_ID2
            0xFF,   // DEV_ID3
            0xFF,   // DEV_ID4
            0xFF,   // DEV_ID5_MSB
            0x82,   // MFG_ID_U         union
            0xFF,   // MFG_ID_LSB
            0xFF,   // MFG_ID_MSB
            0xFF,   // EDSBANK
            0x82,   // PROFILE_ID_U     union
            0xFF,   // PROFILE_ID_LSB
            0xFF,   // PROFILE_ID_MSB
            0x84,   // SERIAL_U         union
            0xFF,   // SERIAL0_LSB
            0xFF,   // SERIAL1
            0xFF,   // SERIAL2
            0xFF,   // SERIAL3_MSB

            /// Preset function
            0xF0,   // OFF_ABZ0_LSB     (b7-4)
            0xFF,   // OFF_ABZ1
            0xFF,   // OFF_ABZ2
            0xFF,   // OFF_ABZ3
            0xFF,   // OFF_ABZ4_MSB
            0x83,   // OFF_POS_U        union
            0xFF,   // OFF_POS0_LSB
            0xFF,   // OFF_POS1
            0xFF,   // OFF_POS2_MSB
            0x85,   // PRES_POS_U       union
            0xF0,   // PRES_POS0_LSB    (b7-4)
            0xFF,   // PRES_POS1
            0xFF,   // PRES_POS2
            0xFF,   // PRES_POS3
            0xFF    // PRES_POS4_MSB
        };
        uint64_leu _tmpBuff64;
        unsigned char _address;
        unsigned char _hardRev;
        unsigned char _sdadOutMsb;
        unsigned char _sdadOutLsb;
        unsigned char _sdadOutSize;
        fctStatus _initStatus;
        void (*_csFct_ptr)(const bool);
        void (*_streamFct_ptr)(unsigned char* const, unsigned char*, const unsigned int);
        fctStatus _readRegister(const unsigned char registerToRead, const unsigned int bytesToRead, unsigned char* buffPtr);
        fctStatus _writeRegister(const unsigned char registerToWrite, const unsigned int bytesToWrite, unsigned char* buffPtr);
        fctStatus _readRegStatus(void);
        fctStatus _readSdad(const unsigned int bytesToRead, unsigned char* buffPtr);
        fctStatus _readSdadStatus(const unsigned int bytesToRead, unsigned char* buffPtr);
};

#endif

