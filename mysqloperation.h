#ifndef MYSQLOPERATION_H
#define MYSQLOPERATION_H

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

class Data
{
public:
    QString name;
    int weight;
    int height;
    int liftNum;    
    int liftweight;
    int calories;

};


class MySqlOperation
{
public:
    MySqlOperation();
    ~MySqlOperation();
    void insertData(QString name,int height,int weight,int liftNum,int liftweight,int calories);
    void deleteData(QString name);
    Data searchData(QString name);
    void upDateData(QString name,int height,int weight,int liftNum,int liftweight,int calories);
private:
    QSqlDatabase database;
    QSqlQuery sqlQuery;
    Data data;

};

#endif // MYSQLOPERATION_H
