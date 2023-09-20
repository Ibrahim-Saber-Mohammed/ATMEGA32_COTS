/********************************************************************************/
/* Author 		: Ibrahim Saber 												*/
/* Date 		: 22/12/2020 													*/
/* Version 		: V01															*/
/********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"


void Relay_voidInit(u8 Copy_u8portnum , u8 Copy_u8Pinnum)
{
	GPIO_voidSetPinDir( Copy_u8portnum, Copy_u8Pinnum, OUTPUT );
}

void Relay_voidON(u8 Copy_u8portnum , u8 Copy_u8Pinnum)
{
	GPIO_voidSetPinVal( Copy_u8portnum, Copy_u8Pinnum, HIGH );
}

void Relay_voidOFF(u8 Copy_u8portnum , u8 Copy_u8Pinnum)
{
	GPIO_voidSetPinVal( Copy_u8portnum, Copy_u8Pinnum, LOW );
}