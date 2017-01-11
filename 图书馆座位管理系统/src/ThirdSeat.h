#pragma once
#include"Seat.h"
#ifndef THIRDSEAT_H
#define THIRDSEAT_H
class ThirdSeat :public Seat
{
public:
	ThirdSeat();
	virtual int getRoom();
	virtual int getFloor();
	virtual unsigned int getNumber();
	virtual bool getHaveShelf();
	virtual string getShelfName();
	virtual bool getHavePower();
private:
	const int floor=3;
};
#endif // !THIRDSEAT_H

