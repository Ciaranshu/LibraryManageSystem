#include"Seat.h"
#include"Natural.h"
#include"FifthSeat.h"
#include"FourthSeat.h"
#include"ThirdSeat.h"
#include"Computerreading.h"
#include"Culture.h"
#include"Englishbook.h"
#include"Industry.h"
#include"LawandEconomics.h"
#include"Natural.h"
#include"Naturalmagazine.h"
#include"Pastmagazine.h"
#include"Computerreading.h"
#include"Social.h"
#include"Socialmagazine.h"
#include<iostream>
#include<fstream>

using namespace std;
//a is an array of bool byte
//currentTime is the time at this moment,with range from 0 to 12
bool* getSeatsSituation(int theFloor,int theRoom,bool *a,int currentTime, int date=0)
{

    int floor = theFloor;
    int room = theRoom;

    //floor3
    if (floor == 3)
    {
        //room1 Naturalbook
        if (room == 1)
        {
            fstream ClientFile("Naturalbook.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Naturalbook* seat = new Naturalbook(1, false, " ", false);
                        SeatRecord rec;
            //read record one by one until getting a appropriate seat
            for (int i = 0; i < 48; i++)
            {


                //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                if(date==1)
                {
                    a[i]=(*seat).getAllOccupancyStatusindayone()[currentTime];

                }
                else  a[i]=(*seat).getAllOccupancyStatusindaytwo()[currentTime];

            }
            delete seat;
            ClientFile.close();
            return a;
        }
        //room2 Industrybook
        else if (room == 2)
        {
            fstream ClientFile("Industry.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Industrybook* seat = new Industrybook(1, false, " ", false);
                        SeatRecord rec;
            //read record one by one until getting a appropriate seat
            for (int i = 0; i < 48; i++)
            {

                                   //read a record

                //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);
                if(date==1)
                a[i]=(*seat).getAllOccupancyStatusindayone()[currentTime];
                else
                    a[i]=(*seat).getAllOccupancyStatusindaytwo()[currentTime];



            }
            delete seat;
            ClientFile.close();
            return a;

        }
        else if (room == 2)
        {
            fstream ClientFile("Computerreading.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Computerreading* seat = new Computerreading(1, false, " ", false);

            //read record one by one until getting a appropriate seat
            SeatRecord rec;
            for (int i = 0; i < 36; i++)
            {


                //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);
                if(date==1)
                a[i]=(*seat).getAllOccupancyStatusindayone()[currentTime];
                else
                    a[i]=(*seat).getAllOccupancyStatusindaytwo()[currentTime];



            }
            ClientFile.close();

            return a;

        }
    }

    //floor4
    else if (floor == 4)
    {
        //room1 Social
        if (room == 1)
        {
            fstream ClientFile("Social.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Social* seat = new Social(1, false, " ", false);

            //read record one by one until getting a appropriate seat
                        SeatRecord rec;
            for (int i = 0; i < 48; i++)
            {


                //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);
                a[i]=(*seat).getAllOccupancyStatusindayone()[currentTime];


            }
            ClientFile.close();

            return a;


        }
        //room2 LawandEconomics
        else if (room == 2)
        {
            fstream ClientFile("LawandEconomics.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            LawandEconomics* seat = new LawandEconomics(1, false, " ", false);

            //read record one by one until getting a appropriate seat
                        SeatRecord rec;
            for (int i = 0; i < 48; i++)
            {

                //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);
                if(date==1)
                a[i]=(*seat).getAllOccupancyStatusindayone()[currentTime];
                else
                    a[i]=(*seat).getAllOccupancyStatusindaytwo()[currentTime];

            }
            ClientFile.close();

            return a;

        }
        //room3 Culture
        else if (room == 3)
        {
            fstream ClientFile("Culture.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Culture* seat = new Culture(1, false, " ", false);

            //read record one by one until getting a appropriate seat
                        SeatRecord rec;
            for (int i = 0; i < 48; i++)
            {

                //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);
                if(date==1)
                a[i]=(*seat).getAllOccupancyStatusindayone()[currentTime];
                else
                    a[i]=(*seat).getAllOccupancyStatusindaytwo()[currentTime];

            }
            ClientFile.close();

            return a;
        }
    }

    //floor5
    else if (floor == 5)
    {
        //room1 Pastmagazine
        if (room == 1)
        {
            fstream ClientFile("Pastmagazine.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Pastmagazine* seat = new Pastmagazine(1, false, " ", false);

            //read record one by one until getting a appropriate seat
                        SeatRecord rec;
            for (int i = 0; i < 48; i++)
            {


                //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);
                if(date==1)
                a[i]=(*seat).getAllOccupancyStatusindayone()[currentTime];
                else
                    a[i]=(*seat).getAllOccupancyStatusindaytwo()[currentTime];
                //search seats for today

            }
            ClientFile.close();

            return a;

        }
        //room2 Naturalmagazine
        else if (room == 2)
        {
            fstream ClientFile("Naturalmagazine.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Naturalmagazine* seat = new Naturalmagazine(1, false, " ", false);

            //read record one by one until getting a appropriate seat
                        SeatRecord rec;
            for (int i = 0; i < 48; i++)
            {

                                   //read a record

                //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);
                if(date==1)
                a[i]=(*seat).getAllOccupancyStatusindayone()[currentTime];
                else
                    a[i]=(*seat).getAllOccupancyStatusindaytwo()[currentTime];

            }
            ClientFile.close();

            return a;
        }
        //room3 Socialmagazine
        else if (room == 3)
        {
            fstream ClientFile("Socialmagazine.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Socialmagazine* seat = new Socialmagazine(1, false, " ", false);

            //read record one by one until getting a appropriate seat
                        SeatRecord rec;
            for (int i = 0; i < 48; i++)
            {

                //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);
                if(date==1)
                a[i]=(*seat).getAllOccupancyStatusindayone()[currentTime];
                else
                a[i]=(*seat).getAllOccupancyStatusindaytwo()[currentTime];
            }
            ClientFile.close();

            return a;

        }


    }return a;
}






bool accountVerification(string userName, string passWord){

    string _account;
    string _password;
    ifstream in("account password.txt"); // the name of file can be
                                         // the format of the data shoube :account+space+password
                                         // one account one line
                                         //for example:
                                         //201530541562 123456
                                         //201530541563 111111

    if(!in)
    {
        cerr << "txt\" could not be opened.";
        in.close();
        return false;
    }

    while(in>>_account)
    {
        if(_account==userName)
        {
            in>>_password;
            if(_password==passWord)
            {

                in.close();
                return true;
            }
            else
                in.close();
                return false;
        }
        else
        {
            // to skip the wrong line
            in>>_password;
            continue;
        }

    }
    in.close();
    return false;
}


void upDate(int theFloor,int theRoom)
{

    int floor = theFloor;
    int room = theRoom;

    //floor3
    if (floor == 3)
    {
        //room1 Naturalbook
        if (room == 1)
        {
            fstream ClientFile("Naturalbook.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Naturalbook *seat = new Naturalbook(1, false, " ", false);

            //read record one by one until getting a appropriate seat
                        SeatRecord rec;
            for (int i = 0; i < 48; i++)
            {



                //read a record
                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                (*seat).refresh();
                seat2Record(seat, &rec);
                ClientFile.seekp(i * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));

            }
            ClientFile.close();

        }
        //room2 Industrybook
        else if (room == 2)
        {
            fstream ClientFile("Industry.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Industrybook* seat = new Industrybook(1, false, " ", false);

            //read record one by one until getting a appropriate seat
                        SeatRecord rec;
            for (int i = 0; i < 48; i++)
            {

                                   //read a record

                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                (*seat).refresh();
                seat2Record(seat, &rec);
                ClientFile.seekp(i * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));



            }
            ClientFile.close();



        }
        else if (room == 2)
        {
            fstream ClientFile("Computerreading.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Computerreading* seat = new Computerreading(1, false, " ", false);

            //read record one by one until getting a appropriate seat
            SeatRecord rec;
            for (int i = 0; i < 36; i++)
            {
                                   //read a record

                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                (*seat).refresh();
                seat2Record(seat, &rec);
                ClientFile.seekp(i * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));


            }
            ClientFile.close();



        }
    }

    //floor4
    else if (floor == 4)
    {
        //room1 Social
        if (room == 1)
        {
            fstream ClientFile("Social.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Social* seat = new Social(1, false, " ", false);

            //read record one by one until getting a appropriate seat
                        SeatRecord rec;
            for (int i = 0; i < 48; i++)
            {
                                   //read a record

                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                (*seat).refresh();
                seat2Record(seat, &rec);
                ClientFile.seekp(i * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));

            }
            ClientFile.close();




        }
        //room2 LawandEconomics
        else if (room == 2)
        {
            fstream ClientFile("LawandEconomics.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            LawandEconomics* seat = new LawandEconomics(1, false, " ", false);

                        SeatRecord rec;

            //read record one by one until getting a appropriate seat
            for (int i = 0; i < 48; i++)
            {
                                   //read a record

                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                (*seat).refresh();
                seat2Record(seat, &rec);
                ClientFile.seekp(i * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));


            }
            ClientFile.close();



        }
        //room3 Culture
        else if (room == 3)
        {
            fstream ClientFile("Culture.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Culture* seat = new Culture(1, false, " ", false);

            //read record one by one until getting a appropriate seat
                        SeatRecord rec;
            for (int i = 0; i < 48; i++)
            {

                                   //read a record

                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                (*seat).refresh();
                seat2Record(seat, &rec);
                ClientFile.seekp(i * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));


            }
            ClientFile.close();


        }
    }

    //floor5
    else if (floor == 5)
    {
        //room1 Pastmagazine
        if (room == 1)
        {
            fstream ClientFile("Pastmagazine.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Pastmagazine* seat = new Pastmagazine(1, false, " ", false);

            //read record one by one until getting a appropriate seat
                        SeatRecord rec;
            for (int i = 0; i < 48; i++)
            {
                                   //read a record

                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                (*seat).refresh();
                seat2Record(seat, &rec);
                ClientFile.seekp(i * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));

            }
            ClientFile.close();



        }
        //room2 Naturalmagazine
        else if (room == 2)
        {
            fstream ClientFile("Naturalmagazine.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Naturalmagazine* seat = new Naturalmagazine(1, false, " ", false);

            //read record one by one until getting a appropriate seat
                        SeatRecord rec;
            for (int i = 0; i < 48; i++)
            {

                                   //read a record

                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                (*seat).refresh();
                seat2Record(seat, &rec);
                ClientFile.seekp(i * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));

            }
            ClientFile.close();


        }
        //room3 Socialmagazine
        else if (room == 3)
        {
            fstream ClientFile("Socialmagazine.dat", ios::out | ios::in | ios::binary);

            //create a null objective
            Socialmagazine* seat = new Socialmagazine(1, false, " ", false);

            //read record one by one until getting a appropriate seat
                        SeatRecord rec;
            for (int i = 0; i < 48; i++)
            {
                                   //read a record

                ClientFile.seekg(i * sizeof(SeatRecord));
                ClientFile.read(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));
                record2Seat(&rec, seat);

                (*seat).refresh();
                seat2Record(seat, &rec);
                ClientFile.seekp(i * sizeof(SeatRecord));
                ClientFile.write(reinterpret_cast<char*>(&rec), sizeof(SeatRecord));

            }
            ClientFile.close();

        }


    }
}
