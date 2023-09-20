/*
 * ADC_program.c
 *
 *  Created on: Jul 4, 2021
 *      Author: ibrahim
 */
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"

void __vector_16(void)__attribute__((signal));

void (*ADC_CALL_BACK)(void);

ADC_Config_t ADC_Configurations;

void ADC_voidInit  (  void  )
{
	ADMUX = 0x00;
	ADCSRA = 0x00;
	/* Enable the ADC */
	SET_BIT(ADCSRA , ADEN);
	ADMUX |= ADC_REFERANCE_VOLTAGE;
	ADCSRA |= ADC_PRESCALER;

#if ADC_ADJUST == ADC_LEFT_ADJUST
	SET_BIT(ADMUX, ADLAR);
#elif	ADC_ADJUST == ADC_RIGHT_ADJUST
	CLR_BIT(ADMUX, ADLAR);
#else
#warning "Wrong ADC_ADJUST config"
	CLR_BIT(ADMUX, ADLAR);
#endif

#if ADC_AUTO_TRIGGER == ADC_ENABLE_AUTO_TRIGGERING
	SET_BIT(ADCSRA, ADATE);
	ADCSRA |= ADC_AUTO_TRIGGER_SOURCE;
#elif ADC_AUTO_TRIGGER == ADC_DISABLE_AUTO_TRIGGERING
	CLR_BIT(ADCSRA, ADATE);
#else
#warning "Wrong AutoTrigger Config"
	CLR_BIT(ADCSRA, ADATE);
#endif

#if ADC_INTERRUPT == ADC_ENABLE_INTERRUPT
	SET_BIT(ADCSRA, ADIF);
	SET_BIT(ADCSRA , ADIE);
#elif ADC_INTERRUPT == ADC_DISABLE_INTERRUPT
	CLR_BIT(ADCSRA , ADIE);
#else
	CLR_BIT(ADCSRA , ADIE);
#warning "Wrong Interrupt Configurations"
#endif
}
void ADC_voidSetConfigurations ( ADC_Config_t * Copy_structADC_Configurations )
{
	ADC_Configurations = *Copy_structADC_Configurations;
	if(Copy_structADC_Configurations != NULL)
	{
		/******************************************************/
		/* Clear the Registers */
		ADMUX = 0x00;
		ADCSRA = 0x00;
		/******************************************************/

		/* Enable the ADC */
		SET_BIT(ADCSRA , ADEN);
		/* Reference Voltage and the Channel Configurations */
		ADMUX |= Copy_structADC_Configurations->ADC_Vref_option | Copy_structADC_Configurations->ADC_Channel;

		/******************************************************/
		if (Copy_structADC_Configurations->ADC_Adjust == ADC_LEFT_ADJUST)
		{
			SET_BIT(ADMUX, ADLAR);
		}

		/**********************************************************/
		/* Auto Triggering */
		if(Copy_structADC_Configurations->ADC_AutoTriggering == ADC_ENABLE_AUTO_TRIGGERING)
		{
			SET_BIT(ADCSRA, ADATE);
			SFIOR &= ~( (0b111)<<5 ) ;
			SFIOR |= Copy_structADC_Configurations->ADC_Auto_Trigg_SRC;
		}
		else
		{
			CLR_BIT(ADCSRA, ADATE);
		}
		/***********************************************************/
		/***** Interrupt ******/
		/* Clear Flag by Writing 1 */
		SET_BIT(ADCSRA, ADIF);
		if (Copy_structADC_Configurations->ADC_InterruptEnable == ADC_ENABLE_INTERRUPT)
		{
			SET_BIT(ADCSRA , ADIE);
		}
		else
		{
			CLR_BIT( ADCSRA , ADIE);
		}
		/*********************************************************/
		/* ADC pre scaler */
		ADCSRA |= Copy_structADC_Configurations->ADC_PreScaler;

		/* Save Call Back Function */
		ADC_CALL_BACK = Copy_structADC_Configurations->ADC_CallBack;
	}
}
u16 ADC_u8ReadChannel  (  u8 Copy_u8Channel_index  )
{
	ADMUX &=~(0b1111);
	ADMUX |= Copy_u8Channel_index;
	u16 LOC_u16Result = 0;
	/* Start Conversion */
	SET_BIT(ADCSRA, ADSC);
	/* Pooling the Flag  */
	while(!GET_BIT(ADCSRA, ADIF));
	if (ADC_Configurations.ADC_Adjust == ADC_RIGHT_ADJUST)
	{
		LOC_u16Result = (ADCL)|(ADCH<<8);
	}
	else if( ADC_Configurations.ADC_Adjust == ADC_LEFT_ADJUST )
	{
		LOC_u16Result = (ADCH<<2);
	}
	/* Clearing the Flag */
	SET_BIT(ADCSRA, ADIF);

	return LOC_u16Result;
}
u8 ADC_u8SetCallBack  (  void (*Copy_PtrCallBack)(void) )
{
	u8 LOC_u8ErrorState = STD_NOK;
	if(Copy_PtrCallBack != NULL)
	{
		LOC_u8ErrorState = STD_OK;
		ADC_CALL_BACK = Copy_PtrCallBack;

	}
	return LOC_u8ErrorState;
}
void ADC_voidEnableInterrupt   ( void )
{
	SET_BIT(ADCSRA , ADIE);
}
void ADC_voidDisableInterrupt  ( void )
{
	CLR_BIT(ADCSRA , ADIE);
}

void __vector_16(void)
{
	if (ADC_CALL_BACK != NULL)
	{
		ADC_CALL_BACK();
	}
}
