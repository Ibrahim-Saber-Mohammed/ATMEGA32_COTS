/*
 * SPI_private.h
 *
 *  Created on: Aug 23, 2021
 *      Author: ibrahim
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_



#define SPCR		*( (volatile u8 * const) 0x2D )
#define SPIE		7
#define SPE			6
#define DORD		5
#define MSTR		4
#define CPOL		3
#define CPHA		2
#define SPR1		1
#define SPR0		0


#define SPSR		*( (volatile u8 * const) 0x2E )
#define SPIF		7
#define WCOL		6
#define SPDR		*( (volatile u8 * const) 0x2F )


#define MASTER	0
#define SLAVE	1

#define NORMAL_SPEED	0
#define DOUBLE_SPEED	1

#define ENABLE_INTERRUPT	1
#define DISABLE_INTERRUPT	0

#define LSB_FIRST			0
#define MSB_FIRST			1

#define READ_WRITE			0
#define WRITE_READ			1


#define SPI_FALLING			0
#define SPI_RIDING			1

#define SPI_ENABLE			1
#define SPI_DISABLE			0

#define CLK_DEV_4			0
#define CLK_DEV_16			1
#define CLK_DEV_64			2
#define CLK_DEV_128			3

#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
