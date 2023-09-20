/********************************************************************************/
/* Author 		: Ibrahim saber													*/
/* Date 		: 10/11/2020													*/
/* Version		: V00															*/
/********************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"

#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

/* 
	* The funcion configure the LED Pin as Output
	* The function takes the LED_PORT and THE lED-PIN
	* The function Writes 1 at the DDRx to make the pin OUTPUT
*/
void LED_voidInit(u8 Copy_u8PortNum , u8 Copy_u8PinNum )
{
	GPIO_voidSetPinDir(Copy_u8PortNum , Copy_u8PinNum ,OUTPUT);

}

/* 
	* The funcion Turn the LED ON
	* The function takes the LED_PORT and THE lED-PIN
	* The function Writes 1 to the pin at the PORTx to logic HIGH 
*/
void LED_voidON(u8 Copy_u8PortNum , u8 Copy_u8PinNum )
{
	GPIO_voidSetPinVal(Copy_u8PortNum , Copy_u8PinNum , HIGH);
	
}


/* 
	* The funcion Turn the LED OFF
	* The function takes the LED_PORT and THE lED-PIN
	* The function Writes 1 to the pin at the PORTx to logic LOW 
*/
void LED_voidOFF(u8 Copy_u8PortNum , u8 Copy_u8PinNum )
{
	GPIO_voidSetPinVal(Copy_u8PortNum , Copy_u8PinNum , LOW);

}

/* 
	* The funcion TOGGLE the LED State
	* The function takes the LED_PORT and THE lED-PIN
	* The function Toggle the value of the pin from one state to another (HIGH..>LOW OR LOW..> HIGH) 
*/
void LED_voidTOGGLE(u8 Copy_u8PortNum , u8 Copy_u8PinNum )
{
	GPIO_voidTogglePin(Copy_u8PortNum , Copy_u8PinNum );
}