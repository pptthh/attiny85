/**
 * The Tinusaur Project
 * Tutorial 001: Blinking LED
 * file: main.c
 * created: 2014-01-04
 **/
#include <util/delay.h>
// ====================================
//					ATtiny
//					25/45/85
//				  +--------+
//			PB5 --+ o  Vcc +------------
//			PB3 --+        +-- PB0
//			PB4 --+        +-- PB1 - LED
//  --------------+ GND    +-- PB2
//				  +--------+
// ====================================
// Define the I/O port to be used for the LED.
// This a number between 0 and 7 that tells which bit to use.

int main(void)
{
    while (true)
    	loop();
    return (0);
}
void loop()
{
	PORTB |= 2;
	_delay_us(195000);
	
	DDRB |= 2;
	_delay_us(5000);
	
	DDRB &= ~2;
	_delay_us(100000);
	
	DDRB |= 2;
	_delay_us(5000);
	
	DDRB &= ~2;
	_delay_us(195000);
	
	PORTB &= ~2;
	_delay_ms(500);
}

