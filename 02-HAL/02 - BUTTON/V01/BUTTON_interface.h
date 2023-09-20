/********************************************************************************/
/* Author 		: Ibrahim saber													*/
/* Date 		: 10/11/2020													*/
/* Version		: V00															*/
/********************************************************************************/

#ifndef BUTTON_INTERFACE_H
#define BUTTON_INTERFACE_H

typedef enum{
	
	PULL_UP				,
	PULL_DOWN			,
	INPUT_FLOATING	
	
}Switch_connection;

typedef struct {
	
	u8 Port 				;
	u8 Pin 					;
	Switch_connection Type	;
	
}Switch_CONFIG;

void BUTTON_voidInit( Switch_CONFIG Copy_structSwitch );

u8 BUTTON_u8Read 	( Switch_CONFIG Copy_structSwitch );

#endif
