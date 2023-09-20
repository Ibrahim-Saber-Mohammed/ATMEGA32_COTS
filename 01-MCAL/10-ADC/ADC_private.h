/*
 * ADC_private.h
 *
 *  Created on: Jul 4, 2021
 *      Author: ibrahim Saber Moahmmed
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_


#define ADMUX					*( (volatile u8 * const) 0x27 )
#define ADCSRA					*( (volatile u8 * const) 0x26 )
#define ADCL					*( (volatile u8 * const) 0x24 )
#define ADCH					*( (volatile u8 * const) 0x25 )
#define SFIOR					*( (volatile u8 * const) 0x50 )


#define ADLAR				5
#define ADEN				7
#define ADSC				6
#define ADATE				5
#define ADIF				4
#define ADIE				3



#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
