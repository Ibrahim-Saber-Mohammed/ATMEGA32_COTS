#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"



static UART_CONFIGS USART_Configs ;  // Gloabla Variable to save the Data of the cinfigurations inside

static void (*TX_CALL_BACK)(void)    = NULL;   // Call back Function to the Transmit ISR
static void (*RX_CALL_BACK)(void)    = NULL;   // Call back Function to the Receive ISR
static void (*UDRE_CALL_BACK)(void)  = NULL;   // Call back Function to the UART Error ISR // you can delete this

void UART_voidSetConfigurations(UART_CONFIGS Copy_structConfigurations)  // The user pass the Configurations 
{
	USART_Configs = Copy_structConfigurations;  // Copy and save the configyrations to the Global Variable to use inside the Driver
		/***** Speed  ******/
	if ( Copy_structConfigurations.Mode == ASYNCHRONOUS )
	{
		if ( Copy_structConfigurations.speed == DOUBLE_SPEED )
		{
			UCSRA->Bit.U2X = 1;
		}
		else
		{
			UCSRA->Bit.U2X = 0;
		}
	}
	else{
		UCSRA->Bit.U2X = 0;
	}
	
	
		/***** Enable or Disable the transmition Channel ****/
	if (Copy_structConfigurations.TX == TX_ENABLE)
	{
		UCSRB->Bit.TXEN = 1;
	}
	else if ( Copy_structConfigurations.TX == TX_DISABLE ) {
		UCSRB->Bit.TXEN = 0;
	}
	else
	{
		
	}
		/*** Enable or Disable the Recieve Channel *****/
	if (Copy_structConfigurations.RX == RX_ENABLE)
	{
		UCSRB->Bit.RXEN = 1;
	}
	else if ( Copy_structConfigurations.RX == RX_DISABLE ) {
		UCSRB->Bit.RXEN = 0;
	}
	else
	{
		
	}
		/***** Enable or Disable the interrupt of the TX ******/
	if (Copy_structConfigurations.TXC_INT == TXC_ENABLE)
	{
		UCSRB->Bit.TXCIE = 1;
	}
	else if ( Copy_structConfigurations.TXC_INT == TXC_DISABLE ){
		UCSRB->Bit.TXCIE = 0;
	}
	else
	{
		
	}
		/***** Enable or Disable the interrupt of the RX   ******/ 
	if (Copy_structConfigurations.RXC_INT == RXC_ENABLE)
	{
		UCSRB->Bit.RXCIE = 1;
	}
	else if ( Copy_structConfigurations.RXC_INT == RXC_DISABLE ){
		UCSRB->Bit.RXCIE = 0;
	}
	else
	{
		
	}
		/***** Enable or Disable the interrupt of the Data Register Empty   ******/ 
	if ( Copy_structConfigurations.UDRE_INT == UDRE_ENABLE)
	{
		UCSRB->Bit.UDRIE = 1;
	}
	else if( Copy_structConfigurations.UDRE_INT == UDRE_DISABLE )
	{
		UCSRB->Bit.UDRIE = 0;
	}
	else
	{
		
	}
		/***** Parity ******/
		
	UCSRC |= (1<<URSEL)| Copy_structConfigurations.parity ;
	
		/**** Charcter Size   ******/
	if (Copy_structConfigurations.data_Length!= NINE_BITS)
	{
		UCSRC |= (1<<URSEL)| Copy_structConfigurations.data_Length ;
	}
	else if(Copy_structConfigurations.data_Length == NINE_BITS)
	{
		UCSRC |= (1<<URSEL)| ( Copy_structConfigurations.data_Length &(0b11) ) ;
		UCSRB->Bit.UCSZ2 = 1;
	}
	else 
	{
		
	}
		/****** Stop Bit ******/
	UCSRC |= (1<<URSEL)| Copy_structConfigurations.stop;
		/*****  Mode *******/
	UCSRC |= (1<<URSEL) | Copy_structConfigurations.Mode;
	
}
void UART_voidSetBaudrate( u64 Copy_u32BaudRate)
{
	/**** Set the BAUD Rate ****/  //The Equations are From the data sheet
	u32 UBRR_VAL = 0;
	if (USART_Configs.Mode == SYNCHORONOUS)  // USe the Global Variable to Know the user Configurations
	{
		UBRR_VAL = ( CLK / (2*Copy_u32BaudRate ) ) - 1;
	}
	else if ( USART_Configs.Mode == ASYNCHRONOUS && USART_Configs.speed == NORMAL_SPEED )
	{
		UBRR_VAL = ( CLK / (16*Copy_u32BaudRate ) ) - 1;
	}
	else if ( USART_Configs.Mode == ASYNCHRONOUS && USART_Configs.speed == DOUBLE_SPEED )
	{
		UBRR_VAL = ( CLK / (8*Copy_u32BaudRate ) ) - 1;
	}
	UBRRH = (u8)( UBRR_VAL >> 8); // I need The second 8 Bits to be Written in UBRRH
	UBRRL = (u8) UBRR_VAL; // Write the First 8 bits
	
}
void UART_voidSetTXC_CallBAck ( void (*Copy_ptrFunction)(void) ){
	if ( Copy_ptrFunction != NULL ){
		TX_CALL_BACK = Copy_ptrFunction;
	}
}

void UART_voidSetRXC_CallBAck ( void (*Copy_ptrFunction)(void) )
{
	if ( Copy_ptrFunction != NULL ){
		RX_CALL_BACK = Copy_ptrFunction;
	}
}

void UART_voidSetUDRE_CallBAck( void (*Copy_ptrFunction)(void) )
{
	if ( Copy_ptrFunction != NULL ){
		UDRE_CALL_BACK = Copy_ptrFunction;
	}
}


void USART_voidTXInterrupt  ( TRANSMIT_INT TX_INT   )
{
	if ( TX_INT == TX_ENABLE )
	{
		UCSRB->Bit.TXCIE = 1;  // Equvilent to SET Bit
	}
	else if ( TX_INT == TX_DISABLE )
	{
		UCSRB->Bit.TXCIE = 0; // Clear Bit
	}
	else{
		
	}
}
void USART_voidRXInterrupt  ( RECIEVE_INT RX_INT    )
{
	if ( RX_INT == RX_ENABLE )
	{
		UCSRB->Bit.RXCIE = 1;
	}
	else if ( RX_INT == RX_DISABLE )
	{
		UCSRB->Bit.RXCIE = 0;
	}
	else{
		
	}
}
void USART_voidUDREInterrupt( BUFFER_EMPTY_INT UDRE_INT )
{
	if ( UDRE_INT == RX_ENABLE )
	{
		UCSRB->Bit.UDRIE = 1;
	}
	else if ( UDRE_INT == RX_DISABLE )
	{
		UCSRB->Bit.UDRIE = 0;
	}
	else{
		
	}
}

void UART_voidTransmit_Char  ( u16 Copy_u8Data      )
{
	while( UCSRA->Bit.UDRE == 0 ); // Wait until the Flag is raised then will go out from the Loop
	if (USART_Configs.data_Length==NINE_BITS)
	{
		UCSRB->Bit.TXB8= (Copy_u8Data >> 8) & 1 ;
	}
	UDR = (u8)Copy_u8Data; // Read the Data
	
}

Error_State UART_voidRecieve_Char   ( u16 * Copy_ptrData   )
{
	Error_State state = OK;
	u32 TimeOut = 0;
	*Copy_ptrData = 0;
	while(UCSRA->Bit.RXC == 0);
	
		if( USART_Configs.data_Length == NINE_BITS )
		{
			*Copy_ptrData  = UCSRB->Bit.RXB8 << 8  ;
		}
		*Copy_ptrData |= UDR;

	return state;
}

void UART_voidTransmit_String( u8 * Copy_ptrString )
{
	u8 iterator = 0;
	while(Copy_ptrString[iterator]!='\0')  // Transmit until reach the Null character
	{
		UART_voidTransmit_Char(Copy_ptrString[iterator]);  // Send the Character
		iterator++; // Increase the Iterator to Transmit the Next character
	}
}

void UART_voidRecieve_String ( u8 * Copy_ptrString )
{
	u8 iterator = 0;
	// u8 Dummy = OK ;
	u16 recieved = 0;
	while( recieved != 13)  // 13 is the AscII of the Enter 
	{
		UART_voidRecieve_Char(&recieved);  // Receive a character
		Copy_ptrString[iterator++] = (u8)recieved;  // Save the Received Data in the Buffer and increase the Iterator to save the next character in the new Position

	}
	
}
