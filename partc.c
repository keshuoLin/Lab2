#include <avr/io.h>
#include <avr/interrupt.h>


void initialize(){
	cli();					//Disable all global interrupts
	DDRB &=~(1<<DDB0);		//Set PB0 as an input pin
	DDRB |=(1<<DDB5);		//Set PB5 as an output pin
	PORTB |= (1<<PORTB0);   //Enable pull up resistor on PB0
	
	//Enable Timer1
	TCCR1A &=~(<<WGM10);
	TCCR1A &=~(<<WGM11);
	TCCR1B &=~(<<WGM12);	
	TCCR1B &=~(<<WGM13);	
	
	//Write a logic one to ICF1 to clear it
	TIFR1 |= (1<<ICF1);
	
	//Looking for a falling edge
	TCCR1B &= ~(1<<ICES1);
	
	//Enable Timer/Counter1 input capture interrupt
	TIMSK1 |= (1<<ICIE1);

	sei();	//Enable global interrupts
}

ISR(TIMER1_CAPT_vect){
	PORTB^=(1<<PORTB5);
	TCCR1B^=(1<<ICES1);
}

int main(void)
{
	initialize();

	while(1)
	{
	}
}