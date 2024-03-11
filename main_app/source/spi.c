#include "spi.h"

void spi_init() {
	RCC->APB2ENR |= (1 << 12);
	RCC->APB2ENR |= 1 << 2;
	SPI1->CR1 |= (1 << 0);
	SPI1->CR1 |= (1 << 1);
	SPI1->CR1 |= (1 << 2);
	SPI1->CR1 |= (3 << 3);
	SPI1->CR1 &= ~(1 << 7);
	SPI1->CR1 |= (1 << 9);
	SPI1->CR1 |= (1 << 8);
	SPI1->CR1 &= ~(1 << 10);
	SPI1->CR1 &= ~(1 << 11);

	GPIOA->CRL &= ~(0x0F << 20);
	GPIOA->CRL |= (0x0B << 20);

	GPIOA->CRL &= ~(0x0F << 28);
	GPIOA->CRL |= (0x0B << 28);

	GPIOA->CRL &= ~(0x0F << 24);
	GPIOA->CRL |= (1 << 26);

	GPIOA->CRL &= ~(0x0F << 16);
	GPIOA->CRL |= (0x03 << 16);

}

void spi_enable() {
	SPI1->CR1 |= (1 << 6);
}

void spi_disable() {
	SPI1->CR1 &= ~(1 << 6);
}

void spi_transmit(uint8_t data) {
	while (!((SPI1->SR) & (0x02)))
		;

	SPI1->DR = data;
	while (((SPI1->SR) & (1 << 7)))
		;

	uint8_t temp1 = 0;
	temp1 = SPI1->DR;
	temp1 = SPI1->SR;
}
