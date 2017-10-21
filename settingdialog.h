#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include <mainwindow.h>
#include <QSerialPort>
#include <QDebug>
#include <QMessageBox>
#include "mainwindow.h"
namespace Ui {
class settingDialog;
}
class settingDialog : public QDialog
{
    //friend class MainWindow;
    Q_OBJECT
public:
        explicit settingDialog(QWidget *parent = 0);

  ~settingDialog();


private:
    Ui::settingDialog *ui;
    //QSerialPort *serialPort;
    QTimer *time1;
    QTimer *obotimer;
    QByteArray rxData;
    QSerialPort port;
private slots:
   // void readyReadSlot();
    void on_sendButton_clicked();
    void on_OpenButton_clicked();
};

#endif // SETTINGDIALOG_H
