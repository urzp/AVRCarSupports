/* 
* Main_Screen.cpp
*
* Created: 21.08.2018 12:04:23
* Author: user
*/


#include "Screen.h"



// default constructor
Screen::Screen()
{
} //Main_Screen

void Screen::Init(){
	 
}

void Screen::Render(Activity &activity, Carrage &carrage){
	if(carrage.flagNewMalfuction){carrage.flagNewMalfuction=false;activity.Statment=SCREEN_MESSAGE; activity.TypeMessage = MESSAGE_GET_MALFUCTION;}
	if(carrage.flagGetLimits){carrage.flagGetLimits=false; activity.Statment=SCREEN_MESSAGE; activity.TypeMessage = MESSAGE_GET_LIMITS;}	
	Lcd_clear();
	switch(activity.Statment){
		case(SCREEN_MAIN):Render_main(activity,carrage);break;
		case(SCREEN_ADJUST):Render_main(activity,carrage);break;
		case(SCREEN_MENU):Render_menu(activity,carrage);break;
		case(SCREEN_TUNNING):Render_tunning(activity,carrage);break;
		case(SCREEN_LIMITS):Render_limits(activity,carrage);break;
		case(SCREEN_SET_MALFACTION):Render_maltifaction(activity,carrage);break;
		case(SCREEN_SET_ERRORS):Render_ERRORS(activity,carrage);break;
		case(SCREEN_ERROR_WHEEL):Render_ERROR(activity,carrage);break;\
		case(SCREEN_MESSAGE):Message(activity,carrage);break;
		case(SCREEN_LCD_SETTINGS):Render_LCDSettings(activity,carrage);break;
	}
	Lcd_update();
}

void Screen::PrintTitle(Activity &activity, Carrage &carrage){
	if(activity.Cursor < PARKING_SAVE){
		Lcd_print(5, 0, FONT_1X,(unsigned char *)"МЕНЮ");
		Lcd_print(2, 1, FONT_1X,(unsigned char *)"Установить");
		Lcd_print(2, 2, FONT_1X,(unsigned char *)"Сохранить");
		Lcd_print(2, 3, FONT_1X,(unsigned char *)"Настройки");
		Lcd_print(2, 4, FONT_1X,(unsigned char *)"Панель упр.");
		}else if(activity.Cursor < PARKING_SET){
		Lcd_print(3, 0, FONT_1X,(unsigned char *)"Сохранить");
		Lcd_print(2, 1, FONT_1X,(unsigned char *)"Парковка");
		Lcd_print(2, 2, FONT_1X,(unsigned char *)"Нижняя поз.");
		Lcd_print(2, 3, FONT_1X,(unsigned char *)"Верхняя поз.");
		Lcd_print(2, 4, FONT_1X,(unsigned char *)"Панель упр.");
		}else if (activity.Cursor < SETTINGS_TUNING ){
		Lcd_print(3, 0, FONT_1X,(unsigned char *)"Установить");
		Lcd_print(2, 1, FONT_1X,(unsigned char *)"Парковка");
		Lcd_print(2, 2, FONT_1X,(unsigned char *)"Нижнее поз.");
		Lcd_print(2, 3, FONT_1X,(unsigned char *)"Верхняя поз.");
		Lcd_print(2, 4, FONT_1X,(unsigned char *)"Панель упр.");
		}else{
		Lcd_print(3, 0, FONT_1X,(unsigned char *)"Настройки");
		Lcd_print(2, 1, FONT_1X,(unsigned char *)"Калибровка");
		Lcd_print(2, 2, FONT_1X,(unsigned char *)"Ограничения");
		Lcd_print(2, 3, FONT_1X,(unsigned char *)"В движении");
		Lcd_print(2, 4, FONT_1X,(unsigned char *)"Ошибки");
		Lcd_print(2, 5, FONT_1X,(unsigned char *)"Дисплей");
	}
	
	
}


void Screen::Render_main(Activity &activity, Carrage &carrage){	
	Draw_icon_menu();
	Draw_icon_carrage(activity);
	Draw_Carrage(carrage);
	Draw_adjustment_carrage(activity);
	Draw_CursorMainScreen(activity);	
	Print_Step_Value(activity);
	
}

void Screen::Render_menu(Activity &activity, Carrage &carrage){
	PrintTitle(activity,carrage);
	Draw_CursorMenuScreen(activity);
}

void Screen::Render_tunning(Activity &activity, Carrage &carrage){
	Lcd_print(2, 0, FONT_1X,(unsigned char *)"Калибровка");
	Lcd_print(0, 1, FONT_1X,(unsigned char *)"Корр-ия");
	Lcd_print(0, 2, FONT_1X,(unsigned char *)"Инер-ия");
	Lcd_print(0, 3, FONT_1X,(unsigned char *)"Погре-ть");
	Lcd_print(0, 4, FONT_1X,(unsigned char *)"Шаг");
	
	LcdGotoXY(3,5);LcdChr_full(0x9E);LcdChr_full(0x9F);//menu
	LcdGotoXY(8,5);LcdChr_full(0xAD);LcdChr_full(0xAE);//Panel
	
	Lcd_printf(9, 1, FONT_1X, carrage.tunning , 2);
	Lcd_printf2(10, 2, FONT_1X, carrage.inertion/100 , 2);
	Lcd_printf(9, 3, FONT_1X, carrage.accuracy , 2);
	Lcd_printf2(10, 4, FONT_1X, carrage.step_force_move/100 , 2);
	
	
	
	switch(activity.Cursor){
		case(TUNING):LcdGotoXY(8,1);LcdChr_full(0x9A);LcdGotoXY(13,1);LcdChr_full(0x9B);break;
		case(TUNING_INERT):LcdGotoXY(8,2);LcdChr_full(0x9A);LcdGotoXY(13,2);LcdChr_full(0x9B);break;
		case(TUNING_ACCURACY):LcdGotoXY(8,3);LcdChr_full(0x9A);LcdGotoXY(13,3);LcdChr_full(0x9B);break;
		case(TUNING_STEP):LcdGotoXY(8,4);LcdChr_full(0x9A);LcdGotoXY(13,4);LcdChr_full(0x9B);break;
		case(EXIT_TUNING):LcdGotoXY(2,5);LcdChr_full(0xA2);break;
		case(EXIT_TUNING_DISPLAY):LcdGotoXY(7,5);LcdChr_full(0xA2);break;
	}
}

void Screen::Render_limits(Activity &activity, Carrage &carrage){
	Lcd_print(2, 0, FONT_1X,(unsigned char *)"Ограничения");
	Lcd_print(2, 2, FONT_1X,(unsigned char *)"min");
	Lcd_printf(8, 2, FONT_1X, carrage.min , 2);
	Lcd_print(2, 3, FONT_1X,(unsigned char *)"max");
	Lcd_printf(8, 3, FONT_1X, carrage.max , 2);
	switch(activity.Cursor){
		case(LIMITS_MIN):LcdGotoXY(7,2);LcdChr_full(0x9A);LcdGotoXY(12,2);LcdChr_full(0xA2);break;
		case(LIMITS_MAX):LcdGotoXY(7,3);LcdChr_full(0x9A);LcdGotoXY(12,3);LcdChr_full(0xA2);break;
		case(EXIT_LIMITS):LcdGotoXY(2,5);LcdChr_full(0xA2);break;
		case(EXIT_LIMITS_DISPLAY):LcdGotoXY(8,5);LcdChr_full(0xA2);break;
	}
	LcdGotoXY(3,5);LcdChr_full(0x9E);LcdChr_full(0x9F);//menu
	LcdGotoXY(9,5);LcdChr_full(0xAD);LcdChr_full(0xAE);//Panel
}

void Screen::Render_maltifaction(Activity &activity, Carrage &carrage){
	Lcd_print(2, 0, FONT_1X,(unsigned char *)"В движении");
	Lcd_print(0, 1, FONT_1X,(unsigned char *)"Длительность");
	Lcd_print(0, 2, FONT_1X,(unsigned char *)"теста");
	Lcd_print(0, 3, FONT_1X,(unsigned char *)"Порог");
	Lcd_print(0, 4, FONT_1X,(unsigned char *)"Включить");
	
	Lcd_printf2(10, 2, FONT_1X, carrage.countToMalfunctionLimit/100 , 2);	
	Lcd_printf(9, 3, FONT_1X, carrage.sensitivityMove, 2);	
	switch(carrage.OnOffMalfunction){
		case(false):Lcd_print(10, 4, FONT_1X,(unsigned char *)"отк");break;
		case(true):Lcd_print(10, 4, FONT_1X,(unsigned char *)"вкл");break;
	}
	
	switch(activity.Cursor){
		case(ONOF_MALFACTION):LcdGotoXY(9,4);LcdChr_full(0xA2);break;
		case(SENSITIVE_MALFACTION):LcdGotoXY(8,3);LcdChr_full(0x9A);LcdGotoXY(13,3);LcdChr_full(0x9B);break;
		case(TIME_MALFACTION):LcdGotoXY(8,2);LcdChr_full(0x9A);LcdGotoXY(13,2);LcdChr_full(0x9B);break;
		case(EXIT_MALFACTION):LcdGotoXY(2,5);LcdChr_full(0xA2);break;
		case(EXIT_MALFACTION_DISPLAY):LcdGotoXY(8,5);LcdChr_full(0xA2);break;
	}
	LcdGotoXY(3,5);LcdChr_full(0x9E);LcdChr_full(0x9F);//menu
	LcdGotoXY(9,5);LcdChr_full(0xAD);LcdChr_full(0xAE);//Panel
}

void Screen::Render_ERRORS(Activity &activity, Carrage &carrage){
	Lcd_print(2, 0, FONT_1X,(unsigned char *)"Сброс ошибок");
	Lcd_print(2, 1, FONT_1X,(unsigned char *)"1.Стойка");
	Lcd_print(2, 2, FONT_1X,(unsigned char *)"2.Стойка");
	Lcd_print(2, 3, FONT_1X,(unsigned char *)"3.Стойка");
	Lcd_print(2, 4, FONT_1X,(unsigned char *)"4.Стойка");
	LcdGotoXY(3,5);LcdChr_full(0x9E);LcdChr_full(0x9F);//menu
	LcdGotoXY(9,5);LcdChr_full(0xAD);LcdChr_full(0xAE);//Panel
	
	Lcd_print(11, 1, FONT_1X,(unsigned char *)"--");
	Lcd_print(11, 2, FONT_1X,(unsigned char *)"--");
	Lcd_print(11, 3, FONT_1X,(unsigned char *)"--");
	Lcd_print(11, 4, FONT_1X,(unsigned char *)"--");
		
	if(carrage.Wheel_1.Error>0){Lcd_print(11, 1, FONT_1X,(unsigned char *)"E");Lcd_printf(12, 1, FONT_1X, carrage.Wheel_1.Error , 0);}
	if(carrage.Wheel_2.Error>0){Lcd_print(11, 2, FONT_1X,(unsigned char *)"E");Lcd_printf(12, 2, FONT_1X, carrage.Wheel_2.Error , 0);}
	if(carrage.Wheel_3.Error>0){Lcd_print(11, 3, FONT_1X,(unsigned char *)"E");Lcd_printf(12, 3, FONT_1X, carrage.Wheel_3.Error , 0);}
	if(carrage.Wheel_4.Error>0){Lcd_print(11, 4, FONT_1X,(unsigned char *)"E");Lcd_printf(12, 4, FONT_1X, carrage.Wheel_4.Error , 0);}
		
	switch(activity.Cursor){
		case(ERRORS_RESET):LcdGotoXY(0,0);LcdChr_full(0x9B);break;
		case(ERRORS_WHEEL1):LcdGotoXY(0,1);LcdChr_full(0x9B);break;
		case(ERRORS_WHEEL2):LcdGotoXY(0,2);LcdChr_full(0x9B);break;
		case(ERRORS_WHEEL3):LcdGotoXY(0,3);LcdChr_full(0x9B);break;
		case(ERRORS_WHEEL4):LcdGotoXY(0,4);LcdChr_full(0x9B);break;
		case(ERRORS_EXIT):LcdGotoXY(2,5);LcdChr_full(0xA2);break;
		case(ERRORS_EXIT_DISPLAY):LcdGotoXY(8,5);LcdChr_full(0xA2);break;
	}
}

void Screen::Render_ERROR(Activity &activity, Carrage &carrage){
	switch(activity.Cursor){
		case(ERRORS_WHEEL1):Lcd_print(3, 0, FONT_1X,(unsigned char *)"1 Стойка");PrintError(carrage.Wheel_1);break;
		case(ERRORS_WHEEL2):Lcd_print(3, 0, FONT_1X,(unsigned char *)"2 Стойка");PrintError(carrage.Wheel_2);break;
		case(ERRORS_WHEEL3):Lcd_print(3, 0, FONT_1X,(unsigned char *)"3 Стойка");PrintError(carrage.Wheel_3);break;
		case(ERRORS_WHEEL4):Lcd_print(3, 0, FONT_1X,(unsigned char *)"4 Стойка");PrintError(carrage.Wheel_4);break;
	}

}

void Screen::PrintError(Wheel wheel){
	if(wheel.Error == 0){
		Lcd_print(1, 2, FONT_1X,(unsigned char *)"Ошибок нет");
		}else{
		Lcd_print(1, 1, FONT_1X,(unsigned char *)"Ошибка Е");
		Lcd_printf(9, 1, FONT_1X, wheel.Error , 0);
		switch(wheel.Error){
			case(1):Lcd_print(0, 2, FONT_1X,(unsigned char *)"нет ответа стойки при попытке изменить ее положение");break;//"нет ответа стойки при попытке изменить ее положение"
			case(2):Lcd_print(0, 2, FONT_1X,(unsigned char *)"невозжможно выставить заданное положение");break;//"невозжможно выставить заданное положение"
			case(3):Lcd_print(0, 2, FONT_1X,(unsigned char *)"зависание датчика положения во время движения");break; //"зависание датчика положения во время движения"
		}
	}
}

void Screen::Render_LCDSettings(Activity &activity, Carrage &carrage){
	Lcd_print(3, 0, FONT_1X,(unsigned char *)"Дисплей");
	Lcd_print(0, 1, FONT_1X,(unsigned char *)"контрастность");

	LcdGotoXY(3,5);LcdChr_full(0x9E);LcdChr_full(0x9F);//menu
	LcdGotoXY(9,5);LcdChr_full(0xAD);LcdChr_full(0xAE);//Panel
	
	//Lcd_print(6, 3, FONT_1X, carrage.LCD_contrast , 2);
	
		LcdGotoXY(5 , 3 );
		LcdStepLevel(carrage.LCD_contrast - 0xB6);

	
	
	switch(activity.Cursor){
		case(LCD_SET_CONTRAST):LcdGotoXY(3,3);LcdChr_full(0x9A);LcdGotoXY(10,3);LcdChr_full(0x9B);break;
		case(LCD_EXIT):LcdGotoXY(2,5);LcdChr_full(0xA2);break;
		case(LCD_EXIT_DISPLAY):LcdGotoXY(8,5);LcdChr_full(0xA2);break;
	}
}


// ******************************************************
//              HELPERS
// ******************************************************

void Screen::Draw_icon_menu(){
	LcdGotoXY(6,0);
	LcdChr_full(0x9E);
	LcdGotoXY(7,0);
	LcdChr_full(0x9F);
}

void Screen::Draw_icon_carrage(Activity &activity){
	if (!(activity.Statment == SCREEN_ADJUST) ){
		LcdGotoXY(6,5);LcdChr_full(0xA3);LcdChr_full(0xA4);
	};
}



void Screen::Draw_Carrage(Carrage &carrage){
	
	Draw_Wheel(carrage.Wheel_1, carrage.caragemove);
	Draw_Wheel(carrage.Wheel_2, carrage.caragemove);
	Draw_Wheel(carrage.Wheel_3, carrage.caragemove);
	Draw_Wheel(carrage.Wheel_4, carrage.caragemove);
}

void Screen::Draw_Wheel(Wheel wheel, bool moving){
	int i;
	int pos_x;
	int pos_y;
	int hight_pos_x;
	int hight_pos_y;
	int Char_wheel[6];
	//get position
	switch(wheel.number){
		case 1:pos_x  = 3;pos_y = 0; hight_pos_x = 0; hight_pos_y = 1 ; break;
		case 2:pos_x  = 9;pos_y = 0; hight_pos_x = 11; hight_pos_y = 1 ;break;
		case 3:pos_x  = 9;pos_y = 3; hight_pos_x = 11; hight_pos_y = 4 ;break;
		case 4:pos_x  = 3;pos_y = 3; hight_pos_x = 0; hight_pos_y = 4 ;break;
	}
	
	if(moving){
		//moving
		i_effects++;
		if (i_effects>30){i_effects=0;}
		if(wheel.malfuction){
			Char_wheel[0] = 0x8C;
			Char_wheel[1] = 0x8D;
			Char_wheel[2] = 0x8E;
			Char_wheel[3] = 0x8F;
			Char_wheel[4] = 0x90;
			Char_wheel[5] = 0x91;
		}else{
			if(i_effects<10){
				Char_wheel[0] = 0xAF;
				Char_wheel[1] = 0xB0;
				Char_wheel[2] = 0xB1;
				Char_wheel[3] = 0xB2;
				Char_wheel[4] = 0xB3;
				Char_wheel[5] = 0xB4;
			}else if (i_effects<20){
				Char_wheel[0] = 0xB5;
				Char_wheel[1] = 0xB6;
				Char_wheel[2] = 0xB7;
				Char_wheel[3] = 0xB8;
				Char_wheel[4] = 0xB9;
				Char_wheel[5] = 0xBA;
			}else {
				Char_wheel[0] = 0xBB;
				Char_wheel[1] = 0xBC;
				Char_wheel[2] = 0xBD;
				Char_wheel[3] = 0xBE;
				Char_wheel[4] = 0xBF;
				Char_wheel[5] = 0xC0;
			}
			
		}
	}else{
	
		//not moving
		if(wheel.malfuction){
			if(wheel.selected){
				Char_wheel[0] = 0xA7;
				Char_wheel[1] = 0xA8;
				Char_wheel[2] = 0xA9;
				Char_wheel[3] = 0xAA;
				Char_wheel[4] = 0xAB;
				Char_wheel[5] = 0xAC;			
			}else{
				Char_wheel[0] = 0x8C;
				Char_wheel[1] = 0x8D;
				Char_wheel[2] = 0x8E;
				Char_wheel[3] = 0x8F;
				Char_wheel[4] = 0x90;
				Char_wheel[5] = 0x91;
			}
		} else if (wheel.selected){
				Char_wheel[0] = 0x80;//;
				Char_wheel[1] = 0x81;//;
				Char_wheel[2] = 0x82;//;
				Char_wheel[3] = 0x83;//;
				Char_wheel[4] = 0x84;//;
				Char_wheel[5] = 0x85;//;
		} else {
			Char_wheel[0] = 0x86;
			Char_wheel[1] = 0x87;
			Char_wheel[2] = 0x88;
			Char_wheel[3] = 0x89;
			Char_wheel[4] = 0x8A;
			Char_wheel[5] = 0x8B;
		}
	}

	//draw wheel 2 symbols for cycle 
	for ( i = 0; i <= 4; i = i + 2 ){
		LcdGotoXY(pos_x, pos_y);
		LcdChr_full(Char_wheel[i]);
		LcdGotoXY(pos_x + 1, pos_y);
		LcdChr_full(Char_wheel[i+1]); 
		pos_y ++;
	}
	float hight = wheel.sethight;
	//Lcd_printf2(hight_pos_x, hight_pos_y-1, FONT_1X, hight, 2);
	//print hight wheel	
	hight = wheel.get_hight();	
	Lcd_printf2(hight_pos_x, hight_pos_y, FONT_1X, hight, 2);	
	//print point
	LcdGotoXY(hight_pos_x , hight_pos_y + 1 );
	LcdChr_full(0xA0);	
}

void Screen::Draw_adjustment_carrage(Activity &activity){
	int statment = activity.Statment;
	if (statment == SCREEN_ADJUST){
		LcdGotoXY(6,2);
		LcdChr_full(0x96);
		LcdGotoXY(7,2);
		LcdChr_full(0x97);
		LcdGotoXY(6,3);
		LcdChr_full(0x98);
		LcdGotoXY(7,3);
		LcdChr_full(0x99);
	} else {
		LcdGotoXY(6,2);
		LcdChr_full(0x92);
		LcdGotoXY(7,2);
		LcdChr_full(0x93);
		LcdGotoXY(6,3);
		LcdChr_full(0x94);
		LcdGotoXY(7,3);
		LcdChr_full(0x95);
	}

}	

bool Screen::Draw_CursorMainScreen(Activity &activity){
	
	if (activity.Statment == SCREEN_ADJUST ){return false;};
	switch(activity.Cursor){
		case(MENU):LcdGotoXY(6,1);LcdChr_full(0x9C);LcdChr_full(0x9D);break;
		case(ADJUST):LcdGotoXY(6,1);LcdChr_full(0xA5);LcdChr_full(0xA6);break;
		case(CARRAGE):LcdGotoXY(6,4);LcdChr_full(0xA5);LcdChr_full(0xA6);break;
		case(LEFTUP):LcdGotoXY(5,1);LcdChr_full(0x9A);break;
		case(LEFTDOWN):LcdGotoXY(5,4);LcdChr_full(0x9A);break;
		case(RIGHTUP):LcdGotoXY(8,1);LcdChr_full(0x9B);break;
		case(RIGHTDOWN):LcdGotoXY(8,4);LcdChr_full(0x9B);break;
		case(ALLWHEEL):Draw_all_cursor_wheel();break;
	}	
	
}

void Screen::Draw_CursorMenuScreen(Activity &activity){
	//LcdGotoXY(0,1);LcdChr_full(0x9B);
	switch(activity.Cursor){
		case(SETPOSITION):LcdGotoXY(0,1);LcdChr_full(0x9B);break;
		case(SAVE):LcdGotoXY(0,2);LcdChr_full(0x9B);break;
		case(SETTINGS):LcdGotoXY(0,3);LcdChr_full(0x9B);break;
		case(EXIT_1):LcdGotoXY(0,4);LcdChr_full(0x9B);break;
		
		case(PARKING_SAVE):LcdGotoXY(0,1);LcdChr_full(0x9B);break;
		case(HIGHTPOSITION_SAVE):LcdGotoXY(0,2);LcdChr_full(0x9B);break;
		case(EXIT_SAVE):LcdGotoXY(0,4);LcdChr_full(0x9B);break;
		case(LOWPOSITION_SAVE):LcdGotoXY(0,3);LcdChr_full(0x9B);break;
		
		case(PARKING_SET):LcdGotoXY(0,1);LcdChr_full(0x9B);break;
		case(HIGHTPOSITION_SET):LcdGotoXY(0,2);LcdChr_full(0x9B);break;
		case(LOWPOSITION_SET):LcdGotoXY(0,3);LcdChr_full(0x9B);break;
		case(EXIT_SET):LcdGotoXY(0,4);LcdChr_full(0x9B);break;
		
		case(SETTINGS_TUNING):LcdGotoXY(0,1);LcdChr_full(0x9B);break;
		case(SETTINGS_LIMITS):LcdGotoXY(0,2);LcdChr_full(0x9B);break;
		case(SETTINGS_TEST_MALFACTION):LcdGotoXY(0,3);LcdChr_full(0x9B);break;
		case(SETTINGS_RESET_ERRORS):LcdGotoXY(0,4);LcdChr_full(0x9B);break;
		case(SETTINGS_LCD):LcdGotoXY(0,5);LcdChr_full(0x9B);break;
	}
}

bool Screen::Print_Step_Value(Activity &activity){
	if (activity.Statment != SCREEN_ADJUST ){return false;}
	float step = activity.Get_val_step();
	Lcd_printf(5, 1, FONT_1X, step , 2);
	//
	LcdGotoXY(5 , 4 );
	LcdStepLevel(activity.Step);
	
}

bool Screen::Draw_all_cursor_wheel(){
	LcdGotoXY(5,1);LcdChr_full(0x9A);
	LcdGotoXY(5,4);LcdChr_full(0x9A);
	LcdGotoXY(8,1);LcdChr_full(0x9B);
	LcdGotoXY(8,4);LcdChr_full(0x9B);
}

bool Screen::Message(Activity &activity, Carrage &carrage){
	switch(activity.TypeMessage){
		case(MESSAGE_SAVE):MessageSave();break;
		case(MESSAGE_SELECT_MALFUCTION):MessageSelectMalfuction();break;
		case(MESSAGE_GET_MALFUCTION):MessageGetMalfuction();break;
		case(MESSAGE_NO_ANY_SELECTED):MessageNoAnySelected();break;
		case(MESSAGE_GET_LIMITS):MessageGetLimits();break;
		case(MESSAGE_ANEBLE_WHILE_DRIVING):AnableWhileDriving();break;
	}
	
}

void Screen::MessageSave(){
	Lcd_print(2, 2, FONT_1X,(unsigned char *)"Сохранено...");
}

void Screen::MessageSelectMalfuction(){
	Lcd_print(3, 0, FONT_1X,(unsigned char *)"Внимание");
	Lcd_print(1, 1, FONT_1X,(unsigned char *)"Стойка(и) несправны. Возможна не адекватная реакция.");
	Lcd_print(1, 5, FONT_1X,(unsigned char *)"Нажмите Ок");
}

void Screen::MessageGetMalfuction(){
	Lcd_print(4, 0, FONT_1X,(unsigned char *)"Ошибка");
	Lcd_print(0, 1, FONT_1X,(unsigned char *)"Информация в");
	Lcd_print(0, 2, FONT_1X,(unsigned char *)"меню настройки");
	Lcd_print(0, 3, FONT_1X,(unsigned char *)"ошибки");
	Lcd_print(2, 5, FONT_1X,(unsigned char *)"нажмите ОК");
}

void Screen::MessageNoAnySelected(){

	Lcd_print(3, 2, FONT_1X,(unsigned char *)"Выберите");
	Lcd_print(3, 3, FONT_1X,(unsigned char *)"стойку(и)");

}

void Screen::MessageGetLimits(){
	Lcd_print(3, 2, FONT_1X,(unsigned char *)"Достигнуто");
	Lcd_print(2, 3, FONT_1X,(unsigned char *)"ограничение");
}

void Screen::AnableWhileDriving(){
	Lcd_print(2, 1, FONT_1X,(unsigned char *)"Недоступно");
	Lcd_print(2, 2, FONT_1X,(unsigned char *)" во время");
	Lcd_print(2, 3, FONT_1X,(unsigned char *)" движения");
}