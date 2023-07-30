/**
 * @author Abdelrahman Elhetamy
 * @file DMA_program.c
 * @brief Implementation of DMA generic driver based on STM32F303RE(Cortex-M4)
 * @date July 2023
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"

#include "DMA_reg.h"
#include "DMA_prv.h"
#include "DMA_cfg.h"
#include "DMA_interface.h"

void DMA_voidInit(void)
{
	/**
	 *
	 * 1-Mem2Mem
	 * 2-Very High priority
	 * 3- Source Size , Dest size
	 * 4-MINC , PINC ->Activated
	 * 5- Circular deactivated
	 * 6- Direction ?
	 * 7- Transfer Interrupt enable
	 *
	 */
#if DMA_CHANNEL == CHANNEL_1
	SET_BIT(DMA1->DMA_Channel[CHANNEL_1].DMA_CCR,CCRA_TCIE);
	SET_BIT(DMA1->DMA_Channel[CHANNEL_1].DMA_CCR,CCRA_PL0);
	SET_BIT(DMA1->DMA_Channel[CHANNEL_1].DMA_CCR,CCRA_PL1);
	SET_BIT(DMA1->DMA_Channel[CHANNEL_1].DMA_CCR,CCRA_MEM2MEM);
	SET_BIT(DMA1->DMA_Channel[CHANNEL_1].DMA_CCR,CCRA_MINC);
	SET_BIT(DMA1->DMA_Channel[CHANNEL_1].DMA_CCR,CCRA_PINC);
	CLR_BIT(DMA1->DMA_Channel[CHANNEL_1].DMA_CCR,CCRA_DIR);

#if 	DMA_SourceSize == EIGHT_BIT
	CLR_BIT(DMA1->DMA_Channel[CHANNEL_1].DMA_CCR,CCRA_MSIZE0);
	CLR_BIT(DMA1->DMA_Channel[CHANNEL_1].DMA_CCR,CCRA_MSIZE1);
#elif 	DMA_SourceSize == SIXTEEN_BIT
	SET_BIT(DMA1->DMA_Channel[CHANNEL_1].DMA_CCR,CCRA_MSIZE0);
	CLR_BIT(DMA1->DMA_Channel[CHANNEL_1].DMA_CCR,CCRA_MSIZE1);
#elif 	DMA_SourceSize == THIRTYTWO_BIT
	SET_BIT(DMA1->DMA_Channel[CHANNEL_1].DMA_CCR,CCRA_MSIZE0);
	SET_BIT(DMA1->DMA_Channel[CHANNEL_1].DMA_CCR,CCRA_MSIZE1);
#endif

#if 	DMA_DestinationSize == EIGHT_BIT
	CLR_BIT(DMA1->DMA_Channel[CHANNEL_1].DMA_CCR,CCRA_PSIZE0);
	CLR_BIT(DMA1->DMA_Channel[CHANNEL_1].DMA_CCR,CCRA_PSIZE1);
#elif 	DMA_DestinationSize == SIXTEEN_BIT
	SET_BIT(DMA1->DMA_Channel[CHANNEL_1].DMA_CCR,CCRA_PSIZE0);
	CLR_BIT(DMA1->DMA_Channel[CHANNEL_1].DMA_CCR,CCRA_PSIZE1);
#elif 	DMA_DestinationSize == THIRTYTWO_BIT
	SET_BIT(DMA1->DMA_Channel[CHANNEL_1].DMA_CCR,CCRA_PSIZE0);
	SET_BIT(DMA1->DMA_Channel[CHANNEL_1].DMA_CCR,CCRA_PSIZE1);
#endif

#elif DMA_CHANNEL == CHANNEL_2
	SET_BIT(DMA1->DMA_Channel[CHANNEL_2].DMA_CCR,CCRA_TCIE);
	SET_BIT(DMA1->DMA_Channel[CHANNEL_2].DMA_CCR,CCRA_PL0);
	SET_BIT(DMA1->DMA_Channel[CHANNEL_2].DMA_CCR,CCRA_PL1);
	SET_BIT(DMA1->DMA_Channel[CHANNEL_2].DMA_CCR,CCRA_MEM2MEM);
	SET_BIT(DMA1->DMA_Channel[CHANNEL_2].DMA_CCR,CCRA_MINC);
	SET_BIT(DMA1->DMA_Channel[CHANNEL_2].DMA_CCR,CCRA_PINC);
	CLR_BIT(DMA1->DMA_Channel[CHANNEL_2].DMA_CCR,CCRA_DIR);

#if 	DMA_SourceSize == EIGHT_BIT
	CLR_BIT(DMA1->DMA_Channel[CHANNEL_2].DMA_CCR,CCRA_MSIZE0);
	CLR_BIT(DMA1->DMA_Channel[CHANNEL_2].DMA_CCR,CCRA_MSIZE1);
#elif 	DMA_SourceSize == SIXTEEN_BIT
	SET_BIT(DMA1->DMA_Channel[CHANNEL_2].DMA_CCR,CCRA_MSIZE0);
	CLR_BIT(DMA1->DMA_Channel[CHANNEL_2].DMA_CCR,CCRA_MSIZE1);
#elif 	DMA_SourceSize == THIRTYTWO_BIT
	SET_BIT(DMA1->DMA_Channel[CHANNEL_2].DMA_CCR,CCRA_MSIZE0);
	SET_BIT(DMA1->DMA_Channel[CHANNEL_2].DMA_CCR,CCRA_MSIZE1);
#endif

#if 	DMA_DestinationSize == EIGHT_BIT
	CLR_BIT(DMA1->DMA_Channel[CHANNEL_2].DMA_CCR,CCRA_PSIZE0);
	CLR_BIT(DMA1->DMA_Channel[CHANNEL_2].DMA_CCR,CCRA_PSIZE1);
#elif 	DMA_DestinationSize == SIXTEEN_BIT
	SET_BIT(DMA1->DMA_Channel[CHANNEL_2].DMA_CCR,CCRA_PSIZE0);
	CLR_BIT(DMA1->DMA_Channel[CHANNEL_2].DMA_CCR,CCRA_PSIZE1);
#elif 	DMA_DestinationSize == THIRTYTWO_BIT
	SET_BIT(DMA1->DMA_Channel[CHANNEL_2].DMA_CCR,CCRA_PSIZE0);
	SET_BIT(DMA1->DMA_Channel[CHANNEL_2].DMA_CCR,CCRA_PSIZE1);
#endif
#else
#error Wrong DMA Channel Selection
#endif
}


void DMA_voidStartChannel(uint8 Copy_u8ChannelNum,uint32 * Copy_pu32Source,uint32 * Copy_pu32Destination,uint16 Copy_u16BlockSize)
{
	/**
	 * Make Sure DMA Disabled first
	 */
	CLR_BIT(DMA1->DMA_Channel[Copy_u8ChannelNum].DMA_CCR,CCRA_EN);

	/**
	 * Write the Address
	 */
	DMA1->DMA_Channel[Copy_u8ChannelNum].DMA_CPAR = (uint32)Copy_pu32Source;
	DMA1->DMA_Channel[Copy_u8ChannelNum].DMA_CMAR = (uint32)Copy_pu32Destination;


	DMA1->DMA_Channel[Copy_u8ChannelNum].DMA_CNDTR = Copy_u16BlockSize;

	/**
	 * Enable DMA
	 */
	SET_BIT(DMA1->DMA_Channel[Copy_u8ChannelNum].DMA_CCR,CCRA_EN);

}

void DMA1_CH1_IRQHandler(void)
{

	CLR_BIT(DMA1->DMA_IFCR,IFCR_CGIF1);
	CLR_BIT(DMA1->DMA_IFCR,IFCR_CTCIF1);

}

