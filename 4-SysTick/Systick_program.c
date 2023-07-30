/**
 * @author Abdelrahman Elhetamy
 * @file Systick_program.c
 * @brief Implementation of Systick driver functions based on STM32F303RE (ARM Cortex-M4)
 * @date July 2023 
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"

#include "Systick_reg.h"
#include "Systick_prv.h"
#include "Systick_cfg.h"
#include "Systick_interface.h"


static uint8	Mode ;
static void	(*STK_pvfCallBack) (void) = NULL;

/**
 * @brief This Function initialize the Systick through the control register
 */
void	STK_voidInit(void)
{
	/*	Systick Enable & clock source (AHB / 8)	(HSI = 8MHz ==> 1usec)*/
	STK -> STK_CTRL = 0x00000001;
}

/**
 * @brief This Function is synchronous counting till a certain time which the developer provide through polling
 * @param Copy_u32Ticks the ticks i want to wait 
 */
void	STK_voidBusyWait(uint32 Copy_u32Ticks)
{
	/*	Disable Timer 		*/
	CLR_BIT(STK -> STK_CTRL , SysT_ENABLE);
	/*	Load Ticks 			*/
	STK -> STK_LOAD = Copy_u32Ticks;
	/*	Enable Timer		*/
	SET_BIT(STK -> STK_CTRL , SysT_ENABLE);
	/*	wait on the flag	*/
	while(GET_BIT(STK -> STK_CTRL , SysT_CountFlag) == 0)
	{
		asm("NOP");
	}
	/*	Disable timer		*/
	CLR_BIT(STK -> STK_CTRL , SysT_ENABLE);
	STK -> STK_LOAD = 0;
	STK -> STK_VAL = 0;
}

/**
 * @brief This Function is Asynchronous counting till a certain time which the developer provide (End of job notification mechanism)
 * @param Copy_u32Ticks	the ticks i want to wait
 * @param Copy_voidCallBack	assign pointer to function that i want to call after the systick finish it's work
 */
void	STK_voidSingleInterval(uint32 Copy_u32Ticks, void (*Copy_voidCallBack) (void))
{
	/*	Disable Timer 				*/
	CLR_BIT(STK -> STK_CTRL , SysT_ENABLE);
	/*	Load Ticks 					*/
	STK -> STK_LOAD = Copy_u32Ticks;
	/*	Set the mode of interrupt	*/
	Mode = SINGLE_INTERVALE;
	/*	Assign Call Back			*/
	STK_pvfCallBack = Copy_voidCallBack;
	/*	Enable Interrupt PIE		*/
	SET_BIT(STK -> STK_CTRL , SysT_Interrupt);
	/*	Enable Timer				*/
	SET_BIT(STK -> STK_CTRL , SysT_ENABLE);
}

/**
 * @brief This Function is Asynchronous counting till a certain time which the developer provide but this time it's periodic which means it comes every certain time (End of job notification mechanism)
 * @param Copy_u32Ticks	the ticks i want to wait
 * @param Copy_voidCallBack	assign pointer to function that i want to call after the systick finish it's work
 */
void	STK_voidPeriodicInterval(uint32 Copy_u32Ticks ,void (*Copy_voidCallBack) (void))
{
	/*	Disable Timer 			*/
	CLR_BIT(STK -> STK_CTRL , SysT_ENABLE);
	/*	Load Ticks 				*/
	STK -> STK_LOAD = Copy_u32Ticks;
	/*	Set the mode of interrupt	*/
	Mode = PERIOD_INTERVALE;
	/*	Assign Call Back			*/
	STK_pvfCallBack = Copy_voidCallBack;
	/*	Enable Interrupt PIE	*/
	SET_BIT(STK -> STK_CTRL , SysT_Interrupt);
	/*	Enable Timer				*/
	SET_BIT(STK -> STK_CTRL , SysT_ENABLE);
}

/**
 * @brief This function is just for disable the systick
 */
void	STK_voidStopInterval(void)
{
	/*	Disable timer		*/
	CLR_BIT(STK -> STK_CTRL , SysT_ENABLE);
	STK -> STK_LOAD = 0;
	STK -> STK_VAL = 0;
}

/**
 * @brief This function get me the reading of value register
 * @return The remaining time of the time i ask to count 
 */
uint32 STK_u32GetRemaningTime(void)
{
	uint32 Local_u8Remaning = STK -> STK_VAL;

	return Local_u8Remaning;

}

/**
 * @brief This function get me the time which had passed since the systick starts to count
 * @return The Elapsed time of the time i want
 */
uint32 STK_u32GetElapsedTime(void)
{
	uint32 Local_u8Elapsed= STK -> STK_LOAD - STK -> STK_VAL;

	return Local_u8Elapsed;
}

/*
void STK_voidSetCallBack(void (*Copy_voidCallBack) (void))
{
	STK_pvfCallBack = Copy_voidCallBack;
}
 */
void	SysTick_Handler(void)
{
	uint8 u8Temp = 0 ;
	if(Mode == SINGLE_INTERVALE)
	{
		/*	Disable Interrupt	*/
		CLR_BIT(STK -> STK_CTRL , SysT_Interrupt);
		/*	Disable Timer		*/
		CLR_BIT(STK -> STK_CTRL , SysT_ENABLE);
		STK -> STK_LOAD = 0;
		STK -> STK_VAL = 0;
	}
	STK_pvfCallBack();
	/*	Clear Interrupt Flag		*/
	u8Temp = 	GET_BIT(STK -> STK_CTRL , SysT_CountFlag);
}

