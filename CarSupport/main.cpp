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

float PositionsStates[3][5] EEMEM;

void IFCarrageSaveStateToEEMEM( int position){
	
	if(activity.SaveFlag){
		eeprom_write_float (&PositionsStates[position][1], carrage.Wheel_1.get_hight());
		eeprom_write_float (&PositionsStates[position][2], carrage.Wheel_2.get_hight());
		eeprom_write_float (&PositionsStates[position][3], carrage.Wheel_3.get_hight());
		eeprom_write_float (&PositionsStates[position][4], carrage.Wheel_4.get_hight());

	}
	activity.SaveFlag = false;
}

void IFCarrageSetStateToEEMEM( int position){
	if(activity.SetFlag){
		carrage.Wheel_1.selected = true;
		carrage.Wheel_2.selected = true;
		carrage.Wheel_3.selected = true;
		carrage.Wheel_4.selected = true;
		carrage.Wheel_1.sethight=eeprom_read_float(&PositionsStates[position][1]);
		carrage.Wheel_2.sethight=eeprom_read_float(&PositionsStates[position][2]);
		carrage.Wheel_3.sethight=eeprom_read_float(&PositionsStates[position][3]);
		carrage.Wheel_4.sethight=eeprom_read_float(&PositionsStates[position][4]);
		screen.Render(activity, carrage);
		carrage.Ajustment();
	}
	activity.SetFlag = false;
}

int main(void)
{	

	Initialisation();
	screen.Render(activity, carrage);
	
    while (1) 
    {	
		
		activity.Cursor_Action(panel, carrage);
		screen.Render(activity, carrage);
		IFCarrageSaveStateToEEMEM(activity.SavePosition);
		IFCarrageSetStateToEEMEM(activity.SavePosition);
    }
}

