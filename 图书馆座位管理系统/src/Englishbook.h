#pragma once
#include"FifthSeat.h"
#include<string>
using namespace std;
#ifndef ENGLISHBOOK_H
#define ENGLISHBOOK_H
class Englishbook :public FifthSeat
{
public:
	Englishbook(unsigned int, bool, string, bool);
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
#endif // !ENGLISHBOOK_H