/* 
* Main_Screen.cpp
*
* Created: 21.08.2018 12:04:23
* Author: user
*/


#include "Screen.h"

const int MENU = 0;
const int LEFTUP = 1;
const int RIGHTUP = 2;
const int RIGHTDOWN = 3;
const int LEFTDOWN = 4;
const int ADJUST = 5;

const int SCREEN_MAIN = 0;
const int SCREEN_MENU = 1;
const int SCREEN_ADJUST = 2;

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

const int SETTINGS_SET = 12;
const int TUNING = 13;
const int LIMITS = 14;
const int TEST_MALFACTION = 15;
const int RESET_ERRORS = 16;


// default constructor
Screen::Screen()
{
} //Main_Screen

void Screen::Init(){
	 
}

void Screen::Render(Activity &_activity, Carrage &_carrage){
	activity = _activity;
	carrage = _carrage;
	Lcd_clear();
	switch(activity.Statment){
		case(SCREEN_MAIN):Render_main();break;
		case(SCREEN_ADJUST):Render_main();break;
		case(SCREEN_MENU):Render_menu();break;
	}
	Lcd_update();
}


//******************
//*  MENU SCREEN  *
//*****************

void Screen::Render_menu(){
	PrintTitle();

	Draw_CursorMenuScreen();	
}

void Screen::PrintTitle(){
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
	}else if (activity.Cursor < SETTINGS_SET ){
		Lcd_print(3, 0, FONT_1X,(unsigned char *)"Установить");
		Lcd_print(2, 1, FONT_1X,(unsigned char *)"Парковка");
		Lcd_print(2, 2, FONT_1X,(unsigned char *)"Нижнее поз.");
		Lcd_print(2, 3, FONT_1X,(unsigned char *)"Верхняя поз.");
		Lcd_print(2, 4, FONT_1X,(unsigned char *)"Выход");
	}else{
		Lcd_print(3, 0, FONT_1X,(unsigned char *)"Настройки");
		Lcd_print(2, 1, FONT_1X,(unsigned char *)"Калибровка");
		Lcd_print(2, 2, FONT_1X,(unsigned char *)"Ограничения");
		Lcd_print(2, 3, FONT_1X,(unsigned char *)"Тест исп-ти");
		Lcd_print(2, 4, FONT_1X,(unsigned char *)"Сброс ошибок");
		Lcd_print(2, 5, FONT_1X,(unsigned char *)"Выход");
	}
	
	
}

void Screen::PtintItems(){

}

void Screen::Draw_CursorMenuScreen(){
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
	}
}


//******************
//*  MAIN SCREEN  *
//*****************

void Screen::Render_main(){	
	Draw_icon_menu();
	Draw_Carrage();
	Draw_adjustment_carrage();
	Draw_CursorMainScreen();	
	Print_Step_Value();
}


void Screen::Draw_icon_menu(){
	LcdGotoXY(6,0);
	LcdChr_full(0x9E);
	LcdGotoXY(7,0);
	LcdChr_full(0x9F);
}

void Screen::Draw_Carrage(){
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

void Screen::Draw_adjustment_carrage(){
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

bool Screen::Draw_CursorMainScreen(){
	
	if (activity.Statment == SCREEN_ADJUST ){return false;};
	int Char_cursor[2];
	int position = activity.Cursor;
	
	switch(position){
		case(MENU):Char_cursor[0]=0x9C;Char_cursor[1]=0x9D;break;
		case(ADJUST):Char_cursor[0]=0x9C;Char_cursor[1]=0x9D;break;
		case(LEFTUP):Char_cursor[0]=0x9A;break;
		case(LEFTDOWN):Char_cursor[0]=0x9A;break;
		case(RIGHTUP):Char_cursor[0]=0x9B;break;
		case(RIGHTDOWN):Char_cursor[0]=0x9B;break;
	}
	
	switch(position){
		case(MENU):LcdGotoXY(6,1);LcdChr_full(Char_cursor[0]);LcdChr_full(Char_cursor[1]);break;
		case(ADJUST):LcdGotoXY(6,4);LcdChr_full(Char_cursor[0]);LcdChr_full(Char_cursor[1]);break;
		case(LEFTUP):LcdGotoXY(5,1);LcdChr_full(Char_cursor[0]);break;
		case(LEFTDOWN):LcdGotoXY(5,4);LcdChr_full(Char_cursor[0]);break;
		case(RIGHTUP):LcdGotoXY(8,1);LcdChr_full(Char_cursor[0]);break;
		case(RIGHTDOWN):LcdGotoXY(8,4);LcdChr_full(Char_cursor[0]);break;
	}	
	
}

bool Screen::Print_Step_Value(){
	if (activity.Statment != SCREEN_ADJUST ){return false;}
	float step = activity.get_val_step();
	Lcd_printf(5, 1, FONT_1X, step , 2);
	//
	LcdGotoXY(5 , 4 );
	LcdStepLevel(activity.Step);
	
}