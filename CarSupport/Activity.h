/* 
* Activity.h
*
* Created: 23.08.2018 11:55:28
* Author: user
*/
#include "Panel.h"
#include "Carrage.h"
#include <avr/pgmspace.h>


#ifndef __ACTIVITY_H__
#define __ACTIVITY_H__


class Activity 
{
//variables
public:
	int Statment;
	
	int Step;
	float button_step;
	int Cursor;
	byte Main_Screen_cursor_pathes[6][6];
	byte Menu_Screen_cursor_pathes[20][5];
	bool SaveFlag;
	bool SetFlag;
	bool SettingsSaveFlag;
	int SavePosition;
	
protected:
private:
	
//functions
public:
	Activity();
	void Init();
	bool Cursor_Action(Panel &panel, Carrage &carrage);
	bool Menu_Screen_Move(Panel &panel, Carrage &carrage);
	bool Main_Screen_Move(Panel &panel, Carrage &carrage);
	void SelectWheel(Carrage &carrage);
	bool Adjusting_Carrage(Panel &panel, Carrage &carrage);
	bool Tunning_rate(Panel &panel, Carrage &carrage);
	bool Limits_set(Panel &panel, Carrage &carrage);
	bool malfaction_set(Panel &panel, Carrage &carrage);
	bool errors(Panel &panel, Carrage &carrage);
	bool error(Panel &panel, Carrage &carrage);
	float get_val_step();
	void Save();
	void Set();
protected:
private:

}; //Activity

#endif //__ACTIVITY_H__
