

/*  
    Modified :  Muchiri john [john@warefab.com]
                Bob Afwata [bobraphtoneafwata@gmail.com]
	changes  :  * To match arduino pin mapping e.g D0 should be PORTD0 not PORTB0
			    * Add hardware pwm definition
				* Add analog pin definition, A0--A7
	
	Author:		Eric Conner
	Email:		Eric@EricConnerApps.com
	Date:		06-10-2013
	Project:	ATmega32 for Arduino IDE
	Version:	v1.2
*/

/*
	Copyright (c) 2015, Eric Conner Apps.

	Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation
	files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, 
	modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software 
	is furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES 
	OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE 
	LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR 
	IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

//total i/o pins
#define NUM_DIGITAL_PINS            32
//number of analog pins
#define NUM_ANALOG_INPUTS           8
//analog-digital pins
#define analogInputToDigitalPin(p)  ((p < 8) ? (p) + 24 : -1)
//hardware pwm pins
#define digitalPinHasPWM(p)         ((p) == 4 || (p) == 5 || (p) == 7 || (p) == 11)

//spi pins
static const uint8_t SS   = 12;
static const uint8_t MOSI = 13;
static const uint8_t MISO = 14;
static const uint8_t SCK  = 15;

//12c pins
static const uint8_t SDA = 17;
static const uint8_t SCL = 16;

//analog pins
static const uint8_t A0 = 24;
static const uint8_t A1 = 25;
static const uint8_t A2 = 26;
static const uint8_t A3 = 27;
static const uint8_t A4 = 28;
static const uint8_t A5 = 29;
static const uint8_t A6 = 30;
static const uint8_t A7 = 31;

//we dont have pin change interupts in mega32
/*
#define digitalPinToPCICR(p)    (((p) >= 0 && (p) <= 32) ? (&PCICR) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) (((p) <= 7) ? 2 : (((p) <= 13) ? 0 : 1))
#define digitalPinToPCMSK(p)    (((p) <= 7) ? (&PCMSK2) : (((p) <= 13) ? (&PCMSK0) : (((p) <= 21) ? (&PCMSK1) : ((uint8_t *)0))))
#define digitalPinToPCMSKbit(p) (((p) <= 7) ? (p) : (((p) <= 13) ? ((p) - 8) : ((p) - 14)))
*/
#ifdef ARDUINO_MAIN


#define PA 1
#define PB 2
#define PC 3
#define PD 4

/*
                   +-\/-+
      (D  8) PB0  1|    |40  PA0 (AI 0)
      (D  9) PB1  2|    |39  PA1 (AI 1)
      (D 10) PB2  3|    |38  PA2 (AI 2)
  PWM (D 11) PB3  4|    |37  PA3 (AI 3)
      (D 12) PB4  5|    |36  PA4 (AI 4)
      (D 13) PB5  6|    |35  PA5 (AI 5)
      (D 14) PB6  7|    |34  PA6 (AI 6)
      (D 15) PB7  8|    |33  PA7 (AI 7) 
           RESET  9|    |32  AREF
             VCC 10|    |31  GND
             GND 11|    |30  AVCC
           XTAL2 12|    |29  PB7 (D 23)
           XTAL1 13|    |28  PC6 (D 22)
       (D 0) PD0 14|    |27  PC5 (D 21)
       (D 1) PD1 15|    |26  PC4 (D 20)
       (D 2) PD2 16|    |25  PC3 (D 19) 
       (D 3) PD3 17|    |24  PC2 (D 18)
   PWM (D 4) PD4 18|    |23  PC1 (D 17)
   PWM (D 5) PD5 19|    |22  PC0 (D 16) 
       (D 6) PD6 20|    |21  PD7 (D 7) PWM
                   +----+
*/

//port registers
const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &DDRA,
	(uint16_t) &DDRB,
	(uint16_t) &DDRC,
	(uint16_t) &DDRD,
};

//port output registers
const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &PORTA,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
};

//port input registers
const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PIN,
	(uint16_t) &PINA,
	(uint16_t) &PINB,
	(uint16_t) &PINC,
	(uint16_t) &PIND,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	PD, /* 0 */
	PD,
	PD,
	PD,
	PD,
	PD,
	PD,
	PD,
	PB, /* 8 */
	PB,
	PB,
	PB,
	PB,
	PB,
	PB,
	PB,
	PC, /* 16 */
	PC,
	PC,
	PC,
	PC,
	PC,
	PC,
	PC,
	PA, /* 24 */
	PA,
	PA,
	PA,
	PA,
	PA,
	PA,
	PA,
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	_BV(0), /* 0, port D */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
	_BV(0), /* 8, port B */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
	_BV(0), /* 16, port C */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
	_BV(0), /* 24, port A */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	NOT_ON_TIMER, /* 0 - port D */
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	TIMER1B,
	TIMER1A,
	NOT_ON_TIMER,
	TIMER2,
	NOT_ON_TIMER, /* 8 - port B */
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	TIMER0A,      /* TODO: Need to verify it */
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER, /* 16 - port C */
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER, /* 24 - port A */
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
};
#endif
#endif
