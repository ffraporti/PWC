#ifndef _DEFINES_H
#define _DEFINES_H


/**
 * Define your MCU model to have the proper includes
 *
 * Available options are:
 *    -> _MCU_MODEL_ATMEGA8
 */
#define _MCU_MODEL_ATMEGA8


#if defined (_MCU_MODEL_ATMEGA8)
	#include <avr/io.h>
	#include <util/delay.h>
#endif


#endif
