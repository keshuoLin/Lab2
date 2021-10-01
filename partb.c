#include <avr/io.h>

void initialize(){
	DDRB &=~(1<<DDB0);	//Set PB0 as an input pin
	DDRB |=(1<<DDB5);	//Set PB5 as an output pin
}

int main(void)
{	
	initialize();

	while(1)
	{
		if (PINB & (1<<PINB0)) //If PB0 is high, drive PB5 low
			PORTB &= ~(1<<PORTB5);
		else  //If PB0 is low, drive PB5 high
			PORTB |= (1<<PORTB5);
	}
}

