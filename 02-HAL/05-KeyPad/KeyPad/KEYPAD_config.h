/*
 * KEYPAD_config.h
 *
 *  Created on: Jun 27, 2021
 *      Author: ibrahim
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_


#define COL0_PORT		GPIOD
#define COL0_PIN		PIN7

#define COL1_PORT		GPIOD
#define COL1_PIN		PIN3

#define COL2_PORT		GPIOD
#define COL2_PIN		PIN4

#define COL3_PORT		GPIOD
#define COL3_PIN		PIN6


#define ROW0_PORT		  GPIOB
#define ROW0_PIN		  PIN0

#define ROW1_PORT		  GPIOB
#define ROW1_PIN		  PIN1

#define ROW2_PORT		  GPIOB
#define ROW2_PIN		  PIN2

#define ROW3_PORT		  GPIOB
#define ROW3_PIN		  PIN3


u8 KEYPAD_Map[4][4]= {	/*Col0  Col1	Col2	Col3*/
		{'7',	'8', 	'9', 	'A'}, /*Row0*/
		{'4', 	'5', 	'6', 	'B'}, /*Row1*/
		{'1', 	'2', 	'3', 	'C'}, /*Row2*/
		{'E', 	'0', 	'C', 	'D'}  /*Row3*/
};


#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
