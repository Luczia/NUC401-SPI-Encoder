/*
 * application.cpp
 *
 *  Created on: Oct 31, 2020
 *      Author: Luczia
 */

#include "application.hpp"
#include "stm32f4xx_hal.h"
#include "stdio.h"
#include "stdarg.h"
#include "main.h"
#include "string.h"
#include "encoder.h"
#include "as5048a.h"
#include "icHausMu.hpp"
#include "dwt_delay.h"


SPI_HandleTypeDef* hspi_enc;
//AS5048A angleSensor(&hspi, SPI2_AS5048_CS_GPIO_Port, SPI2_AS5048_CS_Pin);
IcHausMu ichausmu_enc(ICHAUSMU_HW_REV);


//Ic Haus
uint8_t init_seq[6];
uint8_t spi_tx[3] = {0xA6,0x00,0x00};
uint8_t spi_rx[3] = {0x00,0x00,0x00};
uint16_t positionICMU = 0x0000;


void application_main (SPI_HandleTypeDef *hspi){

  DWT_Init();  // Init the Data Watchpoint and Trace Unit on TIM4 to enable delays in µs

  hspi_enc = hspi; // put hspi as global variable for external functions use
  ichausmu_enc.csFunctionAttach(ChangeCS);
  ichausmu_enc.streamFunctionAttach(TransferIcMU);

  printf("System Init");
  printf("IcMU Init\n");
  encoder_init_ichaus(init_seq);
  for(unsigned int i = 0; i < sizeof(init_seq); i++)
        printf(" %d ,", init_seq[i]);
  printf("\n");

  while (1)
  {

	  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);

	  trig_non_blocking_ichaus_pos_read();
	  DWT_Delay(100); //Let the time to read the latest info | Can be removed when further code will be added
	  float posDeg = positionICMU*360/65536.0;

	  printf("%.3f \n", posDeg);//, status);


	  HAL_Delay(100);
  }
}


void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi)
{
	HAL_GPIO_WritePin(SPI_ICMU_CS_GPIO_Port, SPI_ICMU_CS_Pin, GPIO_PIN_SET);
	positionICMU = spi_rx[1] << 8;
	positionICMU |= spi_rx[2];
}


void encoder_init_ichaus(uint8_t* init_seq_status){

HAL_GPIO_WritePin(SPI_ICMU_CS_GPIO_Port, SPI_ICMU_CS_Pin, GPIO_PIN_SET);

if (init_seq_status == NULL)
	    {
	      uint8_t init_seq_status[6] = {20,20,20,20,20,20};
	    }

init_seq_status[0] = (uint8_t)ichausmu_enc.init();
init_seq_status[1] = (uint8_t)ichausmu_enc.writeIcMuRegister(CIBM, 0x08);       // set bias current, Determined by firstTimeSetup()
init_seq_status[2] = (uint8_t)ichausmu_enc.writeIcMuRegister(LIN, 0x00);       // set the target type as rotative
init_seq_status[3] = (uint8_t)ichausmu_enc.writeIcMuRegister(MPC, 0x05);       // magnetic target is a 32master/31Nonius period
init_seq_status[4] = (uint8_t)ichausmu_enc.changeSdadMode(0x00, 18, 3);        // define the SDAD output
init_seq_status[5] = (uint8_t)ichausmu_enc.setAutomaticGain(true);
}

//Function to read the encoder position with a blocking function | Deprecated
uint8_t read_pos_ichaus(uint16_t* pos){
  uint8_t status;
  uint16_u posICMU;
  status = (uint8_t)ichausmu_enc.readPos(&posICMU);

  *pos = (uint16_t)posICMU.word;

  return status;
}

// Function to start a SPI register read of the encoder position through DMA SPI Read.
//Will trigger a callback function when done "HAL_SPI_TxRxCpltCallback"
void trig_non_blocking_ichaus_pos_read(){

	DWT_Delay(10);
	HAL_GPIO_WritePin(SPI_ICMU_CS_GPIO_Port, SPI_ICMU_CS_Pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive_DMA(hspi_enc, spi_tx, spi_rx, 3);
}

// Function to select the slave (in this case ic-MU)
void ChangeCS(bool state)
{
  if(state)
	  HAL_GPIO_WritePin(SPI_ICMU_CS_GPIO_Port, SPI_ICMU_CS_Pin, GPIO_PIN_RESET);
  else
	  HAL_GPIO_WritePin(SPI_ICMU_CS_GPIO_Port, SPI_ICMU_CS_Pin, GPIO_PIN_SET);
}

// Function to exchange data the slave (in this case ic-MU)
void TransferIcMU(unsigned char* const txBuffer, unsigned char* rxBuffer, const unsigned int bufferLen)
{
  //spiExchange(&SPID1, bufferLen, txBuffer, rxBuffer);
  HAL_SPI_TransmitReceive(hspi_enc, txBuffer, rxBuffer, bufferLen, 1);

}
