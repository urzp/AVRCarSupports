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
	float sethight;
	bool selected;
	bool malfuction;
	bool adjusted;
	SensorsWheels sensorWheels;
protected:
private:

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
protected:
private:
	float diff;
	int _diff;


}; //Wheel

#endif //__WhEEL_H__
