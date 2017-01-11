#pragma once
#include"ThirdSeat.h"
#include<string>
using namespace std;
#ifndef COMPUTERREADING_H
#define COMPUTERREADING_H 
class Computerreading :public ThirdSeat
{
public:
	Computerreading(unsigned int, bool, string, bool);
	virtual unsigned int getNumber();
	void setNumber(unsigned int);
	virtual bool getHaveShelf();
	void setHaveShelf(bool);
	virtual string getShelfName();
	void setShelfName(string);
	virtual bool getHavePower();
	void setHavePower(bool);
	virtual int getRoom();
private:
	unsigned int number;
	bool haveShelf;
	string shelfName;
	bool havePower;
};
#endif // !COMPUTERREADING_H