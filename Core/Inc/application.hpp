/*
 * application.hpp
 *
 *  Created on: Oct 31, 2020
 *      Author: Luczia
 */

#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

#include "stm32f4xx_hal.h"
#include <stdbool.h>

void application_main (SPI_HandleTypeDef *hspi);
void trig_non_blocking_ichaus_pos_read();
void encoder_init_ichaus(uint8_t* init_seq_status);
uint8_t read_pos_ichaus(uint16_t* pos);
void TransferIcMU(unsigned char* const txBuffer, unsigned char* rxBuffer, const unsigned int bufferLen);
void ChangeCS(bool state);


#endif /* APPLICATION_USER_CORE_APPLICATION_HPP_ */
