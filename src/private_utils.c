/*
 * private_utils.c
 *
 *  Created on: 9 de mar de 2018
 *      Author: business
 */
#include "../includes/private_utils.h"

void disable_all_interrupts() {

#if defined (_MCU_MODEL_ATMEGA8)
	cli();
#endif

}

void enable_all_interrupts() {

#if defined (_MCU_MODEL_ATMEGA8)
	sei();
#endif

}
