/*
 * TIMER1_private.h
 *
 *  Created on: Sep 16, 2021
 *      Author: ibrahim
 */

#ifndef MCAL_TIMER1_TIMER1_PRIVATE_H_
#define MCAL_TIMER1_TIMER1_PRIVATE_H_

#define TCNT1 					*((volatile u16 * )0x4C)
#define TCCR1A					*((volatile u8 * )0x4F)
#define TCCR1B					*((volatile u8 * )0x4E)
#define OCRA					*((volatile u16 * )0x4A)
#define OCRB					*((volatile u16 * )0x48)
#define ICR1					*((volatile u16 * )0x46)


#endif /* MCAL_TIMER1_TIMER1_PRIVATE_H_ */
