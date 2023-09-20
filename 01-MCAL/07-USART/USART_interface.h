#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#define NULL 0x00

typedef enum{
	NOK ,
	OK 
}Error_State;
typedef enum{
	TXC_ENABLE,
	TXC_DISABLE,
}TRANSMIT_INT;

typedef enum{
	RXC_ENABLE,
	RXC_DISABLE,
}RECIEVE_INT;

typedef enum{
	UDRE_ENABLE,
	UDRE_DISABLE,
}BUFFER_EMPTY_INT;

typedef enum{
	FIVE_BITS	= (0b00 << 1),
	SIX_BITS	= (0b01 << 1),
	SEVEN_BITS	= (0b10 << 1),
	EIGHT_BITS	= (0b11 << 1),
	NINE_BITS	= (0b111 << 1)
}CHAR_SIZE;

typedef enum{
	NO_PARITY    = (0b00<<4)	,
	EVEN_PARITY	 = (0b10<<4)	,
	ODD_PARITY   = (0b11<<4)
}PARITY_OPTIONS;

typedef enum{
	NORMAL_SPEED,
	DOUBLE_SPEED
}UART_SPPED;

typedef enum{
	ONE_STOP = ( 0 << 3),
	TWO_STOP = ( 1 << 3)
}STOP_BITS;

typedef enum{
	TX_ENABLE	,
	TX_DISABLE	
}TRANSMITER;

typedef enum{
	RX_ENABLE	,
	RX_DISABLE	
}RECIEVER;

typedef enum{
	ASYNCHRONOUS  = (0 << 6),
	SYNCHORONOUS  = (1 << 6)
}USART_Mode;
typedef struct{
	USART_Mode Mode ;
	CHAR_SIZE data_Length;
	PARITY_OPTIONS parity;
	STOP_BITS stop;
	UART_SPPED speed;
	TRANSMITER TX;
	RECIEVER RX ;
	TRANSMIT_INT TXC_INT;
	RECIEVE_INT RXC_INT;
	BUFFER_EMPTY_INT UDRE_INT;	
	
}UART_CONFIGS;

void UART_voidInit(void);

void UART_voidSetConfigurations(UART_CONFIGS Copy_structConfigurations);
void UART_voidSetBaudrate( u64 Copy_u64BaudRate);

void UART_voidSetTXC_CallBAck ( void (*Copy_ptrFunction)(void) );
void UART_voidSetRXC_CallBAck ( void (*Copy_ptrFunction)(void) );
void UART_voidSetUDRE_CallBAck( void (*Copy_ptrFunction)(void) );

void USART_voidTXInterrupt  ( TRANSMIT_INT TX_INT   );
void USART_voidRXInterrupt  ( RECIEVE_INT RX_INT    );
void USART_voidUDREInterrupt( BUFFER_EMPTY_INT UDRE_INT );





void UART_voidTransmit_Char  ( u16 Copy_u8Data      );

Error_State UART_voidRecieve_Char   ( u16 * Copy_ptrData   );

void UART_voidTransmit_String( u8 * Copy_ptrString );

void UART_voidRecieve_String ( u8 * Copy_ptrString );


#endif
