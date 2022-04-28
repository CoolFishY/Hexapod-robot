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
	
	//TIM3�Ļ�������
	TIM_BaseInitStructure.TIM_Prescaler = 720;//Ԥ��Ƶ
	TIM_BaseInitStructure.TIM_Period = 2000;//��������
	TIM_BaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;//���ϼ���
	TIM_BaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM3, &TIM_BaseInitStructure);//��ʼ��TIM3
	
	//����TIM3��ͨ��1���PWM����
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;//TIM �����ȵ���ģʽ 1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//Specifies the TIM Output Compare state
	TIM_OCInitStructure.TIM_Pulse = 0;//����װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//TIM ����Ƚϼ��ԣ���  �������ڵ���TIM_Pulse�����ֵ��ʱ�䣬���Ǹߵ�ƽ������ʱ�䶼�ǵͣ�
	
	TIM_OC1Init(TIM3,&TIM_OCInitStructure);//��ʼ��TIM3��Channel1
	TIM_OC2Init(TIM3,&TIM_OCInitStructure);//��ʼ��TIM3��Channel2
	TIM_OC3Init(TIM3,&TIM_OCInitStructure);//��ʼ��TIM3��Channel3
	TIM_OC4Init(TIM3,&TIM_OCInitStructure);//��ʼ��TIM3��Channel4
	
	
	//Enables or disables the TIMx peripheral Preload register on CCRx.
	TIM_OC1PreloadConfig(TIM3,TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM3,TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM3,TIM_OCPreload_Enable);
	
	
	TIM_ARRPreloadConfig(TIM3,ENABLE);//Enables or disables TIMx peripheral Preload register on ARR.
	TIM_CtrlPWMOutputs(TIM3,ENABLE);// Enables or disables the TIM peripheral Main Outputs.
	
	TIM_Cmd(TIM3,ENABLE);//ʹ��TIM3
	
}

void Init_TIM4(void)
{
	TIM_TimeBaseInitTypeDef TIM_BaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	//TIM4�Ļ�������
	TIM_BaseInitStructure.TIM_Prescaler = 720;//Ԥ��Ƶ
	TIM_BaseInitStructure.TIM_Period = 2000;//��������
	TIM_BaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;//���ϼ���
	TIM_BaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	
	TIM_TimeBaseInit(TIM4, &TIM_BaseInitStructure);//��ʼ��TIM4
	
	//����TIM3��ͨ��1���PWM����
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;//TIM �����ȵ���ģʽ 1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//Specifies the TIM Output Compare state
	TIM_OCInitStructure.TIM_Pulse = 0;//����װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//TIM ����Ƚϼ��ԣ���  �������ڵ���TIM_Pulse�����ֵ��ʱ�䣬���Ǹߵ�ƽ������ʱ�䶼�ǵͣ�
	
	TIM_OC1Init(TIM4,&TIM_OCInitStructure);//��ʼ��TIM4��Channel1
	TIM_OC2Init(TIM4,&TIM_OCInitStructure);//��ʼ��TIM4��Channel2
	TIM_OC3Init(TIM4,&TIM_OCInitStructure);//��ʼ��TIM4��Channel3
	TIM_OC4Init(TIM4,&TIM_OCInitStructure);//��ʼ��TIM4��Channel4
	
	TIM_CtrlPWMOutputs(TIM4,ENABLE);// Enables or disables the TIM peripheral Main Outputs.
	
	//Enables or disables the TIMx peripheral Preload register on CCRx.
	TIM_OC1PreloadConfig(TIM4,TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM4,TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM4,TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM4,TIM_OCPreload_Enable);
	
	TIM_ARRPreloadConfig(TIM4,ENABLE);//Enables or disables TIMx peripheral Preload register on ARR.
	
	TIM_Cmd(TIM4,ENABLE);//ʹ��TIM4
}















