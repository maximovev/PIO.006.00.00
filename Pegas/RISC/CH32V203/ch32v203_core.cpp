#include "ch32v203_core.h"

void device_cpu::init()
{
	RCC_HSEConfig(RCC_HSE_ON);
	RCC_WaitForHSEStartUp();
	RCC_PLLConfig(RCC_PLLSource_HSE_Div1,RCC_PLLMul_9);
	RCC_PLLCmd(ENABLE);
	RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
	RCC_HCLKConfig(RCC_SYSCLK_Div2);
	RCC_PCLK1Config(RCC_HCLK_Div1);
	RCC_PCLK2Config(RCC_HCLK_Div1);
	RCC_ADCCLKConfig(RCC_PCLK2_Div4);
	RCC_MCOConfig(RCC_MCO_NoClock);


}

void device_cpu::Peripheral_APB1_Config(uint32_t RCC_APB1Periph, FunctionalState NewState)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph,NewState);
}

void device_cpu::Peripheral_APB2_Config(uint32_t RCC_APB1Periph, FunctionalState NewState)
{
	RCC_APB2PeriphClockCmd(RCC_APB1Periph,NewState);
}

void device_cpu::Peripheral_APB2_Reset(uint32_t RCC_APB1Periph, FunctionalState NewState)
{
	RCC_APB2PeriphResetCmd(RCC_APB1Periph, NewState);
}

void device_cpu::Peripheral_APB1_Reset(uint32_t RCC_APB1Periph, FunctionalState NewState)
{
	RCC_APB1PeriphResetCmd(RCC_APB1Periph, NewState);
}

unsigned int device_cpu::GetClockFreq()
{
	// hardware cpu clock, setup at init
	return 72000000;
}

void device_cpu::Timer_SetEncoderMode(TIM_TypeDef *TIMx)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure = { 0 };

	TIM_TimeBaseInitStructure.TIM_Period = 65535;
	TIM_TimeBaseInitStructure.TIM_Prescaler = 3;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIMx, &TIM_TimeBaseInitStructure);
	TIM_EncoderInterfaceConfig(TIMx,TIM_EncoderMode_TI1,TIM_ICPolarity_Rising,TIM_ICPolarity_Rising);
}

void device_cpu::Timer_SetPWMMode(TIM_TypeDef *TIMx,unsigned int prescaler,unsigned int channel,unsigned int pulse)
{
	TIM_OCInitTypeDef pwm;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure = { 0 };

	TIM_TimeBaseInitStructure.TIM_Period = 360;
	TIM_TimeBaseInitStructure.TIM_Prescaler = prescaler;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit( TIMx, &TIM_TimeBaseInitStructure);

	pwm.TIM_OCMode=TIM_OCMode_PWM1;
	pwm.TIM_Pulse=pulse;
	pwm.TIM_OCPolarity=TIM_OCPolarity_High;
	pwm.TIM_OutputState=TIM_OutputState_Enable;

	switch(channel)
	{
		case 0:
		{
			TIM_OC1Init(TIMx,&pwm);
		}break;
		case 1:
		{
			TIM_OC2Init(TIMx,&pwm);
		}break;
		case 2:
		{
			TIM_OC3Init(TIMx,&pwm);
		}break;
		case 3:
		{
			TIM_OC4Init(TIMx,&pwm);
		}break;
	}

	TIM_CtrlPWMOutputs(TIMx,ENABLE);
	TIM_OC4PreloadConfig(TIMx, TIM_OCPreload_Disable);
	TIM_ARRPreloadConfig(TIMx, ENABLE);
	TIM_Cmd( TIMx, ENABLE);
}

void device_cpu::Timer_PWM_Set_Pulse(TIM_TypeDef *TIMx,unsigned int value)
{

}

void device_cpu::Timer_PWM_Set_Value(TIM_TypeDef *TIMx, unsigned int channel,unsigned int value)
{
	switch(channel)
	{
		case 0:
		{
			TIMx->CH1CVR=value;
		}break;
		case 1:
		{
			TIMx->CH2CVR=value;
		}break;
		case 2:
		{
			TIMx->CH3CVR=value;
		}break;
		case 3:
		{
			TIMx->CH4CVR=value;
		}break;
	}

}

void device_cpu::Timer_Enable(TIM_TypeDef *TIMx, FunctionalState NewState)
{
	TIM_Cmd(TIMx,NewState);
}

int device_cpu::Timer_GetCounter(TIM_TypeDef *TIMx)
{
	return TIMx->CNT;
}
