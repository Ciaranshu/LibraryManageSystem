#include "Socialmagazine.h"

Socialmagazine::Socialmagazine(unsigned int number, bool haveShelf, string shelfName, bool havePower)
{
	Socialmagazine::number = number;
	Socialmagazine::haveShelf = haveShelf;
	Socialmagazine::shelfName = shelfName;
	Socialmagazine::havePower = havePower;
}
unsigned int Socialmagazine::getNumber()
{
	return number;
}
void Socialmagazine::setNumber(unsigned int number)
{
	Socialmagazine::number = number;
}

bool Socialmagazine::getHaveShelf()
{
	return haveShelf;
}

void Socialmagazine::setHaveShelf(bool haveShelf)
{
	Socialmagazine::haveShelf = haveShelf;
}

string Socialmagazine::getShelfName()
{
	return shelfName;
}

void Socialmagazine::setShelfName(string shelfName)
{
	Socialmagazine::shelfName = shelfName;
}

bool Socialmagazine::getHavePower()
{
	return havePower;
}

void Socialmagazine::setHavePower(bool havePower)
{
	Socialmagazine::havePower = havePower;
}

int Socialmagazine::getRoom()
{
    return 3;
}
