/**
 * 	PWC - A module used to control power source drivers.
 *
 *	Author: Felipe Fraporti - ffraporti@gmail.com
 *	Collaborators: Breno Cardoso - brenocastrocardoso@gmail.com
 */

#include "includes/defines.h"

ISR(TIMER2_OVF_vect)
{

	//put_to_sleep();
	//sleep_disable();
	sleep_disable();

	bit_set(PORTC, PC5);

	reg_clear(TCNT2);



	put_to_sleep();

	//interrupt flag is cleared by hardware

}

int main() {

	/* Setting PC5 as output */
	bit_set(DDRC, DDC5);

	bit_clear(PORTC, PC5);
	_delay_ms(200);

	/*
	 * The clock source for Timer/Counter2 is named clk T2S . clk T2S is by default connected to the main
	   system I/O clock clk I/O . By setting the AS2 bit in ASSR, Timer/Counter2 is asynchronously
	   clocked from the TOSC1 pin. This enables use of Timer/Counter2 as a Real Time Counter
	   (RTC). When AS2 is set, pins TOSC1 and TOSC2 are disconnected from Port B. A crystal can
	   then be connected between the TOSC1 and TOSC2 pins to serve as an independent clock
	   source for Timer/Counter2. The Oscillator is optimized for use with a 32.768kHz crystal. Apply-
	   ing an external clock source to TOSC1 is not recommended.
	*/
	bit_set(ASSR,AS2);

	/*
	 * When the OCIE2 bit is written to one and the I-bit in the Status Register is set (one), the
	   Timer/Counter2 Compare Match interrupt is enabled.
	 * When the TOIE2 bit is written to one and the I-bit in the Status Register is set (one), the
	   Timer/Counter2 Overflow interrupt is enabled.
	*/
	bit_clear(TIMSK, OCIE2);

	/* enable overflow interrupt for timer 2 */
	bit_set(TIMSK, TOIE2);

	/*
	 * The TOV2 bit is set (one) when an overflow occurs in Timer/Counter2. TOV2 is cleared by hard-
	   ware when executing the corresponding interrupt Handling Vector. Alternatively, TOV2 is
	   cleared by writing a logic one to the flag. When the SREG I-bit, TOIE2 (Timer/Counter2 Overflow
	   Interrupt Enable), and TOV2 are set (one), the Timer/Counter2 Overflow interrupt is executed. In
	   PWM mode, this bit is set when Timer/Counter2 changes counting direction at 0x00.
	 */
	bit_set(TIFR, TOV2);

	/* clear counter */
	reg_clear(TCNT2);

	/* The three clock select bits select the clock source to be used by the Timer/Counter
	 *
	 * CS22 CS21 CS20
	 * 0    0    0		-> no clock source
	 * 0    0    1		-> CLKt2, no prescaler
	 * 0    1    0		-> CLKt2/8
	 * 0    1    1		-> CLKt2/32
	 * 1    0    0		-> CLKt2/64
	 * 1    0    1		-> CLKt2/128
	 * 1    1    0		-> CLKt2/256
	 * 1    1    1		-> CLKt2/1024
	 *
	*/
	bit_clear(TCCR2, CS22);
	bit_clear(TCCR2, CS21);
	bit_set(TCCR2, CS20);

	/* enable interrupt */
	sei();

	config_power_saving();

	while(1) {




		//config_standby();

	}

	return 1;
}
