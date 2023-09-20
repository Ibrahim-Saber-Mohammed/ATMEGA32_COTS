#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

typedef union{
	u8 Byte;
	struct{
		u8 MPCM : 1;
		u8 U2X  : 1;
		u8 PE 	: 1;
		u8 DOR  : 1;
		u8 FE   : 1;
		u8 UDRE : 1;
		u8 TXC  : 1;
		u8 RXC  : 1;
	}Bit;
}UCSRA_REG;

typedef union{
	u8 Byte;
	struct{
		u8 TXB8   : 1;
		u8 RXB8   : 1;
		u8 UCSZ2  : 1;
		u8 TXEN   : 1;
		u8 RXEN   : 1;
		u8 UDRIE  : 1;
		u8 TXCIE  : 1;
		u8 RXCIE  : 1;
	}Bit;
}UCSRB_REG;

#define UCPOL  	0
#define UCSZ0	1
#define UCSZ1	2
#define USBS    3
#define UPM0	4
#define UPM1	5
#define UMSEL 	6
#define URSEL   7

#define UBRRL		*( (volatile u8 * const ) 0x29 )
#define UDR			*( (volatile u8 * const ) 0x2C )
#define UBRRH		*( (volatile u8 * const ) 0x40 )
#define UCSRC		*( (volatile u8 * const ) 0x40 )

#define UCSRA		( (volatile UCSRA_REG * const ) 0x2B )
#define UCSRB		( (volatile UCSRB_REG * const ) 0x2A )

#endif
