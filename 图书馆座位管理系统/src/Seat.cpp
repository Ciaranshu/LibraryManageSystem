#include<iostream>
#include"Seat.h"
Seat::Seat()
{
    for (int i = 0; i < 26; i++)
	{
		OccupancyTimeindayone[i] = false;
		OccupancyTimeindaytwo[i] = false;
		studentsNumberindayone[i] = 0;
		studentsNumberindaytwo[i] = 0;
	}
}
void Seat::makeOccupancyindayone(int date, long studentnumber)
{
	OccupancyTimeindayone[date] = true;
	studentsNumberindayone[date] = studentnumber;
}
void Seat::makeOccupancyindaytwo(int date, long studentnumber)
{
	OccupancyTimeindaytwo[date] = true;
	studentsNumberindaytwo[date] = studentnumber;
}
void Seat::cancelOccupancyindayone(int date)
{
	OccupancyTimeindayone[date] = false;
}
void Seat::cancelOccupancyindaytwo(int date)
{
	OccupancyTimeindaytwo[date] = false;
}

bool * Seat::getAllOccupancyStatusindayone()
{
	return OccupancyTimeindayone;
}

long * Seat::getAllNumberindayone()
{
	return studentsNumberindayone;
}

bool * Seat::getAllOccupancyStatusindaytwo()
{
	return OccupancyTimeindaytwo;
}

long * Seat::getAllNumberindaytwo()
{
	return studentsNumberindaytwo;
}

void Seat::refresh()
{
	for (int i = 0; i < 26; i++)
	{
		studentsNumberindayone[i] = studentsNumberindaytwo[i];
		studentsNumberindaytwo[i] = 0;
		OccupancyTimeindayone[i] = OccupancyTimeindaytwo[i];
		OccupancyTimeindaytwo[i] = false;
	}

}

int Seat::getRoom()
{
	return 0;
}

int Seat::getFloor()
{
	return 0;
}

unsigned int Seat::getNumber()
{
	return 0;
}

bool Seat::getHaveShelf()
{
	return false;
}

string Seat::getShelfName()
{
	return string();
}

bool Seat::getHavePower()
{
	return false;
}


//void seat::makeoccupancyindayone(int date)
//{
//	occupancytimeindayone[date] = true;
//}
//void seat::canceloccupancy(int date)
//{
//	occupancytime[date] = false;
//}
//void seat::setstarttime()//�趨��ʼʱ��
//{
//	if (hour >= 8 && hour <= 21)
//		starthour = hour;
//	else//��΢��һ�£��һ���֪������Ҫ��������~~
//		;
//	if (minute >= 0 && minute <= 59)
//		startminute = minute;
//	else//��΢��һ�£��һ���֪������Ҫ��������~~
//		;
//}
//void seat::setstarttimeandovertime(int starthour, int startminute,int overhour, int overminute)//�趨ʱ��
//{
//		seat::starthour = starthour;
//		seat::startminute = startminute;
//		seat::overhour = overhour;
//		seat::overminute = overminute;
//	//��΢��һ�£��һ���֪������Ҫ��ô����������~~
//}

//void Seat::makeOccupancy()
//{
//	OccupancyStatus = true;
//}
//void Seat::cancelOccupancy()
//{
//	OccupancyStatus = false;
//}
//void Seat::setOccupancy(bool OccupancyStatus)
//{
//	Seat::OccupancyStatus = OccupancyStatus;
//}
//int * Seat::getStarttime()
//{
//	int*starttimes;
//	starttimes = new int[2];
//	starttimes[0] = starthour;
//	starttimes[1] = startminute;
//	return starttimes;
//}
//int * Seat::getOvertime()
//{
//	int*overtimes;
//	overtimes = new int[2];
//	overtimes[0] = overhour;
//	overtimes[1] = overminute;
//	return overtimes;
//}
