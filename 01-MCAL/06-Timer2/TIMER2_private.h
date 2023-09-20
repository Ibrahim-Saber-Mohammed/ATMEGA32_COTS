/*
 * Timer2_private.h
 *
 *  Created on: Sep 8, 2021
 *      Author: ibrahim
 */

#ifndef MCAL_TIMER2_TIMER2_PRIVATE_H_
#define MCAL_TIMER2_TIMER2_PRIVATE_H_

#define TIMSK               *( ( volatile u8 * const ) 0x59 )
#define TIFR                *( ( volatile u8 * const ) 0x58 )

#define OCR2				*( ( volatile u8 * const ) 0x43 )
#define TCNT2				*( ( volatile u8 * const ) 0x44 )
#define TCCR2				*( ( volatile u8 * const ) 0x45 )


#define TIMER2_TCCR2_FOC2		7
#define TIMER2_TCCR2_WGM20		6
#define TIMER2_TCCR2_COM21		5
#define TIMER2_TCCR2_COM20		4
#define TIMER2_TCCR2_WGM21		3
#define TIMER2_TCCR2_CS22		2
#define TIMER2_TCCR2_CS21		1
#define TIMER2_TCCR2_CS20		0

#define TIMER2_TIMSK_OCIE2		7
#define TIMER2_TIMSK_TOIE2		6

#define TIMER2_TIFR_OCF2		7
#define TIMER2_TIFR_TOV2		6

#endif /* MCAL_TIMER2_TIMER2_PRIVATE_H_ */
