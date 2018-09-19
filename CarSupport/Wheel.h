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
	float maxHight;
	float minHight;
	float oldHigit;
	float checkhight;
	float sethight;
	bool selected;
	bool malfuction;
	bool adjusted;
	bool move;
	int Error;
	int countToMalfunction;
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
	bool ControlMalfinction(int countToMalfunctionLimit);
	void SetLimitsSetHight();
	bool Up(float step);
	bool Down(float step);
	bool IsChanchedHight();
	void Select();
	void initialHight();
	int takeDerection();
	bool Check();
	bool selected_malfinction();
	bool MalFunctionAndnotselected();
protected:
private:



}; //Wheel

#endif //__WhEEL_H__
