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
	
	DDRB = 0xFF;
	DDRD = 0xFF;
	
	okButton.Init('B', 0);
	upButton.Init('B', 1);
	downButton.Init('B', 2);
	leftButton.Init('B',3);
	rightButton.Init('B',4);
	
	panel.Init(okButton,upButton,downButton,leftButton,rightButton);
	
	suppot_1.Init('D', 1);
	
}





#endif /* INITIALISATION_H_ */