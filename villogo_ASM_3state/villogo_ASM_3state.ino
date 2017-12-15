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
//#define RESET_PORT PB5
#define LED_PORT PB1

int main(void)
{
    while (true)
    {
		PORTB |= (1 << LED_PORT);	// Set the LED bit to "1" - LED will be "on".
		_delay_us(247500);			// Wait a little. The delay function simply does N-number of "empty" loops.
		
		DDRB |= (1 << LED_PORT);
		_delay_us(5000);
		
		DDRB &= ~(1 << LED_PORT);
		_delay_us(247500);
		
		PORTB &= ~(1 << LED_PORT);
		// Wait a little.
		_delay_ms(1500);
    }
    // Return the mandatory for the "main" function value.
    return (0);
}
