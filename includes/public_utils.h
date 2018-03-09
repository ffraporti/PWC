#ifndef PUBLIC_UTILS_H_
#define PUBLIC_UTILS_H_

#include <avr/sleep.h>

#include "private_utils.h"
#include "reg_atmega8.h"

void config_idle();
void config_power_saving();
void config_standby();

void put_to_sleep();
void wake_up();

#endif
