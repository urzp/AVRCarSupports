/* 
* Carrage.h
*
* Created: 20.08.2018 8:59:10
* Author: user
*/

#include "Wheel.h"
#include "Support.h"
#include "LCDn5110.h"
#include <avr/eeprom.h>

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
	float tunning;
	float min,max;
	float countToMalfunctionLimit;
	bool OnOffMalfunction;
	bool flagNewMalfuction;
	bool flagGetLimits;
protected:
private:
	int sort_array[4];
	byte derWheel[5];
	int checked[5];
	int finish;
	int _step;
//functions
public:
	Carrage();
	void Init();
	bool IfForseAdjast();
	void beforeAdjast();
	void Up(float step);
	void Down(float step);
	void ForceUp();
	void ForceDown();
	bool IfSelectetMalfuction();
	void SetLimits();
	void CheckLimitsSetHight();
	void Ajustment();
	void test();
	bool chechAll();
	bool chechWheelsBefore();
	void Fast_print_LSD_hight(Wheel wheel);
	int  getStep();
	void ControlMalfinction();
	void ResecCountMalfinction();
	void switch_malfaction();
	void errorsReset();
	void SelectAllWheel();
	void DiSelectAllWheel();
	void SwitchAllWheel();
	bool AnySelected();
	bool ChekGetLimits();
	
protected:
private:

}; //Carrage

#endif //__CARRAGE_H__
