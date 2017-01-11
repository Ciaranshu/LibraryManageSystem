#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTimer>
#include <iostream>
#include<QDateTime>
#include<QPushButton>
#include<stdlib.h>
#include<QtGui>

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

#include"seatsRecommend.h"
#include"interface.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
        ui->setupUi(this);

        QPushButton *seatsOn3FRoom1 = new QPushButton[48];//group0
        QPushButton *seatsOn3FRoom2 = new QPushButton[48];//group1
        QPushButton *seatsOn4FRoom1 = new QPushButton[48];//group2
        QPushButton *seatsOn4FRoom2 = new QPushButton[48];//group3
        QPushButton *seatsOn4FRoom3 = new QPushButton[48];//group4
        QPushButton *seatsOn5FRoom1 = new QPushButton[48];//group5
        QPushButton *seatsOn5FRoom2 = new QPushButton[48];//group6
        QPushButton *seatsOn5FRoom3 = new QPushButton[48];//group7
        QPushButton *seatsOn5FRoom4 = new QPushButton[48];//group8
        QPushButton *seatsOn3FMutiple = new QPushButton[36];//group9

        ui->lineEdit_passwordInput->setEchoMode(QLineEdit::Password);


        seatsOn3F = new QButtonGroup[2];
        seatsOn4F = new QButtonGroup[3];
        seatsOn5F = new QButtonGroup[4];
        seatsOnMutiple = new QButtonGroup;

      QTimer *timer1=new QTimer(this);//用于时间显示
      QTimer *timerRefresh = new QTimer(this);

      timerRefresh->start(10*60*1000);
      timer1->start(1000);
      connect(timer1, SIGNAL(timeout()), this, SLOT(tim_slot()));

      connect(ui->pushButton_3F_Right,SIGNAL(click()),this,SLOT(on_pushButton_3F_Right_clicked()));
      connect(ui->pushButton_3F_left,SIGNAL(click()),this,SLOT(on_pushButton_3F_left_clicked()));
      connect(ui->pushButton_4F_Right,SIGNAL(click()),this,SLOT(on_pushButton_4F_Right_clicked()));
      connect(ui->pushButton_4F_left,SIGNAL(click()),this,SLOT(on_pushButton_4F_left_clicked()));
      connect(ui->pushButton_5F_Right,SIGNAL(click()),this,SLOT(on_pushButton_5F_Right_clicked()));
      connect(ui->pushButton_5F_left,SIGNAL(click()),this,SLOT(on_pushButton_5F_left_clicked()));

      connect(ui->pushButton_3FTo4F,SIGNAL(clicked()),this,SLOT(on_pushButton_To4F_clicked()));
      connect(ui->pushButton_3FTo5F,SIGNAL(clicked()),this,SLOT(on_pushButton_To5F_clicked()));
      connect(ui->pushButton_4FTo3F,SIGNAL(clicked()),this,SLOT(on_pushButton_To3F_clicked()));
      connect(ui->pushButton_4FTo5F,SIGNAL(clicked()),this,SLOT(on_pushButton_To5F_clicked()));
      connect(ui->pushButton_5FTo3F,SIGNAL(clicked()),this,SLOT(on_pushButton_To3F_clicked()));
      connect(ui->pushButton_5FTo4F,SIGNAL(clicked()),this,SLOT(on_pushButton_To4F_clicked()));

      connect(ui->pushButton_1To2,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_To2_clicked()));
      connect(ui->pushButton_1To3,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_To3_clicked()));
      connect(ui->pushButton_2To1,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_To1_clicked()));
      connect(ui->pushButton_2To3,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_To3_clicked()));
      connect(ui->pushButton_3To1,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_To1_clicked()));
      connect(ui->pushButton_3To2,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_To2_clicked()));
      connect(ui->pushButton_4To1,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_To1_clicked()));
      connect(ui->pushButton_4To2,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_To2_clicked()));
      connect(ui->pushButton_4To3,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_To3_clicked()));

      connect(ui->pushButton_Recommendation,SIGNAL(clicked()),this,SLOT(on_pushButton_Recommendation_clicked()));
      connect(ui->pushButton_Reservation,SIGNAL(clicked()),this,SLOT(on_pushButton_Reservation_clicked()));
      connect(ui->pushButton_SignIn,SIGNAL(click()),this,SLOT(on_pushButton_SignIn_clicked()));
      connect(ui->pushButton_ResultReturn,SIGNAL(clicked()),this,SLOT(on_pushButton_ResultReturn_clicked()));
      connect(ui->pushButton_consult,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_consult_clicked()));

      connect(&seatsOn3F[0],SIGNAL(buttonClicked(int)),this,SLOT(on_seats_Room1_clicked(int)));
      connect(&seatsOn3F[1],SIGNAL(buttonClicked(int)),this,SLOT(on_seats_Room2_clicked(int)));
      connect(&seatsOn4F[0],SIGNAL(buttonClicked(int)),this,SLOT(on_seats_Room1_clicked(int)));
      connect(&seatsOn4F[1],SIGNAL(buttonClicked(int)),this,SLOT(on_seats_Room2_clicked(int)));
      connect(&seatsOn4F[2],SIGNAL(buttonClicked(int)),this,SLOT(on_seats_Room3_clicked(int)));
      connect(&seatsOn5F[0],SIGNAL(buttonClicked(int)),this,SLOT(on_seats_Room1_clicked(int)));
      connect(&seatsOn5F[1],SIGNAL(buttonClicked(int)),this,SLOT(on_seats_Room2_clicked(int)));
      connect(&seatsOn5F[2],SIGNAL(buttonClicked(int)),this,SLOT(on_seats_Room3_clicked(int)));
      connect(&seatsOn5F[3],SIGNAL(buttonClicked(int)),this,SLOT(on_seats_Room4_clicked(int)));
      //connect(seatsOnMutiple,SIGNAL(buttonClicked(int)),this,SLOT(on_seats_Room3_clicked(int)));

      connect(ui->comboBox_1_seatNumber,SIGNAL(currentIndexChanged()),this,SLOT(on_comboBox_1_seatNumber_currentIndexChanged()));



      for(int i =0;i<36;i++){
            seatsOnMutiple->addButton(&seatsOn3FMutiple[i],i);
            seatsOn3FMutiple[i].setStyleSheet("QPushButton{border-image: url(:/new/prefix1/unselected.png);}"
                                            "QPushButton:hover{border-image: url(:/new/prefix1/selected.png);}"
                                            "QPushButton:pressed{border-image: url(:/new/prefix1/selected.png};");
            seatsOn3FMutiple[i].setParent(ui->stackedWidget_3F_Room3);

            if(i == 0){
                seatsOn3FMutiple[i].setGeometry(640,620,57,57);
                continue;
            }
            int x = i/6;
            switch(x){
            case 0:
                seatsOn3FMutiple[i].setGeometry(640,seatsOn3FMutiple[i-1].y()-120,57,57);
                break;
            case 1:
                seatsOn3FMutiple[i].setGeometry(640-120,seatsOn3FMutiple[i-6].y(),57,57);
                break;
            case 2:
                seatsOn3FMutiple[i].setGeometry(640-120*2,seatsOn3FMutiple[i-12].y(),57,57);
                break;
            case 3:
                seatsOn3FMutiple[i].setGeometry(640-120*3,seatsOn3FMutiple[i-18].y(),57,57);
                break;
            case 4:
                seatsOn3FMutiple[i].setGeometry(640-120*4,seatsOn3FMutiple[i-24].y(),57,57);
                break;
            case 5:
                seatsOn3FMutiple[i].setGeometry(640-120*5,seatsOn3FMutiple[i-30].y(),57,57);
                break;
            }

      }


      for(int i=0;i<48;i++){
          seatsOn3FRoom1[i].setStyleSheet("QPushButton{border-image: url(:/new/prefix1/unselected2.png);}"
                                          "QPushButton:hover{border-image: url(:/new/prefix1/selected2.png);}"
                                          "QPushButton:pressed{border-image: url(:/new/prefix1/selected2.png};");

          seatsOn3FRoom1[i].setParent(ui->stackedWidget_3F_Room1);

          seatsOn3FRoom2[i].setStyleSheet("QPushButton{border-image: url(:/new/prefix1/unselected2.png);}"
                                          "QPushButton:hover{border-image: url(:/new/prefix1/selected2.png);}"
                                          "QPushButton:pressed{border-image: url(:/new/prefix1/selected2.png};");

          seatsOn3FRoom2[i].setParent(ui->stackedWidget_3F_Room2);

          seatsOn4FRoom1[i].setStyleSheet("QPushButton{border-image: url(:/new/prefix1/unselected2.png);}"
                                          "QPushButton:hover{border-image: url(:/new/prefix1/selected2.png);}"
                                          "QPushButton:pressed{border-image: url(:/new/prefix1/selected2.png};");

          seatsOn4FRoom1[i].setParent(ui->stackedWidget_4F_Room1);

          seatsOn4FRoom2[i].setStyleSheet("QPushButton{border-image: url(:/new/prefix1/unselected2.png);}"
                                          "QPushButton:hover{border-image: url(:/new/prefix1/selected2.png);}"
                                          "QPushButton:pressed{border-image: url(:/new/prefix1/selected2.png};");

          seatsOn4FRoom2[i].setParent(ui->stackedWidget_4F_Room2);

          seatsOn4FRoom3[i].setStyleSheet("QPushButton{border-image: url(:/new/prefix1/unselected2.png);}"
                                          "QPushButton:hover{border-image: url(:/new/prefix1/selected2.png);}"
                                          "QPushButton:pressed{border-image: url(:/new/prefix1/selected2.png};");

          seatsOn4FRoom3[i].setParent(ui->stackedWidget_4F_Room3);

          seatsOn5FRoom1[i].setStyleSheet("QPushButton{border-image: url(:/new/prefix1/unselected2.png);}"
                                          "QPushButton:hover{border-image: url(:/new/prefix1/selected2.png);}"
                                          "QPushButton:pressed{border-image: url(:/new/prefix1/selected2.png};");

          seatsOn5FRoom1[i].setParent(ui->stackedWidget_5F_Room1);

          seatsOn5FRoom2[i].setStyleSheet("QPushButton{border-image: url(:/new/prefix1/unselected2.png);}"
                                          "QPushButton:hover{border-image: url(:/new/prefix1/selected2.png);}"
                                          "QPushButton:pressed{border-image: url(:/new/prefix1/selected2.png};");

          seatsOn5FRoom2[i].setParent(ui->stackedWidget_5F_Room2);

          seatsOn5FRoom3[i].setStyleSheet("QPushButton{border-image: url(:/new/prefix1/unselected2.png);}"
                                          "QPushButton:hover{border-image: url(:/new/prefix1/selected2.png);}"
                                          "QPushButton:pressed{border-image: url(:/new/prefix1/selected2.png};");

          seatsOn5FRoom3[i].setParent(ui->stackedWidget_5F_Room3);

          seatsOn5FRoom4[i].setStyleSheet("QPushButton{border-image: url(:/new/prefix1/unselected2.png);}"
                                          "QPushButton:hover{border-image: url(:/new/prefix1/selected2.png);}"
                                          "QPushButton:pressed{border-image: url(:/new/prefix1/selected2.png};");

          seatsOn5FRoom4[i].setParent(ui->stackedWidget_5F_Room4);

          seatsOn3F[0].addButton(&seatsOn3FRoom1[i],i);
          seatsOn3F[1].addButton(&seatsOn3FRoom2[i],i);

          seatsOn4F[0].addButton(&seatsOn4FRoom1[i],i);
          seatsOn4F[1].addButton(&seatsOn4FRoom2[i],i);
          seatsOn4F[2].addButton(&seatsOn4FRoom3[i],i);

          seatsOn5F[0].addButton(&seatsOn5FRoom1[i],i);
          seatsOn5F[1].addButton(&seatsOn5FRoom2[i],i);
          seatsOn5F[2].addButton(&seatsOn5FRoom3[i],i);
          seatsOn5F[3].addButton(&seatsOn5FRoom4[i],i);


          int index = i/16;


          switch(index){
            case 0:
              if(i == 0){
                 seatsOn3FRoom1[0].setGeometry(530,630,61,23);
                 seatsOn3FRoom2[0].setGeometry(530,630,61,23);
                 seatsOn4FRoom1[0].setGeometry(530,630,61,23);
                 seatsOn4FRoom2[0].setGeometry(530,630,61,23);
                 seatsOn4FRoom3[0].setGeometry(530,630,61,23);
                 seatsOn5FRoom1[0].setGeometry(530,630,61,23);
                 seatsOn5FRoom2[0].setGeometry(530,630,61,23);
                 seatsOn5FRoom3[0].setGeometry(530,630,61,23);
                 seatsOn5FRoom4[0].setGeometry(530,630,61,23);
                 break;
              }
              else if(i%2 == 1){
                 seatsOn3FRoom1[i].setGeometry(QRect(530,(seatsOn3FRoom1[i-1].y()-30),61,23));
                 seatsOn3FRoom2[i].setGeometry(QRect(530,(seatsOn3FRoom2[i-1].y()-30),61,23));
                 seatsOn4FRoom1[i].setGeometry(QRect(530,(seatsOn4FRoom1[i-1].y()-30),61,23));
                 seatsOn4FRoom2[i].setGeometry(QRect(530,(seatsOn4FRoom2[i-1].y()-30),61,23));
                 seatsOn4FRoom3[i].setGeometry(QRect(530,(seatsOn4FRoom3[i-1].y()-30),61,23));
                 seatsOn5FRoom1[i].setGeometry(QRect(530,(seatsOn5FRoom1[i-1].y()-30),61,23));
                 seatsOn5FRoom2[i].setGeometry(QRect(530,(seatsOn5FRoom2[i-1].y()-30),61,23));
                 seatsOn5FRoom3[i].setGeometry(QRect(530,(seatsOn5FRoom3[i-1].y()-30),61,23));
                 seatsOn5FRoom4[i].setGeometry(QRect(530,(seatsOn5FRoom4[i-1].y()-30),61,23));
              }
              else{
                 seatsOn3FRoom1[i].setGeometry(QRect(530,(seatsOn3FRoom1[i-1].y()-40),61,23));
                 seatsOn3FRoom2[i].setGeometry(QRect(530,(seatsOn3FRoom2[i-1].y()-40),61,23));
                 seatsOn4FRoom1[i].setGeometry(QRect(530,(seatsOn4FRoom1[i-1].y()-40),61,23));
                 seatsOn4FRoom2[i].setGeometry(QRect(530,(seatsOn4FRoom2[i-1].y()-40),61,23));
                 seatsOn4FRoom3[i].setGeometry(QRect(530,(seatsOn4FRoom3[i-1].y()-40),61,23));
                 seatsOn5FRoom1[i].setGeometry(QRect(530,(seatsOn5FRoom1[i-1].y()-40),61,23));
                 seatsOn5FRoom2[i].setGeometry(QRect(530,(seatsOn5FRoom2[i-1].y()-40),61,23));
                 seatsOn5FRoom3[i].setGeometry(QRect(530,(seatsOn5FRoom3[i-1].y()-40),61,23));
                 seatsOn5FRoom4[i].setGeometry(QRect(530,(seatsOn5FRoom4[i-1].y()-40),61,23));
              }
              break;
            case 1:
              seatsOn3FRoom1[i].setGeometry(QRect(350,seatsOn3FRoom1[i-16].y(),61,23));
              seatsOn3FRoom2[i].setGeometry(QRect(350,seatsOn3FRoom2[i-16].y(),61,23));
              seatsOn4FRoom1[i].setGeometry(QRect(350,seatsOn4FRoom1[i-16].y(),61,23));
              seatsOn4FRoom2[i].setGeometry(QRect(350,seatsOn4FRoom2[i-16].y(),61,23));
              seatsOn4FRoom3[i].setGeometry(QRect(350,seatsOn4FRoom3[i-16].y(),61,23));
              seatsOn5FRoom1[i].setGeometry(QRect(350,seatsOn5FRoom1[i-16].y(),61,23));
              seatsOn5FRoom2[i].setGeometry(QRect(350,seatsOn5FRoom2[i-16].y(),61,23));
              seatsOn5FRoom3[i].setGeometry(QRect(350,seatsOn5FRoom3[i-16].y(),61,23));
              seatsOn5FRoom4[i].setGeometry(QRect(350,seatsOn5FRoom4[i-16].y(),61,23));
              break;
            case 2:
              seatsOn3FRoom1[i].setGeometry(QRect(170,seatsOn3FRoom1[i-32].y(),61,23));
              seatsOn3FRoom2[i].setGeometry(QRect(170,seatsOn3FRoom2[i-32].y(),61,23));
              seatsOn4FRoom1[i].setGeometry(QRect(170,seatsOn4FRoom1[i-32].y(),61,23));
              seatsOn4FRoom2[i].setGeometry(QRect(170,seatsOn4FRoom2[i-32].y(),61,23));
              seatsOn4FRoom3[i].setGeometry(QRect(170,seatsOn4FRoom3[i-32].y(),61,23));
              seatsOn5FRoom1[i].setGeometry(QRect(170,seatsOn5FRoom1[i-32].y(),61,23));
              seatsOn5FRoom2[i].setGeometry(QRect(170,seatsOn5FRoom2[i-32].y(),61,23));
              seatsOn5FRoom3[i].setGeometry(QRect(170,seatsOn5FRoom3[i-32].y(),61,23));
              seatsOn5FRoom4[i].setGeometry(QRect(170,seatsOn5FRoom3[i-32].y(),61,23));
              break;
          }
      }





}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tim_refresh_slot()//十分钟刷新一次座位表
{
    refresh((new QDateTime)->currentDateTime().toString("h").toStdString(),(new QDateTime)->currentDateTime().toString("m").toStdString(),1);
}

void MainWindow::tim_slot()//时间显示
{
     ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
     ui->lcdNumber->display((new QDateTime)->currentDateTime().toString("hh:mm"));

     if((new QDateTime)->currentDateTime().toString("hh:mm")=="00:00"){
         upDate(3,1);
         upDate(3,2);
         upDate(3,3);
         upDate(4,1);
         upDate(4,2);
         upDate(4,3);
         upDate(5,1);
         upDate(5,2);
         upDate(5,3);
         upDate(5,4);
     }

  }


void MainWindow::on_pushButton_3F_Right_clicked()//3F stacked widget move right
{
    int i = ui->stackedWidget_3F->currentIndex();
    ui->stackedWidget_3F->setCurrentIndex(++i);

}

void MainWindow::on_pushButton_3F_left_clicked()//3F stacked widget move left
{
    int i = ui->stackedWidget_3F->currentIndex();
    ui->stackedWidget_3F->setCurrentIndex(--i);
}

void MainWindow::on_pushButton_4F_Right_clicked()
{
    int i = ui->stackedWidget_4F->currentIndex();
    ui->stackedWidget_4F->setCurrentIndex(++i);
}

void MainWindow::on_pushButton_4F_left_clicked()
{
    int i = ui->stackedWidget_4F->currentIndex();
    ui->stackedWidget_4F->setCurrentIndex(--i);
}


void MainWindow::on_pushButton_5F_Right_clicked()
{
    int i = ui->stackedWidget_5F->currentIndex();
    ui->stackedWidget_5F->setCurrentIndex(++i);
}

void MainWindow::on_pushButton_5F_left_clicked()
{
    int i = ui->stackedWidget_5F->currentIndex();
    ui->stackedWidget_5F->setCurrentIndex(--i);
}


void MainWindow::on_pushButton_To3F_clicked()
{
    ui->stackedWidget_FloorDraft->setCurrentIndex(0);
}


void MainWindow::on_pushButton_To4F_clicked()
{
    ui->stackedWidget_FloorDraft->setCurrentIndex(1);
}



void MainWindow::on_pushButton_To5F_clicked()
{
    ui->stackedWidget_FloorDraft->setCurrentIndex(2);
}

void MainWindow::on_pushButton_To1_clicked(){
    ui->stackedWidget_Function->setCurrentIndex(0);
}

void MainWindow::on_pushButton_To2_clicked(){
    ui->stackedWidget_Function->setCurrentIndex(1);
}

void MainWindow::on_pushButton_To3_clicked(){
    ui->stackedWidget_Function->setCurrentIndex(2);
}

void MainWindow::on_pushButton_Recommendation_clicked(){

      Seat *RecommendSeat = seatsRecommend(ui->comboBox_2_floorNumber->currentIndex()+3,
                                           ui->comboBox_2_roomNumber->currentIndex()+1,
                                           0,
                                           (ui->comboBox_1_slot->currentIndex()==1),
                                           ui->comboBox_2_bookShelf->currentText().toStdString(),
                                           ui->comboBox_2_initialTime->currentIndex()+1,
                                           ui->comboBox_2_endTime->currentIndex()+1,
                                           ui->comboBox_2_DateSet->currentIndex()+1);

     ui->stackedWidget_FloorDraft->setCurrentIndex(RecommendSeat->getFloor()-3);

     if(RecommendSeat->getFloor()==3&&RecommendSeat->getRoom()==3){
           ui->stackedWidget_3F->setCurrentIndex(RecommendSeat->getRoom()-1);
           seatsOnMutiple->button(RecommendSeat->getNumber()-1)->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/selected.png);}");
     }
     else{
        switch(RecommendSeat->getFloor()){
            case 3:
                 ui->stackedWidget_3F->setCurrentIndex(RecommendSeat->getRoom()-1);
                seatsOn3F[RecommendSeat->getRoom()-1].button(RecommendSeat->getNumber()-1)->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/selected2.png);}");
                break;
            case 4:
                 ui->stackedWidget_4F->setCurrentIndex(RecommendSeat->getRoom()-1);
                seatsOn4F[RecommendSeat->getRoom()-1].button(RecommendSeat->getNumber()-1)->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/selected2.png);}");
                break;
            case 5:
                ui->stackedWidget_5F->setCurrentIndex(RecommendSeat->getRoom()-1);
                seatsOn5F[RecommendSeat->getRoom()-1].button(RecommendSeat->getNumber()-1)->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/selected2.png);}");
                break;
        }
     }

     ui->comboBox_1_DateSet->setCurrentIndex(ui->comboBox_2_DateSet->currentIndex());
     ui->comboBox_1_endTime->setCurrentIndex(ui->comboBox_2_endTime->currentIndex());
     ui->comboBox_1_initialTime->setCurrentIndex(ui->comboBox_2_initialTime->currentIndex());
     ui->comboBox_1_bookShelf->setCurrentText(QString::fromStdString(RecommendSeat->getShelfName()));
     ui->comboBox_1_floorNumber->setCurrentIndex(RecommendSeat->getFloor()-3);
     ui->comboBox_1_roomNumber->setCurrentIndex(RecommendSeat->getRoom()-1);
     ui->comboBox_1_slot->setCurrentIndex((int)RecommendSeat->getHavePower());
     ui->comboBox_1_seatNumber->setCurrentIndex(RecommendSeat->getNumber()-1);
     ui->stackedWidget_Function->setCurrentIndex(0);
     delete RecommendSeat;

}

void MainWindow::on_pushButton_Reservation_clicked()
{
    ui->stackedWidget_Function->setCurrentIndex(3);

}

void MainWindow::on_pushButton_SignIn_clicked()
{
    static bool logged = false;


    const char* password = ui->lineEdit_usersnameInput->text().toStdString().c_str();
    long studentNumber = atol(password);

    if (logged){
       seatsReservation(ui->comboBox_1_floorNumber->currentIndex()+3,
                            ui->comboBox_1_roomNumber->currentIndex()+1,
                            ui->comboBox_1_seatNumber->currentIndex()+1,
                            (ui->comboBox_1_slot->currentIndex()==1),
                            ui->comboBox_1_bookShelf->currentText().toStdString(),
                            ui->comboBox_1_initialTime->currentIndex()+1,
                            ui->comboBox_1_endTime->currentIndex()+1,
                            ui->comboBox_1_DateSet->currentIndex()+1,
                            studentNumber);

         ui->label_displayResult->setText(QString::fromStdString("再次预约成功"));


         ui->stackedWidget_Function->setCurrentIndex(4);
        return;
    }

    ui->stackedWidget_Function->setCurrentIndex(3);
    if(accountVerification(ui->lineEdit_usersnameInput->text().toStdString(),ui->lineEdit_passwordInput->text().toStdString())){
        bool reserved = seatsReservation(ui->comboBox_1_floorNumber->currentIndex()+3,
                                         ui->comboBox_1_roomNumber->currentIndex()+1,
                                         ui->comboBox_1_seatNumber->currentIndex()+1,
                                         (ui->comboBox_1_slot->currentIndex()==1),
                                         ui->comboBox_1_bookShelf->currentText().toStdString(),
                                         ui->comboBox_1_initialTime->currentIndex()+1,
                                         ui->comboBox_1_endTime->currentIndex()+1,
                                         ui->comboBox_1_DateSet->currentIndex()+1,
                                         studentNumber);
        if(reserved)
        {
            ui->label_displayResult->setText(QString::fromStdString("预约成功"));

        }
        else{
             ui->label_displayResult->setText(QString::fromStdString("预约失败"));
        }
        logged = true;
    }
    else{
         ui->label_displayResult->setText(QString::fromStdString("用户名或密码错误"));
    }

    ui->lineEdit_usersnameInput->clear();
    ui->lineEdit_passwordInput->clear();
    ui->stackedWidget_Function->setCurrentIndex(4);

    bool seatsReservation(int theFloor, int theRoom, int theSeatNumber, bool theSlot, string theBookshelf, int startTime, int endTime, int theDate, long  studentNumber);
    bool accountVerification(string userName, string passWord);
}

void MainWindow::on_pushButton_ResultReturn_clicked()
{
    ui->stackedWidget_Function->setCurrentIndex(0);
}

void MainWindow::on_comboBox_1_seatNumber_currentIndexChanged()
{
    refresh((new QDateTime)->currentDateTime().toString("h").toStdString(),(new QDateTime)->currentDateTime().toString("m").toStdString(),1);
}

// Seat * seatsSituation(int theFloor, int theRoom, int theSeatNumber);
void MainWindow::on_seats_Room1_clicked(int buttonId){

    Seat *clickedSeat = seatsSituation(ui->stackedWidget_FloorDraft->currentIndex()+3,1,buttonId+1);
    ui->comboBox_1_bookShelf->setCurrentText(QString::fromStdString(clickedSeat->getShelfName()));
    ui->comboBox_1_floorNumber->setCurrentIndex(clickedSeat->getFloor()-3);
    ui->comboBox_1_roomNumber->setCurrentIndex(clickedSeat->getRoom()-1);
    if(clickedSeat->getFloor()==5){
        ui->comboBox_1_slot->setCurrentIndex(1);
    }
    else{
        ui->comboBox_1_slot->setCurrentIndex(0);
    }
    ui->comboBox_1_seatNumber->setCurrentIndex(buttonId);
    ui->stackedWidget_Function->setCurrentIndex(0);
    delete clickedSeat;

}

void MainWindow::on_seats_Room2_clicked(int buttonId){

    Seat *clickedSeat = seatsSituation(ui->stackedWidget_FloorDraft->currentIndex()+3,2,buttonId+1);
    ui->comboBox_1_bookShelf->setCurrentText(QString::fromStdString(clickedSeat->getShelfName()));
    ui->comboBox_1_floorNumber->setCurrentIndex(clickedSeat->getFloor()-3);
    ui->comboBox_1_roomNumber->setCurrentIndex(clickedSeat->getRoom()-1);
    if(clickedSeat->getFloor()==5){
        ui->comboBox_1_slot->setCurrentIndex(1);
    }
    else{
        ui->comboBox_1_slot->setCurrentIndex(0);
    }
    ui->comboBox_1_seatNumber->setCurrentIndex(buttonId);
    ui->stackedWidget_Function->setCurrentIndex(0);
    delete clickedSeat;
}

void MainWindow::on_seats_Room3_clicked(int buttonId){

    Seat *clickedSeat = seatsSituation(ui->stackedWidget_FloorDraft->currentIndex()+3,3,buttonId+1);
    ui->comboBox_1_floorNumber->setCurrentIndex(clickedSeat->getFloor()-3);
    ui->comboBox_1_roomNumber->setCurrentIndex(clickedSeat->getRoom()-1);
    if(clickedSeat->getFloor()==5){
        ui->comboBox_1_slot->setCurrentIndex(1);
    }
    else{
        ui->comboBox_1_slot->setCurrentIndex(0);
    }
    ui->comboBox_1_seatNumber->setCurrentIndex(buttonId);
    ui->stackedWidget_Function->setCurrentIndex(0);
    delete clickedSeat;
}

void MainWindow::on_seats_Room4_clicked(int buttonId){

    Seat *clickedSeat = seatsSituation(ui->stackedWidget_FloorDraft->currentIndex()+3,4,buttonId+1);
    ui->comboBox_1_bookShelf->setCurrentText(QString::fromStdString(clickedSeat->getShelfName()));
    ui->comboBox_1_floorNumber->setCurrentIndex(clickedSeat->getFloor()-3);
    ui->comboBox_1_roomNumber->setCurrentIndex(clickedSeat->getRoom()-1);
    if(clickedSeat->getFloor()==5){
        ui->comboBox_1_slot->setCurrentIndex(1);
    }
    else{
        ui->comboBox_1_slot->setCurrentIndex(0);
    }
    ui->comboBox_1_seatNumber->setCurrentIndex(buttonId);
    ui->stackedWidget_Function->setCurrentIndex(0);
    delete clickedSeat;
}


void MainWindow::on_pushButton_consult_clicked()
{
    refreshseat(ui->comboBox_3_consultPeriod->currentIndex(),ui->comboBox_3_DateSet->currentIndex()+1);
}

//bool* getSeatsSituation(int theFloor,int theRoom,bool *a,int currentTime, int date=0)
void MainWindow::refresh(string refreshHour,string refreshMinute,int date){

    int hour = atoi(refreshHour.c_str());
    int minute = atoi(refreshMinute.c_str());
    int currentPeriod = (hour - 8)*2+(int)(minute / 30);

   if(hour<8&&minute>21){
       return;
   }

   refreshseat(currentPeriod,date);
}


void MainWindow::refreshseat(int currentPeriod,int date)
{

    bool seatJudge[48] = {};

    for(int j=0;j<2;j++){
         getSeatsSituation(3,j+1,seatJudge,currentPeriod,date);

         for(int i=0;i<48;i++){
             if(seatJudge[i]){

                 seatsOn3F[j].button(i)->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/disable2.png);}");
             }
             else{
                 seatsOn3F[j].button(i)->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/unselected2.png);}"
                                                       "QPushButton:hover{border-image: url(:/new/prefix1/selected2.png);}"
                                                       "QPushButton:pressed{border-image: url(:/new/prefix1/selected2.png};");
             }

     }

   }

    for(int j=0;j<3;j++){
         getSeatsSituation(4,j+1,seatJudge,currentPeriod,date);

         for(int i=0;i<48;i++){
             if(seatJudge[i]){
                 seatsOn4F[j].button(i)->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/disable2.png);}");
             }
             else{
                 seatsOn4F[j].button(i)->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/unselected2.png);}"
                                                       "QPushButton:hover{border-image: url(:/new/prefix1/selected2.png);}"
                                                       "QPushButton:pressed{border-image: url(:/new/prefix1/selected2.png};");
             }

    }
   }

    for(int j=0;j<4;j++){
         getSeatsSituation(5,j+1,seatJudge,currentPeriod,date);

         for(int i=0;i<48;i++){
             if(seatJudge[i]){
                 seatsOn5F[j].button(i)->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/disable2.png);}");
             }
             else{
                 seatsOn5F[j].button(i)->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/unselected2.png);}"
                                                       "QPushButton:hover{border-image: url(:/new/prefix1/selected2.png);}"
                                                       "QPushButton:pressed{border-image: url(:/new/prefix1/selected2.png};");
             }

    }
   }

    getSeatsSituation(3,3,seatJudge,currentPeriod,date);

    for(int i=0;i<36;i++){
        if(seatJudge[i]){
            seatsOnMutiple->button(i)->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/disable.png);}");
        }
        else{
            seatsOnMutiple->button(i)->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/unselected.png);}"
                                                     "QPushButton:hover{border-image: url(:/new/prefix1/selected.png);}"
                                                     "QPushButton:pressed{border-image: url(:/new/prefix1/selected.png};");
        }

     }

}
