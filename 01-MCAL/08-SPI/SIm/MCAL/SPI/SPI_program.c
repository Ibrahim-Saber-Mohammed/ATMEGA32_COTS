/*
 * SPI_program.c
 *
 *  Created on: Aug 23, 2021
 *      Author: ibrahim
 */

#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"
#include "../DIO/GPIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"


void SPI_voidInit(void)
{
	// Disable the SPI first then make the configurations
	SPCR &=~(1<<SPE);

	/// MAster Configurations :
	/** * Master Enabel
	 *  * Clock Pre-scaler
	 *  * Speed
	 */
#if MASTER_SLAVE == MASTER
	SPCR |=(1<<MSTR); // Enable the Master mode

#if SPI_SPEED  == DOUBLE_SPEED
	SPSR |= (1 << 0); // Enable Double Speed
#elif SPI_SPEED == NORMAL_SPEED
	SPSR &= ~(1 << 0); // Enable Double Speed
#else
#error "Wrong Configuration"

#endif

#if CLOCK_PRESCALER == CLK_DEV_4
	SPCR &=~(3 << 0) ; // Clear the first two bits
#elif CLOCK_PRESCALER == CLK_DEV_16
	SPCR|=(1 << 0);
	SPCR &=~(1 << 1);
#elif CLOCK_PRESCALER == CLK_DEV_64
	SPCR |= (2 << 0);
#elif CLOCK_PRESCALER == CLK_DEV_128
	SPCR |=(3 << 0);
#endif

#elif MASTER_SLAVE == SLAVE
	SPCR &=~(1<<MSTR); // Enable the SLAVE mode
#endif //<End of the Master

	/// General Configuration must be done for the SPI Communication
	/// These Configuration for both Master and Slave
	/// These Configuration must be the same for the Master and the salve


	/* Interrupt */
#if SPI_INTERRUPT == ENABLE_INTERRUPT
	SPCR |= (1 << SPIE); // Enable the Interrupt
#elif SPI_INTERRUPT == DISABLE_INTERRUPT
	SPCR &= ~(1 << SPIE); // Disable the Interrupt
#else
#error "Wrong Configuration"
#endif

	/* Clock Polarity */
	// First change is rising or falling
#if SPI_CPOL == SPI_FALLING
	SPCR |= (1 << CPOL);  // the leading ("the First edge ")edge is FALLING
#elif SPI_CPOL == SPI_RISING
	SPCR &= ~(1 << CPOL);  // the leading ("the First edge ")edge is RSISING
#else
#error "Wrong Configuration"
#endif

	/* Clock Phase */
	// Read first then read or write first then read
#if SPI_CPHA == READ_WRITE
	SPCR &=~(1 << CPHA);  // read first then Write

#elif SPI_CPHA == WRITE_READ
	SPCR |= (1 << CPHA);  // Setup first then Read
#else
#error "Wrong Configuration"

#endif

	/* Data order */
	// Least significant first or the most
#if DATA_ORDER == LSB_FIRST
	SPCR |= (1 << DORD); // Least Significant Bit First

#elif  DATA_ORDER == MSB_FIRST
	SPCR &= ~(1 << DORD); // Most first
#else
#error "Wrong Configuratins"
#endif

	/* Enable/Disable */
#if SPI_ENABLE_DISABLE == SPI_ENABLE
	SPCR |=(1<<SPE);
#elif SPI_ENABLE_DISABLE == SPI_DISABLE
	SPCR &=~(1<<SPE);
#else
#error "Wrong Configuration"
#endif
}

u8 SPI_u8TransmitReceive(u8 Copy_u8Data)
{
	SPDR = Copy_u8Data;
	while( !(SPSR & (1<<SPIF)) );
	return SPDR;
}


