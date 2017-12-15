/**
 * The Tinusaur Project
 * Tutorial 001: Blinking LED
 * file: main.c
 * created: 2014-01-04
 **/
#include <avr/io.h>
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
#define LED_PORT PB1

int main(void)
{
	// Set the LED port number as output.
	// The DDRB is the data direction for port B.
	// This ...
	//  - shifts the "1" on left to the desired position and ...
	//  - does bitwise "OR" with the value in the port register.
	DDRB |= (1 << LED_PORT);

	// Start infinite loop.
	// (this is how most programs work)
    while (1)
    {
		PORTB |= (1 << LED_PORT);	// Set the LED bit to "1" - LED will be "on".
		_delay_us(15887);			// Wait a little. The delay function simply does N-number of "empty" loops.
		
		PORTB &= ~(1 << LED_PORT);	// Set the LED bit to "0" - LED will be "off".
		// Wait a little.
		_delay_us(131071);
    }
    // Return the mandatory for the "main" function value.
    return (0);
}
