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
#include "test.h"
#include "Initialisation.h"
#include "LCDn5110.h"
#include "Wheel.h"
#include "Carrage.h"
#include "Screen.h"
#include "Activity.h"
#include "EEMEM.h"



int main(void)
{		
	Initialisation();
    while (1) 
    {		
		activity.Cursor_Action(panel, carrage);
		screen.Render(activity, carrage);
		IFCarrageSaveStateToEEMEM(activity.SavePosition);
		IFCarrageSetStateToEEMEM(activity.SavePosition);
		SettingsSave(activity.SettingsSaveFlag);
    }
}

