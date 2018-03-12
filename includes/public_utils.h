#ifndef PUBLIC_UTILS_H_
#define PUBLIC_UTILS_H_

#include <avr/sleep.h>

#include "private_utils.h"
#include "reg_atmega8.h"

#define bit_set(byte, offset)  byte |= (1 << offset)
#define bit_clear(byte, offset) byte &= ~(1 << offset);
#define bit_toggle(byte, offset) byte ^= (1<<offset);

#define reg_clear(reg) reg = 0;
#define reg_write(reg, value) reg = value;

#define bit_read(byte, offset) (byte & (1 << offset)) == (1 << offset);

//uint8_t bit_read(int byte, int offset);

//void wait_for_bit(int byte, int offset, uint8_t state);

#define wait_for_bit(byte, offset, state) uint8_t temp = !state; do {temp = bit_read(byte, offset);} while (temp != state);

void config_idle();
void config_power_saving();
void config_standby();

void put_to_sleep();
void wake_up();

#endif
