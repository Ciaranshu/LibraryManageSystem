#include "Pastmagazine.h"

Pastmagazine::Pastmagazine(unsigned int number, bool haveShelf, string shelfName, bool havePower)
{
	Pastmagazine::number = number;
	Pastmagazine::haveShelf = haveShelf;
	Pastmagazine::shelfName = shelfName;
	Pastmagazine::havePower = havePower;
}
unsigned int Pastmagazine::getNumber()
{
	return number;
}
void Pastmagazine::setNumber(unsigned int number)
{
	Pastmagazine::number = number;
}

bool Pastmagazine::getHaveShelf()
{
	return haveShelf;
}

void Pastmagazine::setHaveShelf(bool haveShelf)
{
	Pastmagazine::haveShelf = haveShelf;
}

string Pastmagazine::getShelfName()
{
	return shelfName;
}

void Pastmagazine::setShelfName(string shelfName)
{
	Pastmagazine::shelfName = shelfName;
}

bool Pastmagazine::getHavePower()
{
	return havePower;
}

void Pastmagazine::setHavePower(bool havePower)
{
	Pastmagazine::havePower = havePower;
}

int Pastmagazine::getRoom()
{
    return 1;
}
