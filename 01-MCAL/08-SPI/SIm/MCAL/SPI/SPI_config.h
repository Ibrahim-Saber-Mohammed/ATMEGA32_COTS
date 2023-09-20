/*
 * SPI_config.h
 *
 *  Created on: Aug 23, 2021
 *      Author: ibrahim
 */

#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_

#define MASTER_SLAVE	MASTER
//< related to master only
#if MASTER_SLAVE == MASTER

#define SPI_SPEED	 NORMAL_SPEED

#define CLOCK_PRESCALER		CLK_DEV_16

#endif

//<General for both

/*
 * DISABLE_INTERRUPT
 * ENABLE_INTERRUPT
 * */
#define SPI_INTERRUPT   	DISABLE_INTERRUPT

/*
 * SPI_ENABLE
 * SPI_DISABLE
 * */
#define SPI_ENABLE_DISABLE  SPI_ENABLE

/*
 * LSB_FIRST
 * MSB_FIRST
 * */
#define DATA_ORDER			LSB_FIRST

/*
 * SPI_FALLING
 * SPI_RISING
 * */
#define SPI_CPOL		SPI_FALLING

/*
 * WRITE_READ
 * READ_WRITE
 * */
#define SPI_CPHA 		READ_WRITE


#endif /* MCAL_SPI_SPI_CONFIG_H_ */
