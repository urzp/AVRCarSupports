/* 
* SensorsWheels.cpp
*
* Created: 28.08.2018 12:50:58
* Author: user
*/

#include <util/delay.h>
#include "SensorsWheels.h"

// default constructor
SensorsWheels::SensorsWheels()
{
} //SensorsWheels

void SensorsWheels::Init(){
	ADMUX |=(1<<REFS0)|(1<<MUX0);//AVCC — источник опорного напряжения
	ADCSRA |=(1<<ADEN)|(1<<ADIE)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);// Включаем АЦП, разрешаем прерывание, настраиваем тактирование
	//sei ();// Глобально разрешаем прерывания
}

float SensorsWheels::getParams(int Input_number){
	ADMUX &= ~ (1<<MUX0);
	ADMUX &= ~ (1<<MUX1);
	ADMUX &= ~ (1<<MUX2);
	ADMUX &= ~ (1<<MUX3);
	switch(Input_number){
		case(1):break;
		case(2):ADMUX |= (1<<MUX0);break;
		case(3):ADMUX |= (1<<MUX1);break;
		case(4):ADMUX |= (1<<MUX0)|(1<<MUX1);break;
	}
	
	
	ADCSRA |=(1<<ADSC);//запуск чтения АЦП однократный	
	ready = false;
	while( !ready ){
		ready = (ADCSRA & (1 << ADIF));
	};
	float Value = ADCW*0.00489;
	return Value;
	
};

