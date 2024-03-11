/*
 * uart.h
 *
 *  Created on: 12 Jul 2023
 *      Author: osonoderin
 */

#ifndef SPI_H_
#define SPI_H_
#include "main.h"
#include <stdint.h>
#include <stdio.h>
void spi_init(void);
//void USART1_IRQHandler(void);
void spi_transmit(uint8_t data);
void spi_enable();
void spi_disable();
extern char temp;
//extern char value[10];

#endif /* UART_H_ */
