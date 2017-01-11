#pragma once
#include"ThirdSeat.h"
#include<string>
using namespace std;
#ifndef NATURAL_H
#define NATURAL_H 
class Naturalbook:public ThirdSeat
{
public:
	Naturalbook(unsigned int,bool,string,bool);
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
#endif // !NATURAL_H
