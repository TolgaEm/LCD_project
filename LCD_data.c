
#include "stm32f4xx.h"   
#include "LCD_Init.h"
#include "LCD_command.h"
#include "LCD_data.h"
#include "delay.h"
#include <stdint.h>

void LCD_data(unsigned char data){
	
	GPIOA->ODR |= 0X01; // RS=1, RW=0, E=0
	GPIOB->ODR = data;
	GPIOA->ODR |= 0X04; // E=1 SECURE COMMAND
	delay();
	GPIOA->ODR = 0X00; // E=0 SECURE COMMAND
	delay();
	
	
}
