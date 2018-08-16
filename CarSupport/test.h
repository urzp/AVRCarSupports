/*
 * test.h
 *
 * Created: 15.08.2018 10:12:31
 *  Author: user
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "Button.h"
#include "Panel.h"
#include "Output.h"
#include "LCDn5110.h"

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
		//Lcd_prints для вывода статичных данных
		Lcd_prints(0, 0, FONT_1X,(unsigned char *)PSTR("Привет!"));
		//Lcd_print для вывода из переменной
		Lcd_print(0, 1, FONT_1X,(unsigned char *)s_data);
		//Lcd_printf для вывода дробного числа (преобразование float в string)
		//2 - число знаков после зяпятой
		Lcd_printf(0, 2, FONT_1X, f_data, 2);

		//передадим данные
		Lcd_update();
}

#endif /* TEST_H_ */