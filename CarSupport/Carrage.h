/* 
* Carrage.h
*
* Created: 20.08.2018 8:59:10
* Author: user
*/

#include "Wheel.h"
#include "Support.h"
#include "LCDn5110.h"

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
	Support support;
protected:
private:
	int sort_array[4];
	int derWheel[5];
	int checked[5];
	int finish;
	int _step;
//functions
public:
	Carrage();
	void Init(Wheel _Wheel_1, Wheel _Wheel_2, Wheel _Wheel_3, Wheel _Wheel_4);
	void beforeAdjast();
	void Up(float step);
	void Down(float step);
	void Ajustment();
	void test();
	bool chechAll();
	bool chechWheelsBefore();
	void Fast_print_LSD_hight(Wheel wheel);
	int getStep();
protected:
private:

}; //Carrage

#endif //__CARRAGE_H__
