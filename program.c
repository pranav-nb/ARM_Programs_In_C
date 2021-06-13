/* C Program to blink LEDs on Port0 using FIOPIN registers based on status of switch*/

#include <stdio.h>
#include "lpc17xx.h"

uint32_t x;
void delay(uint32_t);

int main(void)
{
	LPC_GPIO0->FIODIR = 0x80000001;
	LPC_GPIO1->FIODIR = 0xfffffffe;
	while(1)
	{
		x=LPC_GPIO1->FIOPIN;
		if(x==0)     		// if switch is open, P0.0 LED is blinked
		{
			LPC_GPIO0->FIOPIN^=1<<0;
			LPC_GPIO0->FIOPIN |=1<<31;
			delay(3000000);
		}
		else			// if switch is open, P0.31 LED is blinked
		{
			LPC_GPIO0->FIOPIN^=1<<31;
			LPC_GPIO0->FIOPIN |=1<<0;
			delay(3000000);
		}
	}
}

void delay(uint32_t i)
{
	uint32_t x;
	for(x=0;x<=i;x++)
}
