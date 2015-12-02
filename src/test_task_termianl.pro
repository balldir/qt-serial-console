#-------------------------------------------------
#
# Project created by QtCreator 2013-07-20T14:02:53
#
#-------------------------------------------------

QT       += core gui
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test_task_termianl
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    serialport.cpp

HEADERS  += mainwindow.h \
    serialport.h

FORMS    += mainwindow.ui
