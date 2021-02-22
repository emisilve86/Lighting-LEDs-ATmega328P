/*
 * LightingLEDs
 *
 * main.c
 *
 * Author :  Emiliano Silvestri
 * Email :   emisilve86@gmail.com
 */

#include "lighting.h"

int main(void)
{
	init_ports();

    while (1)
    {
		circular_lights(1000, 4, 200);
		bouncing_lights_vertical(1000, 4, 200);
		zig_zag_lights(1000, 4, 200);
		double_circular_lights(1000, 4, 200);
    }
}