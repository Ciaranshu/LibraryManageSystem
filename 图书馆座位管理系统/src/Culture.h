#pragma once
#include"FourthSeat.h"
#include<string>
using namespace std;
#ifndef CULTURE_H
#define CULTURE_H 
class Culture :public FourthSeat
{
public:
	Culture(unsigned int, bool, string, bool);
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
#endif // !CULTURE_H 