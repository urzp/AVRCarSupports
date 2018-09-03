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
#include <avr/eeprom.h>
#include <stdio.h>
#include "Button.h"
#include "Panel.h"
#include "Output.h"
#include "test.h"
#include "Initialisation.h"
#include "LCDn5110.h"
#include "Wheel.h"
#include "Carrage.h"
#include "Screen.h"
#include "Activity.h"


#define I2C_ADR_PCF8574 0x27




int main(void)
{	

	Initialisation();
	screen.Render(activity, carrage);

	
    while (1) 
    {	
		
		activity.Cursor_Action(panel, carrage);
		screen.Render(activity, carrage);
		//test_out_timer(rightButton,suppot_1);
		//test_Out_Set(downButton,suppot_1);
		//test_panel(panel,suppot_1);
		//test_LCD_clear(panel);
		
    }
}

