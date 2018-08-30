/* 
* Carrage.cpp
*
* Created: 20.08.2018 8:59:09
* Author: user
*/



#include "Carrage.h"

const int NORMAL=0;
const int UP=1;
const int DOWN=2;

// default constructor
Carrage::Carrage()
{
} //Carrage

void Carrage::Init(Wheel _Wheel_1, Wheel _Wheel_2, Wheel _Wheel_3, Wheel _Wheel_4){
	Wheel_1 = _Wheel_1;
	Wheel_2 = _Wheel_2;
	Wheel_3 = _Wheel_3;
	Wheel_4 = _Wheel_4;
	support.Init();
}

void Carrage::beforeAdjast(){
	Wheel_1.initialHight();
	Wheel_2.initialHight();
	Wheel_3.initialHight();
	Wheel_4.initialHight();
}

void Carrage::Up(float step){
	Wheel_1.Up(step);
	Wheel_2.Up(step);
	Wheel_3.Up(step);
	Wheel_4.Up(step);
	Ajustment();
}

void Carrage::Down(float step){
	Wheel_1.Down(step);
	Wheel_2.Down(step);
	Wheel_3.Down(step);
	Wheel_4.Down(step);
	Ajustment();
}

void Carrage::Ajustment(){
	
	finish=1;
	i=0;
	while(i<10){
		derWheel[1] = Wheel_1.takeDerection();
		derWheel[2] = Wheel_2.takeDerection();
		derWheel[3] = Wheel_3.takeDerection();
		derWheel[4] = Wheel_4.takeDerection();
		finish = derWheel[1] + derWheel[2] + derWheel[3] + derWheel[4];
		support.Adjast(100 ,derWheel[1], derWheel[2] ,derWheel[3] ,derWheel[4] );	
		i++;
	}

}