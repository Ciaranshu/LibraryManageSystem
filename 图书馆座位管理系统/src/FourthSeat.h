#pragma once
#include"Seat.h"
#ifndef FOURTHSEAT_H
#define FOURTHSEAT_H
class FourthSeat :public Seat
{
public:
	FourthSeat();
	virtual int getRoom();
	virtual int getFloor();
	virtual unsigned int getNumber();
	virtual bool getHaveShelf();
	virtual string getShelfName();
	virtual bool getHavePower();
private:
	const int floor = 4;
};
#endif // !FOURTHSEAT_H


