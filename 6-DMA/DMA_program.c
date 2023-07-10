/*
 * DMA_program.c
 *
 *  Created on: Jun 25, 2023
 *      Author: user
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"

#include "DMA_reg.h"
#include "DMA_prv.h"
#include "DMA_cfg.h"
#include "DMA_interface.h"


void DMA_voidStartChannel(uint8 Copy_u8ChannelNum,uint32 * Copy_pu32Source,uint32 * Copy_pu32Destination,uint16 Copy_u16ClockSize)
{
	/**
	 *	Start Channel
	 */
	DMA1->DMA_Channel[Copy_u8ChannelNum].DMA_CPAR = (uint32)Copy_pu32Source;
	DMA1->DMA_Channel[Copy_u8ChannelNum].DMA_CMAR = (uint32)Copy_pu32Destination;


	DMA1->DMA_Channel[Copy_u8ChannelNum].DMA_CNDTR = Copy_u16ClockSize;



}

