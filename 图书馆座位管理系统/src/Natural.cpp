#include "Natural.h"
#include<iostream>
using namespace std;
Naturalbook::Naturalbook(unsigned int number, bool haveShelf, string shelfName, bool havePower)
{
	Naturalbook::number = number;
	Naturalbook::haveShelf = haveShelf;
        setShelfName(shelfName);
	Naturalbook::havePower = havePower;
}

unsigned int Naturalbook::getNumber()
{
	return number;
}

void Naturalbook::setNumber(unsigned int number)
{
	Naturalbook::number = number;
}

bool Naturalbook::getHaveShelf()
{
	return haveShelf;
}

void Naturalbook::setHaveShelf(bool haveShelf)
{
	Naturalbook::haveShelf = haveShelf;
}

string Naturalbook::getShelfName()
{
    return shelfName;
}

void Naturalbook::setShelfName(string shelfName)
{
    this->shelfName = shelfName;
}

bool Naturalbook::getHavePower()
{
	return havePower;
}

void Naturalbook::setHavePower(bool havePower)
{
	Naturalbook::havePower = havePower;
}

int Naturalbook::getRoom()
{
    return 1;
}
