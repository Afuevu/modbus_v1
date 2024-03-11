#ifndef SPI_LCD_H_
#define SPI_LCD_H_
#include "main.h"
#include <stdint.h>
#include <stdio.h>
#include "spi.h"
#define EN_ON GPIOB->ODR |= (1 << 7)
#define EN_OFF GPIOB->ODR &= ~(1 << 7)
#define RS_OFF GPIOB->ODR &= ~(1 << 6)
#define RS_ON GPIOB->ODR |= (1 << 6)
#define LATCH_OFF GPIOB->ODR &= ~(1 << 5)
#define LATCH_ON GPIOB->ODR |= (1 << 5)
extern uint8_t  upperNibble;
extern uint8_t  lowerNibble;
extern char value[8];
void lcd_write_nibble(uint8_t nibble);
void lcd_print(uint8_t data);
void lcd_command(uint8_t data);
void lcd_init();
void lcd_setCursor(unsigned char a, unsigned char b);
void lcd_printf(char *str);
void lcd_clear();
#endif /* UART_H_ */
