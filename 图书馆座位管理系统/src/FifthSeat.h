#pragma once
#include"Seat.h"
#ifndef FIFTHSEAT_H
#define FIFTHSEAT_H
class FifthSeat :public Seat
{
public:
	FifthSeat();
	virtual int getRoom();
	virtual int getFloor();
	virtual unsigned int getNumber();
	virtual bool getHaveShelf();
	virtual string getShelfName();
	virtual bool getHavePower();
private:
	const int floor = 5;
};
#endif // !FIFTHSEAT_H
