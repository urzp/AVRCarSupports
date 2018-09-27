/*
 * test.h
 *
 * Created: 15.08.2018 10:12:31
 *  Author: user
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include "Button.h"
#include "Panel.h"
#include "Output.h"
#include "LCDn5110.h"
#include "Carrage.h"
#include "Wheel.h"


#ifndef TEST_H_
#define TEST_H_


void test_out_timer(Button button, Output out){
	if (button.Pressed(10)){
		out.SetOnTime(true, 100);
	};
}


void test_Out_Set(Button button, Output out){
	if (button.Pressed(10)){
		out.Set(true);
		}else{
		out.Set(false);
	};
};

void test_panel(Panel panel, Output out){
	char Pressed_btn = 'N';
	Pressed_btn = panel.Pressed(10);
	
	if (Pressed_btn == 'R'){
		out.SetOnTime(true,10);
		_delay_ms(10);
		out.SetOnTime(true,10);
	}
}

void test_LCD(){
	
		float f_data = 14.43; //дробное
		int i_data = 123; //целое
		char s_data[] = "Hello"; //строка
		
		Lcd_clear();
		LcdGotoXY(0,0);
		LcdChr(FONT_1X,'A');
		LcdGotoXY(1,0);
		LcdChr(FONT_1X,'A');
		//Lcd_prints для вывода статичных данных
		//Lcd_prints(0, 1, FONT_1X,(unsigned char *)PSTR("MAA"));
		////Lcd_print для вывода из переменной
		//Lcd_print(0, 2, FONT_1X,(unsigned char *)s_data);
		////Lcd_printf для вывода дробного числа (преобразование float в string)
		////2 - число знаков после зяпятой
		//Lcd_printf(0, 3, FONT_1X, f_data, 2);

		//передадим данные
		Lcd_update();
}

void test_LCD_clear(Panel panel){
	
	if (panel.Pressed(10) == 'R'){
		Lcd_clear();
		Lcd_update();
	}
	
	
}

void test_LCD_weel(){
	
			Lcd_clear();
			LcdGotoXY(3,0);
			LcdChr_full(0x80);
			LcdGotoXY(4,0);
			LcdChr_full(0x81);
			LcdGotoXY(3,1);
			LcdChr_full(0x82);
			LcdGotoXY(4,1);
			LcdChr_full(0x83);
			LcdGotoXY(3,2);
			LcdChr_full(0x84);
			LcdGotoXY(4,2);
			LcdChr_full(0x85);
			

			LcdGotoXY(3,3);
			LcdChr_full(0x86);
			LcdGotoXY(4,3);
			LcdChr_full(0x87);
			LcdGotoXY(3,4);
			LcdChr_full(0x88);
			LcdGotoXY(4,4);
			LcdChr_full(0x89);
			LcdGotoXY(3,5);
			LcdChr_full(0x8A);
			LcdGotoXY(4,5);
			LcdChr_full(0x8B);
			
			LcdGotoXY(9,3);
			LcdChr_full(0x8C);
			LcdGotoXY(10,3);
			LcdChr_full(0x8D);
			LcdGotoXY(9,4);
			LcdChr_full(0x8E);
			LcdGotoXY(10,4);
			LcdChr_full(0x8F);
			LcdGotoXY(9,5);
			LcdChr_full(0x90);
			LcdGotoXY(10,5);
			LcdChr_full(0x91);
			
			LcdGotoXY(6,2);
			LcdChr_full(0x92);
			LcdGotoXY(7,2);
			LcdChr_full(0x93);
			LcdGotoXY(6,3);
			LcdChr_full(0x94);
			LcdGotoXY(7,3);
			LcdChr_full(0x95);
			
			//LcdGotoXY(6,2);
			//LcdChr_full(0x96);
			//LcdGotoXY(7,2);
			//LcdChr_full(0x97);
			//LcdGotoXY(6,3);
			//LcdChr_full(0x98);
			//LcdGotoXY(7,3);
			//LcdChr_full(0x99);
			
			LcdGotoXY(5,1);
			LcdChr_full(0x9A);
			
			LcdGotoXY(8,4);
			LcdChr_full(0x9B);
			
			LcdGotoXY(6,1);
			LcdChr_full(0x9C);
			LcdGotoXY(7,1);
			LcdChr_full(0x9D);			
			
			
			LcdGotoXY(6,0);
			LcdChr_full(0x9E);
			LcdGotoXY(7,0);
			LcdChr_full(0x9F);
			
			Lcd_update();
		
	};


void test_cars_wheel(Carrage carrage){
	
}


#endif /* TEST_H_ */