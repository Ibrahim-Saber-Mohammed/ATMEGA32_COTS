/*
 * ADC_interface.h
 *
 *  Created on: Jul 4, 2021
 *      Author: ibrahim
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

typedef struct{
	u8 ADC_Channel		;
	u8 ADC_Vref_option	;
	u8 ADC_PreScaler	;
	u8 ADC_AutoTriggering	;
	u8 ADC_Auto_Trigg_SRC	;
	u8 ADC_Adjust		;
	u8 ADC_InterruptEnable	;
	void (*ADC_CallBack)(void);
}ADC_Config_t;

void ADC_voidInit              (                   void                       );
void ADC_voidSetConfigurations ( ADC_Config_t * Copy_structADC_Configurations );
u16 ADC_u8ReadChannel          (           	 u8 Copy_u8Channel_index          );
u8 ADC_u8SetCallBack           (             void (*Copy_PtrCallBack)(void)   );
void ADC_voidEnableInterrupt   (                   void                       );
void ADC_voidDisableInterrupt  (                   void                       );

/******************************************************************/
/* Reference Voltage options */
#define ADC_EXTERNAL_AREF				( (0b00) << 6 )
#define ADC_INTERNAL_AVCC				( (0b01) << 6 )
#define ADC_INTERNAL_2_56				( (0b11) << 6 )
/******************************************************************/

/******************************************************************/
/* Single Ended options */
#define ADC0							 (0b0000 )
#define ADC1							 (0b0001 )
#define ADC2							 (0b0010 )
#define ADC3                             (0b0011 )
#define ADC4                             (0b0100 )
#define ADC5                             (0b0101 )
#define ADC6                             (0b0110 )
#define ADC7                             (0b0111 )
/******************************************************************/

/******************************************************************/
/*  ADC Pre scaler Options  */
#define ADC_CLCK_2						 ( 0b001 )
#define ADC_CLCK_4                       ( 0b010 )
#define ADC_CLCK_8                       ( 0b011 )
#define ADC_CLCK_16                      ( 0b100 )
#define ADC_CLCK_32                      ( 0b101 )
#define ADC_CLCK_64                      ( 0b110 )
#define ADC_CLCK_128                     ( 0b111 )

/******************************************************************/

/******************************************************************/
/* Auto Trigger Source */
#define ADC_FREE_RUNNING				( (0b000)<<5 )
#define ADC_EXTI0						( (0b010)<<5 )
#define ADC_ANALOG_COMPARATOR			( (0b001)<<5 )
#define ADC_TIM0_COMPARE_MATCH			( (0b011)<<5 )
#define ADC_TIM0_OVER_FLOW				( (0b100)<<5 )
#define ADC_TIM1_COMPARE_MATCH_B		( (0b101)<<5 )
#define ADC_TIM1_OVERFLOW				( (0b110)<<5 )
#define ADC_TIM1_ICU					( (0b111)<<5 )
/******************************************************************/
/* Differential Channel Mode */

/******************************************************************/

#define ADC_ENABLE_INTERRUPT			1
#define ADC_DISABLE_INTERRUPT			0

#define ADC_LEFT_ADJUST					1
#define ADC_RIGHT_ADJUST				0

#define ADC_ENABLE_AUTO_TRIGGERING		1
#define ADC_DISABLE_AUTO_TRIGGERING		0

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
