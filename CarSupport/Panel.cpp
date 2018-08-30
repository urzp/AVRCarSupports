/* 
* Panel.cpp
*
* Created: 14.08.2018 12:00:19
* Author: user
*/
const int B_OK = 0;
const int B_UP = 1;
const int B_DOWN = 2;
const int B_LEFT = 3;
const int B_RIGHT = 4;
const int B_NOTHING = -1;

#include "Panel.h"

// default constructor
Panel::Panel()
{
} 

void Panel::Init(Button ok, Button up, Button down, Button left, Button rigit ){
	bat_ok = ok;
	bat_up = up;
	bat_down = down;
	bat_right = rigit;
	bat_left = left;
}

int Panel::Pressed(int debounse){
	if (bat_ok.Pressed(debounse)){ return B_OK ;}
	if (bat_up.Pressed(debounse)){ return  B_UP;}
	if (bat_down.Pressed(debounse)){ return B_DOWN ;}
	if (bat_right.Pressed(debounse)){ return B_RIGHT;}
	if (bat_left.Pressed(debounse)) {return B_LEFT;}	
	return B_NOTHING ;
}