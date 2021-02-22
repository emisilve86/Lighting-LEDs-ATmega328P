/*
 * LightingLEDs
 *
 * lighting.c
 *
 * Author :  Emiliano Silvestri
 * Email :   emisilve86@gmail.com
 */

#include "lighting.h"

/****Disposition*of*LEDs****
 *  _________   _________  *
 * |_LED_1_1_| |_LED_1_2_| *
 *  _________   _________  *
 * |_LED_2_1_| |_LED_2_2_| *
 *  _________   _________  *
 * |_LED_3_1_| |_LED_3_2_| *
 *  _________   _________  *
 * |_LED_4_1_| |_LED_4_2_| *
 *                         *
 ***************************/
#define LED_1_1		(1 << PORTB6)
#define LED_2_1		(1 << PORTB7)
#define LED_3_1		(1 << PORTD5)
#define LED_4_1		(1 << PORTD6)
#define LED_1_2		(1 << PORTD7)
#define LED_2_2		(1 << PORTB0)
#define LED_3_2		(1 << PORTB2)
#define LED_4_2		(1 << PORTB1)

/*****Switching*ON*LEDs*****/
#define SWITCH_ON_1_1	(PORTB |= LED_1_1)
#define SWITCH_ON_2_1	(PORTB |= LED_2_1)
#define SWITCH_ON_3_1	(PORTD |= LED_3_1)
#define SWITCH_ON_4_1	(PORTD |= LED_4_1)
#define SWITCH_ON_1_2	(PORTD |= LED_1_2)
#define SWITCH_ON_2_2	(PORTB |= LED_2_2)
#define SWITCH_ON_3_2	(PORTB |= LED_3_2)
#define SWITCH_ON_4_2	(PORTB |= LED_4_2)

/*****Switching*OFF*LEDs****/
#define SWITCH_OFF_1_1	(PORTB &= ~LED_1_1)
#define SWITCH_OFF_2_1	(PORTB &= ~LED_2_1)
#define SWITCH_OFF_3_1	(PORTD &= ~LED_3_1)
#define SWITCH_OFF_4_1	(PORTD &= ~LED_4_1)
#define SWITCH_OFF_1_2	(PORTD &= ~LED_1_2)
#define SWITCH_OFF_2_2	(PORTB &= ~LED_2_2)
#define SWITCH_OFF_3_2	(PORTB &= ~LED_3_2)
#define SWITCH_OFF_4_2	(PORTB &= ~LED_4_2)

/*****Switching*ON*H-Row****/
#define SWITCH_ON_1_X { SWITCH_ON_1_1; SWITCH_ON_1_2; }
#define SWITCH_ON_2_X { SWITCH_ON_2_1; SWITCH_ON_2_2; }
#define SWITCH_ON_3_X { SWITCH_ON_3_1; SWITCH_ON_3_2; }
#define SWITCH_ON_4_X { SWITCH_ON_4_1; SWITCH_ON_4_2; }

/*****Switching*ON*V-Col****/
#define SWITCH_ON_X_1 { SWITCH_ON_1_1; SWITCH_ON_2_1; SWITCH_ON_3_1; SWITCH_ON_4_1; }
#define SWITCH_ON_X_2 { SWITCH_ON_1_2; SWITCH_ON_2_2; SWITCH_ON_3_2; SWITCH_ON_4_2; }

/*****Switching*OFF*H-Row***/
#define SWITCH_OFF_1_X { SWITCH_OFF_1_1; SWITCH_OFF_1_2; }
#define SWITCH_OFF_2_X { SWITCH_OFF_2_1; SWITCH_OFF_2_2; }
#define SWITCH_OFF_3_X { SWITCH_OFF_3_1; SWITCH_OFF_3_2; }
#define SWITCH_OFF_4_X { SWITCH_OFF_4_1; SWITCH_OFF_4_2; }

/*****Switching*OFF*V-Col***/
#define SWITCH_OFF_X_1 { SWITCH_OFF_1_1; SWITCH_OFF_2_1; SWITCH_OFF_3_1; SWITCH_OFF_4_1; }
#define SWITCH_OFF_X_2 { SWITCH_OFF_1_2; SWITCH_OFF_2_2; SWITCH_OFF_3_2; SWITCH_OFF_4_2; }

void init_ports(void)
{
	DDRB = 0b11000111;
	DDRD = 0b11100000;

	PORTB = 0b00000000;
	PORTD = 0b00000000;
}

void circular_lights(double defer, int iterations, double delay)
{
	_delay_ms(defer);
	
	for (int i=0; i<iterations; i++)
	{
		SWITCH_ON_1_1;
		_delay_ms(delay);
		SWITCH_OFF_1_1;
		
		SWITCH_ON_2_1;
		_delay_ms(delay);
		SWITCH_OFF_2_1;
		
		SWITCH_ON_3_1;
		_delay_ms(delay);
		SWITCH_OFF_3_1;
		
		SWITCH_ON_4_1;
		_delay_ms(delay);
		SWITCH_OFF_4_1;
		
		SWITCH_ON_4_2;
		_delay_ms(delay);
		SWITCH_OFF_4_2;
		
		SWITCH_ON_3_2;
		_delay_ms(delay);
		SWITCH_OFF_3_2;
		
		SWITCH_ON_2_2;
		_delay_ms(delay);
		SWITCH_OFF_2_2;
		
		SWITCH_ON_1_2;
		_delay_ms(delay);
		SWITCH_OFF_1_2;
	}
}

void double_circular_lights(double defer, int iterations, double delay)
{
	_delay_ms(defer);
	
	for (int i=0; i<iterations; i++)
	{
		SWITCH_ON_1_1;
		SWITCH_ON_4_2;
		_delay_ms(delay);
		SWITCH_OFF_1_1;
		SWITCH_OFF_4_2;
		
		SWITCH_ON_2_1;
		SWITCH_ON_3_2;
		_delay_ms(delay);
		SWITCH_OFF_2_1;
		SWITCH_OFF_3_2;
		
		SWITCH_ON_3_1;
		SWITCH_ON_2_2;
		_delay_ms(delay);
		SWITCH_OFF_3_1;
		SWITCH_OFF_2_2;
		
		SWITCH_ON_4_1;
		SWITCH_ON_1_2;
		_delay_ms(delay);
		SWITCH_OFF_4_1;
		SWITCH_OFF_1_2;
	}
}

void bouncing_lights_vertical(double defer, int iterations, double delay)
{
	_delay_ms(defer);
	
	for (int i=0; i<iterations; i++)
	{
		SWITCH_ON_1_X;
		_delay_ms(delay);
		SWITCH_OFF_1_X;
		
		SWITCH_ON_2_X;
		_delay_ms(delay);
		SWITCH_OFF_2_X;
		
		SWITCH_ON_3_X;
		_delay_ms(delay);
		SWITCH_OFF_3_X;
		
		SWITCH_ON_4_X;
		_delay_ms(delay);
		SWITCH_OFF_4_X;
		
		SWITCH_ON_3_X;
		_delay_ms(delay);
		SWITCH_OFF_3_X;
		
		SWITCH_ON_2_X;
		_delay_ms(delay);
		SWITCH_OFF_2_X;
	}
	
	SWITCH_ON_1_X;
	_delay_ms(delay);
	SWITCH_OFF_1_X;
}

void zig_zag_lights(double defer, int iterations, double delay)
{
	_delay_ms(defer);
	
	for (int i=0; i<iterations; i++)
	{
		SWITCH_ON_1_1;
		_delay_ms(delay);
		SWITCH_OFF_1_1;
		
		SWITCH_ON_1_2;
		_delay_ms(delay);
		SWITCH_OFF_1_2;
		
		SWITCH_ON_2_2;
		_delay_ms(delay);
		SWITCH_OFF_2_2;
		
		SWITCH_ON_2_1;
		_delay_ms(delay);
		SWITCH_OFF_2_1;
		
		SWITCH_ON_3_1;
		_delay_ms(delay);
		SWITCH_OFF_3_1;
		
		SWITCH_ON_3_2;
		_delay_ms(delay);
		SWITCH_OFF_3_2;
		
		SWITCH_ON_4_2;
		_delay_ms(delay);
		SWITCH_OFF_4_2;
		
		SWITCH_ON_4_1;
		_delay_ms(delay);
		SWITCH_OFF_4_1;
	}
}