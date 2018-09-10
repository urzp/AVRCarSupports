/* 
* Panel.h
*
* Created: 14.08.2018 12:00:19
* Author: user
*/





#ifndef __PANEL1_H__
#define __PANEL1_H__
#include "Button.h"

class Panel
{
	//variables
	public:
		Button bat_ok;
		Button bat_up;
		Button bat_down;
		Button bat_left;
		Button bat_right;
	protected:
	private:

	//functions
	public:
		Panel();
		void Init(Button &ok, Button &up, Button &down, Button &left, Button &rigit);
		int Pressed(int debounse);
	protected:
	private:


}; //Panel1

#endif //__PANEL1_H__
