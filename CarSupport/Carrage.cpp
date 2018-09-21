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

void Carrage::Init(){
	Wheel_1.Init(1);
	Wheel_2.Init(2);
	Wheel_3.Init(3);
	Wheel_4.Init(4);
	support.Init();
	_step =1;
	chechAll();
}

bool Carrage::IfForseAdjast(){
	
};

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
	ChekGetLimitsHight();
}

void Carrage::Down(float step){
	Wheel_1.Down(step);
	Wheel_2.Down(step);
	Wheel_3.Down(step);
	Wheel_4.Down(step);
	Ajustment();
	ChekGetLimitsLow();
}

void Carrage::ForceUp(){
	if (Wheel_1.selected){derWheel[1]=1;}else{derWheel[1]=0;};
	if (Wheel_2.selected){derWheel[2]=1;}else{derWheel[2]=0;};
	if (Wheel_3.selected){derWheel[3]=1;}else{derWheel[3]=0;};
	if (Wheel_4.selected){derWheel[4]=1;}else{derWheel[4]=0;};
	if(!ChekGetLimitsHight()){support.ForceMove(10,derWheel[1], derWheel[2] ,derWheel[3] ,derWheel[4] );}
}

void Carrage::ForceDown(){
	if (Wheel_1.selected){derWheel[1]=2;}else{derWheel[1]=0;};
	if (Wheel_2.selected){derWheel[2]=2;}else{derWheel[2]=0;};
	if (Wheel_3.selected){derWheel[3]=2;}else{derWheel[3]=0;};
	if (Wheel_4.selected){derWheel[4]=2;}else{derWheel[4]=0;};
	if(!ChekGetLimitsLow()){support.ForceMove(10,derWheel[1], derWheel[2] ,derWheel[3] ,derWheel[4] );}
	
}

bool Carrage::IfSelectetMalfuction(){
	return Wheel_1.selected_malfinction()||Wheel_2.selected_malfinction()||Wheel_3.selected_malfinction()||Wheel_4.selected_malfinction();
}


void Carrage::SetLimits(){
	Wheel_1.maxHight = max;
	Wheel_2.maxHight = max;
	Wheel_3.maxHight = max;
	Wheel_4.maxHight = max;
	
	Wheel_1.minHight = min;
	Wheel_2.minHight = min;
	Wheel_3.minHight = min;
	Wheel_4.minHight = min;
}

void Carrage::CheckLimitsSetHight(){
	Wheel_1.SetLimitsSetHight();
	Wheel_2.SetLimitsSetHight();
	Wheel_3.SetLimitsSetHight();
	Wheel_4.SetLimitsSetHight();
}

void Carrage::Ajustment(){
	CheckLimitsSetHight();
	finish=1;
	int i=0;
	if (chechWheelsBefore()){
		while(finish>0&&i<200){
			LCDflachIndicator(i);
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
	
		if(i>=200){
			if(derWheel[1]>0){Wheel_1.malfuction = true;Wheel_1.Error = 2;flagNewMalfuction = true;}
			if(derWheel[2]>0){Wheel_2.malfuction = true;Wheel_2.Error = 2;flagNewMalfuction = true;}
			if(derWheel[3]>0){Wheel_3.malfuction = true;Wheel_3.Error = 2;flagNewMalfuction = true;}
			if(derWheel[4]>0){Wheel_4.malfuction = true;Wheel_4.Error = 2;flagNewMalfuction = true;}
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
		if  (checked[1]&&checked[2]&&checked[3]&&checked[4]){return true;}else{flagNewMalfuction = true;return false;}					
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
	if  (checked[1]&&checked[2]&&checked[3]&&checked[4]){return true;}else{flagNewMalfuction = true;return false;}
	
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
	return step*tunning;
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
	float hight = wheel.sethight;
	//Lcd_printf2(hight_pos_x, hight_pos_y-1, FONT_1X, hight, 2);
	hight = wheel.get_hight();

	Lcd_printf2(hight_pos_x, hight_pos_y, FONT_1X, hight, 2);
	Lcd_update();
}

void Carrage::ControlMalfinction(){
	if (OnOffMalfunction){
		Wheel_1.IsChanchedHight();
		Wheel_2.IsChanchedHight();
		Wheel_3.IsChanchedHight();
		Wheel_4.IsChanchedHight();
		bool caragemove = (Wheel_1.move|Wheel_2.move|Wheel_3.move|Wheel_4.move);
		if (caragemove){
			if(Wheel_1.ControlMalfinction(countToMalfunctionLimit)){flagNewMalfuction = true;};
			if(Wheel_2.ControlMalfinction(countToMalfunctionLimit)){flagNewMalfuction = true;};
			if(Wheel_3.ControlMalfinction(countToMalfunctionLimit)){flagNewMalfuction = true;};
			if(Wheel_4.ControlMalfinction(countToMalfunctionLimit)){flagNewMalfuction = true;};
		}
	}
}

void Carrage::ResecCountMalfinction(){
	Wheel_1.countToMalfunction = 0;
	Wheel_2.countToMalfunction = 0;
	Wheel_3.countToMalfunction = 0;
	Wheel_4.countToMalfunction = 0;
}


void Carrage::switch_malfaction(){
	OnOffMalfunction = !OnOffMalfunction;
}

void Carrage::errorsReset(){
	Wheel_1.malfuction = false;
	Wheel_1.Error = 0;
	Wheel_2.malfuction = false;
	Wheel_2.Error = 0;
	Wheel_3.malfuction = false;
	Wheel_3.Error = 0;
	Wheel_4.malfuction = false;
	Wheel_4.Error = 0;
}

void Carrage::SelectAllWheel(){
	if(!Wheel_1.malfuction){Wheel_1.selected = true;}
	if(!Wheel_2.malfuction){Wheel_2.selected = true;}
	if(!Wheel_3.malfuction){Wheel_3.selected = true;}
	if(!Wheel_4.malfuction){Wheel_4.selected = true;}
}

void Carrage::DiSelectAllWheel(){
	Wheel_1.selected = false;
	Wheel_2.selected = false;
	Wheel_3.selected = false;
	Wheel_4.selected = false;
}

void Carrage::SwitchAllWheel(){
	if(Wheel_1.MalFunctionAndnotselected()&&Wheel_2.MalFunctionAndnotselected()&&Wheel_3.MalFunctionAndnotselected()&&Wheel_4.MalFunctionAndnotselected()){
		DiSelectAllWheel();
	}else{
		SelectAllWheel();
	}
}

bool Carrage::AnySelected(){
	if(Wheel_1.selected||Wheel_2.selected||Wheel_3.selected||Wheel_4.selected){
		return true;
	}else{return false;}
}

bool Carrage::ChekGetLimitsLow(){
	Wheel_1.CheckGetLimitLow();
	Wheel_2.CheckGetLimitLow();
	Wheel_3.CheckGetLimitLow();
	Wheel_4.CheckGetLimitLow();
	if(Wheel_1.flagGetLimits||Wheel_2.flagGetLimits||Wheel_3.flagGetLimits||Wheel_4.flagGetLimits){
		Wheel_1.flagGetLimits = false;
		Wheel_2.flagGetLimits = false;
		Wheel_3.flagGetLimits = false;
		Wheel_4.flagGetLimits = false;
		flagGetLimits = true;
		return true;
	}else{
		return false;
	}
}

bool Carrage::ChekGetLimitsHight(){
	Wheel_1.CheckGetLimitHight();
	Wheel_2.CheckGetLimitHight();
	Wheel_3.CheckGetLimitHight();
	Wheel_4.CheckGetLimitHight();
	if(Wheel_1.flagGetLimits||Wheel_2.flagGetLimits||Wheel_3.flagGetLimits||Wheel_4.flagGetLimits){
		Wheel_1.flagGetLimits = false;
		Wheel_2.flagGetLimits = false;
		Wheel_3.flagGetLimits = false;
		Wheel_4.flagGetLimits = false;
		flagGetLimits = true;
		return true;
		}else{
		return false;
	}
}

void Carrage::LCDflachIndicator(int i){

	if(i%6>3){

		LcdGotoXY(6,2);
		LcdChr_full(0x96);
		LcdGotoXY(7,2);
		LcdChr_full(0x97);
		LcdGotoXY(6,3);
		LcdChr_full(0x98);
		LcdGotoXY(7,3);
		LcdChr_full(0x99);
		
	}else{

		LcdGotoXY(6,2);
		LcdChr_full(0x92);
		LcdGotoXY(7,2);
		LcdChr_full(0x93);
		LcdGotoXY(6,3);
		LcdChr_full(0x94);
		LcdGotoXY(7,3);
		LcdChr_full(0x95);
		
	}

}