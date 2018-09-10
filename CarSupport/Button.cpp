/* 
* Button.cpp
*
* Created: 14.08.2018 11:50:10
* Author: user
*/


#include "Button.h"
#include <avr/io.h>
#include <util/delay.h>

// default constructor
Button::Button(){
	
}

void Button::Init(char port, int pin)
{
	_port = port;
	_pin = pin;
	slice_limit = 1000;
	switch (_port){
		case 'B': DDRB &= ~(1<<(pin)); PORTB |= (1<<(pin)); break;
		case 'C': DDRC &= ~(1<<(pin)); PORTC |= (1<<(pin)); break;
		case 'D': DDRD &= ~(1<<(pin)); PORTD |= (1<<(pin)); break;
	}
	
}

bool Button::Pressed(int debounce){
	//debounce защита от дребезга
	bool read_pin;
	int i;
	
	if (debounce >= 0){
		switch (_port){
			case 'B': read_pin = ((1 << _pin) & PINB); break;
			case 'C': read_pin = ((1 << _pin) & PINC); break;
			case 'D': read_pin = ((1 << _pin) & PIND); break;
			default: return false;
		}
		
		if (read_pin){
			slice_limit = 1000;
			return false;
			}else{
			debounce--;
		};
	};
	//button anti slice
	slice = 0;
	while((!read_pin)&&(slice<slice_limit)){
		switch (_port){
			case 'B': read_pin = ((1 << _pin) & PINB); break;
			case 'C': read_pin = ((1 << _pin) & PINC); break;
			case 'D': read_pin = ((1 << _pin) & PIND); break;
			default: return false;
		}
		_delay_ms(1);
		slice++;
	}
	slice_limit=100;
	return true;
	
}
