

/*
 * uart.c
 *
 *  Created on: 12 Jul 2023
 *      Author: osonoderin
 */


#include "uart.h"
char temp=0;
//char value[10] ={0};
void uart_init(void) {

	AFIO->MAPR |= 1<<2; // remap uart to pb6 for tx pb7 for rx
	RCC->APB2ENR |= 1 << 14;  //  enable usart1 clock
	RCC->APB2ENR |= 1 << 3;  // enable port A since TX = PA9 and RX = PA10
	RCC->APB2ENR |= 1 << 0;


	GPIOB->CRL &= ~(0x0F << 24);   //clearing tx pin to make all zeros
	GPIOB->CRL |= (0x0B << 24); //setting the Tx pin to output, and alternate function push pull 1011
	///GPIOC ->CRH &= ~(0x0F << 20);
	//GPIOC ->CRH |= (3 << 20);
	// setting the rx pin is not necessary, because at reset the pins are set as input  ** TAKE NOTE*
	//GPIOB ->CRL &= ~(0x0F << 28);   //clearing rx pin to make all zeros
	//GPIOB ->CRL |= (1 << 28);    //setting the rx pin to input

	//setting the baudrate in BRR register
	USART1->BRR = 0x1D4C;//0x1D4C; // setting the baudrate to 9600

	// enabling interrupt on uasart1 for tx and rx
	//USART2 -> CR1 |= (0xA0 <<0);
	//USART1->CR1 |= 1 << 5;
	 USART1 ->CR1 |= USART_CR1_RXNEIE;

	// enabling the tx, rx and uart enable7
	USART1->CR1 |= (3 << 2); // enabling tx and rx
	USART1->CR1 |= (1 << 13);   // enabling usart1
	NVIC_EnableIRQ(USART1_IRQn);

}

///////
void USART1_IRQHandler(void) {

	if ( USART1->SR & 0x20)
		temp = (char) USART1->DR;

	if (USART1->SR & 0x80) {

	}

}

void uart_print(uint8_t data) {

	USART1->DR = data;

	while (!(USART1->SR & 0x40))
		;
}

void uart_printf(char *str) {

	while (*str) {
		uart_print(*str);
		str++;

	}

}

void uart_printn(int d_numb) {
char value1[10];
	sprintf(value1, "%d", d_numb);
	//lcd_clear();
	uart_print('\0');
	uart_printf((char*) value1);
}
