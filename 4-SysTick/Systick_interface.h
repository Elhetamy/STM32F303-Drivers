#ifndef		SYSTICK_INTERFACE_H_
#define		SYSTICK_INTERFACE_H_


typedef struct
{
	volatile uint32	STK_CTRL;
	volatile uint32	STK_LOAD;
	volatile uint32	STK_VAL;
	volatile uint32	STK_CALIB;

}STK_type;

typedef enum
{
	SysT_ENABLE=0,
	SysT_Interrupt,
	SysT_ClkSrc,
	SysT_CountFlag=16
}Ctrl_Bits;


#define			STK				((volatile STK_type *) (SYSTK_BaseAddress))

void STK_voidInit(void);
void STK_voidBusyWait(uint32 Copy_u32Ticks);
void STK_voidSingleInterval(uint32 Copy_u32Ticks, void (*Copy_voidCallBack) (void));
void STK_voidPeriodicInterval(uint32 Copy_u32Ticks ,void (*Copy_voidCallBack) (void));
void STK_voidStopInterval(void);
uint32 STK_u32GetRemaningTime(void);
uint32 STK_u32GetElapsedTime(void);


#endif
