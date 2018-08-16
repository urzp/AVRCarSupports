/* 
* Panel.cpp
*
* Created: 14.08.2018 12:00:19
* Author: user
*/


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

char Panel::Pressed(int debounse){
	if (bat_ok.Pressed(debounse)){ return 'O';}
	if (bat_up.Pressed(debounse)){ return 'U';}
	if (bat_down.Pressed(debounse)){ return 'D';}
	if (bat_right.Pressed(debounse)){ return 'R';}
	if (bat_left.Pressed(debounse)) {return 'L';}	
	return 'N';
}