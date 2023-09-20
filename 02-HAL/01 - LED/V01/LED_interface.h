/********************************************************************************/
/* Author 		: Ibrahim saber													*/
/* Date 		: 10/11/2020													*/
/* Version		: V01															*/
/********************************************************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

/// The Led can be connceted either active low or active high 
/// Active Low connection means tha the cathode of the led is connected to 5v
/// Active HIGH connection means tha the cathode of the led is connected to 0v "GND" 
/// The Led should have voltage difference to be on 
/// The LED_Connection is an enum that contains the two possible types of connection 
typedef enum {
	
	Active_LOW,
	Active_HIGH
	
}LED_Connection;

/// LED_CONFIG is a struct that contains the all arguments that needed to deal with the led 
/// Like the port number and the pin number and the conncetion type 
/// So in the code i will pass an object of the LED_CONFIG to the Functions
typedef struct{
	
	u8 LED_Port					;
	u8 LED_Pin					;
	LED_Connection State	;
	
}LED_CONFIG;

void LED_voidInit	( const LED_CONFIG *Copy_struct_Led_Config );

void LED_voidON  	( const LED_CONFIG *Copy_struct_Led_Config );

void LED_voidOFF 	( const LED_CONFIG *Copy_struct_Led_Config );


#endif
