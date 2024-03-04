#include "uart_receive.h"
#include "stm32f1xx_it.h"
#include <usart.h>
#include <string.h>
extern uint8_t data[rx_len];
extern UART_HandleTypeDef huar1;
#define SIZE 100
#define END '\n'
uint8_t data[SIZE];
uint16_t index = 0; 
uint8_t data[]="tset12345 \n";
void HAL_UART_RxCpltCallback (UART_HandleTypeDef *huart)
{ uint8_t data[]="tset12345 \n";
	if(huart->Instance==USART1)
	{  if (index < rx_len -1)
		{if(data[rx_len-1]!=END)
		{data[rx_len++]=(uint8_t)(huart->Instance-->DR & 0x00FF);}
		 if(data[rx_len-1]!=END)
		 {
		 index = 0;
		}
		}
		else {index = 0;
		memset(data,0,rx_len);}
		 HAL_UART_Receive_IT(&huart1,data,rx_len);
	}		
}