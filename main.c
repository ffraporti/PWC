/**
 * 	PWC - A module used to control power source drivers.
 *
 *	Author: Felipe Fraporti - ffraporti@gmail.com
 *	Collaborators: Breno Cardoso - brenocastrocardoso@gmail.com
 */

#include "includes/defines.h"

void bit_clear(int byte, int offset) {
	byte &= ~(1 << offset);
}

void bit_set(int byte, int offset) {
	byte |= (1 << offset);
}

uint8_t bit_read(int byte, int offset) {
	return (byte & (1 << offset)) == (1 << offset);
}

ISR(TIMER2_OVF_vect)
{
	if (bit_read(PORTB, 1)) {
		bit_set(PORTB, 0);
		bit_clear(PORTB, 1);
	} else if(bit_read(PORTB, 0)) {
		bit_set(PORTB, 1);
		bit_clear(PORTB, 0);
	}
}

int main() {

	//init_T2
	bit_set(ASSR,AS2); // Enable asynchronous mode
	bit_set(TIMSK,TOIE2); //Timer/Counter2 Overflow Interrupt Enable
	bit_set(TIFR,TOV2); //Clear TOV2
	TCNT2=0; //Init Timer Count 2
	TCCR2 = ((1<<CS22)|(1<<CS21)|(1<<CS20)); // Timer Clock = system clock / 1024
	sei(); //enable_interrupts() <=> bit_set(SREG,7);

	config_idle();

	DDRC = 0x20;

	uint8_t is_on = 0;

	bit_set(DDRB, 0); //Pin PB0 is an output
	bit_clear(PORTB, 0);
	bit_set(DDRB, 1); //Pin PB0 is an output
	bit_clear(PORTB, 1);
	bit_set(PORTB, 1);

	while(1) {

		put_to_sleep();
		sleep_disable();

		if(!is_on) {
			PORTC |= 0x20; //turning it on
			is_on = 1;
		} else {
			PORTC &= 0x5F; //turning it off
			is_on = 0;
		}
	}

	return 1;
}
