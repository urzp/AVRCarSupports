/* 
* Carrage.h
*
* Created: 20.08.2018 8:59:10
* Author: user
*/

#include "Wheel.h"

#ifndef __CARRAGE_H__
#define __CARRAGE_H__


class Carrage
{
//variables
public:
	Wheel Wheel_1;
	Wheel Wheel_2;
	Wheel Wheel_3;
	Wheel Wheel_4;
protected:
private:

//functions
public:
	Carrage();
	void Init(Wheel _Wheel_1, Wheel _Wheel_2, Wheel _Wheel_3, Wheel _Wheel_4);
	void Up(float step);
	void Down(float step);
	
protected:
private:

}; //Carrage

#endif //__CARRAGE_H__
