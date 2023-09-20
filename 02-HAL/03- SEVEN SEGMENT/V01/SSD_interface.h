#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

typedef enum{
	
	FOUR_BITS,
	EIGHT_BITS
	
}MOODE;

typedef enum {
	
	LOW_NIBBLE,
	HIGH_NIBBLE,
	None
	
}SSD_Nibble;

typedef enum {
	
	COM_CATHODE,
	COM_ANODE
	
}SSD_type;

typedef struct{
	
	u8 Port						;
	MOODE SEV_SEG_mode			;
	SSD_Nibble nibble		;
	SSD_type type		;
	u8 EN_Port					;
	u8 EN_Pin					;
	
}SSD_config;

void SSD_voidDisplay( SSD_config Copy_structconfigs, u8 Copy_u8Value );

void SSD_voidEnable	( SSD_config Copy_structconfigs );

void SSD_voidDisable( SSD_config Copy_structconfigs );


#endif
