//Public Domain ?
//<author>Max Asaulov</author>
//<email>balldir@gmail.com</email>
//<date>25-07-2013</date>
//<summary>Basic application for serial port communication</summary>

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
