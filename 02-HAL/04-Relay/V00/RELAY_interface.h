/********************************************************************************/
/* Author 		: Ibrahim Saber 												*/
/* Date 		: 22/12/2020 													*/
/* Version 		: V01															*/
/********************************************************************************/
#ifndef RELAY_INTERFACE_H_
#define RELAY_INTERFACE_H_

/* **************************************************************** */
/* Function  : Sets the Relay pin As OUTPUT pin   					*/
/* Arguments : Copy_u8portnum , Copy_u8Pinnum 						*/
/* return 	 : void 												*/
/********************************************************************/

void Relay_voidInit(u8 Copy_u8portnum , u8 Copy_u8Pinnum);


/* **************************************************************** */
/* Function  : Sets the Relay pin with Logic '1' (HIGH)				*/
/* Arguments : Copy_u8portnum , Copy_u8Pinnum 						*/
/* return 	 : void 												*/
/********************************************************************/

void Relay_voidON(u8 Copy_u8portnum , u8 Copy_u8Pinnum);

/* **************************************************************** */
/* Function  : Sets the Relay pin with Logic '0' (LOW)				*/
/* Arguments : Copy_u8portnum , Copy_u8Pinnum 						*/
/* return 	 : void 												*/
/********************************************************************/

void Relay_voidOFF(u8 Copy_u8portnum , u8 Copy_u8Pinnum);


#endif

