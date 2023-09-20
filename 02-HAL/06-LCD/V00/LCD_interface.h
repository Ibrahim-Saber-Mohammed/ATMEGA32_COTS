/******************************************************************************/
/**
*@file    LCD_interface.h
*@brief  This File contains the prototypes of  Functions
*@author Ibrahim Saber
*/
/*****************************************************************************/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define FOUR_BIT      0
#define EIGHT_BIT     1
#define LOW_NIBBLE    0
#define HIGH_NIBBLE   1

#define LCD_FUNCTION_4BIT_2LINES  0x28
#define LCD_FUNCTION_8BIT_2LINES  0x38


#define LCD_CLEAR_SCREEN                       0x01
#define LCD_RETURN_HOME                        0x02
#define LCD_DISP_OFF_CURSOR_ON				   0x0A
#define LCD_DISP_OFF_CURSOR_OFF                0x08
#define LCD_DISP_ON_CURSOR_ON                  0x0E
#define LCD_DISP_ON_CURSOR_OFF                 0x0C
#define MOVE_DISP_LEFT                         0x18
#define MOVE_DISP_RIGHT                        0x1C
#define MOVE_CURSOR_LEFT                       0x10
#define MOVE_CURSOR_RIGHT                      0x14
#define LCD_DISP_ON_CURSOR_BLINKING            0x0F
#define LCD_ENTRY_DEC                          0x04
#define LCD_ENTRY_INC                          0x06
#define LCD_ENTRY_DEC_SHIFT                    0x05
#define LCD_ENTRY_INC_SHIFT                    0x07
#define LCD_ENTRY_MODE                         0x06
#define LCD_BEGIN_AT_FIRST_RAW                 0x80
#define LCD_BEGIN_AT_SECOND_RAW                0xC0

/************************************************************************/
/**           LCD_voidInit												*/
/**@description   :initialize the LCD either 8-BIT Mode or 4-BIT Mode	*/
/**@param[in]    :void													*/
/**@param[out]   :void													*/                       
/************************************************************************/


void LCD_voidInit(void);

/************************************************************************************************/
/* Function name :LCD_voidSend_Command															*/
/**@description  :send command to IR REGISTER of the LCD micro controller and saved in DDRAM	*/
/**@param[in]    :u8 Copy_u8Command																*/
/**@param[out]   :void																			*/
/************************************************************************************************/
void LCD_voidSend_Command(u8 Copy_u8Command);

/************************************************************************************************/
/* Function name :LCD_voidSend_Char																*/
/**@description  :the Function Displays A char on LCD											*/
/**@param[in]    :u8 Copy_u8Char																*/
/**@param[out]   :void																			*/
/************************************************************************************************/
void LCD_voidSend_Char( u8 Copy_u8Char);

/************************************************************************************************/
/* Function name :LCD_voidSend_Number															*/
/**@description  :the Function Displays A number on LCD											*/
/**@param[in]    :u8 Copy_u8num 																*/
/**@param[out]   :void																			*/
/************************************************************************************************/
void LCD_voidSend_Number( u32 Copy_u8num);

/************************************************************************************************/
/* Function name :LCD_voidSend_Real_Number														*/
/**@description  :the Function Displays A float Number on LCD									*/
/**@param[in]    : s64 Copy_u8num 	the number to be displayed									*/
/**@param[out]   :void																			*/
/************************************************************************************************/
void LCD_voidSend_Real_Number(f64 Copy_u8num);


/************************************************************************************************/
/* Function name :LCD_voidSend_String															*/
/**@description  :the Function Displays A string on LCD the string is array of char				*/
/**@param[in]    :Copy_u8data 	the string to be displayed									    */
/**@param[out]   :void																			*/
/************************************************************************************************/
void LCD_voidSend_String(u8 *Copy_u8data);

/************************************************************************************************/
/* Function name :LCD_voidCLEAR_SCREEN															*/
/**@description  :the Function clears the screen												*/
/**@param[in]    :void																			*/
/**@param[out]   :void																			*/
/************************************************************************************************/
void LCD_voidCLEAR_SCREEN(void);

/************************************************************************************************/
/* Function name :LCD_voidGotoxy																*/
/**@description  :the Function moves the cursor and change its position							*/
/** according to the given data represented by the line number and the position					*/
/**@param[in]    :u8 line  unsigned char line number }											*/
/**@param[in]    :u8 position unsigned char position 									        */
/**@param[out]   :void																			*/
/************************************************************************************************/
void LCD_voidGotoxy(u8 Copy_u8line ,u8 Copy_u8position);

#endif