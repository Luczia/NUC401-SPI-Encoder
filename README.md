# NUC401-SPI-Encoder

#Description
Simple program to test the SPI communication between a nucleo f401 with AS5048 and icMU.

It includes DWT (to enable delays in µsecondsm as well as UART communication and SPI non-blocking call though DMA transfers). It rests upon CubeMX ennvironment. 
The code is architectured to enable cpp compilation (as it uses C++ libraies) in root mode (STM32CubeIDE file system compatible with MC-SDK)

The project remains fully reconfigurable with CubeMX (which will generate C files).
To do so, it relies on a cpp_link bridge file which interfaces all the custom code (entry point of custom code is the file application.cpp) with the 
generic file main.c auto-generated by CubeMX
  
  
  
Originally developped and compiled in ST32CubeIDE version: 1.4.2

Last commit tested on STM32CubeIDE version : 1.9.0


#How to use :

Wire the sensor on SPIv3 of the nucleo board :  
<img alt="schematics" src="media/Schematics.png" width="400" >
<img alt="picture" src="media/Picture.jpg" width="400" >

Import this repository in your CubeIDE (or in eclipse configured for embedded devlopement)
File > Import > General > Exisiting Projetc In Workspace > Next > Finish

