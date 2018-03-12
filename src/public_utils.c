#include "../includes/public_utils.h"

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
