/* 
* Weel.h
*
* Created: 17.08.2018 14:01:05
* Author: user
*/

#include "SensorsWheels.h"
#ifndef __WHEEL_H__
#define __WHEEL_H__


class Wheel
{
//variables
public:
	int number;
	float hight;
	float checkhight;
	float sethight;
	bool selected;
	bool malfuction;
	bool adjusted;
	int step;
	SensorsWheels sensorWheels;
protected:
private:
	float diff;
	int _diff;

//functions
public:
	Wheel();
	void Init(int _number);
	float get_hight();
	void set_hight();
	bool Up(float step);
	bool Down(float step);
	void PrintLCD();
	void Select();
	void initialHight();
	int takeDerection();
	bool Check();
protected:
private:



}; //Wheel

#endif //__WhEEL_H__
