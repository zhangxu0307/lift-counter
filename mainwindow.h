#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QTimer>
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>
#include <QFile>
#include <QInputDialog>
#include <QFileDialog>
#include "settingdialog.h"
#include "mysqloperation.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    //friend class settingDialog;
    Q_OBJECT



public:
    explicit MainWindow(QWidget *parent = 0);
    static QSerialPort *serialPort;
    static QTimer *time1;
    static int number;
    static int weight;
    static int energy;

    ~MainWindow();

private:

    Ui::MainWindow *ui;

    //Mysqloperation mySql1;

    QTimer *obotimer;
    QTimer *timer2;    //定时计刷新系统时间
    QString time;      //系统时间显示文本
    QDateTime systime; //新建时间对象
    QByteArray rxData;



private slots:
    //按钮
//    void on_sendButton_clicked();
    //void on_openButton_clicked();
    //void on_closeButton_clicked();
    //菜单栏
//    void on_OpenAction_triggered();
    void on_CloseAction_triggered();
//    void on_SaveAction_triggered();
    void on_ClearAction_triggered();
    void on_ExitAction_triggered();
    //其他
    void readyReadSlot();
    void display();
    void setWeight();
    //两个界面
    void Setting();
    void Saving();
    //系统时间更新
    void timeUpDate();
};

#endif // MAINWINDOW_H
