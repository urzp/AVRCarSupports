/* 
* Activity.cpp
*
* Created: 23.08.2018 11:55:27
* Author: user
*/


#include "Activity.h"

const int MENU  = 0;
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

const int ACTION_WHEEL = 100;
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


const int SCREEN_MAIN = 0;
const int SCREEN_MENU = 1;
const int SCREEN_ADJUST = 2;
const int SCREEN_TUNNING = 3;
const int SCREEN_LIMITS = 4;
const int SCREEN_SET_MALFACTION = 5;

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
const int LIMITS_MIN = 18;
const int LIMITS_MAX = 19;
const int ONOF_MALFACTION =20;
const int TIME_MALFACTION =21;



static const float Steps[] PROGMEM={
	0.01, 0.02, 0.03, 0.04, 0.05,
	0.06, 0.07, 0.08, 0.09, 0.10,
	0.12, 0.15, 0.20, 0.30, 0.50,
	0.75, 1.00, 1.50, 2.00, 3.00 };


// default constructor
Activity::Activity()
{
	
} //Activity

void Activity::Init(){
	SaveFlag = false;
	SetFlag = false;
	Step = 9;	
	
	Cursor = MENU;
	
	Statment = SCREEN_MAIN;
	//cursors map
	Main_Screen_cursor_pathes[MENU][B_LEFT_] = LEFTUP;
	Main_Screen_cursor_pathes[MENU][B_RIGHT] = RIGHTUP;
	Main_Screen_cursor_pathes[MENU][B_UP___] = ACTION_MENU;
	Main_Screen_cursor_pathes[MENU][B_DOWN_] = ADJUST;
	Main_Screen_cursor_pathes[MENU][B_OK___] = ACTION_MENU;
	
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
	
	//******************************
	//   Menu_Screen_cursor_pathes *
	//   MAIN MENU				   *
	//******************************
	Menu_Screen_cursor_pathes[SAVE][B_LEFT_] = ACTION_MENU_EXIT;
	Menu_Screen_cursor_pathes[SAVE][B_RIGHT] = PARKING_SAVE;
	Menu_Screen_cursor_pathes[SAVE][B_UP___] = SAVE;
	Menu_Screen_cursor_pathes[SAVE][B_DOWN_] = SETPOSITION;
	Menu_Screen_cursor_pathes[SAVE][B_OK___] = PARKING_SAVE;
	
	Menu_Screen_cursor_pathes[SETPOSITION][B_LEFT_] = ACTION_MENU_EXIT;
	Menu_Screen_cursor_pathes[SETPOSITION][B_RIGHT] = PARKING_SET;
	Menu_Screen_cursor_pathes[SETPOSITION][B_UP___] = SAVE;
	Menu_Screen_cursor_pathes[SETPOSITION][B_DOWN_] = SETTINGS;
	Menu_Screen_cursor_pathes[SETPOSITION][B_OK___] = PARKING_SET;
	
	Menu_Screen_cursor_pathes[SETTINGS][B_LEFT_] = ACTION_MENU_EXIT;
	Menu_Screen_cursor_pathes[SETTINGS][B_RIGHT] = SETTINGS_TUNING;
	Menu_Screen_cursor_pathes[SETTINGS][B_UP___] = SETPOSITION;
	Menu_Screen_cursor_pathes[SETTINGS][B_DOWN_] = EXIT_1;
	Menu_Screen_cursor_pathes[SETTINGS][B_OK___] = SETTINGS_TUNING;
	
	Menu_Screen_cursor_pathes[EXIT_1][B_LEFT_] = ACTION_MENU_EXIT;
	Menu_Screen_cursor_pathes[EXIT_1][B_RIGHT] = ACTION_MENU_EXIT;
	Menu_Screen_cursor_pathes[EXIT_1][B_UP___] = SETTINGS;
	Menu_Screen_cursor_pathes[EXIT_1][B_DOWN_] = EXIT_1;
	Menu_Screen_cursor_pathes[EXIT_1][B_OK___] = ACTION_MENU_EXIT;
	//*************
	//* SAVE      *
	//*************
	Menu_Screen_cursor_pathes[PARKING_SAVE][B_LEFT_] = SAVE;
	Menu_Screen_cursor_pathes[PARKING_SAVE][B_RIGHT] = ACTION_PARKING_SAVE;
	Menu_Screen_cursor_pathes[PARKING_SAVE][B_UP___] = PARKING_SAVE;
	Menu_Screen_cursor_pathes[PARKING_SAVE][B_DOWN_] = HIGHTPOSITION_SAVE;
	Menu_Screen_cursor_pathes[PARKING_SAVE][B_OK___] = ACTION_PARKING_SAVE;
	
	Menu_Screen_cursor_pathes[HIGHTPOSITION_SAVE][B_LEFT_] = SAVE;
	Menu_Screen_cursor_pathes[HIGHTPOSITION_SAVE][B_RIGHT] = ACTION_HIGHTPOSITION_SAVE;
	Menu_Screen_cursor_pathes[HIGHTPOSITION_SAVE][B_UP___] = PARKING_SAVE;
	Menu_Screen_cursor_pathes[HIGHTPOSITION_SAVE][B_DOWN_] = LOWPOSITION_SAVE;
	Menu_Screen_cursor_pathes[HIGHTPOSITION_SAVE][B_OK___] = ACTION_HIGHTPOSITION_SAVE;
	
	Menu_Screen_cursor_pathes[LOWPOSITION_SAVE][B_LEFT_] = SAVE;
	Menu_Screen_cursor_pathes[LOWPOSITION_SAVE][B_RIGHT] = ACTION_LOWPOSITION_SAVE;
	Menu_Screen_cursor_pathes[LOWPOSITION_SAVE][B_UP___] = HIGHTPOSITION_SAVE;
	Menu_Screen_cursor_pathes[LOWPOSITION_SAVE][B_DOWN_] = EXIT_SAVE;
	Menu_Screen_cursor_pathes[LOWPOSITION_SAVE][B_OK___] = ACTION_LOWPOSITION_SAVE;
	
	Menu_Screen_cursor_pathes[EXIT_SAVE][B_LEFT_] = SAVE;
	Menu_Screen_cursor_pathes[EXIT_SAVE][B_RIGHT] = ACTION_MENU_EXIT;
	Menu_Screen_cursor_pathes[EXIT_SAVE][B_UP___] = LOWPOSITION_SAVE;
	Menu_Screen_cursor_pathes[EXIT_SAVE][B_DOWN_] = EXIT_SAVE;
	Menu_Screen_cursor_pathes[EXIT_SAVE][B_OK___] = ACTION_MENU_EXIT;
	//*************
	//* SET       *
	//*************
	Menu_Screen_cursor_pathes[PARKING_SET][B_LEFT_] = SETPOSITION;
	Menu_Screen_cursor_pathes[PARKING_SET][B_RIGHT] = ACTION_PARKING_SET;
	Menu_Screen_cursor_pathes[PARKING_SET][B_UP___] = PARKING_SET;
	Menu_Screen_cursor_pathes[PARKING_SET][B_DOWN_] = HIGHTPOSITION_SET;
	Menu_Screen_cursor_pathes[PARKING_SET][B_OK___] = ACTION_PARKING_SET;
		
	Menu_Screen_cursor_pathes[HIGHTPOSITION_SET][B_LEFT_] = SETPOSITION;
	Menu_Screen_cursor_pathes[HIGHTPOSITION_SET][B_RIGHT] = ACTION_HIGHTPOSITION_SET;
	Menu_Screen_cursor_pathes[HIGHTPOSITION_SET][B_UP___] = PARKING_SET;
	Menu_Screen_cursor_pathes[HIGHTPOSITION_SET][B_DOWN_] = LOWPOSITION_SET;
	Menu_Screen_cursor_pathes[HIGHTPOSITION_SET][B_OK___] = ACTION_HIGHTPOSITION_SET;
		
	Menu_Screen_cursor_pathes[LOWPOSITION_SET][B_LEFT_] = SETPOSITION;
	Menu_Screen_cursor_pathes[LOWPOSITION_SET][B_RIGHT] = ACTION_LOWPOSITION_SET;
	Menu_Screen_cursor_pathes[LOWPOSITION_SET][B_UP___] = HIGHTPOSITION_SET;
	Menu_Screen_cursor_pathes[LOWPOSITION_SET][B_DOWN_] = EXIT_SET;
	Menu_Screen_cursor_pathes[LOWPOSITION_SET][B_OK___] = ACTION_LOWPOSITION_SET;
		
	Menu_Screen_cursor_pathes[EXIT_SET][B_LEFT_] = SETPOSITION;
	Menu_Screen_cursor_pathes[EXIT_SET][B_RIGHT] = ACTION_MENU_EXIT;
	Menu_Screen_cursor_pathes[EXIT_SET][B_UP___] = LOWPOSITION_SET;
	Menu_Screen_cursor_pathes[EXIT_SET][B_DOWN_] = EXIT_SET;
	Menu_Screen_cursor_pathes[EXIT_SET][B_OK___] = ACTION_MENU_EXIT;
	//*************
	//* SETTINGS  *
	//*************
	Menu_Screen_cursor_pathes[SETTINGS_TUNING][B_LEFT_] = SETTINGS;
	Menu_Screen_cursor_pathes[SETTINGS_TUNING][B_RIGHT] = ACTION_TUNING_SET;
	Menu_Screen_cursor_pathes[SETTINGS_TUNING][B_UP___] = SETTINGS_TUNING;
	Menu_Screen_cursor_pathes[SETTINGS_TUNING][B_DOWN_] = SETTINGS_LIMITS;
	Menu_Screen_cursor_pathes[SETTINGS_TUNING][B_OK___] = ACTION_TUNING_SET;	
	
	Menu_Screen_cursor_pathes[SETTINGS_LIMITS][B_LEFT_] = SETTINGS;
	Menu_Screen_cursor_pathes[SETTINGS_LIMITS][B_RIGHT] = ACTION_LIMITS_SET;
	Menu_Screen_cursor_pathes[SETTINGS_LIMITS][B_UP___] = SETTINGS_TUNING;
	Menu_Screen_cursor_pathes[SETTINGS_LIMITS][B_DOWN_] = SETTINGS_TEST_MALFACTION;
	Menu_Screen_cursor_pathes[SETTINGS_LIMITS][B_OK___] = ACTION_LIMITS_SET;	
	
	Menu_Screen_cursor_pathes[SETTINGS_TEST_MALFACTION][B_LEFT_] = SETTINGS;
	Menu_Screen_cursor_pathes[SETTINGS_TEST_MALFACTION][B_RIGHT] = ACTION_TEST_MALFACTION;
	Menu_Screen_cursor_pathes[SETTINGS_TEST_MALFACTION][B_UP___] = SETTINGS_LIMITS;
	Menu_Screen_cursor_pathes[SETTINGS_TEST_MALFACTION][B_DOWN_] = SETTINGS_RESET_ERRORS;
	Menu_Screen_cursor_pathes[SETTINGS_TEST_MALFACTION][B_OK___] = ACTION_TEST_MALFACTION;
	
	Menu_Screen_cursor_pathes[SETTINGS_RESET_ERRORS][B_LEFT_] = SETTINGS;
	Menu_Screen_cursor_pathes[SETTINGS_RESET_ERRORS][B_RIGHT] = SETTINGS_RESET_ERRORS;
	Menu_Screen_cursor_pathes[SETTINGS_RESET_ERRORS][B_UP___] = SETTINGS_LIMITS;
	Menu_Screen_cursor_pathes[SETTINGS_RESET_ERRORS][B_DOWN_] = SETTINGS_EXIT;
	Menu_Screen_cursor_pathes[SETTINGS_RESET_ERRORS][B_OK___] = SETTINGS_RESET_ERRORS;
	
	Menu_Screen_cursor_pathes[SETTINGS_EXIT][B_LEFT_] = SETTINGS;
	Menu_Screen_cursor_pathes[SETTINGS_EXIT][B_RIGHT] = SETTINGS;
	Menu_Screen_cursor_pathes[SETTINGS_EXIT][B_UP___] = SETTINGS_RESET_ERRORS;
	Menu_Screen_cursor_pathes[SETTINGS_EXIT][B_DOWN_] = SETTINGS_EXIT;
	Menu_Screen_cursor_pathes[SETTINGS_EXIT][B_OK___] = SETTINGS;
}

bool Activity::Cursor_Action(Panel &panel, Carrage &carrage){
	switch(Statment){
		case(SCREEN_MAIN):Main_Screen_Move(panel,carrage);break;
		case(SCREEN_MENU):Menu_Screen_Move(panel,carrage);break;
		case(SCREEN_ADJUST):Adjusting_Carrage(panel,carrage);break;
		case(SCREEN_TUNNING):Tunning_rate(panel,carrage);break;
		case(SCREEN_LIMITS):Limits_set(panel,carrage);break;
		case(SCREEN_SET_MALFACTION):malfaction_set(panel,carrage);break;
	}
}

bool Activity::Menu_Screen_Move(Panel &panel, Carrage &carrage){
		carrage.ControlMalfinction();
		int move = panel.Pressed(100);
		int next;
		if (move == B_NOTHING ){return false;}
		next = Menu_Screen_cursor_pathes[Cursor][move];
		switch(next){
			case (ACTION_MENU_EXIT):Statment=SCREEN_MAIN;Cursor = MENU;break;
			case (ACTION_PARKING_SAVE):Save();break;
			case (ACTION_HIGHTPOSITION_SAVE):Save();break;
			case (ACTION_LOWPOSITION_SAVE):Save();break;
			case (ACTION_PARKING_SET):Set();break;
			case (ACTION_HIGHTPOSITION_SET):Set();break;
			case (ACTION_LOWPOSITION_SET):Set();break;
			case (ACTION_TUNING_SET):Statment = SCREEN_TUNNING;Cursor = SETTINGS_TUNING;break;
			case (ACTION_LIMITS_SET):Statment = SCREEN_LIMITS;Cursor = LIMITS_MIN;break;
			case (ACTION_TEST_MALFACTION):Statment = SCREEN_SET_MALFACTION;Cursor = ONOF_MALFACTION;break;
			default: Cursor = next;break;
		}
		return true;
			
}

void Activity::Save(){
	SaveFlag = true; //For set position in EEMEM
	switch(Cursor){
		case(PARKING_SAVE):SavePosition = 0;break;
		case(HIGHTPOSITION_SAVE):SavePosition = 1;break;
		case(LOWPOSITION_SAVE):SavePosition = 2;break;
	}
	Statment=SCREEN_MAIN;
	Cursor = MENU;
}

void  Activity::Set(){
	SetFlag = true; //For set position in EEMEM and start adjastment there.
	switch(Cursor){
		case(PARKING_SET):SavePosition = 0;break;
		case(HIGHTPOSITION_SET):SavePosition = 1;break;
		case(LOWPOSITION_SET):SavePosition = 2;break;
	}
	Statment=SCREEN_ADJUST;
	Cursor = MENU;
}

bool Activity::Main_Screen_Move(Panel &panel, Carrage &carrage){
		carrage.ControlMalfinction();
		int move = panel.Pressed(100);
		int next;
		
		if (move == B_NOTHING ){return false;}		
		next = Main_Screen_cursor_pathes[Cursor][move];
		switch(next){
			case (ACTION_WHEEL):SelectWheel(carrage);break;
			case (ACTION_ADJUST):Statment = SCREEN_ADJUST; carrage.beforeAdjast() ;break;
			case (ACTION_MENU):Statment = SCREEN_MENU;Cursor = SAVE;break;
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

bool Activity::Adjusting_Carrage(Panel &panel, Carrage &carrage){
		int pressed = panel.Pressed(100);
		if (pressed == B_NOTHING ){return false;}
		switch(pressed){
			case(B_OK___):Statment = SCREEN_MAIN; break;
			case(B_UP___):carrage.Up(get_val_step()); break;
			case(B_DOWN_):carrage.Down(get_val_step()); break;
			case(B_LEFT_):Step--; break;
			case(B_RIGHT):Step++; break;
		}
		if (Step <= 0){Step=0;}
		if (Step >= 19){Step=19;}
}

bool Activity::Tunning_rate(Panel &panel, Carrage &carrage){
	int pressed = panel.Pressed(100);
	if (pressed == B_NOTHING ){button_step=0;return false;}
	switch(pressed){
		case(B_OK___):Statment = SCREEN_MENU;SettingsSaveFlag = true; break;
		case(B_LEFT_):carrage.tunning-=(0.01+button_step);button_step=0.1; break;
		case(B_RIGHT):carrage.tunning+=(0.01+button_step);button_step=0.1; break;
	}
	if (carrage.tunning <= 0){carrage.tunning = 0.01;}
	if (carrage.tunning >= 3){carrage.tunning = 3.00;}
}


bool Activity::Limits_set(Panel &panel, Carrage &carrage){
	int pressed = panel.Pressed(100);
	if (pressed == B_NOTHING ){button_step=0;return false;}
	switch(pressed){
		case(B_OK___):Statment = SCREEN_MENU;Cursor=SETTINGS_LIMITS;SettingsSaveFlag = true; break;
		case(B_LEFT_):if(Cursor==LIMITS_MIN){carrage.min-=(0.01+button_step);}else{carrage.max-=(0.01+button_step);};button_step=0.09; break;
		case(B_RIGHT):if(Cursor==LIMITS_MIN){carrage.min+=(0.01+button_step);}else{carrage.max+=(0.01+button_step);};button_step=0.09; break;
		case(B_DOWN_):Cursor = LIMITS_MAX;break;
		case(B_UP___):Cursor = LIMITS_MIN;break;
	}
	if (carrage.min <= 0){carrage.min = 0.00;}
	if (carrage.max >= 5){carrage.max = 5.00;}
	switch(Cursor){
		case(LIMITS_MIN):if (carrage.min >= carrage.max){carrage.min = carrage.max;};break;
		case(LIMITS_MAX):if (carrage.max <= carrage.min){carrage.max = carrage.min;};break;
	}

}

bool Activity::malfaction_set(Panel &panel, Carrage &carrage){
	int pressed = panel.Pressed(100);
	if (pressed == B_NOTHING ){button_step=0;return false;}
	switch(pressed){
		case(B_OK___):Statment = SCREEN_MENU;Cursor=SETTINGS_TEST_MALFACTION;SettingsSaveFlag = true; break;
		case(B_DOWN_):Cursor=TIME_MALFACTION;break;
		case(B_UP___):Cursor=ONOF_MALFACTION;break;
	}
	if(Cursor==ONOF_MALFACTION){
		switch(pressed){
			case(B_LEFT_):carrage.switch_malfaction(); break;
			case(B_RIGHT):carrage.switch_malfaction(); break;
		}
	}else{
		switch(pressed){
			case(B_LEFT_):carrage.countToMalfunctionLimit-=(1+button_step);button_step=9; break;
			case(B_RIGHT):carrage.countToMalfunctionLimit+=(1+button_step);button_step=9; break;
		}
	}
	if (carrage.countToMalfunctionLimit <= 5){carrage.countToMalfunctionLimit = 5;}
	if (carrage.countToMalfunctionLimit >= 999){carrage.countToMalfunctionLimit = 999;}
}

float Activity::get_val_step(){
	return pgm_read_float (&(Steps[Step]));
}