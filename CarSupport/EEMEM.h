/*
 * EEMEM.h
 *
 * Created: 05.09.2018 13:39:58
 *  Author: user
 */ 


#ifndef CARSATATES_H_
#define CARSATATES_H_




void SettingsSave(bool SettingSave){
	if (SettingSave){
		eeprom_write_float (&Tunning_rate, carrage.tunning);
		eeprom_write_float(&CarrajeMin, carrage.min);
		eeprom_write_float(&CarrajeMax, carrage.max);
		carrage.SetLimits();
		eeprom_write_float (&countToMalfunctionLimit, carrage.countToMalfunctionLimit);
		eeprom_write_byte(&OnOffMalfunction,carrage.OnOffMalfunction); 
	}
}


void IFCarrageSaveStateToEEMEM( int position){
	
	if(activity.SaveFlag){
		eeprom_write_float (&PositionsStates[position][1], carrage.Wheel_1.get_hight());
		eeprom_write_float (&PositionsStates[position][2], carrage.Wheel_2.get_hight());
		eeprom_write_float (&PositionsStates[position][3], carrage.Wheel_3.get_hight());
		eeprom_write_float (&PositionsStates[position][4], carrage.Wheel_4.get_hight());
	}
	activity.SaveFlag = false;
}

void IFCarrageSetStateToEEMEM( int position){
	if(activity.SetFlag){
		carrage.SelectAllWheel();
		screen.Render(activity, carrage);
		carrage.Wheel_1.sethight=eeprom_read_float(&PositionsStates[position][1]);
		carrage.Wheel_2.sethight=eeprom_read_float(&PositionsStates[position][2]);
		carrage.Wheel_3.sethight=eeprom_read_float(&PositionsStates[position][3]);
		carrage.Wheel_4.sethight=eeprom_read_float(&PositionsStates[position][4]);
		carrage.Ajustment();
		//_delay_ms(10);
		//activity.GoToSetPosiions();
		carrage.DiSelectAllWheel();
		activity.Statment = 0;
	}
	activity.SetFlag = false;
}


#endif /* CARSATATES_H_ */