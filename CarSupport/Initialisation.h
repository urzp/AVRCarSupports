/*
 * Initialisation.h
 *
 * Created: 15.08.2018 11:32:41
 *  Author: user
 */ 




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




#ifndef INITIALISATION_H_
#define INITIALISATION_H_

byte FierstStart EEMEM;
float Tunning_rate EEMEM;
float Inertion_rate EEMEM;
float Step_force_move EEMEM;
float Accuracy EEMEM;
float CarrajeMin EEMEM;
float CarrajeMax EEMEM;
byte LCD_contrast EEMEM;
uint8_t OnOffMalfunction EEMEM;
float countToMalfunctionLimit EEMEM;
float PositionsStates[3][5] EEMEM;



Carrage carrage;
Panel panel;
Screen screen;
Activity activity;


void Initialisation(){


	panel.Init();
	carrage.Init();
	activity.Init(carrage);
	
	if(!(eeprom_read_byte(&FierstStart) == 1)){
		eeprom_write_float (&Tunning_rate, 0.50);
		eeprom_write_float (&Inertion_rate, 50);
		eeprom_write_float (&Step_force_move, 10);
		eeprom_write_float (&Accuracy, 0);
		eeprom_write_float (&CarrajeMin, 0.10);
		eeprom_write_float (&CarrajeMax, 4.90);
		eeprom_write_byte(&LCD_contrast, 0xBF);
		eeprom_write_byte(&FierstStart, 1);
	}
	
	// initilisation null EEMEM
	//if(!(eeprom_read_float(&Tunning_rate)>0||eeprom_read_float(&Tunning_rate)<3)){
		//eeprom_write_float (&Tunning_rate, 1.00);
	//}

	
	//if (!(eeprom_read_float(&CarrajeMin)>=0||eeprom_read_float(&CarrajeMin)<=5)){
		//eeprom_write_float (&CarrajeMin, 0.00);
	//}
	
	
	//if (!(eeprom_read_float(&CarrajeMax)>=0||eeprom_read_float(&CarrajeMax)<=5)){
		//eeprom_write_float (&CarrajeMax, 5.00);
	//}
	
	carrage.tunning = eeprom_read_float(&Tunning_rate);
	carrage.inertion = eeprom_read_float(&Inertion_rate);
	carrage.step_force_move = eeprom_read_float(&Step_force_move);
	carrage.accuracy = eeprom_read_float(&Accuracy);
	carrage.min =  eeprom_read_float(&CarrajeMin);
	carrage.max =  eeprom_read_float(&CarrajeMax);
	carrage.LCD_contrast = eeprom_read_byte(&LCD_contrast);
	
	carrage.SetLimits();
	
	if (!(eeprom_read_float(&countToMalfunctionLimit)>=0||eeprom_read_float(&countToMalfunctionLimit)<=999)){
		eeprom_write_float (&countToMalfunctionLimit, 50.0); 
		eeprom_write_byte(&OnOffMalfunction,true);
		
	}
	carrage.countToMalfunctionLimit = eeprom_read_float(&countToMalfunctionLimit);
	carrage.OnOffMalfunction = eeprom_read_byte(&OnOffMalfunction);
	
	Lcd_init(carrage.LCD_contrast);
}

#endif /* INITIALISATION_H_ */