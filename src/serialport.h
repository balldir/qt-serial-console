//Public Domain ?
//<author>Max Asaulov</author>
//<email>balldir@gmail.com</email>
//<date>25-07-2013</date>

#ifndef SERIALPORT_H
#define SERIALPORT_H


#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QStringList>

//расширенный QSerialPort с возможностью установки настроек через строки
//отслеживанием Command Terminator и расширенным набором ошибок
class serialPort : public QSerialPort
{
    Q_OBJECT
public:
    explicit serialPort();
    ~serialPort();

private:
    QString buff;

signals:
    void readData(QString);
    void error(QString);

public slots:
    void baudRateChanged(QString);
    void dataBitsChanged(QString);
    void flowControlChanged(QString);
    void parityChanged(QString);
    void stopBitsChanged(QString);
    void serialPortChanged(QString);

    void sendData(QString);
    void checkForCommandTerminator();
};

#endif // SERIALPORT_H
