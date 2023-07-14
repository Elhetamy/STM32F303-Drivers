

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"


#include "EXTI_reg.h"
#include "EXTI_prv.h"
#include "EXTI_cfg.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"


static void (*EXTI_pvNVICNotification[16])(void) = {NULL};

void EXTI_voidEnable(EXTI_Index Copy_u8ID,uint8 Copy_u8Port)
{
	/**
	 * Configure SYSCFG EXT source
	 */
	switch(Copy_u8ID)
	{
	case EXTI_0_Index :
		if(Copy_u8Port==EXTI_PORTA)
		{
			SYSCFG_EXTICR1=0b0000;
		}
		else if(Copy_u8Port==EXTI_PORTB)
		{
			SYSCFG_EXTICR1=0b0001;
		}
		else if(Copy_u8Port==EXTI_PORTC)
		{
			SYSCFG_EXTICR1=0b0010;
		}
		else if(Copy_u8Port==EXTI_PORTF)
		{
			SYSCFG_EXTICR1=0b0101;
		}
		break;
	case EXTI_1_Index :
		if(Copy_u8Port==EXTI_PORTA)
		{
			SYSCFG_EXTICR1=0b0000 << 4;
		}
		else if(Copy_u8Port==EXTI_PORTB)
		{
			SYSCFG_EXTICR1=0b0010 << 4;
		}
		else if(Copy_u8Port==EXTI_PORTC)
		{
			SYSCFG_EXTICR1=0b0010 << 4;
		}
		else if(Copy_u8Port==EXTI_PORTF)
		{
			SYSCFG_EXTICR1=0b0101 << 4;
		}
		break;
	case EXTI_2_Index :
		if(Copy_u8Port==EXTI_PORTA)
		{
			SYSCFG_EXTICR1=0b0000 << 8;
		}
		else if(Copy_u8Port==EXTI_PORTB)
		{
			SYSCFG_EXTICR1=0b0100 << 8;
		}
		else if(Copy_u8Port==EXTI_PORTC)
		{
			SYSCFG_EXTICR1=0b0010 << 8;
		}
		else if(Copy_u8Port==EXTI_PORTD)
		{
			SYSCFG_EXTICR1=0b0011 << 8;
		}
		break;
	case EXTI_3_Index :
		if(Copy_u8Port==EXTI_PORTA)
		{
			SYSCFG_EXTICR1=0X0000 << 12;
		}
		else if(Copy_u8Port==EXTI_PORTB)
		{
			SYSCFG_EXTICR1=0b0001 << 12;
		}
		else if(Copy_u8Port==EXTI_PORTC)
		{
			SYSCFG_EXTICR1=0X0010 << 12;
		}
		break;
	case EXTI_4_Index :
		if(Copy_u8Port==EXTI_PORTA)
		{
			SYSCFG_EXTICR2=0X0000;
		}
		else if(Copy_u8Port==EXTI_PORTB)
		{
			SYSCFG_EXTICR2=0X0001;
		}
		else if(Copy_u8Port==EXTI_PORTC)
		{
			SYSCFG_EXTICR2=0X0010;
		}
		break;
	case EXTI_5_Index:
		if(Copy_u8Port==EXTI_PORTA)
		{
			SYSCFG_EXTICR2=0X0000 << 4;
		}
		else if(Copy_u8Port==EXTI_PORTB)
		{
			SYSCFG_EXTICR2=0X0010 << 4;
		}
		else if(Copy_u8Port==EXTI_PORTC)
		{
			SYSCFG_EXTICR2=0X0010 << 4;
		}
		break;
	case EXTI_6_Index:
		if(Copy_u8Port==EXTI_PORTA)
		{
			SYSCFG_EXTICR2=0X0000 << 8;
		}
		else if(Copy_u8Port==EXTI_PORTB)
		{
			SYSCFG_EXTICR2=0X0100 << 8;
		}
		else if(Copy_u8Port==EXTI_PORTC)
		{
			SYSCFG_EXTICR2=0X0010 << 8;
		}
		break;
	case EXTI_7_Index:
		if(Copy_u8Port==EXTI_PORTA)
		{
			SYSCFG_EXTICR2=0X0000 << 12;
		}
		else if(Copy_u8Port==EXTI_PORTB)
		{
			SYSCFG_EXTICR2=0X1000 << 12;
		}
		else if(Copy_u8Port==EXTI_PORTC)
		{
			SYSCFG_EXTICR2=0X0010 << 12;
		}
		break;
	case EXTI_8_Index:
		if(Copy_u8Port==EXTI_PORTA)
		{
			SYSCFG_EXTICR3=0X0000;
		}
		else if(Copy_u8Port==EXTI_PORTB)
		{
			SYSCFG_EXTICR3=0X0001;
		}
		else if(Copy_u8Port==EXTI_PORTC)
		{
			SYSCFG_EXTICR3=0X0010;
		}
		break;
	case EXTI_9_Index:
		if(Copy_u8Port==EXTI_PORTA)
		{
			SYSCFG_EXTICR3=0X0000 << 4;
		}
		else if(Copy_u8Port==EXTI_PORTB)
		{
			SYSCFG_EXTICR3=0X0010 << 4;
		}
		else if(Copy_u8Port==EXTI_PORTC)
		{
			SYSCFG_EXTICR3=0X0010 << 4;
		}
		break;
	case EXTI_10_Index:
		if(Copy_u8Port==EXTI_PORTA)
		{
			SYSCFG_EXTICR3=0X0000 << 8;
		}
		else if(Copy_u8Port==EXTI_PORTB)
		{
			SYSCFG_EXTICR3=0X0100 << 8;
		}
		else if(Copy_u8Port==EXTI_PORTC)
		{
			SYSCFG_EXTICR3=0X0010 << 8;
		}
		break;
	case EXTI_11_Index:
		if(Copy_u8Port==EXTI_PORTA)
		{
			SYSCFG_EXTICR3=0X0000 << 12;
		}
		else if(Copy_u8Port==EXTI_PORTB)
		{
			SYSCFG_EXTICR3=0X1000 << 12;
		}
		else if(Copy_u8Port==EXTI_PORTC)
		{
			SYSCFG_EXTICR3=0X0010 << 12;
		}
		break;
	case EXTI_12_Index:
		if(Copy_u8Port==EXTI_PORTA)
		{
			SYSCFG_EXTICR4=0X0000;
		}
		else if(Copy_u8Port==EXTI_PORTB)
		{
			SYSCFG_EXTICR4=0X0001;
		}
		else if(Copy_u8Port==EXTI_PORTC)
		{
			SYSCFG_EXTICR4=0X0010;
		}
		break;
	case EXTI_13_Index:
		if(Copy_u8Port==EXTI_PORTA)
		{
			SYSCFG_EXTICR4=(0X0000 << 4);
		}
		else if(Copy_u8Port==EXTI_PORTB)
		{
			SYSCFG_EXTICR4=0X0010 << 4;
		}
		else if(Copy_u8Port==EXTI_PORTC)
		{
			SYSCFG_EXTICR4=(0X0020 << 4);
		}
		break;
	case EXTI_14_Index:
		if(Copy_u8Port==EXTI_PORTA)
		{
			SYSCFG_EXTICR4=0X0000 << 8;
		}
		else if(Copy_u8Port==EXTI_PORTB)
		{
			SYSCFG_EXTICR4=0X0100 << 8;
		}
		else if(Copy_u8Port==EXTI_PORTC)
		{
			SYSCFG_EXTICR4=0X0200 << 8;
		}
		break;
	case EXTI_15_Index:
		if(Copy_u8Port==EXTI_PORTA)
		{
			SYSCFG_EXTICR4=0X0000 << 12;
		}
		else if(Copy_u8Port==EXTI_PORTB)
		{
			SYSCFG_EXTICR4=0X1000 << 12;
		}
		else if(Copy_u8Port==EXTI_PORTC)
		{
			SYSCFG_EXTICR4=0X2000 << 12;
		}
		break;
	}

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

void EXTI_voidSenseCtrl(Trigger_Source Copy_u8Trigger,EXTI_Index Copy_u8ID)
{
	if(!(Copy_u8ID < 23 && Copy_u8ID > 28))
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
				SET_BIT(EXTI_FTSR1,Copy_u8ID);
			}
			else if(Copy_u8ID < 64)
			{
				Copy_u8ID -= 32;
				SET_BIT(EXTI_FTSR2,Copy_u8ID);
			}
			break;
		}
	}
}

void EXTI_voidSWInterrupt(EXTI_Index Copy_u8EXTISource)
{
	if(Copy_u8EXTISource < 31)
	{
		SET_BIT(EXTI_SWIER1,Copy_u8EXTISource);
		//SET_BIT(EXTI_EMR1,Copy_u8ID);

	}
	else if(Copy_u8EXTISource < 64)
	{
		Copy_u8EXTISource -= 32;
		SET_BIT(EXTI_SWIER2,Copy_u8EXTISource);
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
	SET_BIT(EXTI_PR1,EXTI_0_Index);
}

void EXTI1_IRQHandler(void)
{
	EXTI_pvNVICNotification[EXTI_1_Index]();
	SET_BIT(EXTI_PR1,EXTI_1_Index);
}

void EXTI2_IRQHandler(void)
{
	EXTI_pvNVICNotification[EXTI_2_Index]();
	SET_BIT(EXTI_PR1,EXTI_2_Index);
}

void EXTI3_IRQHandler(void)
{
	EXTI_pvNVICNotification[EXTI_3_Index]();
	SET_BIT(EXTI_PR1,EXTI_3_Index);
}

void EXTI4_IRQHandler(void)
{
	EXTI_pvNVICNotification[EXTI_4_Index]();
	SET_BIT(EXTI_PR1,EXTI_4_Index);
}

void EXTI9_5_IRQHandler(void)
{
	if(GET_BIT(EXTI_PR1,EXTI_5_Index) == 1)
	{
		EXTI_pvNVICNotification[EXTI_5_Index]();
		SET_BIT(EXTI_PR1,EXTI_5_Index);
	}
	else if(GET_BIT(EXTI_PR1,EXTI_6_Index) == 1)
	{
		EXTI_pvNVICNotification[EXTI_6_Index]();
		SET_BIT(EXTI_PR1,EXTI_6_Index);
	}
	else if(GET_BIT(EXTI_PR1,EXTI_7_Index) == 1)
	{
		EXTI_pvNVICNotification[EXTI_7_Index]();
		SET_BIT(EXTI_PR1,EXTI_7_Index);
	}
	else if(GET_BIT(EXTI_PR1,EXTI_8_Index) == 1)
	{
		EXTI_pvNVICNotification[EXTI_8_Index]();
		SET_BIT(EXTI_PR1,EXTI_8_Index);
	}
	else if(GET_BIT(EXTI_PR1,EXTI_9_Index) == 1)
	{
		EXTI_pvNVICNotification[EXTI_9_Index]();
		SET_BIT(EXTI_PR1,EXTI_9_Index);
	}
}


void EXTI15_10_IRQHandler(void)
{
	if(GET_BIT(EXTI_PR1,EXTI_10_Index) == 1)
	{
		EXTI_pvNVICNotification[EXTI_10_Index]();
		SET_BIT(EXTI_PR1,EXTI_10_Index);
	}
	else if(GET_BIT(EXTI_PR1,EXTI_11_Index) == 1)
	{
		EXTI_pvNVICNotification[EXTI_11_Index]();
		SET_BIT(EXTI_PR1,EXTI_11_Index);
	}
	else if(GET_BIT(EXTI_PR1,EXTI_12_Index) == 1)
	{
		EXTI_pvNVICNotification[EXTI_12_Index]();
		SET_BIT(EXTI_PR1,EXTI_12_Index);
	}
	else if(GET_BIT(EXTI_PR1,EXTI_13_Index) == 1)
	{
		EXTI_pvNVICNotification[EXTI_13_Index]();
		SET_BIT(EXTI_PR1,EXTI_13_Index);
	}
	else if(GET_BIT(EXTI_PR1,EXTI_14_Index) == 1)
	{
		EXTI_pvNVICNotification[EXTI_14_Index]();
		SET_BIT(EXTI_PR1,EXTI_14_Index);
	}
	else if(GET_BIT(EXTI_PR1,EXTI_15_Index) == 1)
	{
		EXTI_pvNVICNotification[EXTI_15_Index]();
		SET_BIT(EXTI_PR1,EXTI_15_Index);
	}
}

