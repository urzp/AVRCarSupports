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
	float hightBeforeMove;
	bool flagGetLimits;
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
	int step_min;
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
	bool IsChanchedHight(float sensitive);
	void Select();
	void initialHight();
	bool hightBeforeMoveNoting();
	int takeDerection(float accuracy);
	bool stepMinCorricting();
	bool stepMinReset();
	bool Check();
	bool selected_malfinction();
	bool MalFunctionAndnotselected();
	bool CheckGetLimitLow();
	bool CheckGetLimitHight();
protected:
private:



}; //Wheel

#endif //__WhEEL_H__
