#include "Computerreading.h"

Computerreading::Computerreading(unsigned int number, bool haveShelf, string shelfName, bool havePower)
{
	Computerreading::number = number;
	Computerreading::haveShelf = haveShelf;
	Computerreading::shelfName = shelfName;
	Computerreading::havePower = havePower;
}

unsigned int Computerreading::getNumber()
{
	return number;
}

void Computerreading::setNumber(unsigned int number)
{
	Computerreading::number = number;
}

bool Computerreading::getHaveShelf()
{
	return haveShelf;
}

void Computerreading::setHaveShelf(bool haveShelf)
{
	Computerreading::haveShelf = haveShelf;
}

string Computerreading::getShelfName()
{
	return shelfName;
}

void Computerreading::setShelfName(string shelfName)
{
	Computerreading::shelfName = shelfName;
}

bool Computerreading::getHavePower()
{
	return havePower;
}

void Computerreading::setHavePower(bool havePower)
{
	Computerreading::havePower = havePower;
}

int Computerreading::getRoom()
{
	return 3;
}
