/* 
* Weel.h
*
* Created: 17.08.2018 14:01:05
* Author: user
*/


#ifndef __WHEEL_H__
#define __WHEEL_H__


class Wheel
{
//variables
public:
	int number;
	float hight;
	bool selected;
	bool malfuction;
	bool adjusted;
protected:
private:

//functions
public:
	Wheel();
	void Init(int _number);
	float get_hight();
	void set_hight();

protected:
private:


}; //Wheel

#endif //__WhEEL_H__
