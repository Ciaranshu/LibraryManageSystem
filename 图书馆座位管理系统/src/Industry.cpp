#include "Industry.h"

Industrybook::Industrybook(unsigned int number, bool haveShelf, string shelfName, bool havePower)
{
	Industrybook::number = number;
	Industrybook::haveShelf = haveShelf;
	Industrybook::shelfName = shelfName;
	Industrybook::havePower = havePower;
}

unsigned int Industrybook::getNumber()
{
	return number;
}

void Industrybook::setNumber(unsigned int number)
{
	Industrybook::number = number;
}

bool Industrybook::getHaveShelf()
{
	return haveShelf;
}

void Industrybook::setHaveShelf(bool haveShelf)
{
	Industrybook::haveShelf = haveShelf;
}

string Industrybook::getShelfName()
{
	return shelfName;
}

void Industrybook::setShelfName(string shelfName)
{
	Industrybook::shelfName = shelfName;
}

bool Industrybook::getHavePower()
{
	return havePower;
}

void Industrybook::setHavePower(bool havePower)
{
	Industrybook::havePower = havePower;
}

int Industrybook::getRoom()
{
	return 2;
}
