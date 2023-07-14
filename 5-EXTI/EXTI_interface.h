/**
 * @author Abdelrahman Elhetamy
 * @date 24	Jun 2023
 * @file EXTI_interface.h
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum
{
	RISING_TRIGGER,
	FALLING_TRIGGER
}Trigger_Source;


typedef enum
{
	EXTI_0=6,
	EXTI_1,
	EXTI_2,
	EXTI_3,
	EXTI_4,
	EXTI_5=23,
	EXTI_6=23,
	EXTI_7=23,
	EXTI_8=23,
	EXTI_9=23,
	EXTI_10=40,
	EXTI_11=40,
	EXTI_12=40,
	EXTI_13=40,
	EXTI_14=40,
	EXTI_15=40
}EXTI_NVIC;

typedef enum
{
	EXTI_PORTA,
	EXTI_PORTB,
	EXTI_PORTC,
	EXTI_PORTD,
	EXTI_PORTF
}EXT_INT_port;

typedef enum
{
	EXTI_0_Index,
	EXTI_1_Index,
	EXTI_2_Index,
	EXTI_3_Index,
	EXTI_4_Index,
	EXTI_5_Index,
	EXTI_6_Index,
	EXTI_7_Index,
	EXTI_8_Index,
	EXTI_9_Index,
	EXTI_10_Index,
	EXTI_11_Index,
	EXTI_12_Index,
	EXTI_13_Index,
	EXTI_14_Index,
	EXTI_15_Index
}EXTI_Index;

void EXTI_voidEnable(EXTI_Index Copy_u8ID,uint8 Copy_u8Port);
void EXTI_voidSenseCtrl(Trigger_Source Copy_u8Trigger,EXTI_Index Copy_u8ID);
void EXTI_voidSWInterrupt(EXTI_Index Copy_u8EXTISource);
void EXTI_voidSetCallBackFunc(EXTI_Index Copy_u8EXTISource,void (*Copy_pvFunc)(void));

#endif /* EXTI_INTERFACE_H_ */
