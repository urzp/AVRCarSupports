/* 
* Wheel.cpp
*
* Created: 17.08.2018 14:01:04
* Author: user
*/


#include "Wheel.h"

// default constructor
Wheel::Wheel()
{
} //Wheel

void Wheel::Init(int _number){
	sensorWheels.Init();
	number =  _number;
	hight = 1.50;
}

float Wheel::get_hight(){
	hight = sensorWheels.getParams(number);
	return hight;
}

void Wheel::set_hight(){
	
}

void Wheel::PrintLCD(){
	
}

void Wheel::Select(){
	selected = !selected;
}

bool Wheel::Up(float step){
	if (!selected){return false;}
	hight += step;
	return true;
}

bool Wheel::Down(float step){
	if (!selected){return false;}
	hight -= step;
	return true;
}