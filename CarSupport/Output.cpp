/* 
* Output.cpp
*
* Created: 14.08.2018 11:58:09
* Author: user
*/


#define F_CPU 16000000
#include "Output.h"
#include <avr/io.h>
#include <util/delay.h>


// default constructor
Output::Output()
{
} //Out

void Output::Init(char port, int pin){
	_port = port;
	_pin = pin;
	
	switch (_port){
		case 'B': DDRB |= (1<<(pin)); break;
		case 'C': DDRC |= (1<<(pin)); break;
		case 'D': DDRD |= (1<<(pin)); break;
	}
} 

void Output::Set(bool level){
	if (level){
		switch (_port){
			case 'B': PORTB |= (1<<(_pin)); break;
			case 'C': PORTC |= (1<<(_pin));break;
			case 'D': PORTD |= (1<<(_pin));break;
		}
	}else{
		switch (_port){
			case 'B': PORTB &= ~(1<<(_pin)); break;
			case 'C': PORTC &= ~(1<<(_pin)); break;
			case 'D': PORTD &= ~(1<<(_pin)); break;
		}
	}

}

void Output::SetOnTime(bool level, int t){
	(*this).Set(level);
	for (int i=0;i<t;i++){
		_delay_ms(1);
	};
	(*this).Set(!level);
}
