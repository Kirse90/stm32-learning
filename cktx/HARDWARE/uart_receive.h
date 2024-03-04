#ifndef __UART_RECEIVE_H
#define __UART_RECEIVE_H
#include "main.h"
void HAL_UART_RxCpltCallback (UART_HandleTypeDef *huart);
#define rx_len 4
#endif
