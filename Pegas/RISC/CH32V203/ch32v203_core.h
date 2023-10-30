#ifndef __ch32v203_pegas__
#define __ch32v203_pegas__	1

#include <ch32v20x_gpio.h>
#include <ch32v20x_rcc.h>
#include <ch32v20x_tim.h>

class device_cpu
{
public:
	void init();
	void Peripheral_APB1_Config(uint32_t RCC_APB1Periph, FunctionalState NewState);
	void Peripheral_APB2_Config(uint32_t RCC_APB1Periph, FunctionalState NewState);
	void Peripheral_APB2_Reset(uint32_t RCC_APB1Periph, FunctionalState NewState);
	void Peripheral_APB1_Reset(uint32_t RCC_APB1Periph, FunctionalState NewState);
	unsigned int GetClockFreq();
	void Timer_SetEncoderMode(TIM_TypeDef *TIMx);
	void Timer_SetPWMMode(TIM_TypeDef *TIMx,unsigned int prescaler,unsigned int channel,unsigned int pulse);
	void Timer_Enable(TIM_TypeDef *TIMx, FunctionalState NewState);
	int Timer_GetCounter(TIM_TypeDef *TIMx);
	void Timer_PWM_Set_Value(TIM_TypeDef *TIMx, unsigned int channel,unsigned int value);
	void Timer_PWM_Set_Pulse(TIM_TypeDef *TIMx, unsigned int value);

};



#endif
