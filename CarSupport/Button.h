/* 
* Button.h
*
* Created: 14.08.2018 11:50:11
* Author: user
*/



#ifndef __BUTTON_H__
#define __BUTTON_H__


class Button
{
	//variables
	public:
		char _port;
		int _pin;
	protected:
	private:
	
	

	//functions
	public:
	Button();
		void Init(char port, int pin);
		bool Pressed(int debounce);
	protected:
	private:

}; //Button

#endif //__BUTTON_H__
