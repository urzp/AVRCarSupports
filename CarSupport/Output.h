/* 
* Output.h
*
* Created: 14.08.2018 11:58:09
* Author: user
*/


#ifndef __OUTPUT_H__
#define __OUTPUT_H__


class Output
{
	//variables
	public:
	protected:
	private:
	char _port;
	int _pin;

	//functions
	public:
	Output();
	void Init(char port, int pin);
	void Set(bool level);
	void SetOnTime(bool level, int t);
	protected:
	private:

};

#endif
