/* 
* Activity.cpp
*
* Created: 23.08.2018 11:55:27
* Author: user
*/


#include "Activity.h"

const int MENU = 0;
const int LEFTUP = 1;
const int RIGHTUP = 2;
const int RIGHTDOWN = 3;
const int LEFTDOWN = 4;
const int ADJUST = 5;

const int B_OK___ = 0;
const int B_UP___ = 1;
const int B_DOWN_ = 2;
const int B_LEFT_ = 3;
const int B_RIGHT = 4;
const int B_NOTHING = -1;

const int ACTION_WHEEL = 10;
const int ACTION_ADJUST = 11;


const int SCREEN_MAIN = 0;
const int SCREEN_MENU = 1;
const int SCREEN_ADJUST = 2;

// default constructor
Activity::Activity()
{
	
} //Activity

void Activity::Init(){
	
	Step = 9;
	
	Steps[0]=0.01;
	Steps[1]=0.02;
	Steps[2]=0.03;
	Steps[3]=0.04;
	Steps[4]=0.05;
	Steps[5]=0.06;
	Steps[6]=0.07;
	Steps[7]=0.08;
	Steps[8]=0.09;
	Steps[9]=0.10;
	Steps[10]=0.12;
	Steps[11]=0.15;
	Steps[12]=0.20;
	Steps[13]=0.30;
	Steps[14]=0.50;
	Steps[15]=0.75;
	Steps[16]=1.00;
	Steps[17]=1.50;
	Steps[18]=2.00;
	Steps[19]=3.00;
	
	
	Cursor = MENU;
	
	Statment = SCREEN_MAIN;
	
	Main_Screen_cursor_pathes[MENU][B_LEFT_] = LEFTUP;
	Main_Screen_cursor_pathes[MENU][B_RIGHT] = RIGHTUP;
	Main_Screen_cursor_pathes[MENU][B_UP___] = MENU;
	Main_Screen_cursor_pathes[MENU][B_DOWN_] = ADJUST;
	Main_Screen_cursor_pathes[MENU][B_OK___] = MENU;
	
	Main_Screen_cursor_pathes[LEFTUP][B_LEFT_] = LEFTUP;
	Main_Screen_cursor_pathes[LEFTUP][B_RIGHT] = MENU;
	Main_Screen_cursor_pathes[LEFTUP][B_UP___] = LEFTUP;
	Main_Screen_cursor_pathes[LEFTUP][B_DOWN_] = LEFTDOWN;
	Main_Screen_cursor_pathes[LEFTUP][B_OK___] = ACTION_WHEEL;
	
	Main_Screen_cursor_pathes[LEFTDOWN][B_LEFT_] = LEFTDOWN;
	Main_Screen_cursor_pathes[LEFTDOWN][B_RIGHT] = ADJUST;
	Main_Screen_cursor_pathes[LEFTDOWN][B_UP___] = LEFTUP;
	Main_Screen_cursor_pathes[LEFTDOWN][B_DOWN_] = LEFTDOWN;
	Main_Screen_cursor_pathes[LEFTDOWN][B_OK___] = ACTION_WHEEL;
	
	Main_Screen_cursor_pathes[ADJUST][B_LEFT_] = LEFTDOWN;
	Main_Screen_cursor_pathes[ADJUST][B_RIGHT] = RIGHTDOWN;
	Main_Screen_cursor_pathes[ADJUST][B_UP___] = MENU;
	Main_Screen_cursor_pathes[ADJUST][B_DOWN_] = ADJUST;
	Main_Screen_cursor_pathes[ADJUST][B_OK___] = ACTION_ADJUST;
	
	Main_Screen_cursor_pathes[RIGHTDOWN][B_LEFT_] = ADJUST;
	Main_Screen_cursor_pathes[RIGHTDOWN][B_RIGHT] = RIGHTDOWN;
	Main_Screen_cursor_pathes[RIGHTDOWN][B_UP___] = RIGHTUP;
	Main_Screen_cursor_pathes[RIGHTDOWN][B_DOWN_] = RIGHTDOWN;
	Main_Screen_cursor_pathes[RIGHTDOWN][B_OK___] = ACTION_WHEEL;
	
	Main_Screen_cursor_pathes[RIGHTUP][B_LEFT_] = MENU;
	Main_Screen_cursor_pathes[RIGHTUP][B_RIGHT] = RIGHTUP;
	Main_Screen_cursor_pathes[RIGHTUP][B_UP___] = RIGHTUP;
	Main_Screen_cursor_pathes[RIGHTUP][B_DOWN_] = RIGHTDOWN;
	Main_Screen_cursor_pathes[RIGHTUP][B_OK___] = ACTION_WHEEL;
}

bool Activity::Cursor_Action(Panel panel, Carrage &carrage){
	switch(Statment){
		case(SCREEN_MAIN):Main_Screen_Move(panel,carrage);break;
		case(SCREEN_MENU):;break;
		case(SCREEN_ADJUST):Adjusting_Carrage(panel,carrage);break;
	}
}

bool Activity::Main_Screen_Move(Panel panel, Carrage &carrage){
	
		int move = panel.Pressed(10);
		int next;
		
		if (move == B_NOTHING ){return false;}		
		next = Main_Screen_cursor_pathes[Cursor][move];
		switch(next){
			case (ACTION_WHEEL):SelectWheel(carrage);break;
			case (ACTION_ADJUST):Statment = SCREEN_ADJUST ;break;
			default: Cursor = next;break;
		}
		return true;
}

void Activity::SelectWheel(Carrage &carrage){
	switch(Cursor){
		case(LEFTUP): carrage.Wheel_1.Select(); break;
		case(RIGHTUP): carrage.Wheel_2.Select(); break;
		case(RIGHTDOWN): carrage.Wheel_3.Select(); break;
		case(LEFTDOWN): carrage.Wheel_4.Select(); break;	
	}
}

bool Activity::Adjusting_Carrage(Panel panel, Carrage &carrage){
		int pressed = panel.Pressed(10);
		if (pressed == B_NOTHING ){return false;}
		switch(pressed){
			case(B_OK___):Statment = SCREEN_MAIN; break;
			case(B_UP___):carrage.Up(Steps[Step]); break;
			case(B_DOWN_):carrage.Down(Steps[Step]); break;
			case(B_LEFT_):Step--; break;
			case(B_RIGHT):Step++; break;
		}
		if (Step <= 0){Step=0;}
		if (Step >= 19){Step=19;}
}

float Activity::get_val_step(){
	return Steps[Step];
}