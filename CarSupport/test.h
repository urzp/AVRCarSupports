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
	
		float f_data = 14.43; //�������
		int i_data = 123; //�����
		char s_data[] = "Hello"; //������
		
		Lcd_clear();
		//Lcd_prints ��� ������ ��������� ������
		Lcd_prints(0, 0, FONT_1X,(unsigned char *)PSTR("������!"));
		//Lcd_print ��� ������ �� ����������
		Lcd_print(0, 1, FONT_1X,(unsigned char *)s_data);
		//Lcd_printf ��� ������ �������� ����� (�������������� float � string)
		//2 - ����� ������ ����� �������
		Lcd_printf(0, 2, FONT_1X, f_data, 2);

		//��������� ������
		Lcd_update();
}

#endif /* TEST_H_ */