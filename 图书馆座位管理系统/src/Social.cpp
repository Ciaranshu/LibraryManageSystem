#include "Social.h"

Social::Social(unsigned int number, bool haveShelf, string shelfName, bool havePower)
{
	Social::number = number;
	Social::haveShelf = haveShelf;
	Social::shelfName = shelfName;
	Social::havePower = havePower;
}

unsigned int Social::getNumber()
{
	return number;
}
void Social::setNumber(unsigned int number)
{
	Social::number = number;
}

bool Social::getHaveShelf()
{
	return haveShelf;
}

void Social::setHaveShelf(bool haveShelf)
{
	Social::haveShelf = haveShelf;
}

string Social::getShelfName()
{
	return shelfName;
}

void Social::setShelfName(string shelfName)
{
	Social::shelfName = shelfName;
}

bool Social::getHavePower()
{
	return havePower;
}

void Social::setHavePower(bool havePower)
{
	Social::havePower = havePower;
}

int Social::getRoom()
{
    return 1;
}
