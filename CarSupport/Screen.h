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
protected:
private:
	// HELPERS
	void PrintTitle();
	void Draw_icon_menu();
	void Draw_Carrage();
	void Draw_Wheel(Wheel wheel);
	void Draw_adjustment_carrage();
	bool Draw_CursorMainScreen();
	void Draw_CursorMenuScreen();
	bool Print_Step_Value();
	bool Draw_all_cursor_wheel();
}; //Main_Screen

#endif //__MAIN_SCREEN_H__
