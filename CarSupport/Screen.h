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

protected:
private:
	
//functions
public:
	Screen();
	void Init();
	void Render(Activity &activity, Carrage &carrage);
	void Render_main(Activity &activity, Carrage &carrage);
	void Render_menu(Activity &activity, Carrage &carrage);
	void Render_tunning(Activity &activity, Carrage &carrage);
	void Render_limits(Activity &activity, Carrage &carrage);
	void Render_maltifaction(Activity &activity, Carrage &carrage);
	void Render_ERRORS(Activity &activity, Carrage &carrage);
	void Render_ERROR(Activity &activity, Carrage &carrage);
	void PrintError(Wheel wheel);
protected:
private:
	// HELPERS
	void PrintTitle(Activity &activity, Carrage &carrage);
	void Draw_icon_menu();
	void Draw_icon_carrage(Activity &activity);
	void Draw_Carrage(Carrage &carrage);
	void Draw_Wheel(Wheel wheel);
	void Draw_adjustment_carrage(Activity &activity);
	bool Draw_CursorMainScreen(Activity &activity);
	void Draw_CursorMenuScreen(Activity &activity);
	bool Print_Step_Value(Activity &activity);
	bool Draw_all_cursor_wheel();
	bool Message(Activity &activity, Carrage &carrage);
	void MessageSelectMalfuction();
}; //Main_Screen

#endif //__MAIN_SCREEN_H__
