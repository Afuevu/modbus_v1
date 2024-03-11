/*
 * uart.h
 *
 *  Created on: 12 Jul 2023
 *      Author: osonoderin
 */

#ifndef UART_H_
#define UART_H_
#include "main.h"
#include <stdint.h>
#include <stdio.h>
void uart_init(void);
void USART1_IRQHandler(void);
void uart_print(uint8_t data);
void uart_printn(int d_numb);
void uart_printf(char *str);
extern char temp;
//extern char value[10];

#endif /* UART_H_ */
