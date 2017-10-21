#include "databasedialog.h"
#include "ui_databasedialog.h"
#include "mainwindow.h"

databaseDialog::databaseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::databaseDialog)
{
    ui->setupUi(this);
    this->setFixedSize(428,323);
    ui->LiftNum->setText(QString::number(MainWindow::number, 10));
    ui->Calories->setText(QString::number(MainWindow::energy, 10));
    ui->Liftweight->setText(QString::number(MainWindow::weight, 10));

}

databaseDialog::~databaseDialog()
{
    delete ui;
}

void databaseDialog::on_Save_clicked()
{
    QString name = ui->Name->text();
    int height = ui->Height->text().toInt();
    int weight = ui->Weight->text().toInt();


    int liftNum = ui->LiftNum->text().toInt();
    int liftweight = ui->Liftweight->text().toInt();
    int calories = ui->Calories->text().toInt();

    mySql1.insertData(name,height,weight,liftNum,liftweight,calories);
}

void databaseDialog::on_Delete_clicked()
{
    QString name = ui->Name->text();
    mySql1.deleteData(name);
}

void databaseDialog::on_Search_clicked()
{
    QString name = ui->Name->text();
    Data data = mySql1.searchData(name);
    ui->Name->setText(data.name);
    ui->Height->setText(QString::number(data.height, 10));
    ui->Weight->setText(QString::number(data.weight, 10));
    ui->LiftNum->setText(QString::number(data.liftNum, 10));
    ui->Liftweight->setText(QString::number(data.liftweight, 10));
    ui->Calories->setText(QString::number(data.calories, 10));

}

void databaseDialog::on_UpDate_clicked()
{
    QString name = ui->Name->text();
    int height = ui->Height->text().toInt();
    int weight = ui->Weight->text().toInt();
    int liftNum = ui->LiftNum->text().toInt();
    int liftweight = ui->Liftweight->text().toInt();
    int calories = ui->Calories->text().toInt();

    mySql1.upDateData(name,height,weight,liftNum,liftweight,calories);
}
