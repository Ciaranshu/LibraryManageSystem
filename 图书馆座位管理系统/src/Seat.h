#include<string>
using namespace std;
#pragma once
#ifndef SEAT_H
#define SEAT_H
struct SeatRecord;
class Seat
{
public:
	Seat();
	void makeOccupancyindayone(int,long);
	void makeOccupancyindaytwo(int,long);
	void cancelOccupancyindayone(int);
	void cancelOccupancyindaytwo(int);
	bool* getAllOccupancyStatusindayone();
	long* getAllNumberindayone();
	bool* getAllOccupancyStatusindaytwo();
	long* getAllNumberindaytwo();

    void setAllOccupancyStatusindayone(bool* v)
    {
        for (int i = 0; i < 26; i++) {
            OccupancyTimeindayone[i] = v[i];
        }
    }

    void setAllNumberindayone(long* v)
    {
        for (int i = 0; i < 26; i++) {
            studentsNumberindayone[i] = v[i];
        }
    }
    void setAllOccupancyStatusindaytwo(bool* v)
    {
        for (int i = 0; i < 26; i++) {
            OccupancyTimeindaytwo[i] = v[i];
        }
    }
    void setAllNumberindaytwo(long* v)
    {
        for (int i = 0; i < 26; i++) {
            studentsNumberindaytwo[i] = v[i];
        }
    }

    void refresh();
	virtual int getRoom();
	virtual int getFloor();
	virtual unsigned int getNumber();
	virtual bool getHaveShelf();
	virtual string getShelfName();
        virtual bool getHavePower();
        virtual void setNumber(unsigned int) {}
        virtual void setHaveShelf(bool) {}
        virtual void setShelfName(string) {}
        virtual void setHavePower(bool) {}

protected:
    long studentsNumberindayone[26];
	long studentsNumberindaytwo[26];
	bool OccupancyTimeindayone[26];
	bool OccupancyTimeindaytwo[26];

	
};

struct SeatRecord {
    int starthour;
    int startminute;
    long studentsNumberindayone[26];
    long studentsNumberindaytwo[26];
    bool OccupancyTimeindayone[26];
    bool OccupancyTimeindaytwo[26];
    unsigned int number;
    bool haveShelf;
    char shelfName[20];
    bool havePower;

    short __padding;
};

static void seat2Record(Seat* s, SeatRecord* sr)
{
    long* nrOne = s->getAllNumberindayone();
    long* nrTwo = s->getAllNumberindaytwo();
    bool* ocOne = s->getAllOccupancyStatusindayone();
    bool* ocTwo = s->getAllOccupancyStatusindaytwo();
    for (int i = 0; i < 26; i++) {
        sr->studentsNumberindayone[i] = nrOne[i];
        sr->studentsNumberindaytwo[i] = nrTwo[i];
        sr->OccupancyTimeindayone[i] = ocOne[i];
        sr->OccupancyTimeindaytwo[i] = ocTwo[i];
    }
    sr->number = s->getNumber();
    sr->haveShelf = s->getHaveShelf();
    sr->havePower = s->getHavePower();

    std::string shelf = s->getShelfName();
    for (int i = 0; i < shelf.length(); i++) {
       sr->shelfName[i] = shelf[i];
    }
    sr->shelfName[shelf.length()] = '\0';
}

static void record2Seat(SeatRecord* sr, Seat* s)
{
    for (int i = 0; i < 26; i++) {
        s->setAllNumberindayone(sr->studentsNumberindayone);
        s->setAllNumberindaytwo(sr->studentsNumberindaytwo);
        s->setAllOccupancyStatusindayone(sr->OccupancyTimeindayone);
        s->setAllOccupancyStatusindaytwo(sr->OccupancyTimeindaytwo);
    }
    s->setNumber(sr->number);
    s->setHavePower(sr->havePower);
    s->setHaveShelf(sr->haveShelf);
    s->setShelfName(string(sr->shelfName));
}

#endif // !SEAT_H

