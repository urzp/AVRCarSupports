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
#include "Wheel.h"
#include "Carrage.h"
#include "Main_Screen.h"
#include "Activity.h"




#ifndef INITIALISATION_H_
#define INITIALISATION_H_

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

Output suppot_1;


Main_Screen mainScreen;

Activity activity;




void Initialisation(){
	
	
	
	okButton.Init('D', 2);
	upButton.Init('D', 3);
	downButton.Init('D', 4);
	leftButton.Init('D',5);
	rightButton.Init('D',6);
	
	panel.Init(okButton,upButton,downButton,leftButton,rightButton);
	
	suppot_1.Init('D', 0);
	
	Lcd_init();
	
	wheel_lf.Init(1);
	wheel_rf.Init(2);
	wheel_rr.Init(3);
	wheel_lr.Init(4);
	
	carrage.Init(wheel_lf,wheel_rf,wheel_rr,wheel_lr);

	
	activity.Init();
	

	
}





#endif /* INITIALISATION_H_ */