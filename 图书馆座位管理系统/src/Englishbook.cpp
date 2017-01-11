#include "Englishbook.h"

Englishbook::Englishbook(unsigned int number, bool haveShelf, string shelfName, bool havePower)
{
	Englishbook::number = number;
	Englishbook::haveShelf = haveShelf;
	Englishbook::shelfName = shelfName;
	Englishbook::havePower = havePower;
}
unsigned int Englishbook::getNumber()
{
	return number;
}
void Englishbook::setNumber(unsigned int number)
{
	Englishbook::number = number;
}

bool Englishbook::getHaveShelf()
{
	return haveShelf;
}

void Englishbook::setHaveShelf(bool haveShelf)
{
	Englishbook::haveShelf = haveShelf;
}

string Englishbook::getShelfName()
{
	return shelfName;
}

void Englishbook::setShelfName(string shelfName)
{
	Englishbook::shelfName = shelfName;
}

bool Englishbook::getHavePower()
{
	return havePower;
}

void Englishbook::setHavePower(bool havePower)
{
	Englishbook::havePower = havePower;
}

int Englishbook::getRoom()
{
    return 4;
}
