#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "EXIT.h"

uint8_t KeyNum;

int main(void)
{
	LED_Init();
	Key_Init();
	EXITaa_Init();
	
	while (1)
	{ KeyNum = Key_GetNum();
		
			GPIO_ResetBits(GPIOA, GPIO_Pin_12);
			Delay_ms(1000);
			GPIO_SetBits(GPIOA, GPIO_Pin_12);
			Delay_ms(1000);
			
		}
}

void EXTI15_10_IRQHandler(void)
{
	if (EXTI_GetITStatus(EXTI_Line14) == SET)		//判断是否是外部中断14号线触发的中断
	{
		/*如果出现数据乱跳的现象，可再次判断引脚电平，以避免抖动*/
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0)
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0)
			{Delay_ms(100);
			LED1_Turn();}				
		else	
			while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 1){GPIO_ResetBits(GPIOA, GPIO_Pin_12);
			Delay_ms(1000);
			GPIO_SetBits(GPIOA, GPIO_Pin_12);
			Delay_ms(1000);}
		
		//EXTI_ClearITPendingBit(EXTI_Line14);		//清除外部中断14号线的中断标志位
	//												中断标志位必须清除
//													否则中断将连续不断地触发，导致主程序卡死
	}
}
