#include<iostream>
#include<fstream>
#include<string>
#include"Seat.h"
#include "Computerreading.h"
#include "Natural.h"
#include "Culture.h"
#include "Industry.h"
#include "LawandEconomics.h"
#include "Socialmagazine.h"
#include "Social.h"
#include "Pastmagazine.h"
#include "Naturalmagazine.h"
#include "Englishbook.h"
#include"seatsRecommend.h"
using namespace std;

Seat * seatsRecommend(int theFloor, int theRoom, int theSeatNumber, bool theSlot, string theBookshelf, int theStartTime, int theEndTime, int theDate)
{
    int floor = theFloor;
    int room = theRoom;
    bool slot = theSlot;
    string bookshelf = theBookshelf;
    int startTime = theStartTime;
    int endTime = theEndTime;
    int date = theDate;// need to add

    //floor3
    if (floor == 3)
    {

        //room1 Naturalbook
        if (room == 1)
        {
            SeatRecord rec;
            fstream ClientFile("Naturalbook.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Naturalbook* seat = new Naturalbook (1, false, " ", false);

            //read record one by one until getting a appropriate seat
            for (int i = 0; i < 48; i++)
            {
                bool judge = true; //bool to mark if the seat is choosable later

                                   //read a record

                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                //search seats for today
                if (date == 1)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindayone();

                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }

                    //if yes, whether it matches the other conditions
                    if (judge)
                    {
                        if ((bookshelf.compare((*seat).getShelfName()) == 0) && ((*seat).getHavePower() == slot))
                        {
                            //if so, return the seat
                            ClientFile.close();
                            return seat;
                        }
                    }
                }

                //search seats for tomorrow
                else if (date == 2)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindaytwo();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }

                    //if yes, whether it matches the other conditions
                    if (judge)
                    {
                        if (( ((*seat).getShelfName()).compare(bookshelf) == 0) && (*seat).getHavePower() == slot)
                        {
                            //if so, return the seat
                            ClientFile.close();
                            return seat;
                        }
                    }

                }
            }

            //if there is no matched seat, try to recommend seats in the same room
            for (int i = 0; i < 48; i++)
            {
                bool judge = true;//bool to mark if the seat is choosable later

                                  //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                //search seats for today
                if (date == 1)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindayone();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }
                    //if so, return the seat
                    if (judge)
                    {
                        ClientFile.close();
                        return seat;
                    }
                }

                //search seats for tomorrow
                else if (date == 2)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindaytwo();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }
                    //if so, return the seat
                    if (judge)
                    {
                        ClientFile.close();
                        return seat;
                    }
                }
            }
        }
        //room2 Industry
        else if (room == 2)
        {
            SeatRecord rec;
            fstream ClientFile("Industry.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Industrybook* seat = new Industrybook(1, false, " ", false);

            //read record one by one until getting a appropriate seat
            for (int i = 0; i < 48; i++)
            {
                bool judge = true; //bool to mark if the seat is choosable later

                                   //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                //search seats for today
                if (date == 1)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindayone();

                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }

                    //if yes, whether it matches the other conditions
                    if (judge)
                    {
                        if ((bookshelf.compare((*seat).getShelfName()) == 0) && ((*seat).getHavePower() == slot))
                        {
                            //if so, return the seat
                            ClientFile.close();
                            return seat;
                        }
                    }
                }

                //search seats for tomorrow
                else if (date == 2)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindaytwo();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }

                    //if yes, whether it matches the other conditions
                    if (judge)
                    {
                        if (( ((*seat).getShelfName()).compare(bookshelf) == 0) && (*seat).getHavePower() == slot)
                        {
                            //if so, return the seat
                            ClientFile.close();
                            return seat;
                        }
                    }

                }
            }

            //if there is no matched seat, try to recommend seats in the same room
            for (int i = 0; i < 48; i++)
            {
                bool judge = true;//bool to mark if the seat is choosable later

                                  //read a record
                ClientFile.seekg(i * sizeof(Industrybook));
                ClientFile.read(reinterpret_cast<char*>(seat), sizeof(Industrybook));

                //search seats for today
                if (date == 1)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindayone();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }
                    //if so, return the seat
                    if (judge)
                    {
                        ClientFile.close();
                        return seat;
                    }
                }

                //search seats for tomorrow
                else if (date == 2)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindaytwo();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }
                    //if so, return the seat
                    if (judge)
                    {
                        ClientFile.close();
                        return seat;
                    }
                }
            }
        }
    }

    //floor4
    else if (floor == 4)
    {
        //room1 Social
        if (room == 1)
        {
            SeatRecord rec;
            fstream ClientFile("Social.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Social* seat = new Social(1, false, " ", false);

            //read record one by one until getting a appropriate seat
            for (int i = 0; i < 48; i++)
            {
                bool judge = true; //bool to mark if the seat is choosable later

                                   //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                //search seats for today
                if (date == 1)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindayone();

                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }

                    //if yes, whether it matches the other conditions
                    if (judge)
                    {
                        if ((bookshelf.compare((*seat).getShelfName()) == 0) && ((*seat).getHavePower() == slot))
                        {
                            //if so, return the seat
                            ClientFile.close();
                            return seat;
                        }
                    }
                }

                //search seats for tomorrow
                else if (date == 2)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindaytwo();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }

                    //if yes, whether it matches the other conditions
                    if (judge)
                    {
                        if (( ((*seat).getShelfName()).compare(bookshelf) == 0) && (*seat).getHavePower() == slot)
                        {
                            //if so, return the seat
                            ClientFile.close();
                            return seat;
                        }
                    }

                }
            }

            //if there is no matched seat, try to recommend seats in the same room
            for (int i = 0; i < 48; i++)
            {
                bool judge = true;//bool to mark if the seat is choosable later

                                  //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                //search seats for today
                if (date == 1)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindayone();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }
                    //if so, return the seat
                    if (judge)
                    {
                        ClientFile.close();
                        return seat;
                    }
                }

                //search seats for tomorrow
                else if (date == 2)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindaytwo();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }
                    //if so, return the seat
                    if (judge)
                    {
                        ClientFile.close();
                        return seat;
                    }
                }
            }

        }
        //room2 LawandEconomics
        else if (room == 2)
        {
            SeatRecord rec;
            fstream ClientFile("LawandEconomics.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            LawandEconomics* seat = new LawandEconomics(1, false, " ", false);

            //read record one by one until getting a appropriate seat
            for (int i = 0; i < 48; i++)
            {
                bool judge = true; //bool to mark if the seat is choosable later

                                   //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                //search seats for today
                if (date == 1)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindayone();

                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }

                    //if yes, whether it matches the other conditions
                    if (judge)
                    {
                        if ((bookshelf.compare((*seat).getShelfName()) == 0) && ((*seat).getHavePower() == slot))
                        {
                            //if so, return the seat
                            ClientFile.close();
                            return seat;
                        }
                    }
                }

                //search seats for tomorrow
                else if (date == 2)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindaytwo();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }

                    //if yes, whether it matches the other conditions
                    if (judge)
                    {
                        if (( ((*seat).getShelfName()).compare(bookshelf) == 0) && (*seat).getHavePower() == slot)
                        {
                            //if so, return the seat
                            ClientFile.close();
                            return seat;
                        }
                    }

                }
            }

            //if there is no matched seat, try to recommend seats in the same room
            for (int i = 0; i < 48; i++)
            {
                bool judge = true;//bool to mark if the seat is choosable later

                                  //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                //search seats for today
                if (date == 1)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindayone();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }
                    //if so, return the seat
                    if (judge)
                    {
                        ClientFile.close();
                        return seat;
                    }
                }

                //search seats for tomorrow
                else if (date == 2)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindaytwo();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }
                    //if so, return the seat
                    if (judge)
                    {
                        ClientFile.close();
                        return seat;
                    }
                }
            }
        }
        //room3 Culture
        else if (room == 3)
        {
            SeatRecord rec;
            fstream ClientFile("Culture.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Culture* seat = new Culture(1, false, " ", false);

            //read record one by one until getting a appropriate seat
            for (int i = 0; i < 48; i++)
            {
                bool judge = true; //bool to mark if the seat is choosable later

                                   //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                //search seats for today
                if (date == 1)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindayone();

                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }

                    //if yes, whether it matches the other conditions
                    if (judge)
                    {
                        if ((bookshelf.compare((*seat).getShelfName()) == 0) && ((*seat).getHavePower() == slot))
                        {
                            //if so, return the seat
                            {
                                ClientFile.close();
                                return seat;
                            }
                        }
                    }
                }

                //search seats for tomorrow
                else if (date == 2)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindaytwo();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }

                    //if yes, whether it matches the other conditions
                    if (judge)
                    {
                        if (( ((*seat).getShelfName()).compare(bookshelf) == 0) && (*seat).getHavePower() == slot)
                        {
                            //if so, return the seat
                            {
                                ClientFile.close();
                                return seat;
                            }
                        }
                    }

                }
            }

            //if there is no matched seat, try to recommend seats in the same room
            for (int i = 0; i < 48; i++)
            {
                bool judge = true;//bool to mark if the seat is choosable later

                                  //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                //search seats for today
                if (date == 1)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindayone();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }
                    //if so, return the seat
                    if (judge)
                    {
                        ClientFile.close();
                        return seat;
                    }
                }

                //search seats for tomorrow
                else if (date == 2)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindaytwo();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }
                    //if so, return the seat
                    if (judge)
                    {
                        ClientFile.close();
                        return seat;
                    }
                }
            }
        }
    }

    //floor5
    else if (floor == 5)
    {
        //room1 Pastmagazine
        if (room == 1)
        {
            SeatRecord rec;
            fstream ClientFile("Pastmagazine.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Pastmagazine* seat = new Pastmagazine(1, false, " ", false);

            //read record one by one until getting a appropriate seat
            for (int i = 0; i < 48; i++)
            {
                bool judge = true; //bool to mark if the seat is choosable later

                                   //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                //search seats for today
                if (date == 1)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindayone();

                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }

                    //if yes, whether it matches the other conditions
                    if (judge)
                    {
                        if ((bookshelf.compare((*seat).getShelfName()) == 0) && ((*seat).getHavePower() == slot))
                        {
                            //if so, return the seat
                            {
                                ClientFile.close();
                                return seat;
                            }
                        }
                    }
                }

                //search seats for tomorrow
                else if (date == 2)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindaytwo();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }

                    //if yes, whether it matches the other conditions
                    if (judge)
                    {
                        if (( ((*seat).getShelfName()).compare(bookshelf) == 0) && (*seat).getHavePower() == slot)
                        {
                            //if so, return the seat
                            {
                                ClientFile.close();
                                return seat;
                            }
                        }
                    }

                }
            }

            //if there is no matched seat, try to recommend seats in the same room
            for (int i = 0; i < 48; i++)
            {
                bool judge = true;//bool to mark if the seat is choosable later

                                  //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                //search seats for today
                if (date == 1)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindayone();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }
                    //if so, return the seat
                    if (judge)
                    {
                        ClientFile.close();
                        return seat;
                    }
                }

                //search seats for tomorrow
                else if (date == 2)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindaytwo();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }
                    //if so, return the seat
                    if (judge)
                    {
                        ClientFile.close();
                        return seat;
                    }
                }
            }

        }
        //room2 Naturalmagazine
        else if (room == 2)
        {
            SeatRecord rec;
            fstream ClientFile("Naturalmagazine.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Naturalmagazine* seat = new Naturalmagazine(1, false, " ", false);

            //read record one by one until getting a appropriate seat
            for (int i = 0; i < 48; i++)
            {
                bool judge = true; //bool to mark if the seat is choosable later

                                   //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                //search seats for today
                if (date == 1)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindayone();

                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }

                    //if yes, whether it matches the other conditions
                    if (judge)
                    {
                        if ((bookshelf.compare((*seat).getShelfName()) == 0) && ((*seat).getHavePower() == slot))
                        {
                            //if so, return the seat
                            {
                                ClientFile.close();
                                return seat;
                            }
                        }
                    }
                }

                //search seats for tomorrow
                else if (date == 2)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindaytwo();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }

                    //if yes, whether it matches the other conditions
                    if (judge)
                    {
                        if (( ((*seat).getShelfName()).compare(bookshelf) == 0) && (*seat).getHavePower() == slot)
                        {
                            //if so, return the seat
                            {
                                ClientFile.close();
                                return seat;
                            }
                        }
                    }

                }
            }

            //if there is no matched seat, try to recommend seats in the same room
            for (int i = 0; i < 48; i++)
            {
                bool judge = true;//bool to mark if the seat is choosable later

                                  //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                //search seats for today
                if (date == 1)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindayone();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }
                    //if so, return the seat
                    if (judge)
                    {
                        ClientFile.close();
                        return seat;
                    }
                }

                //search seats for tomorrow
                else if (date == 2)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindaytwo();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }
                    //if so, return the seat
                    if (judge)
                    {
                        ClientFile.close();
                        return seat;
                    }
                }
            }
        }
        //room3 Socialmagazine
        else if (room == 3)
        {
            SeatRecord rec;
            fstream ClientFile("Socialmagazine.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Socialmagazine* seat = new Socialmagazine(1, false, " ", false);

            //read record one by one until getting a appropriate seat
            for (int i = 0; i < 48; i++)
            {
                bool judge = true; //bool to mark if the seat is choosable later

                                   //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                //search seats for today
                if (date == 1)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindayone();

                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }

                    //if yes, whether it matches the other conditions
                    if (judge)
                    {
                        if ((bookshelf.compare((*seat).getShelfName()) == 0) && ((*seat).getHavePower() == slot))
                        {
                            //if so, return the seat
                            {
                                ClientFile.close();
                                return seat;
                            }
                        }
                    }
                }

                //search seats for tomorrow
                else if (date == 2)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindaytwo();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }

                    //if yes, whether it matches the other conditions
                    if (judge)
                    {
                        if (( ((*seat).getShelfName()).compare(bookshelf) == 0) && (*seat).getHavePower() == slot)
                        {
                            //if so, return the seat
                            {
                                ClientFile.close();
                                return seat;
                            }
                        }
                    }

                }
            }

            //if there is no matched seat, try to recommend seats in the same room
            for (int i = 0; i < 48; i++)
            {
                bool judge = true;//bool to mark if the seat is choosable later

                                  //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                //search seats for today
                if (date == 1)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindayone();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }
                    //if so, return the seat
                    if (judge)
                    {
                        ClientFile.close();
                        return seat;
                    }
                }

                //search seats for tomorrow
                else if (date == 2)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindaytwo();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }
                    //if so, return the seat
                    if (judge)
                    {
                        ClientFile.close();
                        return seat;
                    }
                }
            }
        }
        //room4 Englishbook
        else if (room == 4)
        {
            SeatRecord rec;
            fstream ClientFile("Englishbook.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Englishbook* seat = new Englishbook(1, false, " ", false);

            //read record one by one until getting a appropriate seat
            for (int i = 0; i < 48; i++)
            {
                bool judge = true; //bool to mark if the seat is choosable later

                                   //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                //search seats for today
                if (date == 1)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindayone();

                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }

                    //if yes, whether it matches the other conditions
                    if (judge)
                    {
                        if ((bookshelf.compare((*seat).getShelfName()) == 0) && ((*seat).getHavePower() == slot))
                        {
                            //if so, return the seat
                            {
                                ClientFile.close();
                                return seat;
                            }
                        }
                    }
                }

                //search seats for tomorrow
                else if (date == 2)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindaytwo();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }

                    //if yes, whether it matches the other conditions
                    if (judge)
                    {
                        if (( ((*seat).getShelfName()).compare(bookshelf) == 0) && (*seat).getHavePower() == slot)
                        {
                            //if so, return the seat
                            {
                                ClientFile.close();
                                return seat;
                            }
                        }
                    }

                }
            }

            //if there is no matched seat, try to recommend seats in the same room
            for (int i = 0; i < 48; i++)
            {
                bool judge = true;//bool to mark if the seat is choosable later

                                  //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                //search seats for today
                if (date == 1)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindayone();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }
                    //if so, return the seat
                    if (judge)
                    {
                        ClientFile.close();
                        return seat;
                    }
                }

                //search seats for tomorrow
                else if (date == 2)
                {
                    //test if the seat is choosable
                    bool * t = (*seat).getAllOccupancyStatusindaytwo();
                    for (int i = startTime - 1; i < endTime - 1; i++)
                    {
                        if (t[i] != false)
                        {
                            judge = false;
                            break;
                        }
                    }
                    //if so, return the seat
                    if (judge)
                    {
                        ClientFile.close();
                        return seat;
                    }
                }
            }
        }
    }

    //if there is no fit seat in the room,  return a null seat
    Seat * nullSeat = new Seat;
    return nullSeat;
}


bool seatsReservation(int theFloor, int theRoom, int theSeatNumber, bool theSlot, string theBookshelf, int theStartTime, int theEndTime, int theDate, long  theStudentNumber)
{
    int floor = theFloor;
    int room = theRoom;
    int seatNumber = theSeatNumber;
    int startTime = theStartTime;
    int endTime = theEndTime;
    int date = theDate;
    long studentNumber = theStudentNumber;
    //floor 3
    if (floor == 3)
    {
        //room 1 Naturalbook
        if (room == 1)
        {
            SeatRecord rec;
            fstream ClientFile("Naturalbook.dat", ios::out | ios::in | ios::binary);

            //create a objective for reading
            Naturalbook* seat = new Naturalbook(1, false, " ", false);

            //read the wanted seat
            ClientFile.seekg((seatNumber - 1) * sizeof(SeatRecord));
            ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
            record2Seat(&rec, seat);

            //reservation for today
            if (date == 1)
            {
                for (int i = startTime - 1; i < endTime - 1; i++)
                {
                    (*seat).makeOccupancyindayone(i, studentNumber);
                }

                seat2Record(seat, &rec);
                ClientFile.seekp((seatNumber - 1) * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<const char*>(&rec), sizeof(SeatRecord));
                //seat = {};



                //close to release memory
                ClientFile.close();
            }

            //reservation for tomorrow
            else if (date == 2)
            {
                //bool * t = (*seat).getAllOccupancyStatusindaytwo();
                for (int i = startTime - 1; i < endTime - 1; i++)
                {
                    (*seat).makeOccupancyindaytwo(i, studentNumber);
                }

                seat2Record(seat, &rec);
                ClientFile.seekp((seatNumber - 1) * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<const char*>(&rec), sizeof(SeatRecord));

                //close to release memory
                ClientFile.close();
            }

            //reservation success
            delete seat;
            return true;
        }

        //room 2 Industry
        else if (room == 2)
        {
            SeatRecord rec;
            fstream ClientFile("Industry.dat", ios::out | ios::in | ios::binary);

            //create a objective for reading
            Industrybook* seat = new Industrybook(1, false, " ", false);

            //read the wanted seat
            ClientFile.seekg((seatNumber - 1) * sizeof(SeatRecord));
            ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
            record2Seat(&rec, seat);

            //reservation for today
            if (date == 1)
            {
                for (int i = startTime - 1; i < endTime - 1; i++)
                {
                    (*seat).makeOccupancyindayone(i, studentNumber);
                }

                seat2Record(seat, &rec);
                ClientFile.seekp((seatNumber - 1) * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<const char*>(&rec), sizeof(SeatRecord));

                //close to release memory
                ClientFile.close();
            }

            //reservation for tomorrow
            else if (date == 2)
            {
                for (int i = startTime - 1; i < endTime - 1; i++)
                {
                    (*seat).makeOccupancyindaytwo(i, studentNumber);
                }

                seat2Record(seat, &rec);
                ClientFile.seekp((seatNumber - 1) * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<const char*>(&rec), sizeof(SeatRecord));

                //close to release memory
                ClientFile.close();
            }

            //reservation success
            delete seat;
            return true;
        }
    }

    //floor 4
    else if (floor == 4)
    {
        //room 1 Social
        if (room == 1)
        {
            SeatRecord rec;
            fstream ClientFile("Social.dat", ios::out | ios::in | ios::binary);

            //create a objective for reading
            Social* seat = new Social(1, false, " ", false);

            //read the wanted seat
            ClientFile.seekg((seatNumber - 1) * sizeof(SeatRecord));
            ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
            record2Seat(&rec, seat);

            //reservation for today
            if (date == 1)
            {
                for (int i = startTime - 1; i < endTime - 1; i++)
                {
                    (*seat).makeOccupancyindayone(i, studentNumber);
                }

                seat2Record(seat, &rec);
                ClientFile.seekp((seatNumber - 1) * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<const char*>(&rec), sizeof(SeatRecord));

                //close to release memory
                ClientFile.close();
            }

            //reservation for tomorrow
            else if (date == 2)
            {
                for (int i = startTime - 1; i < endTime - 1; i++)
                {
                    (*seat).makeOccupancyindaytwo(i, studentNumber);
                }

                seat2Record(seat, &rec);
                ClientFile.seekp((seatNumber - 1) * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<const char*>(&rec), sizeof(SeatRecord));

                //close to release memory
                ClientFile.close();
            }

            //reservation success
            delete seat;
            return true;
        }

        //room 2 LawandEconomics
        else if (room == 2)
        {
            SeatRecord rec;
            fstream ClientFile("LawandEconomics.dat", ios::out | ios::in | ios::binary);

            //create a objective for reading
            LawandEconomics* seat = new LawandEconomics(1, false, " ", false);

            //read the wanted seat
            ClientFile.seekg((seatNumber - 1) * sizeof(SeatRecord));
            ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
            record2Seat(&rec, seat);

            //reservation for today
            if (date == 1)
            {
                for (int i = startTime - 1; i < endTime - 1; i++)
                {
                    (*seat).makeOccupancyindayone(i, studentNumber);
                }

                seat2Record(seat, &rec);
                ClientFile.seekp((seatNumber - 1) * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<const char*>(&rec), sizeof(SeatRecord));

                //close to release memory
                ClientFile.close();
            }

            //reservation for tomorrow
            else if (date == 2)
            {
                for (int i = startTime - 1; i < endTime - 1; i++)
                {
                    (*seat).makeOccupancyindaytwo(i, studentNumber);
                }

                seat2Record(seat, &rec);
                ClientFile.seekp((seatNumber - 1) * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<const char*>(&rec), sizeof(SeatRecord));

                //close to release memory
                ClientFile.close();
            }

            //reservation success
            delete seat;
            return true;
        }

        //room 3 Culture
        else if (room == 3)
        {
            SeatRecord rec;
            fstream ClientFile("Culture.dat", ios::out | ios::in | ios::binary);

            //create a objective for reading
            Culture* seat = new Culture(1, false, " ", false);

            //read the wanted seat
            ClientFile.seekg((seatNumber - 1) * sizeof(SeatRecord));
            ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
            record2Seat(&rec, seat);

            //reservation for today
            if (date == 1)
            {
                for (int i = startTime - 1; i < endTime - 1; i++)
                {
                    (*seat).makeOccupancyindayone(i, studentNumber);
                }

                seat2Record(seat, &rec);
                ClientFile.seekp((seatNumber - 1) * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<const char*>(&rec), sizeof(SeatRecord));

                //close to release memory
                ClientFile.close();
            }

            //reservation for tomorrow
            else if (date == 2)
            {
                for (int i = startTime - 1; i < endTime - 1; i++)
                {
                    (*seat).makeOccupancyindaytwo(i, studentNumber);
                }

                seat2Record(seat, &rec);
                ClientFile.seekp((seatNumber - 1) * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<const char*>(&rec), sizeof(SeatRecord));

                //close to release memory
                ClientFile.close();
            }

            //reservation success
            delete seat;
            return true;
        }
    }

    //floor 5
    else if (floor == 5)
    {
        //room 1 Pastmagazine
        if (room == 1)
        {
            SeatRecord rec;
            fstream ClientFile("Pastmagazine.dat", ios::out | ios::in | ios::binary);

            //create a objective for reading
            Pastmagazine* seat = new Pastmagazine(1, false, " ", false);

            //read the wanted seat
            ClientFile.seekg((seatNumber - 1) * sizeof(SeatRecord));
            ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
            record2Seat(&rec, seat);

            //reservation for today
            if (date == 1)
            {
                for (int i = startTime - 1; i < endTime - 1; i++)
                {
                    (*seat).makeOccupancyindayone(i, studentNumber);
                }

                seat2Record(seat, &rec);
                ClientFile.seekp((seatNumber - 1) * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<const char*>(&rec), sizeof(SeatRecord));

                //close to release memory
                ClientFile.close();
            }

            //reservation for tomorrow
            else if (date == 2)
            {
                for (int i = startTime - 1; i < endTime - 1; i++)
                {
                    (*seat).makeOccupancyindaytwo(i, studentNumber);
                }

                seat2Record(seat, &rec);
                ClientFile.seekp((seatNumber - 1) * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<const char*>(&rec), sizeof(SeatRecord));

                //close to release memory
                ClientFile.close();
            }

            //reservation success
            delete seat;
            return true;
        }

        //room 2 Naturalmagazine
        else if (room == 2)
        {
            SeatRecord rec;
            fstream ClientFile("Naturalmagazine.dat", ios::out | ios::in | ios::binary);

            //create a objective for reading
            Naturalmagazine* seat = new Naturalmagazine(1, false, " ", false);

            //read the wanted seat
            ClientFile.seekg((seatNumber - 1) * sizeof(SeatRecord));
            ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
            record2Seat(&rec, seat);

            //reservation for today
            if (date == 1)
            {
                for (int i = startTime - 1; i < endTime - 1; i++)
                {
                    (*seat).makeOccupancyindayone(i, studentNumber);
                }

                seat2Record(seat, &rec);
                ClientFile.seekp((seatNumber - 1) * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<const char*>(&rec), sizeof(SeatRecord));

                //close to release memory
                ClientFile.close();
            }

            //reservation for tomorrow
            else if (date == 2)
            {
                for (int i = startTime - 1; i < endTime - 1; i++)
                {
                    (*seat).makeOccupancyindaytwo(i, studentNumber);
                }

                seat2Record(seat, &rec);
                ClientFile.seekp((seatNumber - 1) * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<const char*>(&rec), sizeof(SeatRecord));

                //close to release memory
                ClientFile.close();
            }

            //reservation success
            delete seat;
            return true;
        }

        //room 3 Socialmagazine
        else if (room == 3)
        {
            SeatRecord rec;
            fstream ClientFile("Socialmagazine.dat", ios::out | ios::in | ios::binary);

            //create a objective for reading
            Culture* seat = new Culture(1, false, " ", false);

            //read the wanted seat
            ClientFile.seekg((seatNumber - 1) * sizeof(SeatRecord));
            ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
            record2Seat(&rec, seat);

            //reservation for today
            if (date == 1)
            {
                for (int i = startTime - 1; i < endTime - 1; i++)
                {
                    (*seat).makeOccupancyindayone(i, studentNumber);
                }

                seat2Record(seat, &rec);
                ClientFile.seekp((seatNumber - 1) * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<const char*>(&rec), sizeof(SeatRecord));

                //close to release memory
                ClientFile.close();
            }

            //reservation for tomorrow
            else if (date == 2)
            {
                for (int i = startTime - 1; i < endTime - 1; i++)
                {
                    (*seat).makeOccupancyindaytwo(i, studentNumber);
                }

                seat2Record(seat, &rec);
                ClientFile.seekp((seatNumber - 1) * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<const char*>(&rec), sizeof(SeatRecord));

                //close to release memory
                ClientFile.close();
            }

            //reservation success
            delete seat;
            return true;
        }

        //room 4 Englishbook
        else if (room == 4)
        {
            SeatRecord rec;
            fstream ClientFile("Englishbook.dat", ios::out | ios::in | ios::binary);

            //create a objective for reading
            Englishbook* seat = new Englishbook(1, false, " ", false);

            //read the wanted seat
            ClientFile.seekg((seatNumber - 1) * sizeof(SeatRecord));
            ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
            record2Seat(&rec, seat);

            //reservation for today
            if (date == 1)
            {
                for (int i = startTime - 1; i < endTime - 1; i++)
                {
                    (*seat).makeOccupancyindayone(i, studentNumber);
                }

                seat2Record(seat, &rec);
                ClientFile.seekp((seatNumber - 1) * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<const char*>(&rec), sizeof(SeatRecord));

                //close to release memory
                ClientFile.close();
            }

            //reservation for tomorrow
            else if (date == 2)
            {
                for (int i = startTime - 1; i < endTime - 1; i++)
                {
                    (*seat).makeOccupancyindaytwo(i, studentNumber);
                }

                seat2Record(seat, &rec);
                ClientFile.seekp((seatNumber - 1) * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<const char*>(&rec), sizeof(SeatRecord));

                //close to release memory
                ClientFile.close();
            }

            //reservation success
            delete seat;
            return true;
        }
    }

    //failed
    return false;
}

Seat * seatsSituation(int theFloor, int theRoom, int theSeatNumber)
{
    int floor = theFloor;
    int room = theRoom;
    int seatNumber = theSeatNumber;

    //floor3
    if (floor == 3)
    {
        //room1 Naturalbook
        if (room == 1)
        {
            SeatRecord rec;
            fstream ClientFile("Naturalbook.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Naturalbook* seat = new Naturalbook(1, false, " ", false);

            //read a record
            ClientFile.seekg((seatNumber - 1) * sizeof(SeatRecord));
            ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
            record2Seat(&rec, seat);

            ClientFile.close();
            return seat;
        }

        //room2 Industry
        else if (room == 2)
        {
            SeatRecord rec;
            fstream ClientFile("Industry.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Industrybook* seat = new Industrybook(1, false, " ", false);

            //read a record
            ClientFile.seekg((seatNumber - 1) * sizeof(SeatRecord));
            ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
            record2Seat(&rec, seat);

            ClientFile.close();
            return seat;
        }
    }

    //floor4
    else if (floor == 4)
    {
        //room1 Social
        if (room == 1)
        {
            SeatRecord rec;
            fstream ClientFile("Social.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Social* seat = new Social(1, false, " ", false);

            //read a record
            ClientFile.seekg((seatNumber - 1) * sizeof(SeatRecord));
            ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
            record2Seat(&rec, seat);

            ClientFile.close();
            return seat;
        }

        //room2 LawandEconomics
        else if (room == 2)
        {
            SeatRecord rec;
            fstream ClientFile("LawandEconomics.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            LawandEconomics* seat = new LawandEconomics(1, false, " ", false);

            //read a record
            ClientFile.seekg((seatNumber - 1) * sizeof(SeatRecord));
            ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
            record2Seat(&rec, seat);

            ClientFile.close();
            return seat;
        }

        //room3 Culture
        else if (room == 3)
        {
            SeatRecord rec;
            fstream ClientFile("Culture.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Culture* seat = new Culture(1, false, " ", false);

            //read a record
            ClientFile.seekg((seatNumber - 1) * sizeof(SeatRecord));
            ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
            record2Seat(&rec, seat);

            ClientFile.close();
            return seat;
        }
    }

    //floor5
    else if (floor == 5)
    {
        //room1 Pastmagazine
        if (room == 1)
        {
            SeatRecord rec;
            fstream ClientFile("Pastmagazine.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Pastmagazine* seat = new Pastmagazine(1, false, " ", false);

            //read a record
            ClientFile.seekg((seatNumber - 1) * sizeof(SeatRecord));
            ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
            record2Seat(&rec, seat);

            ClientFile.close();
            return seat;
        }

        //room2 Naturalmagazine
        else if (room == 2)
        {
            SeatRecord rec;
            fstream ClientFile("Naturalmagazine.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Naturalmagazine* seat = new Naturalmagazine(1, false, " ", false);

            //read a record
            ClientFile.seekg((seatNumber - 1) * sizeof(SeatRecord));
            ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
            record2Seat(&rec, seat);

            ClientFile.close();
            return seat;
        }


        //room3 Socialmagazine
        else if (room == 3)
        {
            SeatRecord rec;
            fstream ClientFile("Socialmagazine.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Socialmagazine* seat = new Socialmagazine(1, false, " ", false);

            //read a record
            ClientFile.seekg((seatNumber - 1) * sizeof(SeatRecord));
            ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
            record2Seat(&rec, seat);

            ClientFile.close();
            return seat;
        }

        //room4 Englishbook
        else if (room == 4)
        {
            SeatRecord rec;
            fstream ClientFile("Englishbook.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Englishbook* seat = new Englishbook(1, false, " ", false);

            //read a record
            ClientFile.seekg((seatNumber - 1) * sizeof(SeatRecord));
            ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
            record2Seat(&rec, seat);

            ClientFile.close();
            return seat;
        }
    }
    //if there is no fit seat in the room,  return a null seat
    Seat * nullSeat = new Seat;
    return nullSeat;
}
