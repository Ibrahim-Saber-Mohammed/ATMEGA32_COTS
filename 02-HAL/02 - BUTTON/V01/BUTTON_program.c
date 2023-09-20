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
void BUTTON_voidInit( Switch_CONFIG Copy_structSwitch )
{
	GPIO_voidSetPinDir(Copy_structSwitch.Port , Copy_structSwitch.Pin ,INPUT);
	// Enable the Internal Pull up resistor
	if( Copy_structSwitch.type == PULL_UP )
	{
		GPIO_voidSetPinVal(Copy_structSwitch.Port , Copy_structSwitch.Pin ,HIGH);
	}

}

/* 
	* The funcion read the Button State
	* The function takes the BUTTON_PORT and THE BUTTON-PIN
	* The function reads the pin at PINx and return the value (0 , 1) 
*/
u8 BUTTON_u8Read(Switch_CONFIG Copy_structSwitch )
{
	u8 LocalReadVal ;
	LocalReadVal = GPIO_u8ReadPin ( Copy_structSwitch.Port , Copy_structSwitch.Pin );
	return LocalReadVal;
}


