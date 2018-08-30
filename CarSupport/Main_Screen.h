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


#ifndef __MAIN_SCREEN_H__
#define __MAIN_SCREEN_H__


class Main_Screen
{
//variables
public:
protected:
private:
	
//functions
public:
	Main_Screen();
	void Init();
	void Render(Activity activity, Carrage carrage);
protected:
private:
	void Draw_menu();
	void Draw_Carrage(Carrage carrage);
	void Draw_Wheel(Wheel wheel);
	void Draw_adjustment_carrage(int statment);
	bool Draw_Cursor(Activity activity);
	bool Print_Step_Value(Activity activity);
}; //Main_Screen

#endif //__MAIN_SCREEN_H__
