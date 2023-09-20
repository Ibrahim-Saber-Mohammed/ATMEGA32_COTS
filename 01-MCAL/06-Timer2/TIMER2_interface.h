/*
 * Timer2_interface.h
 *
 *  Created on: Sep 8, 2021
 *      Author: ibrahim
 */

#ifndef MCAL_TIMER2_TIMER2_INTERFACE_H_
#define MCAL_TIMER2_TIMER2_INTERFACE_H_

typedef enum{
	TIMER2_NORMAL				= ( 0b0 << 6 ) | ( 0b0 << 3 ),
	TIMER2_COMAPRE_MATCH		= ( 0b0 << 6 ) | ( 0b1 << 3 ),
	TIMER2_FAST_PWM				= ( 0b1 << 6 ) | ( 0b1 << 3 ),
	TIMER2_PHASE_CORRECT_PWM 	= ( 0b1 << 6 ) | ( 0b0 << 3 )
}TIMER2_OpertaionMode_t;

typedef enum{
	TIMER2_OVE_INTERRUPT_ENABLE  = ( 0b1 << 6 ),
	TIMER2_COMP_INTERRUPT_ENABLE = ( 0b1 << 7 ),
	TIMER2_DISABLE_INTERRUPT     = ( 0b00 << 6)
}TIMER2_InterruptSource_t;

typedef enum{
	TIMER2_DISABLE	= 0x00  ,
	TIMER2_CLK_DEV_1		,
	TIMER2_CLK_DEV_8		,
	TIMER2_CLK_DEV_32		,
	TIMER2_CLK_DEV_64		,
	TIMER2_CLK_DEV_128		,
	TIMER2_CLK_DEV_256		,
	TIMER2_CLK_DEV_1024
}TIMER2_Clock_Prescaler_t;

typedef enum{
	TIMER2_OC2_NON_PWM_DISCONNECT  		= ( 0b00 << 4 )  ,
	TIMER2_OC2_NON_PWM_TOGGLE      		= ( 0b01 << 4 )  ,
	TIMER2_OC2_NON_PWM_CLEAR       		= ( 0b10 << 4 )  ,
	TIMER2_OC2_NON_PWM_SET		   		= ( 0b11 << 4 )  ,
	TIMER2_OC2_FAST_PWM_DISCONNECT 		= ( 0b00 << 4 )  ,
	TIMER2_OC2_FAST_PWM_NON_INVERTING 	= ( 0b10 << 4 )  ,
	TIMER2_OC2_FAST_PWM_INVERTING		= ( 0b11 << 4 )	 ,
	TIMER2_OC2_PHASE_CORRECT_PWM        = ( 0b00 << 4 )		,
	TIMER2_OC2_PHASE_CORRECT_PWM_NON_INVERTING 	= ( 0b10 << 4 )   ,
	TIMER2_OC2_PHASE_CORRECT_PWM_INVERTING		= ( 0b11 << 4 )

}TIMER2_CompareOutput_t;

typedef struct{
	TIMER2_OpertaionMode_t		TIM2_Mode			;
	TIMER2_InterruptSource_t	TIM2_Interrupt		;
	TIMER2_Clock_Prescaler_t	TIM2_ClockSelect	;
	TIMER2_CompareOutput_t		TIM2_OutputCompare	;
}TIMER2_Configs_t;

u8 TIM2_u8SetTimerConfigurations( const TIMER2_Configs_t * Copy_structConfigurations );

void TIM2_voidSet_OCR2_value(u8 Copy_u8Value);

void TIM2_voidSet_TCNT2_value(u8 Copy_u8Value);

void TIM2_voidEnable_OVE_Interrupt();

void TIM2_voidDisable_OVE_Interrupt();

void TIM2_voidEnable_COMP_Interrupt();

void TIM2_voidDisable_COMP_Interrupt();

u8 TIM2_u8Set_OVE_CallBack( void(* Copy_ptrFuncCallBack)(void) );

u8 TIM2_u8Set_COMP_CallBack( void(* Copy_ptrFuncCallBack)(void) );

#endif /* MCAL_TIMER2_TIMER2_INTERFACE_H_ */
