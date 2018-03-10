#include "../includes/public_utils.h"

void bit_clear(int byte, int offset) {
	byte &= ~(1 << offset);
}

void bit_set(int byte, int offset) {
	byte |= (1 << offset);
}

void bit_toggle(int byte, int offset) {
	byte ^= (1 << offset);
}

uint8_t bit_read(int byte, int offset) {
	return (byte & (1 << offset)) == (1 << offset);
}

void wait_for_bit(int byte, int offset, uint8_t state) {
	uint8_t temp = !state;
	do {
		temp = bit_read(byte, offset);
	} while (temp != state);
}

void reg_clear(int reg) {
	reg = 0;
}

void config_power_saving() {
	set_sleep_mode(SLEEP_POWERSAVE_MODE);
}

void config_idle() {
	set_sleep_mode(SLEEP_IDLE_MODE);
}

void config_standby() {
	set_sleep_mode(SLEEP_STANDBY_MODE);
}

void put_to_sleep() {
	disable_all_interrupts();
	sleep_enable();
	enable_all_interrupts();
	sleep_cpu();
}

void wake_up() {
	sleep_disable();
}
