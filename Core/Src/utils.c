/*
 * utils.c
 *
 *  Created on: 18 lis 2022
 *      Author: gerwant22
 */
#include "main.h"
#include "string.h"
#include "usart.h"

void UartLog(char *Message)
{
  HAL_UART_Transmit(&huart2, (uint8_t *)Message, strlen(Message), 10);
}