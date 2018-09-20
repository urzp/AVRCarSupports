/* 
* Wheel.cpp
*
* Created: 17.08.2018 14:01:04
* Author: user
*/

const int NORMAL=0;
const int UP=1;
const int DOWN=2;

#include "Wheel.h"



// default constructor
Wheel::Wheel()
{
} //Wheel

void Wheel::Init(int _number){
	sensorWheels.Init();
	number =  _number;
	maxHight = 5.00;
	minHight = 0.01;
	oldHigit = get_hight();
	countToMalfunction = 0;
	Error = 0;
}

float Wheel::get_hight(){
	hight = sensorWheels.getParams(number);
	return hight;
}

void Wheel::initialHight(){
	get_hight();
	sethight = hight;
}

int Wheel::takeDerection(){	
	if (!selected) return NORMAL;
	if (malfuction) return 0;
	hight = get_hight();
	if(sethight==0){sethight=0.01;}//correcting
	diff = sethight*300 - hight*300;
	step = diff;
	_diff = diff;
	adjusted = false;
	if (_diff < 0){ step = (0 - step) ; return DOWN;}
	if (_diff > 0){ ; return UP;}
	step = 0;
	adjusted = true;
	return NORMAL;
}

bool Wheel::Check(){
	checkhight = hight;
	hight = get_hight();
	if (checkhight == hight){
		malfuction = true;
		Error = 1;
		return false;
	} else{
		malfuction = false;
		return true;
	}
}

bool Wheel::ControlMalfinction(int countToMalfunctionLimit ){
	if(!move&&malfuction==false){
		countToMalfunction++;
		if(countToMalfunction>countToMalfunctionLimit){
			malfuction = true;
			Error = 3;
			return true;
		}
	}else{
		countToMalfunction=0;
		return false;
	}
	return false;
}

void Wheel::SetLimitsSetHight(){
	if(sethight>=maxHight){sethight=maxHight;}
	if(sethight<=minHight){sethight=minHight;}
}

bool Wheel::IsChanchedHight(){
	if(oldHigit != get_hight()){
		oldHigit = hight;
		move = true;
		return true;
	}else{
		move = false;
		return false;		
	}
}

void Wheel::Select(){
	selected = !selected;
}

bool Wheel::Up(float step){
	if (!selected){return false;}
	sethight += step;
	if (sethight > maxHight){sethight = maxHight;flagGetLimits=true;}
	return true;
}

bool Wheel::Down(float step){
	if (!selected){return false;}
	sethight -= step;
	if (sethight < minHight){sethight = minHight;flagGetLimits=true;}
	return true;
}

bool Wheel::selected_malfinction(){
	if(selected&&malfuction){return true;}
	else{return false;}
}


bool Wheel::MalFunctionAndnotselected(){
	if(malfuction){return true;}
	if(selected){return true;}
	return false;
}

bool Wheel::CheckGetLimit(){
	if(hight<=minHight||hight>=maxHight){
		flagGetLimits=true;
		return true;
	}else{return false;}
}