/***********************************************************************/
/** author  : Ibrahim Saber Mohammed								  **/
/** Date    : 4 May 2021											  **/
/** Version : V00 													  **/
/***********************************************************************/

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#define MASTER 		1
#define SLAVE 		0

#define STAND_SPEED  32
#define FAST_SPEED   2

#define GEN_CALL_ENABLE   1
#define GEN_CALL_DISABLE  0

typedef enum{
	NOK,
	OK
}ERROR_STATE;

typedef enum{
	STANDARD_SPEED = 32,
	FAST_SPEED = 2;
}I2C_SPEED;

typedef enum{
	I2C_GENERAL_CALL_DISABLE ,
	I2C_GENERAL_CALL_ENABLE
}GENERAL_CALL ;

typedef struct{
	I2C_SPEED speed;
	u8 NodeAddress;
	GENERAL_CALL G_CALL ;
}I2C_MASTER_CONFIG;

typedef struct{
	u8 NodeAddress;
	GENERAL_CALL G_CALL ;
}I2C_SLAVE_CONFIG;

void I2C_voidInit(void);
void I2C_MASTER_voidSetConfigure(I2C_MASTER_CONFIG Copy_structConfigurations);

ERROR_STATE I2C_MASTER_enumSendStart(void);
ERROR_STATE I2C_MASTER_enumSendRepeatedStart(void);
void I2C_MASTER_voidSendSTOP(void);
ERROR_STATE I2C_MASTER_enumSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);
ERROR_STATE I2C_MASTER_enumSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);
ERROR_STATE I2C_MASTER_enumSendByte(u8 Copy_u8Data);
ERROR_STATE I2C_MASTER_enumReadByte_With_NACK(u8 * Copy_u8Data);

void I2C_SLAVE_voidSetConfigure ( I2C_SLAVE_CONFIG Copy_structConfigurations );
ERROR_STATE I2C_SLAVE_Listen_Adress_MASTER_Read(void);
ERROR_STATE I2C_SLAVE_Listen_Adress_MASTER_Write(void);
ERROR_STATE I2C_SLAVE_enumSendByte_NACK(u8 Copy_u8Data);
ERROR_STATE I2C_SLAVE_enumReadByte(u8 * Copy_u8Data);




#endif
