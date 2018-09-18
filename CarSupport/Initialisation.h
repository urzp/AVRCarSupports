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
uint8_t OnOffMalfunction EEMEM;
float countToMalfunctionLimit EEMEM;
float PositionsStates[3][5] EEMEM;

Carrage carrage;
Panel panel;
Screen screen;
Activity activity;


void Initialisation(){
	Lcd_init();
	panel.Init();
	carrage.Init();
	activity.Init(carrage);
	
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
	
	if (!(eeprom_read_float(&countToMalfunctionLimit)>=0||eeprom_read_float(&countToMalfunctionLimit)<=999)){
		eeprom_write_float (&countToMalfunctionLimit, 50.0); 
		eeprom_write_byte(&OnOffMalfunction,true);
		
	}
	carrage.countToMalfunctionLimit = eeprom_read_float(&countToMalfunctionLimit);
	carrage.OnOffMalfunction = eeprom_read_byte(&OnOffMalfunction);
}

#endif /* INITIALISATION_H_ */