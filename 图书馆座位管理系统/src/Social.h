#pragma once
#include"FourthSeat.h"
#include<string>
using namespace std;
#ifndef SOCIAL_H
#define SOCIAL_H
class Social :public FourthSeat
{
public:
	Social(unsigned int, bool, string, bool);
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
#endif // !SOCIAL_H