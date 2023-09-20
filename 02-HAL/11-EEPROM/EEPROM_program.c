/***********************************************************************/
/** author  : Ibrahim Saber Mohammed								  **/
/** Date    : 4 May 2021											  **/
/** Version : V00 													  **/
/***********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "I2C_interface.h"

#include "EEPROM_interface.h"
#include "EEPROM_config.h"
#include "EEPROM_private.h"

void EEPROM_voidInit(void)
{
	I2C_voidInit();
}

