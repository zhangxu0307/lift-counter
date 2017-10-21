#-------------------------------------------------
#
# Project created by QtCreator 2016-04-14T09:03:37
#
#-------------------------------------------------

QT       += serialport core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LiftCounter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    settingdialog.cpp \
    databasedialog.cpp \
    Mysqloperation.cpp

HEADERS  += mainwindow.h \
    settingdialog.h \
    databasedialog.h \
    mysqloperation.h

FORMS    += mainwindow.ui \
    settingdialog.ui \
    databasedialog.ui

RESOURCES += \
    res.qrc

SUBDIRS += \
    ../../Qt/mysqlTest/mysqlTest/mysqlTest.pro \
    ../../Qt/mysqlTest/mysqlTest/mysqlTest.pro \
    mysqlTest/mysqlTest/mysqlTest.pro
