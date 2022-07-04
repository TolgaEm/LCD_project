
#include "stm32f4xx.h"   
#include "LCD_Init.h"
#include "LCD_command.h"
#include "LCD_data.h"
#include "delay.h"

int main() {
	
	LCD_Init();
	LCD_command(0X01);
	LCD_command(0X08);
	delay();
	LCD_data('T');
	delay();
	LCD_data('O');
	delay();
	LCD_data('L');
	delay();
	LCD_data('G');
	delay();
	LCD_data('A');
	delay();
}
