/* 
* SensorsWheels.h
*
* Created: 28.08.2018 12:50:58
* Author: user
*/
#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef __SENSORSWHEELS_H__
#define __SENSORSWHEELS_H__


class SensorsWheels
{
//variables
public:
	
protected:
private:
	bool ready;

//functions
public:
	SensorsWheels();
	void Init();
	float getParams(int Input_number);
protected:
private:


}; //SensorsWheels

#endif //__SENSORSWHEELS_H__
