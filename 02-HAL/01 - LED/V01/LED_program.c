/********************************************************************************/
/* Author 		: Ibrahim saber													*/
/* Date 		: 10/11/2020													*/
/* Version		: V01															*/
/********************************************************************************/

#include "../../LIB/BIT_MATH/BIT_MATH.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

/*********************************************************************************************************************/
/** 
	@brief 	* The function configure the LED Pin as Output
			* The function takes the LED_PORT and THE lED-PIN from the LED_CONFIG struct 
			* The function Writes 1 at the DDRx to make the pin OUTPUT
			
	@param[in] LED_CONFIG Copy_struct_Led_Config "the input parameter is an object of struct LED_CONFIG"
	@param[out] void
*/
/*********************************************************************************************************************/
void LED_voidInit	( const LED_CONFIG * Copy_struct_Led_Config )
{
	DIO_SetPinDirection(Copy_struct_Led_Config->LED_Port, Copy_struct_Led_Config->LED_Pin, OUTPUT);
}

/*************************************************************************************************************************/
/* 
	@brief	* The function Turn the LED ON
			* The function takes the LED_PORT and THE lED-PIN from the LED_CONFIG struct 
			* The function Checks if 
								1-the connection type is "Active_HIGH" Writes 1 to the pin at the PORTx to logic HIGH 
								2-the connection type is "Active_LOW" Writes 0 to the pin at the PORTx to logic LOW 
	@param[in] LED_CONFIG Copy_struct_Led_Config "the input parameter is an object of struct LED_CONFIG"
	@param[out] void
*/
/************************************************************************************************************************/
void LED_voidON  	( const LED_CONFIG * Copy_struct_Led_Config )
{
	if(Copy_struct_Led_Config.State == Active_HIGH)
	{
		
		DIO_SetPinValue(Copy_struct_Led_Config->LED_Port, Copy_struct_Led_Config->LED_Pin, HIGH);
	}
	else if(Copy_struct_Led_Config.State == Active_LOW)
	{
		DIO_SetPinValue(Copy_struct_Led_Config->LED_Port, Copy_struct_Led_Config->LED_Pin, LOW);
	}
}

/******************************************************************************************************************************/
/* 
	@berief		* The function Turn the LED OFF
				* The function takes the LED_PORT and THE lED-PIN from the LED_CONFIG struct 
				* The function Checks if 
								1-the connection type is "Active_HIGH" Writes 0 to the pin at the PORTx to logic LOW 
								2-the connection type is "Active_LOW" Writes 1 to the pin at the PORTx to logic HIGH
								
	@param[in] LED_CONFIG Copy_struct_Led_Config "the input parameter is an object of struct LED_CONFIG"
	@param[out] void
*/
/******************************************************************************************************************************/
void LED_voidOFF 	( const LED_CONFIG *Copy_struct_Led_Config )
{
	if(Copy_struct_Led_Config->State == Active_HIGH)
	{
		
		DIO_SetPinValue(Copy_struct_Led_Config->LED_Port, Copy_struct_Led_Config->LED_Pin, LOW);
	}
	else if(Copy_struct_Led_Config.State == Active_LOW)
	{
		DIO_SetPinValue(Copy_struct_Led_Config->LED_Port, Copy_struct_Led_Config->LED_Pin, HIGH);
	}
	
}
