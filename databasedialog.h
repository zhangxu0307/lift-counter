#ifndef DATABASEDIALOG_H
#define DATABASEDIALOG_H

#include <QDialog>
#include <mainwindow.h>
#include <QDebug>
#include <QMessageBox>
#include "mysqloperation.h"

namespace Ui {
class databaseDialog;
}

class databaseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit databaseDialog(QWidget *parent = 0);
    ~databaseDialog();

private:
    Ui::databaseDialog *ui;
    MySqlOperation mySql1;

private slots:
    void on_Save_clicked();
    void on_Delete_clicked();
    void on_Search_clicked();
    void on_UpDate_clicked();
};

#endif // DATABASEDIALOG_H
