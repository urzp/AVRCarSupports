/*
 * CarSupport.cpp
 *
 * Created: 14.08.2018 11:49:17
 * Author : user
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "Button.h"
#include "Panel.h"
#include "Output.h"
#include "test.h"
#include "Initialisation.h"
#include "LCDn5110.h"



int main(void)
{	
	
	
	Initialisation();
	
	test_LCD();
	

	
    while (1) 
    {
		
		//test_out_timer(rightButton,suppot_1);
		//test_Out_Set(downButton,suppot_1);
		//test_panel(panel,suppot_1);
		//test_LCD_clear(panel);
		
    }
}

