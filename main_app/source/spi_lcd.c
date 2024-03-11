#include "spi_lcd.h"

char value[8] = { 0 };
uint8_t upperNibble = 0;
uint8_t lowerNibble = 0;
// LCD Commands

void lcd_write_nibble(uint8_t nibble) {
	spi_enable();
	spi_transmit(nibble);

	LATCH_ON;
	delay_ms(1);
	LATCH_OFF;
	delay_ms(1);
	EN_ON;
	delay_ms(1);
	EN_OFF;
	delay_ms(1);
	spi_disable();
}

void lcd_print(uint8_t data) {
	RS_ON;
	upperNibble = data >> 4;
	lowerNibble = data & 15;
	lcd_write_nibble(upperNibble);
	lcd_write_nibble(lowerNibble);

}

void lcd_command(uint8_t data) {
	RS_OFF;
	upperNibble = data >> 4;
	lowerNibble = data & 15;
	lcd_write_nibble(upperNibble);
	lcd_write_nibble(lowerNibble);

}

void lcd_init() {

	delay_ms(15);
	//  lcd_command(0x33); ///careful of this
	//  lcd_command(0x32); ///careful of  this
	lcd_command(0x02);
	lcd_command(0x28);
	lcd_command(0x80);
	lcd_command(0x0C);
	lcd_command(0x01);
}

void lcd_setCursor(unsigned char a, unsigned char b) {

	const unsigned char row[4][20] = { { 0x80, 0x81, 0x82, 0x83, 0x84, 0x85,
			0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90,
			0x91, 0x92, 0x93 }, { 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6,
			0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1,
			0xD2, 0xD3 }, { 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B,
			0x9C, 0x9D, 0x9E, 0x9F, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6,
			0xA7 }, { 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC,
			0xDD, 0xDE, 0xDF, 0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7 } };

	lcd_command(row[a][b]);
}

void lcd_printf(char *str) {

	while (*str) {
		lcd_print(*str);
		str++;

	}

}

void lcd_clear() {
	lcd_command(0x01);
}

//void lcd_printn(double x) {
//    uint8_t a=0;
//    uint8_t b=0;
//    uint8_t c=0;
//    uint8_t d=0;
//    uint16_t e,g,h,p=0;
//    float f=0.00;
//     uint16_t t=0;
//     t=x;
//    a=(t/1000);
//    b=((t/100)%10);
//    c=((t/10)%10);
//    d=(t%10);
//    e=x;
//    f=(x-e);
//    p=(f*100);
//    g=p/10;
//    h=p%10;
//    if(a==0){
//
//    }
//    else{
//        lcd_print(a+0x30);
//    }
//    if((b==0)&& (a==0)){
//
//
//    }
//
//    else{
//        lcd_print(b+0x30);
//    }
//
//    if((b==0)&& (a==0) && (c==0)){
//
//
//    }
//
//    else{
//        lcd_print(c+0x30);
//    }
//    lcd_print(d+0x30);
//    lcd_print('.');
//    lcd_print(g+0x30);
//    lcd_print(h+0x30);
//
//
//}

void lcd_printn(int d_numb) {

	sprintf(value, "%d", d_numb);
	//lcd_clear();
	lcd_printf(value);
}

//void lcd_printnu(float x) {
//
//    sprintf(value, "%.2f", x);
//    lcd_printf(value);
//}
