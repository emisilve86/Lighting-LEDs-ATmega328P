/*
 * LightingLEDs
 *
 * lighting.h
 *
 * Author :  Emiliano Silvestri
 * Email :   emisilve86@gmail.com
 */

#ifndef LIGHTING_H_
#define LIGHTING_H_

#include <avr/io.h>

/****************************************************************
 * In order to get functionality backward compatible with       *
 * previous versions, the macro "__DELAY_BACKWARD_COMPATIBLE__" *
 * must be defined before including the "delay.h" header file.  *
 ****************************************************************/
#define __DELAY_BACKWARD_COMPATIBLE__

/****************************************************************
 * We use the ATmega328P internal oscillator working at 8 MHz   *
 * and divided by 8 by the microcontroller's prescaler. Hence,  *
 * we observe 1 MHz working frequency.                          *
 ****************************************************************/
#define F_CPU	1000000

#include <util/delay.h>

void init_ports(void);
void circular_lights(double, int, double);
void double_circular_lights(double, int, double);
void bouncing_lights_vertical(double, int, double);
void zig_zag_lights(double, int, double);

#endif /* LIGHTING_H_ */