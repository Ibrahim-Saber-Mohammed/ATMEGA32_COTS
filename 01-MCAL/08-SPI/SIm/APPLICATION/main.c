/*
 * main.c
 *
 *  Created on: Aug 23, 2021
 *      Author: ibrahim
 */

#include "../LIB/STD_TYPES/STD_TYPES.h"
#include "../LIB/BIT_MATH/BIT_MATH.h"

#include "../MCAL/DIO/GPIO_interface.h"
#include "../MCAL/SPI/SPI_interface.h"
#include "../HAL/CLCD/CLCD_interface.h"

#include "util/delay.h"


#define MOSI		GPIOB, 	PIN5
#define MISO		GPIOB,	PIN6
#define SS			GPIOB, 	PIN4
#define SCK			GPIOB,	PIN7

int main(void)
{
	GPIO_voidSetPinDir(MOSI, OUTPUT);
	GPIO_voidSetPinDir(MISO, INPUT);
	GPIO_voidSetPinDir(SS  , OUTPUT);
	GPIO_voidSetPinDir(SCK , OUTPUT);

	GPIO_voidSetPinVal(SS , HIGH); // slect no slaves

	CLCD_voidInit();

	SPI_voidInit();

	u8 Buffer = 0;
	CLCD_voidGoToX_Y(CLCD_ROW1, CLCD_COL1);
	CLCD_voidSendString((u8*)"Received :");

	GPIO_voidSetPinVal(SS, LOW); // when slave elect is low the slave is selected
	Buffer = SPI_u8TransmitReceive('T'); // Spi Transmit 9 and receive value in Buffer
	GPIO_voidSetPinVal(SS, HIGH); // end communication

	CLCD_voidSendCharacter(Buffer); // Display the received value
	CLCD_voidSendNumber(Buffer); // Display the received value
	while(1)
	{

	}
	return 0;
}
