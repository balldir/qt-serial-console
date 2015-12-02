//Public Domain ?
//<author>Max Asaulov</author>
//<email>balldir@gmail.com</email>
//<date>25-07-2013</date>

#include "serialport.h"

serialPort::serialPort()
{

   connect(this,SIGNAL(readyRead()),this,SLOT(checkForCommandTerminator()));
}

serialPort::~serialPort()
{
    close();
}

//интерфейс между enum и string с отслеживанием ошибок
void serialPort::baudRateChanged(QString baudRate)
{
    bool ok;
    qint32 value = baudRate.toInt(&ok,10);
    if (!isOpen()) {
        emit error("Port is not opened");
        return;
    }
    if (ok == false) {
            if (!setBaudRate(QSerialPort::UnknownBaud)) emit error("Error during setting baud rate");
            return;
        }
    if (!setBaudRate(value)) emit error("Error during setting baud rate");
}

//интерфейс между enum и string с отслеживанием ошибок
void serialPort::dataBitsChanged(QString dataBit)
{
    bool ok = true;
    if (!isOpen()) {
        emit error("Port is not opened");
        return;
    }
    qint32 value = dataBit.toInt(&ok,10);
    if (!ok )
        ok = setDataBits(QSerialPort::UnknownDataBits);
    else switch (value)
            {
            case 5: ok = setDataBits(QSerialPort::Data5);
                    break;
            case 6: ok = setDataBits(QSerialPort::Data6);
                    break;
            case 7: ok = setDataBits(QSerialPort::Data7);
                    break;
            case 8: ok = setDataBits(QSerialPort::Data8);
                    break;
        };
    if (!ok) emit error("Error during setting data bits");
}

//интерфейс между enum и string с отслеживанием ошибок
void serialPort::flowControlChanged(QString flowControl)
{
    if (!isOpen()) {
        emit error("Port is not opened");
        return;
    }
    bool ok = true;
    if (flowControl == "No Flow Control")   ok = setFlowControl(QSerialPort::NoFlowControl);
    if (flowControl == "Hardware Control")  ok = setFlowControl(QSerialPort::HardwareControl);
    if (flowControl == "Software Control")  ok = setFlowControl(QSerialPort::SoftwareControl);
    if (flowControl == "Unknown")           ok = setFlowControl(QSerialPort::UnknownFlowControl);
    if (!ok) emit error("Error during setting flow control");
}

//интерфейс между enum и string с отслеживанием ошибок
void serialPort::parityChanged(QString parity)
{
    if (!isOpen()) {
        emit error("Port is not opened");
        return;
    }
    bool ok = true;
    if (parity == "No Parity")      ok = setParity(QSerialPort::NoParity);
    if (parity == "Even Parity")    ok = setParity(QSerialPort::EvenParity);
    if (parity == "Odd Parity")     ok = setParity(QSerialPort::OddParity);
    if (parity == "Space Parity")   ok = setParity(QSerialPort::SpaceParity);
    if (parity == "Mark Parity")    ok = setParity(QSerialPort::MarkParity);
    if (parity == "Unknown")        ok = setParity(QSerialPort::UnknownParity);
    if (!ok) emit error("Error during setting parity");
}

//интерфейс между enum и string с отслеживанием ошибок
void serialPort::stopBitsChanged(QString stopBit)
{
    if (!isOpen()) {
        emit error("Port is not opened");
        return;
    }
    bool ok = true;
    if (stopBit == "One Stop")          ok = setStopBits(QSerialPort::OneStop);
    if (stopBit == "One And Half Stop") ok = setStopBits(QSerialPort::OneAndHalfStop);
    if (stopBit == "Two Stop")          ok = setStopBits(QSerialPort::TwoStop);
    if (stopBit == "Unknown")           ok = setStopBits(QSerialPort::UnknownStopBits);
    if (!ok) emit error("Error during setting stop bit");
}

//интерфейс между enum и string с отслеживанием ошибок
void serialPort::serialPortChanged(QString serialPort)
{
    close();
    QSerialPortInfo portInfo = 	QSerialPortInfo(serialPort);
    setPort(portInfo);
    if (!open(QIODevice::ReadWrite)) {
        emit error("Can't open " + serialPort);
        return;
    }
}

//отправка сообщения с отслеживанием ошибок
void serialPort::sendData(QString string)
{
    bool ok = true;
    if (!isOpen()) {
        emit error("Can't send data.Device is not opened");
        return;
    }
    if (!(ok = write(string.toLatin1().data()))) emit error("Data has not been send");
}

//при поступлении новых данных проверяет есть ли CommandTerminator
void serialPort::checkForCommandTerminator()
{
    buff += QString(readAll());          //TODO: не может вернуть ошибку переделать
    if (buff.contains('\r')) {
        emit readData(buff);
        buff.clear();
    }
}
