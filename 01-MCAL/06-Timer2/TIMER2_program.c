/*
 * TIMER2_program.c
 *
 *  Created on: Sep 8, 2021
 *      Author: ibrahim
 */

#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"

#include "TIMER2_interface.h"
#include "TIMER2_config.h"
#include "TIMER2_private.h"


static void( * TIM2_OVE_CALL_BACK )(void) = NULL ;
static void( * TIM2_COMP_CALL_BACK )(void) = NULL;

u8 TIM2_u8SetTimerConfigurations( const TIMER2_Configs_t * Copy_structConfigurations )
{
	u8 Local_u8ErrorState = STD_OK;
	if( Copy_structConfigurations != NULL )
	{
		TCCR2 &= ~(0xFF);
		TCCR2 |= Copy_structConfigurations->TIM2_Mode | Copy_structConfigurations->TIM2_ClockSelect | Copy_structConfigurations->TIM2_OutputCompare;
		TIMSK &= ~(0b11 << 6);
		TIMSK |= Copy_structConfigurations->TIM2_Interrupt;
	}
	else
	{
		Local_u8ErrorState = STD_NOK;
	}
	return Local_u8ErrorState;
}

void TIM2_voidSet_TCNT2_value(u8 Copy_u8Value)
{
	TCNT2 = Copy_u8Value;
}

void TIM2_voidSet_OCR2_value(u8 Copy_u8Value)
{
	OCR2 = Copy_u8Value;
}

void TIM2_voidEnable_OVE_Interrupt()
{
	TIMSK |= (1 << TIMER2_TIMSK_TOIE2 );
}
void TIM2_voidDisable_OVE_Interrupt()
{
	TIMSK &= ~(1 << TIMER2_TIMSK_TOIE2 );
}

u8 TIM2_u8Set_OVE_CallBack( void(* Copy_ptrFuncCallBack)(void) )
{
	u8 Local_u8ErrorState = STD_OK;
	if( Copy_ptrFuncCallBack != NULL )
	{
		TIM2_OVE_CALL_BACK = Copy_ptrFuncCallBack;
	}
	else
	{
		Local_u8ErrorState = STD_NOK;
	}

	return (Local_u8ErrorState);
}

u8 TIM2_u8Set_COMP_CallBack( void(* Copy_ptrFuncCallBack)(void) )
{
	u8 Local_u8ErrorState = STD_OK;
	if( Copy_ptrFuncCallBack != NULL )
	{
		TIM2_COMP_CALL_BACK = Copy_ptrFuncCallBack;
	}
	else
	{
		Local_u8ErrorState = STD_NOK;
	}

	return (Local_u8ErrorState);
}

void TIM2_voidEnable_COMP_Interrupt()
{
	TIMSK |= ( 1 << TIMER2_TIMSK_OCIE2 );
}
void TIM2_voidDisable_COMP_Interrupt()
{
	TIMSK &= ~( 1 << TIMER2_TIMSK_OCIE2 );
}

/* Timer2 OverFlow ISR */
void __vector_5(void)__attribute__((signal));
void __vector_5(void)
{
	if( TIM2_OVE_CALL_BACK != NULL )
	{
		TIM2_OVE_CALL_BACK();
	}
}

/* Compare Match ISR */
void __vector_4(void)__attribute__((signal));
void __vector_4(void)
{
	if( TIM2_COMP_CALL_BACK != NULL )
	{
		TIM2_COMP_CALL_BACK();
	}
}
