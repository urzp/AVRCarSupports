/* 
* Support.cpp
*
* Created: 29.08.2018 13:22:16
* Author: user
*/

#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>

#include "Support.h"

#define START       0x08    //START has been transmitted
#define REP_START   0x10
#define MT_DATA_ACK 0x28
#define MT_SLA_ACK  0x18

//Master Transmitter staus codes
#define MT_ADR_ACK  0x18    //SLA+W has been tramsmitted and ACK received
#define MT_ADR_NACK 0x20    //SLA+W has been tramsmitted and NACK received

#define MT_DATA_ACK 0x28    //Data byte has been tramsmitted and ACK received
#define MT_DATA_NACK 0x30   //Data byte has been tramsmitted and NACK received
#define MT_ARB_LOST 0x38    //Arbitration lost in SLA+W or data bytes

#define WRITE       0x00
#define READ        0x01

#define READ_END    0x01
#define READ_NOEND  0x00

#define ERROR       0x01
#define SUCCESS     0x00

#define I2C_ADR_PCF8574 0x3F

static uint8_t send_i2c(uint8_t value);
static uint8_t start_i2c(uint8_t d_adr);
static inline void stop_i2c();
static uint8_t write_i2c(uint8_t ADR, uint8_t value);

const int NORMAL=0;
const int UP=1;
const int DOWN=2;

// default constructor
Support::Support()
{
} //Support


void Support::Init(){
	TWBR = 39;
	write_i2c((I2C_ADR_PCF8574<<1), 0x00);
} 

void Support::Down(int ms_time, bool support_1, bool support_2, bool support_3, bool support_4 ){
	uint8_t data = (support_1<<1)|(support_2<<3)|(support_3<<5)|(support_4<<7);
	write_i2c((I2C_ADR_PCF8574<<1), data);
	for (i=0;i<ms_time;i++){_delay_ms(1);}
	write_i2c((I2C_ADR_PCF8574<<1), 0x00);
}

void Support::Up(int ms_time, bool support_1, bool support_2, bool support_3, bool support_4 ){
	uint8_t data = (support_1<<0)|(support_2<<2)|(support_3<<4)|(support_4<<6);
	write_i2c((I2C_ADR_PCF8574<<1), data);
	for (i=0;i<ms_time;i++){_delay_ms(1);}
	write_i2c((I2C_ADR_PCF8574<<1), 0x00);
}

void Support::Adjast(int ms_time, int DerWheel_1, int DerWheel_2,int DerWheel_3, int DerWheel_4){
	if(ms_time>0){
		uint8_t data = 0x00;
		if(DerWheel_1 == UP){data |= (1<<0);};
		if(DerWheel_1 == DOWN){data |= (1<<1);};
		
		if(DerWheel_2 == UP){data |= (1<<2);};
		if(DerWheel_2 == DOWN){data |= (1<<3);};
		
		if(DerWheel_3 == UP){data |= (1<<4);};
		if(DerWheel_3 == DOWN){data |= (1<<5);};
		
		if(DerWheel_4 == UP){data |= (1<<6);};
		if(DerWheel_4 == DOWN){data |= (1<<7);};
		
		write_i2c((I2C_ADR_PCF8574<<1), data);
		for (i=0;i<ms_time;i++){_delay_ms(1);}
		write_i2c((I2C_ADR_PCF8574<<1), 0x00);
		_delay_ms(20);
	}
	
}

void Support::ForceMove(int ms_time, int DerWheel_1, int DerWheel_2,int DerWheel_3, int DerWheel_4){
	if(ms_time>0){
		uint8_t data = 0x00;
		if(DerWheel_1 == UP){data |= (1<<0);};
		if(DerWheel_1 == DOWN){data |= (1<<1);};
		
		if(DerWheel_2 == UP){data |= (1<<2);};
		if(DerWheel_2 == DOWN){data |= (1<<3);};
		
		if(DerWheel_3 == UP){data |= (1<<4);};
		if(DerWheel_3 == DOWN){data |= (1<<5);};
		
		if(DerWheel_4 == UP){data |= (1<<6);};
		if(DerWheel_4 == DOWN){data |= (1<<7);};
		
		write_i2c((I2C_ADR_PCF8574<<1), data);
		for (i=0;i<ms_time;i++){_delay_ms(1);}
		write_i2c((I2C_ADR_PCF8574<<1), 0x00);
		_delay_ms(1);
	}
	
}


static uint8_t write_i2c(uint8_t ADR, uint8_t value) {
	uint8_t ret;
	if (start_i2c(ADR) != ERROR)
	{
		ret=send_i2c(value);
		stop_i2c();
		} else {
		stop_i2c();
		ret=ERROR;
	}
	return ret;
}

uint8_t send_i2c(uint8_t value)
{
	TWDR = value;
	TWCR = (1<<TWINT) | (1<<TWEN);
	// wail until transmission completed and ACK/NACK has been received
	while(!(TWCR & (1<<TWINT))) {};
	// check value of TWI Status Register. Mask prescaler bits.

	value = TWSR & 0xF8;
	return (value == MT_SLA_ACK || value == MT_DATA_ACK) ? SUCCESS : ERROR;
}


static uint8_t start_i2c(uint8_t d_adr)
{
	TWCR=(1<<TWINT) | (1<<TWSTA) | (1<<TWEN); // START
	while (!(TWCR & (1<<TWINT))) {};

	uint8_t twst; twst = (TWSR & 0xF8); // check value of TWI Status Register. Mask prescaler bits.
	if ((twst != START) && (twst != REP_START))
	return ERROR;
	return send_i2c(d_adr);
};

static inline void stop_i2c()
{
	TWCR=(1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}