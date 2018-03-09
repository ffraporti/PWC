#ifndef _REG_ATMEGA8_H
#define _REG_ATMEGA8_H

/**
 * Power modes for ATMega8 - datasheet page 33
 *
 *  To enter any of the five sleep modes, the SE bit in MCUCR must be written to logic one and a
	SLEEP instruction must be executed. The SM2, SM1, and SM0 bits in the MCUCR Register
	select which sleep mode (Idle, ADC Noise Reduction, Power-down, Power-save, or Standby)
	will be activated by the SLEEP instruction. See Table 13 for a summary. If an enabled interrupt
	occurs while the MCU is in a sleep mode, the MCU wakes up. The MCU is then halted for four
	cycles in addition to the start-up time, it executes the interrupt routine, and resumes execution
	from the instruction following SLEEP. The contents of the Register File and SRAM are unaltered
	when the device wakes up from sleep. If a reset occurs during sleep mode, the MCU wakes up
	and executes from the Reset Vector.
 *
 * Bits SM2, SM1 and SM0
 */

#define SLEEP_IDLE_MODE						SLEEP_MODE_IDLE
#define SLEEP_ADCNOISEREDUCTION_MODE		SLEEP_MODE_ADC
#define SLEEP_POWERDOWN_MODE				SLEEP_MODE_PWR_DOWN
#define SLEEP_POWERSAVE_MODE 				SLEEP_MODE_PWR_SAVE
#define SLEEP_STANDBY_MODE					SLEEP_MODE_STANDBY

#endif
