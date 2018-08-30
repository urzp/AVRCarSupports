/*
 * CarSupport.cpp
 *
 * Created: 14.08.2018 11:49:17
 * Author : user
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include "Button.h"
#include "Panel.h"
#include "Output.h"
#include "test.h"
#include "Initialisation.h"
#include "LCDn5110.h"
#include "Wheel.h"
#include "Carrage.h"
#include "Main_Screen.h"
#include "Activity.h"

#define I2C_ADR_PCF8574 0x27




int main(void)
{	

	Initialisation();
	mainScreen.Render(activity, carrage);

	
    while (1) 
    {	
		
		activity.Cursor_Action(panel, carrage);
		mainScreen.Render(activity, carrage);
		//test_out_timer(rightButton,suppot_1);
		//test_Out_Set(downButton,suppot_1);
		//test_panel(panel,suppot_1);
		//test_LCD_clear(panel);
		
    }
}

