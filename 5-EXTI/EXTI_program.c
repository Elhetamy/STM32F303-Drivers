

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"


#include "EXTI_reg.h"
#include "EXTI_prv.h"
#include "EXTI_cfg.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"


static void (*EXTI_pvNVICNotification[16])(void) = NULL;

void EXTI_voidEnable(uint8 Copy_u8ID)
{
	/**
	 * Enable The Masked bit in NVIC
	 */
	/*uint8 Local_u8MaskedToNVIC = 0xFF;
	if(Copy_u8ID <= 0 && Copy_u8ID >= 4)
	{
		Local_u8MaskedToNVIC = EXTI_0 + Copy_u8ID;
	}
	else if(Copy_u8ID >= 5 && Copy_u8ID <= 9)
	{
		Local_u8MaskedToNVIC = EXTI_5;
	}
	else if(Copy_u8ID >= 10 && Copy_u8ID <= 15)
	{
		Local_u8MaskedToNVIC = EXTI_11;
	}*/
	NVIC_voidPerInterruptEnable(Copy_u8ID);

	/**
	 * Enable Interrupt Mask and Event Mask
	 */
	if(Copy_u8ID < 31)
	{
		SET_BIT(EXTI_IMR1,Copy_u8ID);
		SET_BIT(EXTI_EMR1,Copy_u8ID);

	}
	else if(Copy_u8ID < 64)
	{
		Copy_u8ID -= 32;
		SET_BIT(EXTI_IMR2,Copy_u8ID);
		SET_BIT(EXTI_EMR2,Copy_u8ID);
	}

}

void EXTI_voidSenseCtrl(Trigger_Source Copy_u8Trigger,uint8 Copy_u8ID)
{
	if(Copy_u8ID < 23 && Copy_u8ID > 28)
	{
		switch(Copy_u8Trigger)
		{
		case RISING_TRIGGER:
			if(Copy_u8ID < 31)
			{
				SET_BIT(EXTI_RSTR1,Copy_u8ID);
			}
			else if(Copy_u8ID < 64)
			{
				Copy_u8ID -= 32;
				SET_BIT(EXTI_RSTR2,Copy_u8ID);
			}
			break;
		case FALLING_TRIGGER:
			if(Copy_u8ID < 31)
			{
				SET_BIT(EXTI_FSTR1,Copy_u8ID);
			}
			else if(Copy_u8ID < 64)
			{
				Copy_u8ID -= 32;
				SET_BIT(EXTI_FSTR2,Copy_u8ID);
			}
			break;
		}
	}
}

void EXTI_voidSWInterrupt(EXTI_Index Copy_u8EXTISource)
{
	if(Copy_u8ID < 31)
	{
		SET_BIT(EXTI_SWIER1,Copy_u8ID);
		//SET_BIT(EXTI_EMR1,Copy_u8ID);

	}
	else if(Copy_u8ID < 64)
	{
		Copy_u8ID -= 32;
		SET_BIT(EXTI_SWIER2,Copy_u8ID);
		//SET_BIT(EXTI_EMR2,Copy_u8ID);
	}
}

void EXTI_voidSetCallBackFunc(EXTI_Index Copy_u8EXTISource,void (*Copy_pvFunc)(void))
{
	EXTI_pvNVICNotification[Copy_u8EXTISource]= Copy_pvFunc;
}

void EXTI0_IRQHandler(void)
{
	EXTI_pvNVICNotification[EXTI_0_Index]();
}

void EXTI1_IRQHandler(void)
{
	EXTI_pvNVICNotification[EXTI_1_Index]();
}

void EXTI2_IRQHandler(void)
{
	EXTI_pvNVICNotification[EXTI_2_Index]();
}

void EXTI3_IRQHandler(void)
{
	EXTI_pvNVICNotification[EXTI_3_Index]();
}

void EXTI4_IRQHandler(void)
{
	EXTI_pvNVICNotification[EXTI_4_Index]();
}

void EXTI9_5_IRQHandler(void)
{
	if(GET_BIT(EXTI_PR1,EXTI_5_Index) == 1)
	{
		EXTI_pvNVICNotification[EXTI_5_Index]();
	}
	else if(GET_BIT(EXTI_PR1,EXTI_6_Index) == 1)
	{
		EXTI_pvNVICNotification[EXTI_6_Index]();
	}
	else if(GET_BIT(EXTI_PR1,EXTI_7_Index) == 1)
	{
		EXTI_pvNVICNotification[EXTI_7_Index]();
	}
	else if(GET_BIT(EXTI_PR1,EXTI_8_Index) == 1)
	{
		EXTI_pvNVICNotification[EXTI_8_Index]();
	}
	else if(GET_BIT(EXTI_PR1,EXTI_9_Index) == 1)
	{
		EXTI_pvNVICNotification[EXTI_9_Index]();
	}
}


void EXTI15_10_IRQHandler(void)
{
	if(GET_BIT(EXTI_PR1,EXTI_10_Index) == 1)
	{
		EXTI_pvNVICNotification[EXTI_10_Index]();
	}
	else if(GET_BIT(EXTI_PR1,EXTI_11_Index) == 1)
	{
		EXTI_pvNVICNotification[EXTI_11_Index]();
	}
	else if(GET_BIT(EXTI_PR1,EXTI_12_Index) == 1)
	{
		EXTI_pvNVICNotification[EXTI_12_Index]();
	}
	else if(GET_BIT(EXTI_PR1,EXTI_13_Index) == 1)
	{
		EXTI_pvNVICNotification[EXTI_13_Index]();
	}
	else if(GET_BIT(EXTI_PR1,EXTI_14_Index) == 1)
	{
		EXTI_pvNVICNotification[EXTI_14_Index]();
	}
	else if(GET_BIT(EXTI_PR1,EXTI_15_Index) == 1)
	{
		EXTI_pvNVICNotification[EXTI_15_Index]();
	}
}

