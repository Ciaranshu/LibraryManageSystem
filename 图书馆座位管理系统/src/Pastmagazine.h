#pragma once
#include"FifthSeat.h"
#include<string>
using namespace std;
#ifndef PASTMAGAZINE_H
#define PASTMAGAZINE_H
class Pastmagazine :public FifthSeat
{
public:
	Pastmagazine(unsigned int, bool, string, bool);
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
#endif // !PASTMAGAZINE_H