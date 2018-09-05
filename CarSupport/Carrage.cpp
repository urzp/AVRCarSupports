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

const int PARKING = 0;
const int HIGHTPOSITION = 1;
const int LOWPOSITION = 2;

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
	chechAll();
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
	if (chechWheelsBefore()){
		while(finish>0&&i<100){
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
	
		if(i>=100){
			if(derWheel[1]>0){Wheel_1.malfuction = true;}
			if(derWheel[2]>0){Wheel_2.malfuction = true;}
			if(derWheel[3]>0){Wheel_3.malfuction = true;}
			if(derWheel[4]>0){Wheel_4.malfuction = true;}
		}
	}
}

bool Carrage::chechWheelsBefore(){
		derWheel[1] = Wheel_1.takeDerection();
		Fast_print_LSD_hight(Wheel_1);
		derWheel[2] = Wheel_2.takeDerection();
		Fast_print_LSD_hight(Wheel_2);
		derWheel[3] = Wheel_3.takeDerection();
		Fast_print_LSD_hight(Wheel_3);
		derWheel[4] = Wheel_4.takeDerection();
		Fast_print_LSD_hight(Wheel_4);
		support.Adjast(10 ,derWheel[1], derWheel[2] ,derWheel[3] ,derWheel[4] );
		if	(derWheel[1]>0){checked[1]=Wheel_1.Check();}else{checked[1]=true;}
		if	(derWheel[2]>0){checked[2]=Wheel_2.Check();}else{checked[2]=true;}
		if	(derWheel[3]>0){checked[3]=Wheel_3.Check();}else{checked[3]=true;}
		if	(derWheel[4]>0){checked[4]=Wheel_4.Check();}else{checked[4]=true;}	
		if  (checked[1]&&checked[2]&&checked[3]&&checked[4]){return true;}else{return false;}					
}

bool Carrage::chechAll(){
	Wheel_1.get_hight();
	Wheel_2.get_hight();
	Wheel_3.get_hight();
	Wheel_4.get_hight();
	support.Adjast(10 ,1, 1 ,1 ,1 );
	checked[1]=Wheel_1.Check();	
	checked[2]=Wheel_2.Check();
	checked[3]=Wheel_3.Check();
	checked[4]=Wheel_4.Check();
	support.Adjast(10 ,2, 2 ,2 ,2 );
	if  (checked[1]&&checked[2]&&checked[3]&&checked[4]){return true;}else{return false;}
	
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
	float hight = wheel.get_hight();
	Lcd_printf2(hight_pos_x, hight_pos_y, FONT_1X, hight, 2);
	Lcd_update();
}

void Carrage::ControlMalfinction(){
	Wheel_1.IsChanchedHight();
	Wheel_2.IsChanchedHight();
	Wheel_3.IsChanchedHight();
	Wheel_4.IsChanchedHight();
	bool caragemove = (Wheel_1.move|Wheel_2.move|Wheel_3.move|Wheel_4.move);
	if (caragemove){
		Wheel_1.ControlMalfinction();
		Wheel_2.ControlMalfinction();
		Wheel_3.ControlMalfinction();
		Wheel_4.ControlMalfinction();
	}

}