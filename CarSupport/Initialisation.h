/*
 * Initialisation.h
 *
 * Created: 15.08.2018 11:32:41
 *  Author: user
 */ 



#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include "Button.h"
#include "Panel.h"
#include "test.h"
#include "LCDn5110.h"
#include "Wheel.h"
#include "Carrage.h"
#include "Screen.h"
#include "Activity.h"


#define I2C_ADR_PCF8574 0x27

#ifndef INITIALISATION_H_
#define INITIALISATION_H_

float Tunning_rate EEMEM;
float CarrajeMin EEMEM;
float CarrajeMax EEMEM;
float PositionsStates[3][5] EEMEM;

Button okButton;
Button upButton;
Button downButton;
Button leftButton;
Button rightButton;

Wheel wheel_lf;
Wheel wheel_rf;
Wheel wheel_rr;
Wheel wheel_lr;

Carrage carrage;
Panel panel;
Screen screen;
Activity activity;


void Initialisation(){
	okButton.Init('D', 2);
	upButton.Init('D', 3);
	downButton.Init('D', 4);
	leftButton.Init('D',5);
	rightButton.Init('D',6);
	panel.Init(okButton,upButton,downButton,leftButton,rightButton);
	Lcd_init();
	wheel_lf.Init(1);
	wheel_rf.Init(2);
	wheel_rr.Init(3);
	wheel_lr.Init(4);
	carrage.Init(wheel_lf,wheel_rf,wheel_rr,wheel_lr);
	activity.Init();
	screen.Render(activity, carrage);
	
	// initilisation null EEMEM
	if(!(eeprom_read_float(&Tunning_rate)>0||eeprom_read_float(&Tunning_rate)<3)){
		eeprom_write_float (&Tunning_rate, 1.00);
	}
	carrage.tunning = eeprom_read_float(&Tunning_rate);
	
	if (!(eeprom_read_float(&CarrajeMin)>=0||eeprom_read_float(&CarrajeMin)<=5)){
		eeprom_write_float (&CarrajeMin, 0.00);
	}
	carrage.min =  eeprom_read_float(&CarrajeMin);
	
	if (!(eeprom_read_float(&CarrajeMax)>=0||eeprom_read_float(&CarrajeMax)<=5)){
		eeprom_write_float (&CarrajeMax, 5.00);
	}
	carrage.max =  eeprom_read_float(&CarrajeMax);
	
	carrage.SetLimits();
}

#endif /* INITIALISATION_H_ */