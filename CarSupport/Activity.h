/* 
* Activity.h
*
* Created: 23.08.2018 11:55:28
* Author: user
*/
#include "Panel.h"
#include "Carrage.h"
#include <util/delay.h>
#include <avr/pgmspace.h>


#ifndef __ACTIVITY_H__
#define __ACTIVITY_H__

const int MESSAGE_SAVE = 0;
const int MESSAGE_SELECT_MALFUCTION = 1;

const int MENU = 0;
const int LEFTUP = 1;
const int RIGHTUP = 2;
const int RIGHTDOWN = 3;
const int LEFTDOWN = 4;
const int ADJUST = 5;
const int CARRAGE = 6;
const int ALLWHEEL = 7;

const int B_OK___ = 0;
const int B_UP___ = 1;
const int B_DOWN_ = 2;
const int B_LEFT_ = 3;
const int B_RIGHT = 4;
const int B_W_UP_ = 5;
const int B_W_DOWN = 6;
const int B_NOTHING = -1;

const int ACTION_WHEEL = 100;
const int ACTION_ALL_WHEEL = 114;
const int ACTION_ADJUST = 101;
const int ACTION_MENU = 102;
const int ACTION_MENU_EXIT = 103;
const int ACTION_PARKING_SAVE =104;
const int ACTION_HIGHTPOSITION_SAVE =105;
const int ACTION_LOWPOSITION_SAVE =106;
const int ACTION_PARKING_SET =107;
const int ACTION_HIGHTPOSITION_SET =108;
const int ACTION_LOWPOSITION_SET =109;
const int ACTION_TUNING_SET = 110;
const int ACTION_LIMITS_SET = 111;
const int ACTION_TEST_MALFACTION = 112;
const int ACTION_ERRORS = 113;

const int SCREEN_MAIN = 0;
const int SCREEN_MENU = 1;
const int SCREEN_ADJUST = 2;
const int SCREEN_TUNNING = 3;
const int SCREEN_LIMITS = 4;
const int SCREEN_SET_MALFACTION = 5;
const int SCREEN_SET_ERRORS = 6;
const int SCREEN_ERROR_WHEEL = 7;
const int SCREEN_MESSAGE = 8;

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

static const float Steps[] PROGMEM={
	0.01, 0.02, 0.03, 0.04, 0.05,
	0.06, 0.07, 0.08, 0.09, 0.10,
	0.12, 0.15, 0.20, 0.30, 0.50,
	0.75, 1.00, 1.50, 2.00, 3.00 };

class Activity 
{
//variables
public:

	byte Statment;
	int Step;
	float button_step;
	byte Cursor;
	byte Main_Screen_cursor_pathes[7][6];
	byte Menu_Screen_cursor_pathes[20][5];
	bool SaveFlag;
	bool SetFlag;
	bool SettingsSaveFlag;
	byte SavePosition;
	int TypeMessage;
	
protected:
private:
	
//functions
public:
	Activity();
	bool Cursor_Action(Panel &panel, Carrage &carrage);
	bool Main_Screen_Move(Panel &panel, Carrage &carrage);
	bool Adjusting_Carrage(Panel &panel, Carrage &carrage);
	bool Menu_Screen_Move(Panel &panel, Carrage &carrage);
	bool Tunning_rate(Panel &panel, Carrage &carrage);
	bool Limits_set(Panel &panel, Carrage &carrage);
	bool Malfaction_set(Panel &panel, Carrage &carrage);
	bool Errors(Panel &panel, Carrage &carrage);
	bool Error(Panel &panel, Carrage &carrage);
	bool Message(Panel &panel);
	bool ExitMessageButton(Panel &panel);
	// HELPERS
	void Init();
	void SelectWheel(Carrage &carrage);
	void SelectAllWheel(Carrage &carrage);
	float Get_val_step();
	void Save();
	void Set();
	void ForceMove(Carrage &carrage, int derection);
	bool TrySelectMalfunctionWheel(Carrage &carrage);
	
protected:
private:

}; //Activity

#endif //__ACTIVITY_H__
