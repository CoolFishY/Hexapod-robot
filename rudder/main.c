#include "stm32f10x.h"
#include "usart.h"
#include "tim.h"

uint8_t pData[5] = {0};
uint8_t DataBit;
uint8_t cmd;
uint8_t channel;
uint8_t DataL;
uint8_t DataH;
uint8_t count = 0;

int current_val;//当前值
int dest_val = 1000;//比较值

uint16_t Data;
int flag = 0;
int i = 0;

void mydelay(int x)
{
	int i;
	while(x--)
		for(i=0;i<1000;i++);
}

void Clock_Config(void)
{
	RCC_DeInit();
	RCC_HSEConfig(RCC_HSE_ON);//Configures the External High Speed oscillator (HSE).
	while(SUCCESS != RCC_WaitForHSEStartUp());//Waits for HSE start-up.

	RCC_PLLConfig(RCC_PLLSource_HSE_Div1,RCC_PLLMul_9);// Configures the PLL clock source and multiplication factor.
	RCC_PLLCmd(ENABLE);//Enables or disables the PLL.
	while(RESET == RCC_GetFlagStatus(RCC_FLAG_PLLRDY));//PLL clock ready
	
	RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);//PLL selected as system clock
	RCC_HCLKConfig(RCC_SYSCLK_Div1);//Configures the AHB clock (HCLK).AHB clock = SYSCLK
	RCC_PCLK1Config(RCC_HCLK_Div2);//Configures the Low Speed APB clock (PCLK1).
	RCC_PCLK2Config(RCC_HCLK_Div1);//Configures the High Speed APB clock (PCLK2).
}

void Init_GPIO(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//PA6:TIM3_CH1  PA7:TIM3_CH2
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//PB0:TIM3_CH3  PB1:TIM3_CH4
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	//PB6:TIM4_CH1  PB7:TIM4_CH2 PB8:TIM4_CH3  PB9:TIM4_CH4 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}



void Set_channel_position(uint8_t channel,int data)
{
	int pulse; 
	pulse = data/10;
	printf("set pos:%d\r\n",pulse);
	TIM_SetCompare4(TIM3,pulse);
}

void Do_command(uint8_t* buf)
{
	int channel;
	int Data;
	if((buf[1]!=0x2) || (buf[0]!=0xff) ){
		return ;
	}
	//解析出 通道和 值
	channel = buf[2];
	Data = (buf[4] << 8) + buf[3];
	printf("channel:%d,data:%d\r\n",channel,Data);
	Set_channel_position(channel,Data) ;
}
//串口接收 控制指令
void USART1_IRQHandler(void)
{
	if(USART_GetITStatus(USART1,USART_IT_RXNE) == SET)//接收到一个字节
	{
		//USART_SendByte(USART1,USART_ReceiveData(USART1));

		DataBit = USART_ReceiveData(USART1);
		pData[count++] = DataBit;
	
		#if 0
		if(count==5){
			Do_command(pData);
			count=0;
		}
		#endif
		
		#if 1
		if((pData[0] == 0xff) && (count == 5))
		{
			count = 0;
			cmd = pData[1];							//指令
			channel = pData[2];						//通道
			dest_val = (pData[4] << 8) + pData[3];	//位置值(500-2500)
			printf("channel:%d,dest_val：%d\r\n",channel,dest_val);
		}
	
		#endif 
		
		//USART_ClearITPendingBit(USART1,USART_IT_RXNE);//清中断标志位
		
		
	}
	//else if(USART_GetITStatus(USART1,USART_IT_IDLE) == SET)//接收到一帧数据
	//{
	//	USART_SendByte(USART1,USART_ReceiveData(USART1));
	//}
}

#if 1
//50ms  0.05s
void TIM2_IRQHandler(void)
{
	if(SET == TIM_GetITStatus(TIM2,TIM_IT_Update))
	{
		if(cmd!=0x2){
			return ;
		}
		switch(channel)
		{
			case 4:   
				TIM_SetCompare4(TIM3,dest_val/10);break;
			case 5:
				TIM_SetCompare3(TIM3,dest_val/10);break;
			case 6:
				TIM_SetCompare2(TIM3,dest_val/10);break;
			case 7:
				TIM_SetCompare1(TIM3,dest_val/10);break;
			case 8:
				TIM_SetCompare4(TIM4,dest_val/10);break;
			case 9:
				TIM_SetCompare3(TIM4,dest_val/10);break;
			case 0xa:
				TIM_SetCompare2(TIM4,dest_val/10);break;
			case 0xb:
				TIM_SetCompare1(TIM4,dest_val/10);break;
		 		
			
			default: break;
		}
	}
	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);	//清中断标志
}
#endif 

int main()
{
	RCC_DeInit();
	Clock_Config();
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	
	Init_NVIC_USART();
	Init_NVIC_TIM2();
	Init_GPIO();
	Init_USART_GPIO();
	Init_USART();
	Init_TIM2();
	Init_TIM3();
	Init_TIM4();

	printf("RootArmBottom-driven \r\n");
	printf("\r\n");
	while(1)
	{
		switch(cmd)
		{
			case 0x01://设置舵机速度
				
				break;
			case 0x02://设置舵机位置
				//SetPostion();
				break;
			case 0x09://启动动作组
				break;
			case 0x0b://急停/恢复
				break;
			default:
				break;

		}
	}
}