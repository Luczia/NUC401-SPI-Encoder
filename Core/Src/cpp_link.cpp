/*
 * cpp_link.cpp
 *
 *  Created on: Oct 31, 2020
 *      Author: Luczia
 */


//#include "configuration.h"
#include "cpp_link.hpp"
#include "application.hpp"


#ifdef __cplusplus
	extern "C"
	{
#endif

	void cpp_link (SPI_HandleTypeDef *hspi)
		{
		application_main(hspi);
		}

#ifdef __cplusplus
	}
#endif
