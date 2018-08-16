/*
 * Initialisation.h
 *
 * Created: 15.08.2018 11:32:41
 *  Author: user
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "Button.h"
#include "Panel.h"
#include "Output.h"
#include "test.h"
#include "LCDn5110.h"


#ifndef INITIALISATION_H_
#define INITIALISATION_H_

Button okButton;
Button upButton;
Button downButton;
Button leftButton;
Button rightButton;

Panel panel;

Output suppot_1;


void Initialisation(){
	

	
	okButton.Init('D', 1);
	upButton.Init('D', 2);
	downButton.Init('D', 3);
	leftButton.Init('D',4);
	rightButton.Init('D',5);
	
	panel.Init(okButton,upButton,downButton,leftButton,rightButton);
	
	suppot_1.Init('D', 0);
	
	Lcd_init();
	
}





#endif /* INITIALISATION_H_ */