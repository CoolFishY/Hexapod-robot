#include "stm32f10x.h"
#include "usart.h"

int fputc(int ch, FILE *fp)
{
	USART_SendData(USART1, ch);
	
	while(RESET == USART_GetFlagStatus(USART1,USART_FLAG_TXE));
	
	return ch;
}

void Init_NVIC_USART(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&NVIC_InitStructure);

}

#if 0
void USART1_IRQHandler(void)
{
	if(USART_GetITStatus(USART1,USART_IT_RXNE) == SET)
	{
		USART_SendByte(USART1,USART_ReceiveData(USART1));
	}
	USART_ClearITPendingBit(USART1,USART_IT_RXNE);//清中断标志位
}
#endif

void Init_USART_GPIO(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//PA9 Init
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//PA10 Init
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void Init_USART(void)
{
	USART_InitTypeDef USART_InitStructure;
		
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	
	USART_Init(USART1, &USART_InitStructure);
	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//串口中断配置
	//USART_ITConfig(USART1, USART_IT_TXE, ENABLE); 
	
	USART_Cmd(USART1,ENABLE);
}

void USART_SendByte(USART_TypeDef* USARTx,char ch)
{
	USART_SendData(USARTx,ch);

	while(RESET == USART_GetFlagStatus(USARTx,USART_FLAG_TC));
}

void USART_SendString(USART_TypeDef* USARTx, char *string)
{
	while(*string)
		USART_SendByte(USARTx,*string++);
	return;
}

char USART_RecvByte(USART_TypeDef * USARTx)
{
	char ch;
	while(RESET == USART_GetFlagStatus(USART1,USART_FLAG_RXNE));
	
	ch = USART_ReceiveData(USART1);
	
	return ch;
}

