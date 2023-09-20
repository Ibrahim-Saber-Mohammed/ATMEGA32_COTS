/***********************************************************************/
/** author  : Ibrahim Saber Mohammed								  **/
/** Date    : 4 May 2021											  **/
/** Version : V00 													  **/
/***********************************************************************/

#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_

			/* 1- MASTER
			   2- SLAVE			*/
#define I2C_MODE	MASTER

			/* 1- STAND_SPEED
			   2- FAST_SPEED	*/
#if I2C_MODE == MASTER
	#define I2C_SPEED	STAND_SPEED
#endif
				/* Optional except any address Starts with xxx 0000 or xxx 1111 */
#define NODE_ADDRESS  1

			/* 1- GEN_CALL_ENABLE
			   2- GEN_CALL_DISABLE */
#define GEN_CALL		GEN_CALL_DISABLE

#endif
