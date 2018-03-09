#ifndef _DEFINES_H_
#define _DEFINES_H_


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

	#include "reg_atmega8.h"
	#include "public_utils.h"
#endif


#endif
