#include "mainwindow.h"
#include "ui_mainwindow.h"

int MainWindow::number = 0;
int MainWindow::weight = 0;
int MainWindow::energy = 0;
QSerialPort *(MainWindow::serialPort) = new QSerialPort();
QTimer *(MainWindow::time1) = new QTimer();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(460,460);
    setWindowTitle(tr("运动健身数据采集"));
    weight = 10;

    timer2 = new QTimer(this);//定时计
    timer2->start(1000);//定时器开始计时，其中1000表示1000ms即1s,每1000ms就会触发一次槽函数。读取系统时间

    connect(time1,SIGNAL(timeout()),this,SLOT(readyReadSlot()));
    connect(time1,SIGNAL(timeout()),this,SLOT(display()));
    connect(ui->weightBox,SIGNAL(returnPressed()),this,SLOT(setWeight()));
    connect(ui->OpenAction,SIGNAL(triggered()),this,SLOT(Setting()));
    connect(ui->SaveAction,SIGNAL(triggered()),this,SLOT(Saving()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(timeUpDate()));//定时一到就刷新时间。
}

MainWindow::~MainWindow()
{
    delete ui;
}

//关闭串口
void MainWindow::on_CloseAction_triggered()
{
    serialPort->close();
    ui->statusBar->showMessage(tr("关闭串口成功"));
   // connect(ui->CloseAction,SIGNAL(triggered()),this,SLOT(Stop()));
}
//输入举重重量，默认10kg
void MainWindow::setWeight()
{
    weight = ui->weightBox->text().toInt();
    qDebug()<<"weight is "<<weight;
}
//计算运动量并显示
void MainWindow::display()
{
    time1->stop();
    if(rxData.startsWith('a'))
    {
        QString s = QString(rxData);
        QString S;

        if(s[rxData.length()-1] == 'c')
            for(int i = rxData.length()-2;i > 0;i--)
            {
                if(s[i] == 'b')
                {
                    for(int j = i;j < rxData.length()-3;j++)
                        S[j-i] = s[j+1];
                    number = S.toInt();
                    //qDebug()<<S;
                    break;
                }
            }

        //qDebug()<<number;
        ui->lcdNumber->display(number);
        energy = weight*number*1.435;
        ui->lcdNumber_2->display(energy);
    }

    time1->start();
}

//保存sportBox中的内容
//void MainWindow::on_SaveAction_triggered()
//{

//    if(ui->lcdNumber_2->intValue()==0)
//    {
//    QMessageBox::information(this, "提示消息", tr("貌似还没有数据哦，请开始运动！"), QMessageBox::Ok);
//       return;
//    }


//    QString filename = QFileDialog::getSaveFileName(this, tr("保存为"), tr("未命名.txt"));
//    QFile file(filename);
//    //如果用户取消了保存则直接退出函数
//    if(file.fileName().isEmpty()){
//        return;
//    }
//    //如果打开失败则给出提示并退出函数
//    if(!file.open(QFile::WriteOnly | QIODevice::Text))
//    {
//    QMessageBox::warning(this, tr("保存文件"), tr("打开文件 %1 失败, 无法保存\n%2").arg(filename).arg(file.errorString()), QMessageBox::Ok);
//       return;
//    }
//    //写数据到文件
//    QTextStream out(&file);
//    out.setCodec("system");
//    out<<"TIMES:"<<ui->lcdNumber->intValue();
//    out<<qSetFieldWidth(1)<<'\n';
//    out<<"ENERGY:"<<ui->lcdNumber_2->intValue();
//    file.close();
//    //修改窗口标题为保存文件路径
//    setWindowTitle("saved: " + QFileInfo(filename).canonicalFilePath());

//}
//清空记录
void MainWindow::on_ClearAction_triggered()
{
//    ui->textBrowser->clear();
    ui->lcdNumber->display(0);
    ui->lcdNumber_2->display(0);
    serialPort->flush();
    ui->statusBar->showMessage(tr("记录已经清空"));
}

//退出程序
void MainWindow::on_ExitAction_triggered()
{
    this->close();
}
//设置串口
#include "settingdialog.h"
void MainWindow::Setting()
{
    settingDialog d;
    d.setWindowTitle(tr("设置串口"));
    d.exec();
}
//读取数据
void MainWindow::readyReadSlot()
{
    rxData = serialPort->readAll();
    QString s = QString(rxData);
    QString S;
//   ui->textBrowser->insertPlainText(S);
   qDebug()<<rxData;
    ui->statusBar->showMessage(tr("开始读取运动数据"));
}

//保存到数据库
#include "databasedialog.h"
void MainWindow::Saving()
{
    databaseDialog d;
    d.setWindowTitle(tr("保存到数据库"));
    d.exec();
}

//系统时间
void MainWindow::timeUpDate()
{
    systime=QDateTime::currentDateTime();
    time=systime.toString("yyyy-MM-dd hh:mm:ss dddd");
    ui->timelabel->setText(time);

}
