/*
 * STEPPER_interface.h
 *
 *  Created on: Jul 1, 2021
 *      Author: ibrahim
 */

#ifndef HAL_STEPPER_STEPPER_INTERFACE_H_
#define HAL_STEPPER_STEPPER_INTERFACE_H_

#define ROTATE_CW					0
#define ROTATE_CCW					1
#define STEPPER_FULL_STEP			0
#define STEPPER_HALF_STEP			1

#define STEPPER_MAX_SPEED			2
#define STEPPER_MAX_SPEED_DEV2		4
#define STEEPER_MIN_SPEED			10
#define STEPPER_MID_SPEED			5

typedef struct {
	u8 STEPPER_Direction;
	u8 STEPPER_Speed;
	u16 STEPPER_Angle;
	u8 STEEPER_StepType;
}STEPPER_Configs_t;

void STEPPER_voidInit(void);
void STEPPER_voidMove(STEPPER_Configs_t * Copy_structStepper_configurations);



#endif /* HAL_STEPPER_STEPPER_INTERFACE_H_ */
