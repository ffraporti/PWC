#ifndef PUBLIC_UTILS_H_
#define PUBLIC_UTILS_H_

#include <avr/sleep.h>

#include "private_utils.h"
#include "reg_atmega8.h"

void bit_clear(int byte, int offset) ;
void bit_set(int byte, int offset);
void bit_toggle(int byte, int offset);
uint8_t bit_read(int byte, int offset);
void wait_for_bit(int byte, int offset, uint8_t state);
void reg_clear(int reg);

void config_idle();
void config_power_saving();
void config_standby();

void put_to_sleep();
void wake_up();

#endif
