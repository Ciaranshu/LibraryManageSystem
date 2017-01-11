#include "LawandEconomics.h"

LawandEconomics::LawandEconomics(unsigned int number, bool haveShelf, string shelfName, bool havePower)
{
	LawandEconomics::number = number;
	LawandEconomics::haveShelf = haveShelf;
	LawandEconomics::shelfName = shelfName;
	LawandEconomics::havePower = havePower;
}
unsigned int LawandEconomics::getNumber()
{
	return number;
}
void LawandEconomics::setNumber(unsigned int number)
{
	LawandEconomics::number = number;
}

bool LawandEconomics::getHaveShelf()
{
	return haveShelf;
}

void LawandEconomics::setHaveShelf(bool haveShelf)
{
	LawandEconomics::haveShelf = haveShelf;
}

string LawandEconomics::getShelfName()
{
	return shelfName;
}

void LawandEconomics::setShelfName(string shelfName)
{
	LawandEconomics::shelfName = shelfName;
}

bool LawandEconomics::getHavePower()
{
	return havePower;
}

void LawandEconomics::setHavePower(bool havePower)
{
	LawandEconomics::havePower = havePower;
}

int LawandEconomics::getRoom()
{
    return 2;
}
