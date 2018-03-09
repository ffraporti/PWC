/**
 * 	PWC - A module used to control power source drivers.
 *
 *	Author: Felipe Fraporti - ffraporti@gmail.com
 *	Collaborators: Breno Cardoso - brenocastrocardoso@gmail.com
 */

#include "includes/defines.h"

int main() {

	DDRC = 0x20; //setting PORTC 5 as output (0b01000000);

	while(1) {
		PORTC |= 0x20; //turning it on
		_delay_ms(500);
		PORTC &= 0x5F; //turning it off
		_delay_ms(1000);
	}

	return 0;

	return 1;
}
