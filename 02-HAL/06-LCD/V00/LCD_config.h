/******************************************************************************/
/**
*@file LCD_config.h
*@brief  This File contains the configurations of the LCD
*@author Ibrahim Saber
*/
/*****************************************************************************/

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/**
* @warnning  : The port number should be one of {GPIOA, GPIOB, GPIOC, GPIOD}
* @warnning  : The Pin Number should be {0--->7} or {PIN0, PIN1,...PIN7} 
*/
///< THE Modes Available are { EIGHT_BIT, FOUR_BIT}
#define LCD_MODE      FOUR_BIT   ///< 8-Bit mode so the LCD needs the 8-Pins from MCU OR 4-BIT MODE
///< THE NIBLLE Available are { LOW_NIBBLE, HIGH_NIBBLE}
#ifdef LCD_MODE == FOUR_BIT
#define NIBBLE       HIGH_NIBBLE  ///< if the Mode was FOUR_BIT then the NIBBLE is which 4-Bits from MCU  is connected to THE LCD data Pins
#endif

#define LCD_PORT	  GPIOA      ///< THE LCD is connected to Which Port {GPIOA, GPIOB, GPIOC, GPIOD }

#define LCD_RS		  GPIOB , PIN0   ///< The register select Pin is connected to which port and Which Pin Number
					  
#define LCD_RW		  GPIOB , PIN1   ///< The read/Write Pin of LCD is conn cted to which port and the pin number
					  
#define LCD_EN		  GPIOB , PIN2   ///< The Enable Pin of LCD is conncted to which port and the pin number


#endif