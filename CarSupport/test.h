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

#endif /* TEST_H_ */