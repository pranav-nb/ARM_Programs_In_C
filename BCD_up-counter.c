/* C Program for BCD up-counter on Port0 using FIOPIN registers from 00 to 99*/

#include <stdio.h>
#include "lpc17xx.h"

uint32_t a,b;
void delay(uint32_t);

int main(void)
{
	LPC_GPIO0->FIODIR = 0x000000ff; 		//LEDs on PORT0 are set as output
	for(a=0;a<100;a++)
	{
		b=(((a/10)<<4)|(a%10));  		// Hexadecimal is converted to Decimal
		LPC_GPIO0->FIOPIN=b;
		delay(300000);
	}
	while(1);
}

void delay(uint32_t i)
{
	uint32_t x;
	for(x=0;x<=i;x++)
}
