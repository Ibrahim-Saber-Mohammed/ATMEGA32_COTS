/***********************************************************************/
/** author  : Ibrahim Saber Mohammed								  **/
/** Date    : 4 May 2021											  **/
/** Version : V00 													  **/
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"

void I2C_voidInit(void)
{
	#if I2C_MODE == MASTER
		TWAR = ( NODE_ADDRESS << 1 ) | GEN_CALL ;
		CLR_BIT( TWSR, 0) ;
		CLR_BIT( TWSR, 1) ;
		TWBR = I2C_SPEED ;
	#elif I2C_MODE == SLAVE
		TWAR = ( NODE_ADDRESS << 1 ) | GEN_CALL ;
	#else 
		#error "Wrong I2C Mode"
	#endif
}
void I2C_MASTER_voidSetConfigure(I2C_MASTER_CONFIG Copy_structConfigurations)
{
	TWAR = Copy_structConfigurations.NodeAddress | Copy_structConfigurations.G_CALL ;
	/* Prescaller 1 */
	CLR_BIT( TWSR , 0 );
	CLR_BIT( TWSR , 1 );
	/* Speed due to 8MHz */
	TWBR = Copy_structConfigurations.speed;
}
ERROR_STATE I2C_MASTER_enumSendStart(void)
{
	ERROR_STATE State = NOK;
	/// Setting the Start Condition Bit 
	TWCR->Bit.TWSTA = 1;
	/// Clrearing the Flag by Writting one 
	TWCR->Bit.TWINT = 1;
	/// pooling the Flag
	while( ! TWCR->Bit.TWINT );
	///Checking the Status Register Value With START CONDITION 
	if ( (TWSR & 0xF8) == 0x08 )
	{
		State = OK;
	}
	
	return State;
	
}
ERROR_STATE I2C_MASTER_enumSendRepeatedStart(void)
{
	ERROR_STATE State = NOK;
	/// Setting the Start Condition Bit 
	TWCR->Bit.TWSTA = 1;
	/// Clrearing the Flag by Writting one 
	TWCR->Bit.TWINT = 1;
	/// pooling the Flag
	while( ! TWCR->Bit.TWINT );
	///Checking the Status Register Value with MASTER REPEATED START CONDITION
	if ( (TWSR & 0xF8) == 0x10 )
	{
		State = OK;
	}
	
	return State;
}
void I2C_MASTER_voidSendSTOP(void)
{
	/// Setting the Stop Condition Bit 
	TWCR->Bit.TWSTO = 1;
	/// Clrearing the Flag by Writting one 
	TWCR->Bit.TWINT = 1;
	
}
ERROR_STATE I2C_MASTER_enumSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	ERROR_STATE State = NOK;
	/// Writing the Address of the Slave
	TWDR =  ( Copy_u8SlaveAddress << 1 ) | 0x01 ;
	/// Clearing the Start Condition 
	TWCR->Bit.TWSTA = 0;
	/// Clearing the flag 
	TWCR->Bit.TWINT = 1;
	/// pooling the Flag 
	while(! TWCR->Bit.TWINT);
	if ( (TWSR & 0xF8) == 0x40)
	{
		State = OK;
	}
	return State;
}
ERROR_STATE I2C_MASTER_enumSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	ERROR_STATE State = NOK;
	/// Writing the Address of the Slave
	TWDR =  ( Copy_u8SlaveAddress << 1 ) ;
	/// Clearing the Start Condition 
	TWCR->Bit.TWSTA = 0;
	/// Clearing the flag 
	TWCR->Bit.TWINT = 1;
	/// pooling the Flag 
	while(! TWCR->Bit.TWINT);
	if ( (TWSR & 0xF8) == 0x18)
	{
		State = OK;
	}
	return State;
}
ERROR_STATE I2C_MASTER_enumSendByte(u8 Copy_u8Data)
{
	ERROR_STATE State = NOK ;
	/// Writing data ro TWDR
	TWDR = Copy_u8Data;
	/// Clearing the flag
	TWCR->Bit.TWINT = 1;
	/// pooling the flag 
	while( !TWCR->Bit.TWINT );
	if ( (TWSR&0xF8) == 0x28 )
	{
		State = OK;
	}
	return State ;
}
ERROR_STATE I2C_MASTER_enumReadByte_With_NACK(u8 * Copy_u8Data)
{
	ERROR_STATE State = NOK;
	/// Clearing the flag
	TWCR->Bit.TWINT = 1;
	while( !TWCR->Bit.TWINT );
	if( (TWSR&0xF8) == 0x58)
	{
		State = OK;
		/// Reading the Data from TWDR
		*Copy_u8Data = TWDR ;
	}
	return State;
}
void I2C_SLAVE_voidSetConfigure (u8 I2C_SLAVE_CONFIG Copy_structConfigurations )
{
	TWAR = (Copy_structConfigurations.NodeAddress << 1) | Copy_structConfigurations.G_CALL ;
	
}
ERROR_STATE I2C_SLAVE_Listen_Adress_MASTER_Read(void);
{
	ERROR_STATE State = NOK;
	///Enable the ACK
	TWCR->Bit.TWEA = 1;
	///Clear the flag
	TWCR->Bit.TWINT = 1;
	while( !TWCR->Bit.TWINT  );
	/* MAster Will Read from Slave */
	/* Check the value of status register from Slave in Transmitter mode table */
	if ( (TWSR &0xF8) == 0xA8 )
	{
		State = OK ;
	}
	return State;
}
ERROR_STATE I2C_SLAVE_Listen_Adress_MASTER_Write(void)
{
	ERROR_STATE State = NOK
	///Enable the ACK
	TWCR->Bit.TWEA = 1;
	///Clear the flag
	TWCR->Bit.TWINT = 1;
	while( !TWCR->Bit.TWINT  );
	/* MAster Will Write to Slave */
	/* Check the value of status register from Slave in Reciever mode table */
	if ( (TWSR&0xF8) == 0x60 )
	{
		State = OK ;
	}
	return State;
}
ERROR_STATE I2C_SLAVE_enumSendByte_NACK(u8 Copy_u8Data)
{
	ERROR_STATE State = NOK
	/// Write the data on the Bus
	TWDR = Copy_u8Data;
	///Clear the flag
	TWCR->Bit.TWINT = 1;
	while( !TWCR->Bit.TWINT  );
	if ( (TWSR&0xF8) == 0xC0 )
	{
		State = OK ;
	}
	return State;
}
ERROR_STATE I2C_SLAVE_enumReadByte(u8 * Copy_u8Data)
{
	ERROR_STATE State = NOK
	///Clear the flag
	TWCR->Bit.TWINT = 1;
	while( !TWCR->Bit.TWINT  );
	if ( (TWSR&0xF8) == 0x80 )
	{
		State = OK ;
		/* Reading the Data from the Bus */
		*Copy_u8Data = TWDR ;
	}
	return State;
}
