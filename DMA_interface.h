/**
 * @author Abdelrahman Elhetamy
 * @file DMA_interface.h
 * @brief DMA generic driver based on STM32F303RE(Cortex-M4)
 * @date July 2023
 */

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

#include "DMA_prv.h"

void DMA_voidInit(void);
void DMA_voidStartChannel(uint8 Copy_u8ChannelNum,uint32 * Copy_pu32Source,uint32 * Copy_pu32Destination,uint16 Copy_u16BlockSize);



#endif /* DMA_INTERFACE_H_ */
