/*
 * KEYPAD_program.c
 *
 *  Created on: Jun 27, 2021
 *      Author: ibrahim
 */
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MAth/BIT_MATH.h"
#include "../../MCAL/DIO/GPIO_interface.h"
#include "util/delay.h"

#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"
#include "util/delay.h"


void KEYPAD_voidInit(void)
{
	GPIO_voidSetPinDir(COL0_PORT , COL0_PIN , OUTPUT);
	GPIO_voidSetPinDir(COL1_PORT , COL1_PIN , OUTPUT);
	GPIO_voidSetPinDir(COL2_PORT , COL2_PIN , OUTPUT);
	GPIO_voidSetPinDir(COL3_PORT , COL3_PIN , OUTPUT);

	GPIO_voidSetPinDir(ROW0_PORT , ROW0_PIN , INPUT);
	GPIO_voidSetPinDir(ROW1_PORT , ROW1_PIN , INPUT);
	GPIO_voidSetPinDir(ROW2_PORT , ROW2_PIN , INPUT);
	GPIO_voidSetPinDir(ROW3_PORT , ROW3_PIN , INPUT);

	GPIO_voidSetPinVal(ROW0_PORT , ROW0_PIN , HIGH);
	GPIO_voidSetPinVal(ROW1_PORT , ROW1_PIN , HIGH);
	GPIO_voidSetPinVal(ROW2_PORT , ROW2_PIN , HIGH);
	GPIO_voidSetPinVal(ROW3_PORT , ROW3_PIN , HIGH);

	GPIO_voidSetPinVal(COL0_PORT , COL0_PIN , HIGH);
	GPIO_voidSetPinVal(COL1_PORT , COL1_PIN , HIGH);
	GPIO_voidSetPinVal(COL2_PORT , COL2_PIN , HIGH);
	GPIO_voidSetPinVal(COL3_PORT , COL3_PIN , HIGH);

}

u8 KEYPAD_voidGetPressedButton(void)
{
	u8 Keypad_ColumnsPort[4] = {COL0_PORT, COL1_PORT, COL2_PORT, COL3_PORT};
	u8 Keypad_ColumnsPin[4]  = {COL0_PIN , COL1_PIN, COL2_PIN, COL3_PIN};
	u8 Keypad_RowsPort[4] = {ROW0_PORT, ROW1_PORT, ROW2_PORT, ROW3_PORT};
	u8 Keypad_RowsPin[4]  = {ROW0_PIN, ROW1_PIN, ROW2_PIN, ROW3_PIN};

	u8 Local_uint8_ColumnsIterator = 0;
	u8 Local_uint8RowsIterator = 0;
	u8 Local_uint8PinValue = 0;
	u8 Local_uint8ReturnData = 0;
	for(Local_uint8_ColumnsIterator = 0; Local_uint8_ColumnsIterator <=3 ; Local_uint8_ColumnsIterator++)
	{
		GPIO_voidSetPinVal(Keypad_ColumnsPort[Local_uint8_ColumnsIterator] , Keypad_ColumnsPin[Local_uint8_ColumnsIterator] , LOW);
		for(Local_uint8RowsIterator=0 ; Local_uint8RowsIterator <=3 ; Local_uint8RowsIterator++)
		{
			Local_uint8PinValue = GPIO_u8ReadPin(Keypad_RowsPort[Local_uint8RowsIterator] , Keypad_RowsPin[Local_uint8RowsIterator]);
			if(Local_uint8PinValue == LOW)
			{
				_delay_ms(30);
				Local_uint8PinValue = GPIO_u8ReadPin(Keypad_RowsPort[Local_uint8RowsIterator] , Keypad_RowsPin[Local_uint8RowsIterator]);
				if(Local_uint8PinValue == LOW)
				{
					Local_uint8ReturnData =  KEYPAD_Map[Local_uint8RowsIterator][Local_uint8_ColumnsIterator];
				}
				Local_uint8PinValue = GPIO_u8ReadPin(Keypad_RowsPort[Local_uint8RowsIterator] , Keypad_RowsPin[Local_uint8RowsIterator]);
				while(Local_uint8PinValue == 0)
				{
					Local_uint8PinValue = GPIO_u8ReadPin(Keypad_RowsPort[Local_uint8RowsIterator] , Keypad_RowsPin[Local_uint8RowsIterator]);
				}
				break;
			}
		}
		GPIO_voidSetPinVal(Keypad_ColumnsPort[Local_uint8_ColumnsIterator] , Keypad_ColumnsPin[Local_uint8_ColumnsIterator] , HIGH);
	}
	return Local_uint8ReturnData;

}


