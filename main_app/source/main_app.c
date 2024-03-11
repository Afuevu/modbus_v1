#include "main_app.h"
#include "timer4.h"
#include "uart.h"
#include "spi.h"
#include "spi_lcd.h"
int main_app(void) {

	RCC->APB2ENR |= 1 << 3;
	GPIOB->CRL &= ~(0x0F << 20); // pb5
	GPIOB->CRL |= (0x03 << 20);

	GPIOB->CRL &= ~(0x0F << 24); // pb6
	GPIOB->CRL |= (0x03 << 24);

	GPIOB->CRL &= ~(0x0F << 28); // pb7
	GPIOB->CRL |= (0x03 << 28);

	timer4_Init();
	//uart_init();
	spi_init();

	lcd_init();
	RCC->APB2ENR |= 1 << 4;
	GPIOC->CRH &= ~(0x0F << 20); // PC13
	GPIOC->CRH |= (0x03 << 20);
	GPIOC->ODR |= (1 << 13);
	delay_ms(1000);

	lcd_setCursor(0, 0);
	delay_ms(10);
	//lcd_print('A');
	delay_ms(10);
	while (1) {
		//GPIOC->ODR |= (1 << 13);
		//delay_ms(1000);
		//GPIOC->ODR &= ~(1 << 13);
		//delay_ms(1000);
		for (int i = 0; i < 100; i++) {
			lcd_setCursor(0, 0);
			delay_ms(5);
			lcd_printn(i);
			delay_ms(95);
			GPIOC->ODR ^= (1 << 13);
		}
		//	GPIOC->ODR ^= (1 << 13);
		//delay_ms(900);
//		uart_print('A');
//		delay_ms(500);
//
//		if (temp == 'A') {
//			GPIOC->ODR &= ~(1 << 13);
//			temp = 0;
//		}
//
//		uart_print('B');
//		delay_ms(500);
//
//		if (temp == 'B') {
//			GPIOC->ODR |= (1 << 13);
//			temp = 0;
//		}

//		if (temp == 'A') {
//			GPIOC->ODR &= ~(1 << 13);
//			//delay_ms(500);
//			uart_print(temp);
//			temp = 0;
//		}
//
//		if (temp == 'B') {
//			GPIOC->ODR |= (1 << 13);
//			//delay_ms(500);
//			uart_print(temp);
//			temp = 0;
//		}

	}

}
