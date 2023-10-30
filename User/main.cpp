/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2021/06/06
 * Description        : Main program body.
*********************************************************************************
* Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
* Attention: This software (modified or not) and binary are used for 
* microcontroller manufactured by Nanjing Qinheng Microelectronics.
*******************************************************************************/

/*
 *@Note
 USART Print debugging routine:
 USART1_Tx(PA9).
 This example demonstrates using USART1(PA9) as a print debug port output.

TIM1 - encoder 1, pins PA8,PA9, ch1, ch2
TIM2 - encoder 2, pins PA15,PB3, ch1, ch2

TIM3 - PWM 1 - CH1, PWM2 - CH2

*/

#include "debug.h"

#include "ch32v203_core.h"


/* Global typedef */

/* Global define */

void GPIO_Init();

/* Global Variable */
device_cpu	__cpu;

unsigned int position[2]={1,1};
unsigned int position_last[2]={0,0};

int delta[2]={0,0};

int PWM_Level[2]={-205,-205};

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    __cpu.init();

    __cpu.Peripheral_APB2_Config(RCC_APB2Periph_TIM1,ENABLE);
    __cpu.Peripheral_APB2_Config(RCC_APB2Periph_GPIOA,ENABLE);
    __cpu.Peripheral_APB2_Config(RCC_APB2Periph_GPIOB,ENABLE);
    __cpu.Peripheral_APB1_Config(RCC_APB1Periph_TIM3,ENABLE);
    __cpu.Peripheral_APB1_Config(RCC_APB1Periph_TIM2,ENABLE);

    GPIO_Init();

    __cpu.Timer_SetEncoderMode(TIM1);
    __cpu.Timer_SetEncoderMode(TIM2);

    __cpu.Timer_SetPWMMode(TIM3,6,0,720);
    __cpu.Timer_SetPWMMode(TIM3,6,1,720);

    __cpu.Timer_Enable(TIM1,ENABLE);
    __cpu.Timer_Enable(TIM2,ENABLE);
    __cpu.Timer_Enable(TIM3,ENABLE);



    Delay_Init();

    __cpu.Timer_PWM_Set_Value(TIM3,0,PWM_Level[1]+360);
    __cpu.Timer_PWM_Set_Value(TIM3,1,PWM_Level[0]+360);

    while(1)
    {
    	position[0]=__cpu.Timer_GetCounter(TIM1);
    	position[1]=__cpu.Timer_GetCounter(TIM2);


    	for(int i=0;i<2;i++)
    	{
    		if(position_last[0]!=position[0])
    		{
				if(position_last[0]>position[0])
				{
					if(position_last[0]-position[0]>30000)
					{
						delta[i]=65535+position[0]-position_last[0];
					}
					else
					{
						delta[i]=-(position_last[0]-position[0]);
					}
				}
				else
				{
					if(position[0]-position_last[0]>50000)
					{
						delta[i]=-(65536+position_last[0]-position[0]);
					}
					else
					{
						delta[i]=(position[0]-position_last[0]);
					}
				}

				position_last[i]=position[i];

				PWM_Level[i]=PWM_Level[i]+delta[i];

				if(PWM_Level[i]>-53)
				{
					PWM_Level[i]=-53;
				}

				if(PWM_Level[i]<-360)
				{
					PWM_Level[i]=-360;
				}

				__cpu.Timer_PWM_Set_Value(TIM3,0,PWM_Level[1]+360);
				__cpu.Timer_PWM_Set_Value(TIM3,1,PWM_Level[0]+360);
			}
    	}
    }
}


void GPIO_Init()
{
	GPIO_InitTypeDef __temp;

	__temp.GPIO_Mode=GPIO_Mode_AF_PP;
	__temp.GPIO_Speed=GPIO_Speed_50MHz;

	__temp.GPIO_Pin=GPIO_Pin_8;
	GPIO_Init(GPIOA,&__temp);

	__temp.GPIO_Pin=GPIO_Pin_9;
	GPIO_Init(GPIOA,&__temp);

	__temp.GPIO_Pin=GPIO_Pin_15;
	GPIO_Init(GPIOA,&__temp);

	__temp.GPIO_Pin=GPIO_Pin_3;
	GPIO_Init(GPIOB,&__temp);


	__temp.GPIO_Mode=GPIO_Mode_AF_PP;
	__temp.GPIO_Pin=GPIO_Pin_6;
	GPIO_Init(GPIOA,&__temp);

	__temp.GPIO_Pin=GPIO_Pin_7;
	GPIO_Init(GPIOA,&__temp);


}
