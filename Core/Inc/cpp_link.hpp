/*
 * cpp_link.hpp
 *
 *  Created on: Oct 31, 2020
 *      Author: Luczia
 */

#ifndef CPP_LINK_HPP_
#define CPP_LINK_HPP_

#include "stm32f4xx_hal.h"

	#ifdef __cplusplus
		extern "C"
		{
	#endif

		void cpp_link (SPI_HandleTypeDef *hspi);

	#ifdef __cplusplus
		}
	#endif
#endif /* CPP_LINK_HPP_ */
