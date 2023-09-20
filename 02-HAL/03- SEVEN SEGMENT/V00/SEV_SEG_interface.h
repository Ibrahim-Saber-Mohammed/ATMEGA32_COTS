#ifndef SEV_SEG_INTERFACE_H
#define SEV_SEG_INTERFACE_H

typedef enum{
	
	FOUR_BITS,
	EIGHT_BITS
	
}MOODE;

typedef enum {
	
	LOW_NIBBLE,
	HIGH_NIBBLE,
	None
	
}SEV_SEG_Nibble;

typedef enum {
	
	COM_CATHODE,
	COM_ANODE
	
}SEV_SEG_connection;

typedef struct{
	
	u8 Port						;
	MOODE SEV_SEG_mode			;
	SEV_SEG_Nibble nibble		;
	SEV_SEG_connection type		;
	
}SEV_SEG_config;

void SEV_SEG_voidInit(SEV_SEG_config Copy_structconfigs);

void SEV_SEG_voidDisplay(SEV_SEG_config Copy_structconfigs, u8 Copy_u8Value);

#endif
