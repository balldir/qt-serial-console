//Public Domain ?
//<author>Max Asaulov</author>
// <email>balldir@gmail.com</email>
// <date>25-07-2013</date>

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QFileDialog>
#include <QFile>
#include <QSettings>

#include "serialport.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    serialPort port;

    QString textToHEX(QString,int);
    bool hexToString(QString&);

    void loadSettings();
    void saveSettings();

public slots:
    void setHexMode();
    void setTextMode();

    void sendMessage();
    void setDefault(QString);

    void error(QSerialPort::SerialPortError);
    void printErrorMessage(QString);

    void printSentMessage(QString);
    void printReceivedMessage(QString);
    void printMessageFromScrip(QString);

    void runScript();
};

#endif // MAINWINDOW_H
