/*
* Activity.cpp
*
* Created: 23.08.2018 11:55:27
* Author: user
*/


#include "Activity.h"



// default constructor
Activity::Activity()
{
	
} //Activity

void Activity::Init(Carrage &carrage){
	
	SaveFlag = false;
	SetFlag = false;
	Step = 16;
	
	Cursor = PARKING_SET;
	
	Statment = SCREEN_MENU;
	SelectAllWheel(carrage);
	
	//cursors map
	Main_Screen_cursor_pathes[MENU][B_LEFT_] = LEFTUP;
	Main_Screen_cursor_pathes[MENU][B_RIGHT] = RIGHTUP;
	Main_Screen_cursor_pathes[MENU][B_UP___] = ACTION_MENU;
	Main_Screen_cursor_pathes[MENU][B_DOWN_] = ADJUST;
	Main_Screen_cursor_pathes[MENU][B_OK___] = ACTION_MENU;
	
	Main_Screen_cursor_pathes[LEFTUP][B_LEFT_] = ACTION_WHEEL;
	Main_Screen_cursor_pathes[LEFTUP][B_RIGHT] = MENU;
	Main_Screen_cursor_pathes[LEFTUP][B_UP___] = LEFTUP;
	Main_Screen_cursor_pathes[LEFTUP][B_DOWN_] = LEFTDOWN;
	Main_Screen_cursor_pathes[LEFTUP][B_OK___] = ACTION_WHEEL;
	
	Main_Screen_cursor_pathes[LEFTDOWN][B_LEFT_] = ACTION_WHEEL;
	Main_Screen_cursor_pathes[LEFTDOWN][B_RIGHT] = CARRAGE;
	Main_Screen_cursor_pathes[LEFTDOWN][B_UP___] = LEFTUP;
	Main_Screen_cursor_pathes[LEFTDOWN][B_DOWN_] = LEFTDOWN;
	Main_Screen_cursor_pathes[LEFTDOWN][B_OK___] = ACTION_WHEEL;
	
	Main_Screen_cursor_pathes[ADJUST][B_LEFT_] = LEFTUP;
	Main_Screen_cursor_pathes[ADJUST][B_RIGHT] = RIGHTUP;
	Main_Screen_cursor_pathes[ADJUST][B_UP___] = MENU;
	Main_Screen_cursor_pathes[ADJUST][B_DOWN_] = CARRAGE;
	Main_Screen_cursor_pathes[ADJUST][B_OK___] = ACTION_ADJUST;
	
	Main_Screen_cursor_pathes[RIGHTDOWN][B_LEFT_] = CARRAGE;
	Main_Screen_cursor_pathes[RIGHTDOWN][B_RIGHT] = ACTION_WHEEL;
	Main_Screen_cursor_pathes[RIGHTDOWN][B_UP___] = RIGHTUP;
	Main_Screen_cursor_pathes[RIGHTDOWN][B_DOWN_] = RIGHTDOWN;
	Main_Screen_cursor_pathes[RIGHTDOWN][B_OK___] = ACTION_WHEEL;
	
	Main_Screen_cursor_pathes[RIGHTUP][B_LEFT_] = MENU;
	Main_Screen_cursor_pathes[RIGHTUP][B_RIGHT] = ACTION_WHEEL;
	Main_Screen_cursor_pathes[RIGHTUP][B_UP___] = RIGHTUP;
	Main_Screen_cursor_pathes[RIGHTUP][B_DOWN_] = RIGHTDOWN;
	Main_Screen_cursor_pathes[RIGHTUP][B_OK___] = ACTION_WHEEL;
	
	Main_Screen_cursor_pathes[CARRAGE][B_LEFT_] = LEFTDOWN;
	Main_Screen_cursor_pathes[CARRAGE][B_RIGHT] = RIGHTDOWN;
	Main_Screen_cursor_pathes[CARRAGE][B_UP___] = ADJUST;
	Main_Screen_cursor_pathes[CARRAGE][B_DOWN_] = ACTION_ALL_WHEEL;
	Main_Screen_cursor_pathes[CARRAGE][B_OK___] = ACTION_ALL_WHEEL;
	
	//******************************
	//   Menu_Screen_cursor_pathes *
	//   MAIN MENU				   *
	//******************************

	
	Menu_Screen_cursor_pathes[SETPOSITION][B_LEFT_] = ACTION_MENU_EXIT;
	Menu_Screen_cursor_pathes[SETPOSITION][B_RIGHT] = PARKING_SET;
	Menu_Screen_cursor_pathes[SETPOSITION][B_UP___] = SETPOSITION;
	Menu_Screen_cursor_pathes[SETPOSITION][B_DOWN_] = SAVE;
	Menu_Screen_cursor_pathes[SETPOSITION][B_OK___] = PARKING_SET;
	
	Menu_Screen_cursor_pathes[SAVE][B_LEFT_] = ACTION_MENU_EXIT;
	Menu_Screen_cursor_pathes[SAVE][B_RIGHT] = PARKING_SAVE;
	Menu_Screen_cursor_pathes[SAVE][B_UP___] = SETPOSITION;
	Menu_Screen_cursor_pathes[SAVE][B_DOWN_] = SETTINGS;
	Menu_Screen_cursor_pathes[SAVE][B_OK___] = PARKING_SAVE;
	
	Menu_Screen_cursor_pathes[SETTINGS][B_LEFT_] = ACTION_MENU_EXIT;
	Menu_Screen_cursor_pathes[SETTINGS][B_RIGHT] = SETTINGS_TUNING;
	Menu_Screen_cursor_pathes[SETTINGS][B_UP___] = SAVE;
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
	Menu_Screen_cursor_pathes[SETTINGS_RESET_ERRORS][B_RIGHT] = ACTION_ERRORS;
	Menu_Screen_cursor_pathes[SETTINGS_RESET_ERRORS][B_UP___] = SETTINGS_TEST_MALFACTION;
	Menu_Screen_cursor_pathes[SETTINGS_RESET_ERRORS][B_DOWN_] = SETTINGS_LCD ;
	Menu_Screen_cursor_pathes[SETTINGS_RESET_ERRORS][B_OK___] = ACTION_ERRORS;
	
	Menu_Screen_cursor_pathes[SETTINGS_LCD ][B_LEFT_] = SETTINGS;
	Menu_Screen_cursor_pathes[SETTINGS_LCD ][B_RIGHT] = ACTION_LCD_SETTINGS;
	Menu_Screen_cursor_pathes[SETTINGS_LCD ][B_UP___] = SETTINGS_RESET_ERRORS;
	Menu_Screen_cursor_pathes[SETTINGS_LCD ][B_DOWN_] = SETTINGS_LCD ;
	Menu_Screen_cursor_pathes[SETTINGS_LCD ][B_OK___] = ACTION_LCD_SETTINGS;
	
}

bool Activity::Cursor_Action(Panel &panel, Carrage &carrage){
	switch(Statment){
		case(SCREEN_MAIN):Main_Screen_Move(panel,carrage);break;
		case(SCREEN_MENU):Menu_Screen_Move(panel,carrage);break;
		case(SCREEN_ADJUST):Adjusting_Carrage(panel,carrage);break;
		case(SCREEN_TUNNING):Tunning_rate(panel,carrage);break;
		case(SCREEN_LIMITS):Limits_set(panel,carrage);break;
		case(SCREEN_SET_MALFACTION):Malfaction_set(panel,carrage);break;
		case(SCREEN_SET_ERRORS):Errors(panel,carrage);break;
		case(SCREEN_ERROR_WHEEL):Error(panel,carrage);break;
		case(SCREEN_LCD_SETTINGS):LCD_Settings(panel,carrage);break;
		case(SCREEN_MESSAGE):Message(panel,carrage);break;
	}
}

bool Activity::Main_Screen_Move(Panel &panel, Carrage &carrage){
	carrage.ControlMalfinction();
	int move = panel.Pressed(100);
	int next;
	if (move == B_W_UP_||move == B_W_DOWN){ForceMove(carrage, move);return false;}
	if (move == B_NOTHING ){return false;}
	next = Main_Screen_cursor_pathes[Cursor][move];
	switch(next){
		case (ACTION_WHEEL):SelectWheel(carrage);break;
		case (ACTION_ALL_WHEEL):SelectAllWheel(carrage);break;
		case (ACTION_ADJUST):Statment = SCREEN_ADJUST; carrage.beforeAdjast() ;break;
		case (ACTION_MENU):Statment = SCREEN_MENU;Cursor = SETPOSITION;break;
		default: Cursor = next;break;
	}
	return true;
}

bool Activity::Adjusting_Carrage(Panel &panel, Carrage &carrage){
	carrage.ControlMalfinction();
	if(carrage.caragemove){Statment=SCREEN_MESSAGE; TypeMessage = MESSAGE_ANEBLE_WHILE_DRIVING;return false;}
	int pressed = panel.Pressed(100);
	if (pressed == B_W_UP_||pressed == B_W_DOWN){ForceMove(carrage, pressed);return false;}
	if (pressed == B_NOTHING ){return false;}
	if(B_UP___||B_DOWN_){if(!carrage.AnySelected()){Statment=SCREEN_MESSAGE;TypeMessage=MESSAGE_NO_ANY_SELECTED;}}
	switch(pressed){
		case(B_OK___):Statment = SCREEN_MAIN; break;
		case(B_UP___):carrage.Up(Get_val_step(), panel); break;
		case(B_DOWN_):carrage.Down(Get_val_step(), panel); break;
		case(B_LEFT_):Step--; break;
		case(B_RIGHT):Step++; break;
	}
	if (Step <= 0){Step=0;}
	if (Step >= 19){Step=19;}
}

bool Activity::Menu_Screen_Move(Panel &panel, Carrage &carrage){
	carrage.ControlMalfinction();
	int move = panel.Pressed(100);
	int next;
	if (move == B_W_UP_){Statment=SCREEN_MAIN;Cursor = MENU;return false;}
	if (move == B_W_DOWN){Statment=SCREEN_MAIN;Cursor = MENU;return false;}
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
		case (ACTION_TUNING_SET):Statment = SCREEN_TUNNING;Cursor = TUNING;break;
		case (ACTION_LIMITS_SET):Statment = SCREEN_LIMITS;Cursor = LIMITS_MIN;break;
		case (ACTION_TEST_MALFACTION):Statment = SCREEN_SET_MALFACTION;Cursor = TIME_MALFACTION;break;
		case (ACTION_ERRORS):Statment = SCREEN_SET_ERRORS;Cursor = ERRORS_RESET;break;
		case (ACTION_LCD_SETTINGS):Statment = SCREEN_LCD_SETTINGS;Cursor = LCD_SET_CONTRAST;break;
		default: Cursor = next;break;
	}
	return true;
	
}

bool Activity::Tunning_rate(Panel &panel, Carrage &carrage){
	int pressed = panel.Pressed(100);
	if (pressed == B_W_UP_){Statment=SCREEN_MAIN;Cursor = MENU;return false;}
	if (pressed == B_W_DOWN){Statment=SCREEN_MAIN;Cursor = MENU;return false;}
	if (pressed == B_NOTHING ){button_step=0;return false;}
	if(Cursor==EXIT_TUNING&&pressed==B_OK___){Statment = SCREEN_MENU;Cursor=SETTINGS_TUNING;SettingsSaveFlag = true;return false;}
	if(pressed==B_OK___){Statment = SCREEN_MAIN;Cursor=MENU;SettingsSaveFlag = true;return false;}
	switch(pressed){
		case(B_DOWN_):Cursor++;break;
		case(B_UP___):Cursor--;break;
	}
	if(Cursor==TUNING){
		switch(pressed){
			case(B_LEFT_):carrage.tunning-=(0.01+button_step);button_step=0.09; break;
			case(B_RIGHT):carrage.tunning+=(0.01+button_step);button_step=0.09; break;
		}
	}
	
	if(Cursor==TUNING_INERT){
		switch(pressed){
			case(B_LEFT_):carrage.inertion-=(1+button_step);button_step=9; break;
			case(B_RIGHT):carrage.inertion+=(1+button_step);button_step=9; break;
		}
	}
	
	if(Cursor==TUNING_STEP){
		switch(pressed){
			case(B_LEFT_):carrage.step_force_move-=(1+button_step);button_step=9; break;
			case(B_RIGHT):carrage.step_force_move+=(1+button_step);button_step=9; break;
		}
	}
	
	if(Cursor==TUNING_ACCURACY){
		switch(pressed){
			case(B_LEFT_):carrage.accuracy-=(0.01+button_step);button_step=0.09; break;
			case(B_RIGHT):carrage.accuracy+=(0.01+button_step);button_step=0.09; break;
		}
	}
	
	if(Cursor>=EXIT_TUNING){
		switch(pressed){
			case(B_LEFT_):Cursor--;break;
			case(B_RIGHT):Cursor++;break;
		}
	}
	
	if(Cursor<=TUNING ){Cursor=TUNING ;}
	if(Cursor>=EXIT_TUNING_DISPLAY){Cursor=EXIT_TUNING_DISPLAY ;}
		
	if (carrage.tunning <= 0){carrage.tunning = 0.01;}
	if (carrage.tunning >= 3){carrage.tunning = 3.00;}
	if (carrage.inertion <= 0){carrage.inertion = 0;}
	if (carrage.inertion >= 999){carrage.inertion = 999;}
	if (carrage.step_force_move <= 0){carrage.step_force_move = 0;}
	if (carrage.step_force_move >= 999){carrage.step_force_move = 999;}
	if (carrage.accuracy <= 0){carrage.accuracy = 0.00;}
	if (carrage.accuracy >= 0.50){carrage.accuracy = 0.50;}
}

bool Activity::Limits_set(Panel &panel, Carrage &carrage){
	int pressed = panel.Pressed(100);
	if (pressed == B_W_UP_){Statment=SCREEN_MAIN;Cursor = MENU;return false;}
	if (pressed == B_W_DOWN){Statment=SCREEN_MAIN;Cursor = MENU;return false;}
	if (pressed == B_NOTHING ){button_step=0;return false;}
	if(Cursor==EXIT_LIMITS&&pressed==B_OK___){Statment = SCREEN_MENU;Cursor=SETTINGS_LIMITS;SettingsSaveFlag = true;return false;}
	if(pressed==B_OK___){Statment = SCREEN_MAIN;Cursor=MENU;SettingsSaveFlag = true;return false;}
	switch(pressed){
		case(B_DOWN_):Cursor++;break;
		case(B_UP___):Cursor--;break;
	}
	if(Cursor<EXIT_LIMITS&&Cursor>=LIMITS_MIN){
		switch(pressed){
			case(B_LEFT_):if(Cursor==LIMITS_MIN){carrage.min-=(0.01+button_step);}else{carrage.max-=(0.01+button_step);};button_step=0.09; break;
			case(B_RIGHT):if(Cursor==LIMITS_MIN){carrage.min+=(0.01+button_step);}else{carrage.max+=(0.01+button_step);};button_step=0.09; break;
		}
	}
	if(Cursor>=EXIT_LIMITS&&Cursor<=EXIT_LIMITS_DISPLAY){
		switch(pressed){
			case(B_LEFT_):Cursor--;break;
			case(B_RIGHT):Cursor++;break;
		}
	}
	if(Cursor<=LIMITS_MIN){Cursor=LIMITS_MIN;}
	if(Cursor>=EXIT_LIMITS_DISPLAY){Cursor=EXIT_LIMITS_DISPLAY;}
	if (carrage.min <= 0){carrage.min = 0.00;}
	if (carrage.max >= 5){carrage.max = 5.00;}
	switch(Cursor){
		case(LIMITS_MIN):if (carrage.min >= carrage.max){carrage.min = carrage.max;};break;
		case(LIMITS_MAX):if (carrage.max <= carrage.min){carrage.max = carrage.min;};break;
	}

}

bool Activity::Malfaction_set(Panel &panel, Carrage &carrage){
	int pressed = panel.Pressed(100);
	if (pressed == B_W_UP_){Statment=SCREEN_MAIN;Cursor = MENU;return false;}
	if (pressed == B_W_DOWN){Statment=SCREEN_MAIN;Cursor = MENU;return false;}
	if (pressed == B_NOTHING ){button_step=0;return false;}
	if(Cursor==EXIT_MALFACTION&&pressed==B_OK___){Statment = SCREEN_MENU;Cursor=SETTINGS_TEST_MALFACTION;SettingsSaveFlag = true;return false; }
	if(pressed==B_OK___){Statment = SCREEN_MAIN;Cursor=MENU;SettingsSaveFlag = true;return false;}
	switch(pressed){
		case(B_DOWN_):Cursor++;break;
		case(B_UP___):Cursor--;break;
	}
	
	if(Cursor==ONOF_MALFACTION){
		switch(pressed){
			case(B_LEFT_):carrage.switch_malfaction(); break;
			case(B_RIGHT):carrage.switch_malfaction(); break;
		}
	}
	if(Cursor==TIME_MALFACTION){
		switch(pressed){
			case(B_LEFT_):carrage.countToMalfunctionLimit-=(1+button_step);button_step=9; break;
			case(B_RIGHT):carrage.countToMalfunctionLimit+=(1+button_step);button_step=9; break;
		}
	}
	
	if(Cursor==SENSITIVE_MALFACTION){
		switch(pressed){
			case(B_LEFT_):if(Cursor==LIMITS_MIN){carrage.sensitivityMove-=(0.01+button_step);}else{carrage.sensitivityMove-=(0.01+button_step);};button_step=0.09; break;
			case(B_RIGHT):if(Cursor==LIMITS_MIN){carrage.sensitivityMove+=(0.01+button_step);}else{carrage.sensitivityMove+=(0.01+button_step);};button_step=0.09; break;
		}
	}
	
	if(Cursor>=EXIT_MALFACTION){
		switch(pressed){
			case(B_LEFT_):Cursor--;break;
			case(B_RIGHT):Cursor++;break;
		}
	}
	
	if(Cursor<=TIME_MALFACTION){Cursor=TIME_MALFACTION;}
	if(Cursor>=EXIT_MALFACTION_DISPLAY){Cursor=EXIT_MALFACTION_DISPLAY;}
	if (carrage.countToMalfunctionLimit <= 5){carrage.countToMalfunctionLimit = 5;}
	if (carrage.countToMalfunctionLimit >= 999){carrage.countToMalfunctionLimit = 999;}
}

bool Activity::Errors(Panel &panel, Carrage &carrage){
	int pressed = panel.Pressed(100);
	if (pressed == B_W_UP_){Statment=SCREEN_MAIN;Cursor = MENU;return false;}
	if (pressed == B_W_DOWN){Statment=SCREEN_MAIN;Cursor = MENU;return false;}
	if (pressed == B_NOTHING ){return false;}
	if(pressed == B_OK___&&Cursor==ERRORS_RESET){carrage.errorsReset();return false;}
	if(pressed == B_RIGHT&&Cursor==ERRORS_RESET){carrage.errorsReset();return false;}
	if(pressed == B_OK___&&Cursor==ERRORS_EXIT){Statment = SCREEN_MENU;Cursor=SETTINGS_RESET_ERRORS;return false;}
	if(Cursor==ERRORS_EXIT_DISPLAY&&pressed==B_OK___){Statment = SCREEN_MAIN;Cursor=MENU;SettingsSaveFlag = true;return false;}
	switch(pressed){
		case(B_DOWN_):Cursor++;break;
		case(B_UP___):Cursor--;break;
	}
	if(pressed == B_RIGHT&&Cursor==ERRORS_EXIT){Cursor++;return false;}	
	if(pressed == B_LEFT_&&Cursor==ERRORS_EXIT_DISPLAY){Cursor--;return false;}	
	if(pressed == B_UP___&&Cursor==ERRORS_EXIT_DISPLAY){Cursor--;return false;}
	
	
	
	
	switch(pressed){
		case(B_OK___):Statment=SCREEN_ERROR_WHEEL; break;
		case(B_LEFT_):Statment = SCREEN_MENU;Cursor=SETTINGS_RESET_ERRORS;return false; break;
		case(B_RIGHT):Statment=SCREEN_ERROR_WHEEL; break;
	}
	
	if(Cursor<=ERRORS_RESET){Cursor =ERRORS_RESET;};
	if(Cursor>=ERRORS_EXIT_DISPLAY){Cursor = ERRORS_EXIT_DISPLAY;};

}



bool Activity::Error(Panel &panel, Carrage &carrage){
	int pressed = panel.Pressed(100);
	if (pressed == B_W_UP_){return false;}
	if (pressed == B_W_DOWN){return false;}
	if (pressed == B_NOTHING ){return false;}
	if (!(pressed == B_NOTHING)){Statment=SCREEN_SET_ERRORS;}
	}

bool Activity::LCD_Settings(Panel &panel, Carrage &carrage){
		int pressed = panel.Pressed(100);
		if (pressed == B_W_UP_){Statment=SCREEN_MAIN;Cursor = MENU;return false;}
		if (pressed == B_W_DOWN){Statment=SCREEN_MAIN;Cursor = MENU;return false;}
		if (pressed == B_NOTHING ){return false;}
		if(Cursor==LCD_EXIT&&pressed==B_OK___){Statment = SCREEN_MENU;Cursor=SETTINGS_TUNING;SettingsSaveFlag = true;return false;}
		if(pressed==B_OK___){Statment = SCREEN_MAIN;Cursor=MENU;SettingsSaveFlag = true;return false;}
			
		if(Cursor==LCD_SET_CONTRAST){
			switch(pressed){
				case(B_LEFT_): carrage.LCD_contrast-=1;Lcd_init(carrage.LCD_contrast); break;
				case(B_RIGHT): carrage.LCD_contrast+=1;Lcd_init(carrage.LCD_contrast); break;
			}
		}
		
		switch(pressed){
			case(B_DOWN_):Cursor++;break;
			case(B_UP___):Cursor--;break;
		}
		
		if(pressed == B_RIGHT&&Cursor==LCD_EXIT){Cursor++;return false;}
		if(pressed == B_LEFT_&&Cursor==LCD_EXIT_DISPLAY){Cursor--;return false;}
		if(pressed == B_UP___&&Cursor==LCD_EXIT_DISPLAY){Cursor--;return false;}
		
		if(Cursor<=LCD_SET_CONTRAST){Cursor = LCD_SET_CONTRAST;};
		if(Cursor>=LCD_EXIT_DISPLAY){Cursor = LCD_EXIT_DISPLAY;};
		
		if (carrage.LCD_contrast <= 0xB6){carrage.LCD_contrast = 0xB6;}
		if (carrage.LCD_contrast >= 0xC9){carrage.LCD_contrast = 0xC9;}
}


void Activity::SelectWheel(Carrage &carrage){
	switch(Cursor){
		case(LEFTUP): carrage.Wheel_1.Select(); break;
		case(RIGHTUP): carrage.Wheel_2.Select(); break;
		case(RIGHTDOWN): carrage.Wheel_3.Select(); break;
		case(LEFTDOWN): carrage.Wheel_4.Select(); break;
	}
	if(!MessageMoveMalfunctionReaded){
		if(carrage.IfSelectetMalfuction()){Statment=SCREEN_MESSAGE; TypeMessage = MESSAGE_SELECT_MALFUCTION;};
	}
}

void Activity::SelectAllWheel(Carrage &carrage){
	carrage.SwitchAllWheel();
}



void Activity::Save(){
	SaveFlag = true; //For set position in EEMEM
	switch(Cursor){
		case(PARKING_SAVE):SavePosition = 0;break;
		case(HIGHTPOSITION_SAVE):SavePosition = 1;break;
		case(LOWPOSITION_SAVE):SavePosition = 2;break;
	}
	Statment=SCREEN_MESSAGE;TypeMessage = MESSAGE_SAVE;;
}

float Activity::Get_val_step(){
	return pgm_read_float (&(Steps[Step]));
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

bool Activity::Message(Panel &panel,Carrage &carrage){
	switch(TypeMessage){
		case(MESSAGE_SAVE):_delay_ms(1500);Statment=SCREEN_MENU;Cursor = SAVE;break;
		case(MESSAGE_SELECT_MALFUCTION):MessageSelectMalfunction(panel);break;
		case(MESSAGE_GET_MALFUCTION):MessageGetMalfunction(panel, carrage);break;
		case(MESSAGE_NO_ANY_SELECTED):_delay_ms(1500);Statment=SCREEN_MAIN;Cursor = MENU;break;
		case(MESSAGE_GET_LIMITS):_delay_ms(1500);Statment=SCREEN_LIMITS;Cursor=LIMITS_MIN;break;
		case(MESSAGE_ANEBLE_WHILE_DRIVING):_delay_ms(1500);Statment=SCREEN_MAIN;Cursor = MENU;break;
	}
}


bool Activity::MessageSelectMalfunction(Panel &panel){
	int pressed = panel.Pressed(100);
	if (pressed == B_NOTHING ){return false;}
	if (!(pressed == B_NOTHING)){Statment=SCREEN_MAIN;MessageMoveMalfunctionReaded=true;}
}

bool Activity::MessageGetMalfunction(Panel &panel,Carrage &carrage){
	int pressed = panel.Pressed(100);
	if (pressed == B_NOTHING ){return false;}
	if (!(pressed == B_NOTHING)){carrage.flagNewMalfuction=false;Statment=SCREEN_SET_ERRORS;Cursor=ERRORS_RESET;}
}

bool Activity::ForceMove(Carrage &carrage, int derection){
	if(carrage.caragemove){Statment=SCREEN_MESSAGE; TypeMessage = MESSAGE_ANEBLE_WHILE_DRIVING;return false;}
	if(!MessageMoveMalfunctionReaded){
		if(carrage.IfSelectetMalfuction()){Statment=SCREEN_MESSAGE; TypeMessage = MESSAGE_SELECT_MALFUCTION;};
	}
	carrage.ResecCountMalfinction();
	if(!carrage.AnySelected()){Statment=SCREEN_MESSAGE;TypeMessage=MESSAGE_NO_ANY_SELECTED;}
	switch(derection){
		case(B_W_UP_):carrage.ForceUp();break;
		case(B_W_DOWN):carrage.ForceDown();break;
	}
		
}

void Activity::GoToSetPosiions(){
	Statment = SCREEN_MENU;
	Cursor = PARKING_SET;
}