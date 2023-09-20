/*
 * STEPPER_program.c
 *
 *  Created on: Jul 1, 2021
 *      Author: ibrahim
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/GPIO_interface.h"
#include "STEPPER_interface.h"
#include "STEPPER_config.h"
#include "STEPPER_private.h"
#include "util/delay.h"

static u8 Stepper_Array[4][2] = {{STEPPER_BLUE}, {STEPPER_PINK}, {STEPPER_YELLOW}, {STEPPER_ORANGE}};
void STEPPER_voidInit(void)
{
	/* Configure the PINS as OUTPUT */
	GPIO_voidSetPinDir( STEPPER_PINK	, OUTPUT );
	GPIO_voidSetPinDir( STEPPER_BLUE	, OUTPUT );
	GPIO_voidSetPinDir( STEPPER_ORANGE	, OUTPUT );
	GPIO_voidSetPinDir( STEPPER_YELLOW	, OUTPUT );

	GPIO_voidSetPinVal( STEPPER_PINK	, LOW );
	GPIO_voidSetPinVal( STEPPER_BLUE	, LOW );
	GPIO_voidSetPinVal( STEPPER_ORANGE	, LOW );
	GPIO_voidSetPinVal( STEPPER_YELLOW	, LOW );
}

void STEPPER_voidMove(STEPPER_Configs_t * Copy_structStepper_configurations)
{
	u16 LOC_Angle_Steps = 0;
	u16 LOC_Iterator = 0;
	s8  LOC_Iterator2 = 0;
	if( Copy_structStepper_configurations !=NULL)
	{
		if (Copy_structStepper_configurations->STEEPER_StepType == STEPPER_FULL_STEP)
		{
			// Number of Steps required to Move the Given Angle
			LOC_Angle_Steps = ( ( Copy_structStepper_configurations->STEPPER_Angle )* 32 ) / 5.625 ;
			if(Copy_structStepper_configurations->STEPPER_Direction == ROTATE_CW)
			{
				for(LOC_Iterator = 0; LOC_Iterator < LOC_Angle_Steps/4; LOC_Iterator++)
				{
					for(LOC_Iterator2 = 0; LOC_Iterator2 < STEPPER_PINS ; LOC_Iterator2++)
					{
						Stepper_voidReset();
						GPIO_voidSetPinVal(Stepper_Array[LOC_Iterator2][0],Stepper_Array[LOC_Iterator2][1],HIGH);
						if (Copy_structStepper_configurations->STEPPER_Speed > 0 )
						{
							_delay_ms(Copy_structStepper_configurations->STEPPER_Speed);
						}

					}
				}
			}
			else if(Copy_structStepper_configurations->STEPPER_Direction == ROTATE_CCW)
			{
				for(LOC_Iterator = 0; LOC_Iterator < LOC_Angle_Steps/4; LOC_Iterator++)
				{
					for(LOC_Iterator2 = (STEPPER_PINS-1); LOC_Iterator2 >=0 ; LOC_Iterator2--)
					{
						Stepper_voidReset();
						GPIO_voidSetPinVal(Stepper_Array[LOC_Iterator2][0],Stepper_Array[LOC_Iterator2][1],HIGH);
						if (Copy_structStepper_configurations->STEPPER_Speed > 0 )
						{
							_delay_ms(Copy_structStepper_configurations->STEPPER_Speed);
						}

					}
				}
			}
		}
		else if (Copy_structStepper_configurations->STEEPER_StepType == STEPPER_HALF_STEP)
		{
			// Number of Steps required to Move the Given Angle
			LOC_Angle_Steps = ( ( Copy_structStepper_configurations->STEPPER_Angle )* 64 ) / 5.625 ;
			for(LOC_Iterator = 0; LOC_Iterator<LOC_Angle_Steps/8; LOC_Iterator++)
			{
				STEPPER_voidMoveHalfStep(Copy_structStepper_configurations->STEPPER_Speed, Copy_structStepper_configurations->STEPPER_Direction);
			}
		}
		else
		{
			/* Return Error */
		}
	}
}

static void Stepper_voidReset(void)
{
	GPIO_voidSetPinVal( STEPPER_PINK	, LOW );
	GPIO_voidSetPinVal( STEPPER_BLUE	, LOW );
	GPIO_voidSetPinVal( STEPPER_ORANGE	, LOW );
	GPIO_voidSetPinVal( STEPPER_YELLOW	, LOW );
}
static void STEPPER_voidMoveHalfStep(u8 Copy_u8StepperSpeed, u8 Copy_u8StepperDirection)
{
	if( Copy_u8StepperDirection == ROTATE_CW )
	{

		GPIO_voidSetPinVal( STEPPER_BLUE   , HIGH );
		GPIO_voidSetPinVal( STEPPER_PINK   , LOW  );
		GPIO_voidSetPinVal( STEPPER_YELLOW , LOW  );
		GPIO_voidSetPinVal( STEPPER_ORANGE , HIGH );
		_delay_ms(Copy_u8StepperSpeed);

		GPIO_voidSetPinVal( STEPPER_BLUE   , HIGH );
		GPIO_voidSetPinVal( STEPPER_PINK   , LOW  );
		GPIO_voidSetPinVal( STEPPER_YELLOW , LOW  );
		GPIO_voidSetPinVal( STEPPER_ORANGE , LOW );
		_delay_ms(Copy_u8StepperSpeed);

		GPIO_voidSetPinVal( STEPPER_BLUE   , HIGH );
		GPIO_voidSetPinVal( STEPPER_PINK   , HIGH  );
		GPIO_voidSetPinVal( STEPPER_YELLOW , LOW  );
		GPIO_voidSetPinVal( STEPPER_ORANGE , LOW );
		_delay_ms(Copy_u8StepperSpeed);

		GPIO_voidSetPinVal( STEPPER_BLUE   , LOW );
		GPIO_voidSetPinVal( STEPPER_PINK   , HIGH  );
		GPIO_voidSetPinVal( STEPPER_YELLOW , LOW  );
		GPIO_voidSetPinVal( STEPPER_ORANGE , LOW );
		_delay_ms(Copy_u8StepperSpeed);

		GPIO_voidSetPinVal( STEPPER_BLUE   , LOW );
		GPIO_voidSetPinVal( STEPPER_PINK   , HIGH  );
		GPIO_voidSetPinVal( STEPPER_YELLOW , HIGH  );
		GPIO_voidSetPinVal( STEPPER_ORANGE , LOW );
		_delay_ms(Copy_u8StepperSpeed);

		GPIO_voidSetPinVal( STEPPER_BLUE   , LOW );
		GPIO_voidSetPinVal( STEPPER_PINK   , LOW  );
		GPIO_voidSetPinVal( STEPPER_YELLOW , HIGH  );
		GPIO_voidSetPinVal( STEPPER_ORANGE , LOW );
		_delay_ms(Copy_u8StepperSpeed);

		GPIO_voidSetPinVal( STEPPER_BLUE   , LOW );
		GPIO_voidSetPinVal( STEPPER_PINK   , LOW  );
		GPIO_voidSetPinVal( STEPPER_YELLOW , HIGH  );
		GPIO_voidSetPinVal( STEPPER_ORANGE , HIGH );
		_delay_ms(Copy_u8StepperSpeed);

		GPIO_voidSetPinVal( STEPPER_BLUE   , LOW );
		GPIO_voidSetPinVal( STEPPER_PINK   , LOW  );
		GPIO_voidSetPinVal( STEPPER_YELLOW , LOW  );
		GPIO_voidSetPinVal( STEPPER_ORANGE , HIGH );
		_delay_ms(Copy_u8StepperSpeed);
	}
	else if ( Copy_u8StepperDirection == ROTATE_CCW )
	{
		GPIO_voidSetPinVal( STEPPER_BLUE   , LOW );
		GPIO_voidSetPinVal( STEPPER_PINK   , LOW  );
		GPIO_voidSetPinVal( STEPPER_YELLOW , LOW  );
		GPIO_voidSetPinVal( STEPPER_ORANGE , HIGH );
		_delay_ms(Copy_u8StepperSpeed);

		GPIO_voidSetPinVal( STEPPER_BLUE   , LOW );
		GPIO_voidSetPinVal( STEPPER_PINK   , LOW  );
		GPIO_voidSetPinVal( STEPPER_YELLOW , HIGH  );
		GPIO_voidSetPinVal( STEPPER_ORANGE , HIGH );
		_delay_ms(Copy_u8StepperSpeed);

		GPIO_voidSetPinVal( STEPPER_BLUE   , LOW );
		GPIO_voidSetPinVal( STEPPER_PINK   , LOW  );
		GPIO_voidSetPinVal( STEPPER_YELLOW , HIGH  );
		GPIO_voidSetPinVal( STEPPER_ORANGE , LOW );
		_delay_ms(Copy_u8StepperSpeed);

		GPIO_voidSetPinVal( STEPPER_BLUE   , LOW );
		GPIO_voidSetPinVal( STEPPER_PINK   , HIGH  );
		GPIO_voidSetPinVal( STEPPER_YELLOW , HIGH  );
		GPIO_voidSetPinVal( STEPPER_ORANGE , LOW );
		_delay_ms(Copy_u8StepperSpeed);

		GPIO_voidSetPinVal( STEPPER_BLUE   , LOW );
		GPIO_voidSetPinVal( STEPPER_PINK   , HIGH  );
		GPIO_voidSetPinVal( STEPPER_YELLOW , LOW  );
		GPIO_voidSetPinVal( STEPPER_ORANGE , LOW );
		_delay_ms(Copy_u8StepperSpeed);


		GPIO_voidSetPinVal( STEPPER_BLUE   , HIGH );
		GPIO_voidSetPinVal( STEPPER_PINK   , HIGH  );
		GPIO_voidSetPinVal( STEPPER_YELLOW , LOW  );
		GPIO_voidSetPinVal( STEPPER_ORANGE , LOW );
		_delay_ms(Copy_u8StepperSpeed);

		GPIO_voidSetPinVal( STEPPER_BLUE   , HIGH );
		GPIO_voidSetPinVal( STEPPER_PINK   , LOW  );
		GPIO_voidSetPinVal( STEPPER_YELLOW , LOW  );
		GPIO_voidSetPinVal( STEPPER_ORANGE , LOW );
		_delay_ms(Copy_u8StepperSpeed);

		GPIO_voidSetPinVal( STEPPER_BLUE   , HIGH );
		GPIO_voidSetPinVal( STEPPER_PINK   , LOW  );
		GPIO_voidSetPinVal( STEPPER_YELLOW , LOW  );
		GPIO_voidSetPinVal( STEPPER_ORANGE , HIGH );
		_delay_ms(Copy_u8StepperSpeed);

	}

}
