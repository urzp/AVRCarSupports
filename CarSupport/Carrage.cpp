/* 
* Carrage.cpp
*
* Created: 20.08.2018 8:59:09
* Author: user
*/



#include "Carrage.h"


const int NORMAL=0;
const int UP=1;
const int DOWN=2;

// default constructor
Carrage::Carrage()
{
} //Carrage

void Carrage::Init(Wheel _Wheel_1, Wheel _Wheel_2, Wheel _Wheel_3, Wheel _Wheel_4){
	Wheel_1 = _Wheel_1;
	Wheel_2 = _Wheel_2;
	Wheel_3 = _Wheel_3;
	Wheel_4 = _Wheel_4;
	support.Init();
	_step =1;
}

void Carrage::beforeAdjast(){
	Wheel_1.initialHight();
	Wheel_2.initialHight();
	Wheel_3.initialHight();
	Wheel_4.initialHight();
}

void Carrage::Up(float step){
	Wheel_1.Up(step);
	Wheel_2.Up(step);
	Wheel_3.Up(step);
	Wheel_4.Up(step);
	Ajustment();
}

void Carrage::Down(float step){
	Wheel_1.Down(step);
	Wheel_2.Down(step);
	Wheel_3.Down(step);
	Wheel_4.Down(step);
	Ajustment();
}

void Carrage::Ajustment(){
	
	finish=1;
	int i=0;
	while(finish>0){
		derWheel[1] = Wheel_1.takeDerection();
		Fast_print_LSD_hight(Wheel_1);
		derWheel[2] = Wheel_2.takeDerection();
		Fast_print_LSD_hight(Wheel_2);
		derWheel[3] = Wheel_3.takeDerection();
		Fast_print_LSD_hight(Wheel_3);
		derWheel[4] = Wheel_4.takeDerection();
		Fast_print_LSD_hight(Wheel_4);
		
		finish = derWheel[1] + derWheel[2] + derWheel[3] + derWheel[4];
		support.Adjast(getStep() ,derWheel[1], derWheel[2] ,derWheel[3] ,derWheel[4] );	
		i++;
	}

}


int Carrage::getStep(){
	int step = 0;
	int i;
	sort_array[0] = Wheel_1.step;
	sort_array[1] = Wheel_2.step;
	sort_array[2] = Wheel_3.step;
	sort_array[3] = Wheel_4.step;
	i = 0;
	while(i<4){
		if (sort_array[i]>0){step = sort_array[i];i=5;}
		i++;
	};
	
	if (step == 0){return 0;};
		
	i = 0;	
	while(i<4){
		if ( sort_array[i] > 0){
			if ( step > sort_array[i]){
				step = sort_array[i];
			};
		};
		i++;
	}
	//step = sort_array[0];
	step=step;
	if (step>50){step = 50;}
	return step;
} 

void Carrage::Fast_print_LSD_hight(Wheel wheel){
	int hight_pos_x;
	int hight_pos_y;
	int n = wheel.number;
	int Char_wheel[6];
	//get position
	switch(n){
		case 1:hight_pos_x = 0; hight_pos_y = 1 ; break;
		case 2:hight_pos_x = 11; hight_pos_y = 1 ;break;
		case 3:hight_pos_x = 11; hight_pos_y = 4 ;break;
		case 4:hight_pos_x = 0; hight_pos_y = 4 ;break;
	}
	int hight = 100*wheel.get_hight();
	Lcd_printf(hight_pos_x, hight_pos_y, FONT_1X, hight, 0);
	Lcd_update();
}