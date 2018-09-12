/* 
* Main_Screen.h
*
* Created: 21.08.2018 12:04:25
* Author: user
*/

#include "LCDn5110.h"
#include "Carrage.h"
#include "Wheel.h"
#include "Activity.h"
#include <avr/pgmspace.h>


#ifndef __SCREEN_H__
#define __SCREEN_H__
const int MENU = 0;
const int LEFTUP = 1;
const int RIGHTUP = 2;
const int RIGHTDOWN = 3;
const int LEFTDOWN = 4;
const int ADJUST = 5;

const int SCREEN_MAIN = 0;
const int SCREEN_MENU = 1;
const int SCREEN_ADJUST = 2;
const int SCREEN_TUNNING = 3;
const int SCREEN_LIMITS = 4;
const int SCREEN_SET_MALFACTION = 5;
const int SCREEN_SET_ERRORS = 6;
const int SCREEN_ERROR_WHEEL = 7;

const int SAVE = 0;
const int SETPOSITION = 1;
const int SETTINGS = 2;
const int EXIT_1 = 3;

const int PARKING_SAVE = 4;
const int HIGHTPOSITION_SAVE = 5;
const int LOWPOSITION_SAVE = 6;
const int EXIT_SAVE = 7;

const int PARKING_SET = 8;
const int HIGHTPOSITION_SET = 9;
const int LOWPOSITION_SET = 10;
const int EXIT_SET = 11;

const int SETTINGS_TUNING = 12;
const int SETTINGS_LIMITS= 13;
const int SETTINGS_TEST_MALFACTION = 14;
const int SETTINGS_RESET_ERRORS = 15;
const int SETTINGS_EXIT = 16;

const int TUNING = 17;
const int EXIT_TUNING =18;

const int LIMITS_MIN = 19;
const int LIMITS_MAX = 20;
const int EXIT_LIMITS =21;

const int TIME_MALFACTION =22;
const int ONOF_MALFACTION =23;
const int EXIT_MALFACTION =24;

const int ERRORS_WHEEL1 = 25;
const int ERRORS_WHEEL2 = 26;
const int ERRORS_WHEEL3 = 27;
const int ERRORS_WHEEL4 = 28;
const int ERRORS_RESET = 29;
const int ERRORS_EXIT = 30;

class Screen
{
//variables
public:
	Activity activity;
	Carrage carrage;
protected:
private:
	
//functions
public:
	Screen();
	void Init();
	void Render(Activity &_activity, Carrage &_carrage);
	void Render_main();
	void Render_menu();
	void Render_tunning();
	void Render_limits();
	void Render_maltifaction();
	void Render_ERRORS();
	void Render_ERROR();
	void PrintError(Wheel wheel);
	void PtintItems();
protected:
private:
	void PrintTitle();
	void Draw_icon_menu();
	void Draw_Carrage();
	void Draw_Wheel(Wheel wheel);
	void Draw_adjustment_carrage();
	bool Draw_CursorMainScreen();
	void Draw_CursorMenuScreen();
	bool Print_Step_Value();
}; //Main_Screen

#endif //__MAIN_SCREEN_H__
