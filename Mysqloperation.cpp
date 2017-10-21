#include "mysqloperation.h"

MySqlOperation::MySqlOperation()
{
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("123.206.96.185");
    database.setDatabaseName("smartHealthy");
    database.setUserName("root");
    database.setPassword("123456");
    if(!database.open())
    {
        qDebug()<<database.lastError();
        //qFatal("failed to connect.") ;
    }
    else
    {
        qDebug()<<"DataBase is opened!";
        sqlQuery = QSqlQuery("smartHealthy");
    }

}

MySqlOperation::~MySqlOperation()
{

}

void MySqlOperation::insertData(QString name, int height, int weight, int liftNum, int liftweight, int calories)
{

    sqlQuery.prepare("INSERT INTO lifttable(Name,Height,Weight,LiftNum,Liftweight,Calories)"
                      "VALUES (?, ?, ?, ?, ?, ?)");
    sqlQuery.bindValue(0, name);
    sqlQuery.bindValue(1, height);
    sqlQuery.bindValue(2, weight);
    sqlQuery.bindValue(3, liftNum);
    sqlQuery.bindValue(4, liftweight);
    sqlQuery.bindValue(5, calories);
   // sqlQuery.exec();
    if(!sqlQuery.exec())
    {
    qDebug()<<sqlQuery.lastError();
    }
    else
    {
    qDebug()<<"insert success!";
    }
}

void MySqlOperation::deleteData(QString name)
{
    sqlQuery.prepare("DELETE FROM lifttable WHERE Name=?;");
    sqlQuery.bindValue(0,name);
    //sqlQuery.exec();
    if(!sqlQuery.exec())
    {
    qDebug()<<sqlQuery.lastError();
    }
    else
    {
    qDebug()<<"delete success!";
    }
}

Data MySqlOperation::searchData(QString name)
{
    sqlQuery.prepare("SELECT * FROM lifttable WHERE Name=?");
    sqlQuery.bindValue(0,name);
    //sqlQuery.exec();
    if(!sqlQuery.exec())
    {
        qDebug()<<sqlQuery.lastError();
        //return 0;
    }
    else
    {
        while(sqlQuery.next())
        {
             data.name = sqlQuery.value("Name").toString();
             data.height = sqlQuery.value("Height").toInt();
             data.weight = sqlQuery.value("Weight").toInt();
             data.liftNum = sqlQuery.value("LiftNum").toInt();
             data.liftweight = sqlQuery.value("Liftweight").toInt();
             data.calories = sqlQuery.value("Calories").toInt();
        }

        qDebug()<<"search success!";
        return data;
    }
}

void MySqlOperation::upDateData(QString name, int height, int weight, int liftNum, int liftweight, int calories)
{
    sqlQuery.prepare("UPDATE lifttable SET Height=?,Weight=?,LiftNum=?,Liftweight=?,Calories=? WHERE Name=?");

    sqlQuery.bindValue(0, height);
    sqlQuery.bindValue(1, weight);
    sqlQuery.bindValue(2, liftNum);
    sqlQuery.bindValue(3, liftweight);
    sqlQuery.bindValue(4, calories);
    sqlQuery.bindValue(5, name);
   // sqlQuery.exec();
    if(!sqlQuery.exec())
    {
        qDebug()<<sqlQuery.lastError();
    }
    else
    {
        qDebug()<<"update success!";
    }
}


