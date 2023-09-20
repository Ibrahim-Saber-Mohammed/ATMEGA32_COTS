#include "STD_types.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SEV_SEG_interface.h"
#include "SEV_SEG_config.h"
#include "SEV_SEG_private.h"

void SEV_SEG_voidInit(SEV_SEG_config Copy_structconfigs)
{
	if( Copy_structconfigs.SEV_SEG_mode == EIGHT_BITS )
	{
		GPIO_voidSetPortDir(Copy_structconfigs.Port,0xff);
	}
	else if ( Copy_structconfigs.SEV_SEG_mode == FOUR_BITS )
	{
		if( Copy_structconfigs.nibble == LOW_NIBBLE )
		{
			GPIO_voidSet_LOW_NibbleDir(Copy_structconfigs.Port,OUTPUT);
		}
		else if( Copy_structconfigs.nibble == HIGH_NIBBLE )
		{
			GPIO_voidSet_HIGH_NibbleDir(Copy_structconfigs.Port,OUTPUT);
		}
		else
		{
			
		}
	}
}

void SEV_SEG_voidDisplay(SEV_SEG_config Copy_structconfigs, u8 Copy_u8Value)
{
	u8 array[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
		
	if ( Copy_structconfigs.type == COM_CATHODE )
	{
		if( Copy_structconfigs.SEV_SEG_mode == FOUR_BITS )
		{
			if( Copy_structconfigs.nibble == LOW_NIBBLE )
			{
				GPIO_voidSet_LOW_NibbleVal( Copy_structconfigs.Port , Copy_u8Value );
			}
			else if ( Copy_structconfigs.nibble == HIGH_NIBBLE )
			{
				GPIO_voidSet_HIGH_NibbleVal( Copy_structconfigs.Port , Copy_u8Value );
			}
			else
			{
				
			}
		}
		else if ( Copy_structconfigs.SEV_SEG_mode == EIGHT_BITS )
		{
			GPIO_voidSetPortVal(Copy_structconfigs.Port, array[Copy_u8Value]);
		}
		else
		{
			
		}
	}
	else if ( Copy_structconfigs.type == COM_ANODE )
	{
		if( Copy_structconfigs.SEV_SEG_mode == FOUR_BITS )
		{
			if( Copy_structconfigs.nibble == LOW_NIBBLE )
			{
				GPIO_voidSet_LOW_NibbleVal( Copy_structconfigs.Port , ~Copy_u8Value);
			}
			else if ( Copy_structconfigs.nibble == HIGH_NIBBLE )
			{
				GPIO_voidSet_HIGH_NibbleVal( Copy_structconfigs.Port , ~Copy_u8Value);
			}
			else 
			{
				
			}
		}
		else if ( Copy_structconfigs.SEV_SEG_mode == EIGHT_BITS )
		{
			GPIO_voidSetPortVal(Copy_structconfigs.Port, ~array[Copy_u8Value]);
		}
		else
		{
			
		}
	}
	else
	{
		
	}
}