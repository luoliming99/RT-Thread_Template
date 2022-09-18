#ifndef __BSP_UART_H
#define __BSP_UART_H

#include "ch32f20x.h"
#include <stdio.h>

// 串口3-USART3
#define  DEBUG_USART                    USART3
#define  DEBUG_USART_CLK                RCC_APB1Periph_USART3
#define  DEBUG_USART_APBxClkCmd         RCC_APB1PeriphClockCmd
#define  DEBUG_USART_BAUDRATE           500000

// USART GPIO 引脚宏定义
#define  DEBUG_USART_GPIO_CLK           RCC_APB2Periph_GPIOB
#define  DEBUG_USART_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  DEBUG_USART_TX_GPIO_PORT       GPIOB   
#define  DEBUG_USART_TX_GPIO_PIN        GPIO_Pin_10
#define  DEBUG_USART_RX_GPIO_PORT       GPIOB
#define  DEBUG_USART_RX_GPIO_PIN        GPIO_Pin_11

#define  DEBUG_USART_IRQ                USART3_IRQn
#define  DEBUG_USART_IRQHandler         USART3_IRQHandler

void uart_init(void);
void uart_send_one_byte(USART_TypeDef *pUSARTx, uint8_t ch);
void uart_send_string(USART_TypeDef *pUSARTx, char *str);
void uart_send_data_buf(USART_TypeDef *pUSARTx, uint8_t *pBuf, uint32_t len);

#endif
