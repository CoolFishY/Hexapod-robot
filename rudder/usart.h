#ifndef USART_H
#define USART_H

#include "stm32f10x.h"
#include <stdio.h>

void Init_USART_GPIO(void);
void Init_USART(void);
int fputc(int ch, FILE *fp);

void Init_NVIC_USART(void);
void USART_SendByte(USART_TypeDef* USARTx,char ch);
void USART_SendString(USART_TypeDef* USARTx, char *string);
char USART_RecvByte(USART_TypeDef * USARTx);


#endif
