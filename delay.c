
#include <stdint.h>
#include "delay.h"

uint16_t counter = 100000;


void delay(void){
	while(counter--);
}
