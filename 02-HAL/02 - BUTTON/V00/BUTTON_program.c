/********************************************************************************/
/* Author 		: Ibrahim saber													*/
/* Date 		: 10/11/2020													*/
/* Version		: V00															*/
/********************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include <util/delay.h>

#include "BUTTON_interface.h"
#include "BUTTON_config.h"
#include "BUTTON_private.h"

/* 
	* The funcion configure the BUTTON Pin as INPUT
	* The function takes the BUTTON_PORT and THE BUTTON-PIN
	* The function Writes 0 at the DDRx to make the pin INPUT
*/
void BUTTON_voidInit(u8 Copy_u8PortNum , u8 Copy_u8PinNum )
{
	GPIO_voidSetPinDir(Copy_u8PortNum , Copy_u8PinNum ,INPUT);

}

/* 
	* The funcion read the Button State
	* The function takes the BUTTON_PORT and THE BUTTON-PIN
	* The function reads the pin at PINx and return the value (0 , 1) 
*/
u8 BUTTON_u8Read(u8 Copy_u8PortNum , u8 Copy_u8PinNum )
{
	u8 LocalReadVal ;
	LocalReadVal = GPIO_u8ReadPin( Copy_u8PortNum, Copy_u8PinNum);
	return LocalReadVal;
}


