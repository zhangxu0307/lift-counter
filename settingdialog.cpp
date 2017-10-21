#include "settingdialog.h"
#include "ui_settingdialog.h"

settingDialog::settingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settingDialog)
{
    ui->setupUi(this);
    this->setFixedSize(429,388);

}

settingDialog::~settingDialog()
{
    delete ui;
}
//打开串口
void settingDialog::on_OpenButton_clicked()
{
    MainWindow::serialPort->setPortName(ui->Port->currentText());
    MainWindow::serialPort->open(QIODevice::ReadWrite);
    MainWindow::serialPort->setBaudRate(ui->BaudRate->currentText().toInt());
    MainWindow::serialPort->setDataBits(QSerialPort::DataBits(ui->DataBits->currentText().toInt()));
    MainWindow::serialPort->setStopBits(QSerialPort::StopBits(ui->stopBits->currentText().toInt()));
    MainWindow::serialPort->setParity(QSerialPort::NoParity);
    MainWindow::serialPort->setFlowControl(QSerialPort::NoFlowControl);
    MainWindow::time1->setInterval(70);
    MainWindow::time1->start();
    //判断串口是否打开
    QString portName = ui->Port->currentText();//获取串口名
    if(MainWindow::serialPort->isOpen())
    {
    QMessageBox::information(this, tr("打开成功"), tr("已成功打开串口") + portName, QMessageBox::Ok);
    }
    else
    {
    QMessageBox::critical(this, tr("打开失败"), tr("未能打开串口 ") + portName + tr("\n该串口设备不存在或已被占用"), QMessageBox::Ok);
    return;
    }
}
//发送数据按钮
void settingDialog::on_sendButton_clicked()
{   //发送数据
    QString Tx = ui->lineEdit->text();
    QByteArray TxData = Tx.toLatin1();
    //qDebug()<<TxData;
    MainWindow::serialPort->write(TxData,qstrlen(TxData));
    //如果当前正在连续发送数据，暂停发送
    if(ui->sendButton->text() == tr("暂停"))
    {
        obotimer->stop();
        ui->sendButton->setText(tr("发送"));
        return;
    }
    //如果发送数据为空，给出提示并返回
   if(ui->lineEdit->text().isEmpty())
   {
   QMessageBox::information(this, tr("提示消息"), tr("没有需要发送的数据"), QMessageBox::Ok);
      return;
   }

}
//读取数据
//void settingDialog::readyReadSlot()
//{
//    rxData = MainWindow::serialPort->readAll();
//    QString s = QString(rxData);
//    QString S;
//    ui->textBrowser->insertPlainText(S);
//    qDebug()<<rxData;

//}
