
#include "stm32f4xx.h"   
#include "LCD_Init.h"
#include "LCD_command.h"
#include "LCD_data.h"               

void LCD_Init(void){
		
	 RCC->AHB1ENR |= 0X03; // PORTA, PORTB CLOCK ENABLE
	 RCC->CR |= (1<<0 | 1<<19); // CSS AND HSI ENABLE
	 while(!(RCC->CR & 0X02)); //HSI IS READY
	 RCC->CIR |= (1<<10 | 1<<23); // CSS ON AND HSI FLAG CLEAR
	
	 GPIOA->MODER |= 0X07; // PORTA SET CONTROL OUTPUT (RS,RW,E)
	 GPIOA->OTYPER |= 0X00; 
	 GPIOA->PUPDR |= 0X00;
	 GPIOA->OSPEEDR |= 0X07;
	
	 GPIOB->MODER |= 0X55; // PORTB SET ALL OUTPUT
	 GPIOB->OTYPER |= 0X00; 
	 GPIOB->PUPDR |= 0X00;
	 GPIOB->OSPEEDR |= 0XFF;
	
	 LCD_command(0X38); // 8-BITS, 2 LINE DISPLAY, 5X7 FONT
	 LCD_command(0X06); // INCREMENT AUTOMATICALLY
	 LCD_command(0X0F); // TURN ON DISPLAY
	 LCD_command(0X01); // CLEAR DISPLAY
	
}
