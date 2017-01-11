#include "Culture.h"

Culture::Culture(unsigned int number, bool haveShelf, string shelfName, bool havePower)
{
	Culture::number = number;
	Culture::haveShelf = haveShelf;
	Culture::shelfName = shelfName;
	Culture::havePower = havePower;
}
unsigned int Culture::getNumber()
{
	return number;
}
void Culture::setNumber(unsigned int number)
{
	Culture::number = number;
}

bool Culture::getHaveShelf()
{
	return haveShelf;
}

void Culture::setHaveShelf(bool haveShelf)
{
	Culture::haveShelf = haveShelf;
}

string Culture::getShelfName()
{
	return shelfName;
}

void Culture::setShelfName(string shelfName)
{
	Culture::shelfName = shelfName;
}

bool Culture::getHavePower()
{
	return havePower;
}

void Culture::setHavePower(bool havePower)
{
	Culture::havePower = havePower;
}

int Culture::getRoom()
{
    return 3;
}
