/* 
* Wheel.cpp
*
* Created: 17.08.2018 14:01:04
* Author: user
*/

const int NORMAL=0;
const int UP=1;
const int DOWN=2;

#include "Wheel.h"


// default constructor
Wheel::Wheel()
{
} //Wheel

void Wheel::Init(int _number){
	sensorWheels.Init();
	number =  _number;
	sethight = 2.50;
}

float Wheel::get_hight(){
	hight = sensorWheels.getParams(number);
	return hight;
}

void Wheel::initialHight(){
	get_hight();
	sethight = hight;
}

int Wheel::takeDerection(){
	if (!selected) return NORMAL;
	hight = get_hight();
	diff = sethight*100 - hight*100;
	_diff = diff;
	adjusted = false;
	if (_diff < 0){ stepAdjast = _diff; return DOWN;}
	if (_diff > 0){ stepAdjast = _diff*-1; return UP;}
	stepAdjast = 0;
	adjusted = true;
	return NORMAL;
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
	sethight += step;
	return true;
}

bool Wheel::Down(float step){
	if (!selected){return false;}
	sethight -= step;
	return true;
}