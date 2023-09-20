/******************************************************************************/
/**
*@file LCD_program.c
*@brief  This File contains the implementation of Functions
*@author Ibrahim Saber
*/
/*****************************************************************************/

/**
	* Standard library inclusion 
*/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
/**
	* include the interface files of the used MCAL Layer Drivers 
	* include the the module files 
*/
#include "GPIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"

#include<util/delay.h>

/*********************************************************************************/
/**
* @brief This function initialize the LCD either With the 8-BIT Mode or 4-BIT
		 it sends the commands as the Function set chose the font and the Cursor 
		 and the Display configurations 
		 all configurations are computed and being defined in the interface file 
		 
* @param[in] : void 
* @param[out]: void
*/
/***************************************************************************************/
void LCD_voidInit(void)
{
	/**
		* The Function init should begin with delay for more than 10 ms
		* The PIN RS should be OUTPUT
		* RW PIN------> OUTPUT
		* E PIN ------> OUTPUT 
	*/
	_delay_ms(50);
	GPIO_voidSetPinDir(LCD_RS,OUTPUT);
	GPIO_voidSetPinDir(LCD_RW,OUTPUT);
	GPIO_voidSetPinDir(LCD_EN,OUTPUT);
	/**
		* 8-BIT Mode the LCD PORT (8-pins ) are connected to MC ----> OUTPUT
		* RW ----> LOW " Writing Mode "
		* Calling Function LCD_voidSend Command and Pass the Command 
			* 1- Function Set 
			* 2- Display
			* 3- Clear Screen 
			* 4- Entry Mode
		* after each command should send trigger to the Enable Pin to latch the informations from data pins
	*/
	#if LCD_MODE == EIGHT_BIT 
		GPIO_voidSetPortDir(LCD_PORT,OUTPUT);
		GPIO_voidSetPinVal(LCD_RW,LOW);
		_delay_ms(15);
		LCD_voidSend_Command(LCD_FUNCTION_8BIT_2LINES);
		_delay_ms(1);
		LCD_voidSend_Command(LCD_DISP_ON_CURSOR_ON);
		_delay_ms(1);
		LCD_voidSend_Command(LCD_CLEAR_SCREEN);
		_delay_ms(15);
		LCD_voidSend_Command(LCD_ENTRY_MODE);
		_delay_ms(2);
		
		/**
		* 4-BIT Mode the LCD PORT (4-pins ) are connected to MC ----> OUTPUT
		* In This case if the 4-PINs are connected to LOW NIBBLE i deal with the LOW NIBBlE 
			Function that has been implemented in GPIO Drivers
			if the 4-PINs are connected to HIGH NIBBLE i deal with the HIGH NIBBlE 
			Function that has been implemented in GPIO Drivers
		* RW ----> LOW " Writing Mode "
		* Calling Function LCD_voidSend Command and Pass the Command 
			* 1- Function Set 
			* 2- Display
			* 3- Clear Screen 
			* 4- Entry Mode
		* after each command should send trigger to the Enable Pin to latch the informations from data pins
		
	*/
	#elif LCD_MODE == FOUR_BIT
		#if NIBBLE == LOW_NIBBLE
			GPIO_voidSet_LOW_NibbleDir(LCD_PORT,OUTPUT);
			LCD_voidSend_Command(LCD_RETURN_HOME);
			_delay_ms(15);
			LCD_voidSend_Command(LCD_FUNCTION_4BIT_2LINES);
			_delay_ms(1);
			LCD_voidSend_Command(LCD_DISP_ON_CURSOR_ON);
			_delay_ms(1);
			LCD_voidSend_Command(LCD_CLEAR_SCREEN);
			_delay_ms(15);
			LCD_voidSend_Command(LCD_ENTRY_MODE);
			_delay_ms(2);
		#elif NIBBLE == HIGH_NIBBLE 
			GPIO_voidSet_HIGH_NibbleDir(LCD_PORT,OUTPUT);
			GPIO_voidSetPinVal(LCD_RW,LOW);
			LCD_voidSend_Command(LCD_RETURN_HOME);
			_delay_ms(15);
			LCD_voidSend_Command(LCD_FUNCTION_4BIT_2LINES);
			_delay_ms(1);
			LCD_voidSend_Command(LCD_DISP_ON_CURSOR_ON);
			_delay_ms(1);
			LCD_voidSend_Command(LCD_CLEAR_SCREEN);
			_delay_ms(15);
			LCD_voidSend_Command(LCD_ENTRY_MODE);
			_delay_ms(2);
		#else /* return error */
		
		#endif	
	#else  /* return error */	
	#endif		
}
/**************************************************************************/
/**
	*@brief This Function is used to send Command to the LCD
	*@param[in]  : u8 Copy_u8Command   the Command is a hex number 
	*@param[out] :	void
	
*/
/**************************************************************************/
void LCD_voidSend_Command(u8 Copy_u8Command)
{
	/**
		* RS ----> LOW " COMMAND"
		* RW ----> LOW "Writing"
	*/
	
	GPIO_voidSetPinVal(LCD_RW,LOW);
	/** 
		* 8-BIT MODE ------> send the command to the LCD PORT
		* then Send the trigger to Enable pin (HIGH to LOW pulse)
	*/
	#if LCD_MODE == EIGHT_BIT 
		GPIO_voidSetPortVal(LCD_PORT,Copy_u8Command);
		GPIO_voidSetPinVal(LCD_RS,LOW);
		LCD_voidSend_Enable_Trigger();
		_delay_ms(10);
		/**
			* 4-BIT MODE -----> 1- Send the MSB 4 BITS to the LCD DATA pins 
								2- send trigger to Enable PIN 
								3- Send LSB 4 BITS to the LCD DATA pins 
								4- Send trigger to the Enable PIN
								5- delay (1msec) to let the LCD READ the Command 
		
		*/
	#elif LCD_MODE == FOUR_BIT
		#if NIBBLE == LOW_NIBBLE
			GPIO_voidSet_LOW_NibbleVal(LCD_PORT,Copy_u8Command>>4);
			GPIO_voidSetPinVal(LCD_RS,LOW);
			LCD_voidSend_Enable_Trigger();
			GPIO_voidSet_LOW_NibbleVal(LCD_PORT,Copy_u8Command);
			GPIO_voidSetPinVal(LCD_RS,LOW);
			LCD_voidSend_Enable_Trigger();
			_delay_ms(1);
		#elif NIBBLE == HIGH_NIBBLE
			GPIO_voidSet_HIGH_NibbleVal(LCD_PORT,Copy_u8Command>>4);
			GPIO_voidSetPinVal(LCD_RS,LOW);
			LCD_voidSend_Enable_Trigger();
			GPIO_voidSet_HIGH_NibbleVal(LCD_PORT,Copy_u8Command);
			GPIO_voidSetPinVal(LCD_RS,LOW);
			LCD_voidSend_Enable_Trigger();
			_delay_ms(1);
		#else
			/* return error */
		#endif
	#else 
		/* return error */
	#endif
	
	
	
}
/*****************************************************************************************************/
/**
	@brief  The Function is static so i can not call it from other files " private Function ".
			The Function is used to send a Pulse to the Enable Pin of the LCD 
			THE LCD can not read any data until HIGH to LOW pulse is sent to Enable Pin 
	@param[in]  : void
	@param[out] : void
*/
/*****************************************************************************************************/
static void LCD_voidSend_Enable_Trigger(void)
{
	GPIO_voidSetPinVal(LCD_EN,HIGH);
	_delay_ms(5);
	GPIO_voidSetPinVal(LCD_EN,LOW);
}
/*****************************************************************************************************/
/**
	*@brief the Function is used to send the data to LCD the data are sent in ASCII Code. 
			8-BIT Mode -------> 1- RS --------> HIGH "Data"
								2- RW --------> LOW  "Writing"
								3- Send Data to the LCD PORT 
								4- send The trigger to Enable PIN
								5- delay to LCD read the data 
								
			4-BIT Mode -------> 1- RS --------> HIGH "Data"
								2- RW --------> LOW  "Writing"
								3- Send the MSB 4 BITS to the LCD DATA pins
								4- send trigger to Enable PIN 
								5- Send LSB 4 BITS to the LCD DATA pins 
					            6- Send trigger to the Enable PIN
								7- delay to lCD read the Data
*/
/*****************************************************************************************************/
void LCD_voidSend_Char( u8 Copy_u8Char)
{
	
	GPIO_voidSetPinVal(LCD_RW,LOW);
	#if LCD_MODE == EIGHT_BIT
		GPIO_voidSetPortVal(LCD_PORT,Copy_u8Char);
		GPIO_voidSetPinVal(LCD_RS,HIGH);
		LCD_voidSend_Enable_Trigger();
		
	
	#elif LCD_MODE == FOUR_BIT
		#if NIBBLE == LOW_NIBBLE
			GPIO_voidSet_LOW_NibbleVal(LCD_PORT, Copy_u8Char>>4);
			GPIO_voidSetPinVal(LCD_RS,HIGH);
			LCD_voidSend_Enable_Trigger();
			GPIO_voidSet_LOW_NibbleVal(LCD_PORT, Copy_u8Char);
			GPIO_voidSetPinVal(LCD_RS,HIGH);
			LCD_voidSend_Enable_Trigger();
			_delay_ms(1);
		#elif NIBBLE == HIGH_NIBBLE
			GPIO_voidSet_HIGH_NibbleVal(LCD_PORT, Copy_u8Char>>4);
			GPIO_voidSetPinVal(LCD_RS,HIGH);
			LCD_voidSend_Enable_Trigger();
			GPIO_voidSet_HIGH_NibbleVal(LCD_PORT, Copy_u8Char);
			GPIO_voidSetPinVal(LCD_RS,HIGH);
			LCD_voidSend_Enable_Trigger();
			_delay_ms(1);
		#else
			/* return error */
		#endif
	#else
		/* return error */
	#endif
	
}
/*****************************************************************************************************/
/**
*@brief : this Function is used to Send string to LCD 
		 As the string is an array of characters
		 then the termination of the array is '\n' "NULL" char so we use the pointer to the array 
		 and keep calling the Function send char and increment the pointer
		 until the pointer is pointing to '\0'
*@param[in]  : u8 *Copy_u8data   address of the array of char 
*@param[out] : void		 		 
*/
/****************************************************************************************************/
void LCD_voidSend_String(u8 *Copy_u8data)
{
	while (*Copy_u8data != '\0')
	{
		LCD_voidSend_Char(*Copy_u8data);
		Copy_u8data++;
	}
}

/****************************************************************************************************/
/**
*@brief : this Function is used to Send a number to LCD 
		 the number should be converted to ASCII so the function "sprintf" 
		 sprintf is used to store any thing in a buffer as string 
		 then we send the buffer to the LCD as string using LCD send string
		
*@param[in]  : u8 Copy_u8data   The number to be sent to the LCD
*@param[out] : void		 		 
*/
/****************************************************************************************************/
void LCD_voidSend_Number( u32 Copy_u8num)
{
	/*
		u8 Buffer[7];
		sprintf(Buffer,"%d",Copy_u8num);
		LCD_voidSend_String(Buffer);
	*/
	u64 LOC_u64Reversed = 1 ;

	if( Copy_u64Number == 0 ){ CLCD_voidSendData('0'); }
	else{

		while ( Copy_u64Number != 0 ){

			LOC_u64Reversed = ( LOC_u64Reversed * 10 ) + ( Copy_u64Number % 10 );
			Copy_u64Number /= 10 ;

		}

		while ( LOC_u64Reversed != 1 ){

			CLCD_voidSendData( ( LOC_u64Reversed % 10 ) + 48 );
			LOC_u64Reversed /= 10 ;

		}

	}

}


void LCD_voidSend_Real_Number(f64 Copy_u8num)
{
	u8 str [16];
	u8 *tmpsign = (Copy_u8num < 0) ? "-": "";
	f32 tmpval = (Copy_u8num < 0) ? -Copy_u8num : Copy_u8num;
	s32 tmpInt1 = tmpval;
	f32 tmpFrac = tmpval - tmpInt1;
	s32 tmpInt2 = tmpFrac * 10000;
	sprintf(str, "%s%d.%04d", tmpsign,tmpInt1,tmpInt2);
	LCD_voidSend_String(str);
}

void LCD_voidGotoxy(u8 Copy_u8line ,u8 Copy_u8position)
{
	/// The Start Address of each line in the different LCD types 
	u8 firstCharAddress[4] = {0x80, 0xC0, 0x94, 0xD4};
	/// Local variable to hold the command to be sent to LCD
	u8 Local_Data = 0;
	/// this Step is only Because i'm working with 2*16 LCD 
	if (Copy_u8line > 2 || Copy_u8line < 1 ||  Copy_u8position > 16 || Copy_u8position < 1 )
	{
		//// the command is to goto the beginning 
		Local_Data = 0x80;
	}
	else
	{
		/// the command here takes the line number then its the address of the first element 
		/// then add the column number 
		Local_Data = firstCharAddress[Copy_u8line-1] + Copy_u8position-1 ;
	}
	/// sending the command to LCD 
	LCD_voidSend_Command(Local_Data);
}
