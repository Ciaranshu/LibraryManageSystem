#pragma once
#include<string>

using namespace std;
Seat * seatsRecommend(int theFloor, int theRoom, int theSeatNumber, bool theSlot, string theBookshelf, int theStartTime, int theEndTime, int theDate);


bool seatsReservation(int theFloor, int theRoom, int theSeatNumber, bool theSlot, string theBookshelf, int startTime, int endTime, int theDate, long  studentNumber);
//theDate I add is the day need to be reservated , 1 means today and 2 means tomorrow
//and I also add a parameter studentNumber

Seat * seatsSituation(int theFloor, int theRoom, int theSeatNumber);
