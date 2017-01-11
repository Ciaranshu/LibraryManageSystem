#include "Naturalmagazine.h"

Naturalmagazine::Naturalmagazine(unsigned int number, bool haveShelf, string shelfName, bool havePower)
{
	Naturalmagazine::number = number;
	Naturalmagazine::haveShelf = haveShelf;
	Naturalmagazine::shelfName = shelfName;
	Naturalmagazine::havePower = havePower;
}
unsigned int Naturalmagazine::getNumber()
{
	return number;
}
void Naturalmagazine::setNumber(unsigned int number)
{
	Naturalmagazine::number = number;
}

bool Naturalmagazine::getHaveShelf()
{
	return haveShelf;
}

void Naturalmagazine::setHaveShelf(bool haveShelf)
{
	Naturalmagazine::haveShelf = haveShelf;
}

string Naturalmagazine::getShelfName()
{
	return shelfName;
}

void Naturalmagazine::setShelfName(string shelfName)
{
	Naturalmagazine::shelfName = shelfName;
}

bool Naturalmagazine::getHavePower()
{
	return havePower;
}

void Naturalmagazine::setHavePower(bool havePower)
{
	Naturalmagazine::havePower = havePower;
}

int Naturalmagazine::getRoom()
{
    return 2;
}
