#ifndef _PORT_H
#define _PORT_H

#if defined (GD32F350)

#include "gd32f3x0.h"
#define FLASH_PAGE_SIZE 1024

#elif defined (GD32F130_150)
#include "gd32f1x0.h"
#define FLASH_PAGE_SIZE 1024

#elif defined (STM32F303xC)
#include "stm32f30x.h"
#define FLASH_PAGE_SIZE 2048

#elif defined (STM32F072)
#include "stm32f0xx.h"
#define FLASH_PAGE_SIZE 2048

#elif defined (STM32F030) || defined (STM32F042)
#include "stm32f0xx.h"
#define FLASH_PAGE_SIZE 1024

#elif defined (STM32F10X_HD)
#include "stm32f10x.h"
#define FLASH_PAGE_SIZE 2048

#elif defined (STM32F401xx)
#include "stm32f4xx.h"
#define FLASH_PAGE_SIZE 16384

#endif

#if defined (GD32F350) || defined (GD32F130_150)

#define FLASH_Unlock() fmc_unlock()
#define FLASH_Lock() fmc_lock()
#define FLASH_ErasePage(addr) fmc_page_erase(addr)
#define FLASH_ProgramHalfWord(addr, data) fmc_halfword_program(addr, data)
#define FLASH_ProgramWord(addr, data) fmc_word_program(addr, data)
#define FLASH_ClearFlag(flag) fmc_flag_clear(flag)
#define FLASH_FLAG_PGERR FMC_FLAG_PGERR

#define usart_flag_get1(usartx, flag) (USART_REG_VAL(usartx, flag) & BIT(USART_BIT_POS(flag)))
#define usart_flag_clear1(usartx, flag) do{USART_INTC(usartx) |= BIT(USART_BIT_POS(flag));}while(0)
#define USART_FLAG_RXNE USART_FLAG_RBNE
#define USART_FLAG_TXE USART_FLAG_TBE
#define USART_FLAG_ORE USART_FLAG_ORERR
#define USART_FLAG_FE USART_FLAG_FERR


#elif defined (STM32F303xC) || defined (STM32F072) || defined (STM32F030) || defined (STM32F042)

#define usart_flag_get1(usartx, flag) (usartx->ISR & flag)
#define usart_flag_clear1(usartx, flag) do{usartx->ICR = flag;} while(0)

#elif defined (STM32F10X_HD) || defined (STM32F401xx)
#define usart_flag_get1(usartx, flag) (usartx->SR & flag)
#define usart_flag_clear1(usartx, flag) do{usartx->SR = ~flag;} while(0)


#endif

#if defined (STM32F401xx)

void FLASH_ErasePage(unsigned long addr);

#endif
#endif
