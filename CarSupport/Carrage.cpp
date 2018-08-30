/* 
* Carrage.cpp
*
* Created: 20.08.2018 8:59:09
* Author: user
*/


#include "Carrage.h"

// default constructor
Carrage::Carrage()
{
} //Carrage

void Carrage::Init(Wheel _Wheel_1, Wheel _Wheel_2, Wheel _Wheel_3, Wheel _Wheel_4){
	Wheel_1 = _Wheel_1;
	Wheel_2 = _Wheel_2;
	Wheel_3 = _Wheel_3;
	Wheel_4 = _Wheel_4;
}

void Carrage::Up(float step){
	Wheel_1.Up(step);
	Wheel_2.Up(step);
	Wheel_3.Up(step);
	Wheel_4.Up(step);
}

void Carrage::Down(float step){
	Wheel_1.Down(step);
	Wheel_2.Down(step);
	Wheel_3.Down(step);
	Wheel_4.Down(step);
}