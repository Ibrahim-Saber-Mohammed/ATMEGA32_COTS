#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_



typedef enum{
	LINE0,
	LINE1,
	LINE2
}EXTI_Line;

typedef enum{
	RISING_EDGE,
	FALLING_EDGE,
	ON_CHANGE,
	LOW_LEVEL
}Sense_Mode;

typedef struct{
	EXTI_Line LINE;
	Sense_Mode SENSE;
}EXTI_Config;

void EXTI_voidInit(void);

void EXTI_voidEnable(EXTI_Config  Configurations);

void EXTI_voidDisable(EXTI_Line Copy_enumLine);

void EXTI_voidSetCALLBACK(EXTI_Line Copy_enumLine, void(*CALLBACK)(void));

void EXTI_voidClearflag(EXTI_Line Copy_enumLine );

#endif
