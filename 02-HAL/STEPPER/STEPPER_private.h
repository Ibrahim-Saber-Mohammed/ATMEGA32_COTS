/*
 * STEPPER_private.h
 *
 *  Created on: Jul 1, 2021
 *      Author: ibrahim
 */

#ifndef HAL_STEPPER_STEPPER_PRIVATE_H_
#define HAL_STEPPER_STEPPER_PRIVATE_H_

#define STEPPER_PINS	4
static void Stepper_voidReset(void);
static void STEPPER_voidMoveHalfStep(u8 Copy_u8StepperSpeed, u8 Copy_u8StepperDirection);

#endif /* HAL_STEPPER_STEPPER_PRIVATE_H_ */
