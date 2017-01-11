#pragma once
#include"FourthSeat.h"
#include<string>
using namespace std;
#ifndef LAWANDECONOMICS_H
#define LAWANDECONOMICS_H
class LawandEconomics :public FourthSeat
{
public:
	LawandEconomics(unsigned int, bool, string, bool);
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
#endif // !LAWANDECONOMICS_H