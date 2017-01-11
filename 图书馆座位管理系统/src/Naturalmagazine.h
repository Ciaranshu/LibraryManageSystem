#pragma once
#include"FifthSeat.h"
#include<string>
using namespace std;
#ifndef NATURALMAGAZINE_H
#define NATURALMAGAZINE_H
class Naturalmagazine :public FifthSeat
{
public:
	Naturalmagazine(unsigned int, bool, string, bool);
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
#endif // !NATURALMAGAZINE_H