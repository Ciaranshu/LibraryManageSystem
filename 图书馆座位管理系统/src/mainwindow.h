#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include<QButtonGroup>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void refresh(std::string,std::string,int);
    void refreshseat(int,int);

private slots:

    void tim_slot();

    void tim_refresh_slot();


    void on_pushButton_3F_Right_clicked();

    void on_pushButton_3F_left_clicked();

    void on_pushButton_4F_Right_clicked();

    void on_pushButton_4F_left_clicked();

    void on_pushButton_5F_Right_clicked();

    void on_pushButton_5F_left_clicked();

    void on_pushButton_To3F_clicked();

    void on_pushButton_To4F_clicked();

    void on_pushButton_To5F_clicked();

    void on_pushButton_To1_clicked();

    void on_pushButton_To2_clicked();

    void on_pushButton_To3_clicked();


    void on_pushButton_Recommendation_clicked();

    void on_pushButton_Reservation_clicked();

    void on_pushButton_SignIn_clicked();

    void on_pushButton_ResultReturn_clicked();


    void on_comboBox_1_seatNumber_currentIndexChanged();

    void on_seats_Room1_clicked(int);

    void on_seats_Room2_clicked(int);

    void on_seats_Room3_clicked(int);

    void on_seats_Room4_clicked(int);



    void on_pushButton_consult_clicked();

private:
    Ui::MainWindow *ui;

    QButtonGroup *seatsOn3F;
    QButtonGroup *seatsOn4F;
    QButtonGroup *seatsOn5F;
    QButtonGroup *seatsOnMutiple;


};

#endif // MAINWINDOW_H
