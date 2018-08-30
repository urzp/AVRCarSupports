/* 
* Activity.h
*
* Created: 23.08.2018 11:55:28
* Author: user
*/
#include "Panel.h"
#include "Carrage.h"


#ifndef __ACTIVITY_H__
#define __ACTIVITY_H__


class Activity 
{
//variables
public:
	int Statment;
	float Steps[20];
	int Step;
	int Cursor;
	int Main_Screen_cursor_pathes[6][6];
protected:
private:
	
//functions
public:
	Activity();
	void Init();
	bool Cursor_Action(Panel panel, Carrage &carrage);
	bool Main_Screen_Move(Panel panel, Carrage &carrage);
	void SelectWheel(Carrage &carrage);
	bool Adjusting_Carrage(Panel panel, Carrage &carrage);
	float get_val_step();
protected:
private:

}; //Activity

#endif //__ACTIVITY_H__
