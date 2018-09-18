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
	}
	Lcd_update();
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
	Lcd_printf(5, 2, FONT_1X, carrage.tunning , 2);
	Lcd_print(3, 4, FONT_1X,(unsigned char *)"Сохранить");
	
	switch(activity.Cursor){
		case(TUNING):LcdGotoXY(4,2);LcdChr_full(0x9A);LcdGotoXY(9,2);LcdChr_full(0x9B);break;
		case(EXIT_TUNING):LcdGotoXY(1,4);LcdChr_full(0x9B);break;
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
		case(EXIT_LIMITS):LcdGotoXY(1,5);LcdChr_full(0x9B);break;
	}
	Lcd_print(3, 5, FONT_1X,(unsigned char *)"Сохранить");
}

void Screen::Render_maltifaction(Activity &activity, Carrage &carrage){
	Lcd_print(2, 0, FONT_1X,(unsigned char *)"Диагностика");
	Lcd_print(0, 1, FONT_1X,(unsigned char *)"Длительность");
	Lcd_print(0, 2, FONT_1X,(unsigned char *)"процесса");
	Lcd_printf2(10, 2, FONT_1X, carrage.countToMalfunctionLimit/100 , 2);
	
	Lcd_print(0, 3, FONT_1X,(unsigned char *)"Включить");
	switch(carrage.OnOffMalfunction){
		case(false):Lcd_print(10, 3, FONT_1X,(unsigned char *)"отк");break;
		case(true):Lcd_print(10, 3, FONT_1X,(unsigned char *)"вкл");break;
	}
	
	switch(activity.Cursor){
		case(ONOF_MALFACTION):LcdGotoXY(9,3);LcdChr_full(0xA2);break;
		case(TIME_MALFACTION):LcdGotoXY(9,2);LcdChr_full(0x9A);LcdGotoXY(13,2);LcdChr_full(0x9B);break;
		case(EXIT_MALFACTION):LcdGotoXY(1,5);LcdChr_full(0x9B);break;
	}
	Lcd_print(3, 5, FONT_1X,(unsigned char *)"Сохранить");
}

void Screen::Render_ERRORS(Activity &activity, Carrage &carrage){
	Lcd_print(4, 0, FONT_1X,(unsigned char *)"Ошибки");
	Lcd_print(2, 1, FONT_1X,(unsigned char *)"1.Стойка");
	Lcd_print(2, 2, FONT_1X,(unsigned char *)"2.Стойка");
	Lcd_print(2, 3, FONT_1X,(unsigned char *)"3.Стойка");
	Lcd_print(2, 4, FONT_1X,(unsigned char *)"4.Стойка");
	Lcd_print(2, 5, FONT_1X,(unsigned char *)"Сброс");
	Lcd_print(9, 5, FONT_1X,(unsigned char *)"Выход");
	
	Lcd_print(11, 1, FONT_1X,(unsigned char *)"--");
	Lcd_print(11, 2, FONT_1X,(unsigned char *)"--");
	Lcd_print(11, 3, FONT_1X,(unsigned char *)"--");
	Lcd_print(11, 4, FONT_1X,(unsigned char *)"--");
		
	if(carrage.Wheel_1.Error>0){Lcd_print(11, 1, FONT_1X,(unsigned char *)"E");Lcd_printf(12, 1, FONT_1X, carrage.Wheel_1.Error , 0);}
	if(carrage.Wheel_2.Error>0){Lcd_print(11, 2, FONT_1X,(unsigned char *)"E");Lcd_printf(12, 2, FONT_1X, carrage.Wheel_2.Error , 0);}
	if(carrage.Wheel_3.Error>0){Lcd_print(11, 3, FONT_1X,(unsigned char *)"E");Lcd_printf(12, 3, FONT_1X, carrage.Wheel_3.Error , 0);}
	if(carrage.Wheel_4.Error>0){Lcd_print(11, 4, FONT_1X,(unsigned char *)"E");Lcd_printf(12, 4, FONT_1X, carrage.Wheel_4.Error , 0);}
		
	switch(activity.Cursor){
		case(ERRORS_WHEEL1):LcdGotoXY(0,1);LcdChr_full(0x9B);break;
		case(ERRORS_WHEEL2):LcdGotoXY(0,2);LcdChr_full(0x9B);break;
		case(ERRORS_WHEEL3):LcdGotoXY(0,3);LcdChr_full(0x9B);break;
		case(ERRORS_WHEEL4):LcdGotoXY(0,4);LcdChr_full(0x9B);break;
		case(ERRORS_RESET):LcdGotoXY(0,5);LcdChr_full(0x9B);break;
		case(ERRORS_EXIT):LcdGotoXY(7,5);LcdChr_full(0x9B);break;
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

void Screen::PrintTitle(Activity &activity, Carrage &carrage){
	if(activity.Cursor < PARKING_SAVE){
		Lcd_print(5, 0, FONT_1X,(unsigned char *)"МЕНЮ");
		Lcd_print(2, 1, FONT_1X,(unsigned char *)"Сохранить");
		Lcd_print(2, 2, FONT_1X,(unsigned char *)"Установить");
		Lcd_print(2, 3, FONT_1X,(unsigned char *)"Настройки");
		Lcd_print(2, 4, FONT_1X,(unsigned char *)"Выход");
	}else if(activity.Cursor < PARKING_SET){
		Lcd_print(3, 0, FONT_1X,(unsigned char *)"Сохранить");
		Lcd_print(2, 1, FONT_1X,(unsigned char *)"Парковка");
		Lcd_print(2, 2, FONT_1X,(unsigned char *)"Нижнее поз.");
		Lcd_print(2, 3, FONT_1X,(unsigned char *)"Верхняя поз.");
		Lcd_print(2, 4, FONT_1X,(unsigned char *)"Выход");
	}else if (activity.Cursor < SETTINGS_TUNING ){
		Lcd_print(3, 0, FONT_1X,(unsigned char *)"Установить");
		Lcd_print(2, 1, FONT_1X,(unsigned char *)"Парковка");
		Lcd_print(2, 2, FONT_1X,(unsigned char *)"Нижнее поз.");
		Lcd_print(2, 3, FONT_1X,(unsigned char *)"Верхняя поз.");
		Lcd_print(2, 4, FONT_1X,(unsigned char *)"Выход");
	}else{
		Lcd_print(3, 0, FONT_1X,(unsigned char *)"Настройки");
		Lcd_print(2, 1, FONT_1X,(unsigned char *)"Калибровка");
		Lcd_print(2, 2, FONT_1X,(unsigned char *)"Ограничения");
		Lcd_print(2, 3, FONT_1X,(unsigned char *)"Диагностика");
		Lcd_print(2, 4, FONT_1X,(unsigned char *)"Ошибки");
		Lcd_print(2, 5, FONT_1X,(unsigned char *)"Выход");
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
	Draw_Wheel(carrage.Wheel_1);
	Draw_Wheel(carrage.Wheel_2);
	Draw_Wheel(carrage.Wheel_3);
	Draw_Wheel(carrage.Wheel_4);
}

void Screen::Draw_Wheel(Wheel wheel){
	int i;
	int pos_x;
	int pos_y;
	int hight_pos_x;
	int hight_pos_y;
	int n = wheel.number;
	int Char_wheel[6];
	//get position
	switch(n){
		case 1:pos_x  = 3;pos_y = 0; hight_pos_x = 0; hight_pos_y = 1 ; break;
		case 2:pos_x  = 9;pos_y = 0; hight_pos_x = 11; hight_pos_y = 1 ;break;
		case 3:pos_x  = 9;pos_y = 3; hight_pos_x = 11; hight_pos_y = 4 ;break;
		case 4:pos_x  = 3;pos_y = 3; hight_pos_x = 0; hight_pos_y = 4 ;break;
	}
	//get char of wheel
	if(wheel.malfuction){
		Char_wheel[0] = 0x8C;
		Char_wheel[1] = 0x8D;
		Char_wheel[2] = 0x8E;
		Char_wheel[3] = 0x8F;
		Char_wheel[4] = 0x90;
		Char_wheel[5] = 0x91;
	} else if (wheel.selected){
		Char_wheel[0] = 0x80;
		Char_wheel[1] = 0x81;
		Char_wheel[2] = 0x82;
		Char_wheel[3] = 0x83;
		Char_wheel[4] = 0x84;
		Char_wheel[5] = 0x85;
	} else {
		Char_wheel[0] = 0x86;
		Char_wheel[1] = 0x87;
		Char_wheel[2] = 0x88;
		Char_wheel[3] = 0x89;
		Char_wheel[4] = 0x8A;
		Char_wheel[5] = 0x8B;
	}

	//draw wheel 2 symbols for cycle 
	for ( i = 0; i <= 4; i = i + 2 ){
		LcdGotoXY(pos_x, pos_y);
		LcdChr_full(Char_wheel[i]);
		LcdGotoXY(pos_x + 1, pos_y);
		LcdChr_full(Char_wheel[i+1]); 
		pos_y ++;
	}
	//print hight wheel	
	float hight = wheel.get_hight();	
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
		case(SAVE):LcdGotoXY(0,1);LcdChr_full(0x9B);break;
		case(SETPOSITION):LcdGotoXY(0,2);LcdChr_full(0x9B);break;
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
		case(SETTINGS_EXIT):LcdGotoXY(0,5);LcdChr_full(0x9B);break;
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
	Lcd_print(2, 2, FONT_1X,(unsigned char *)"Сохранено...");
	
}