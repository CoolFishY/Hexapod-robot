#include "stm32f10x.h"

#include "tim.h"

void Init_NVIC_TIM2(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn ;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&NVIC_InitStructure);

}

void Init_TIM2(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_Prescaler = 720;
	TIM_TimeBaseInitStructure.TIM_Period = 1000;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	TIM_Cmd(TIM2,ENABLE);
}


void Init_TIM3(void)
{
	TIM_TimeBaseInitTypeDef TIM_BaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	//TIM3的基本配置
	TIM_BaseInitStructure.TIM_Prescaler = 720;//预分频
	TIM_BaseInitStructure.TIM_Period = 2000;//计数周期
	TIM_BaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;//向上计数
	TIM_BaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM3, &TIM_BaseInitStructure);//初始化TIM3
	
	//配置TIM3的通道1输出PWM脉冲
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;//TIM 脉冲宽度调制模式 1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//Specifies the TIM Output Compare state
	TIM_OCInitStructure.TIM_Pulse = 0;//设置装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//TIM 输出比较极性：高  即周期内低于TIM_Pulse这个阈值的时间，都是高电平，其他时间都是低；
	
	TIM_OC1Init(TIM3,&TIM_OCInitStructure);//初始化TIM3的Channel1
	TIM_OC2Init(TIM3,&TIM_OCInitStructure);//初始化TIM3的Channel2
	TIM_OC3Init(TIM3,&TIM_OCInitStructure);//初始化TIM3的Channel3
	TIM_OC4Init(TIM3,&TIM_OCInitStructure);//初始化TIM3的Channel4
	
	
	//Enables or disables the TIMx peripheral Preload register on CCRx.
	TIM_OC1PreloadConfig(TIM3,TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM3,TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM3,TIM_OCPreload_Enable);
	
	
	TIM_ARRPreloadConfig(TIM3,ENABLE);//Enables or disables TIMx peripheral Preload register on ARR.
	TIM_CtrlPWMOutputs(TIM3,ENABLE);// Enables or disables the TIM peripheral Main Outputs.
	
	TIM_Cmd(TIM3,ENABLE);//使能TIM3
	
}

void Init_TIM4(void)
{
	TIM_TimeBaseInitTypeDef TIM_BaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	//TIM4的基本配置
	TIM_BaseInitStructure.TIM_Prescaler = 720;//预分频
	TIM_BaseInitStructure.TIM_Period = 2000;//计数周期
	TIM_BaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;//向上计数
	TIM_BaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	
	TIM_TimeBaseInit(TIM4, &TIM_BaseInitStructure);//初始化TIM4
	
	//配置TIM3的通道1输出PWM脉冲
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;//TIM 脉冲宽度调制模式 1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//Specifies the TIM Output Compare state
	TIM_OCInitStructure.TIM_Pulse = 0;//设置装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//TIM 输出比较极性：高  即周期内低于TIM_Pulse这个阈值的时间，都是高电平，其他时间都是低；
	
	TIM_OC1Init(TIM4,&TIM_OCInitStructure);//初始化TIM4的Channel1
	TIM_OC2Init(TIM4,&TIM_OCInitStructure);//初始化TIM4的Channel2
	TIM_OC3Init(TIM4,&TIM_OCInitStructure);//初始化TIM4的Channel3
	TIM_OC4Init(TIM4,&TIM_OCInitStructure);//初始化TIM4的Channel4
	
	TIM_CtrlPWMOutputs(TIM4,ENABLE);// Enables or disables the TIM peripheral Main Outputs.
	
	//Enables or disables the TIMx peripheral Preload register on CCRx.
	TIM_OC1PreloadConfig(TIM4,TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM4,TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM4,TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM4,TIM_OCPreload_Enable);
	
	TIM_ARRPreloadConfig(TIM4,ENABLE);//Enables or disables TIMx peripheral Preload register on ARR.
	
	TIM_Cmd(TIM4,ENABLE);//使能TIM4
}















