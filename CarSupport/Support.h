/* 
* Support.h
*
* Created: 29.08.2018 13:22:17
* Author: user
*/


#ifndef __SUPPORT_H__
#define __SUPPORT_H__


class Support
{
//variables
public:
protected:
private:
	int i;

//functions
public:
	Support();
	void Init();
	void Down(int ms_time, bool support_1, bool support_2, bool support_3, bool support_4 );
	void Up(int ms_time, bool support_1, bool support_2, bool support_3, bool support_4 );
	void Adjast(int ms_time, int DerWheel_1, int DerWheel_2,int DerWheel_3, int DerWheel_4);
protected:
private:


}; //Support

#endif //__SUPPORT_H__
