//Public Domain ?
//<author>Max Asaulov</author>
//<email>balldir@gmail.com</email>
//<date>25-07-2013</date>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QThread>

namespace comPortSettings {
    QStringList bitsRates = (QStringList()<<"2400"<<"4800"<<"9600"<<"19200"
                                          <<"38400"<<"57600"<<"115200");
    QStringList dataBits = (QStringList()<<"5"<<"6"<<"7"<<"8");
    QStringList parityBits = (QStringList()<<"No Parity"<<"Even Parity"<<"Odd Parity"<<"Space Parity"<<"Mark Parity");
    QStringList stopBits = (QStringList()<<"One Stop"<<"One And Half Stop"<<"Two Stop");
    QStringList flowControl = (QStringList()<<"No Flow Control"<<"Hardware Control"<<"Software Control");
    QString errors[] = {"NoError","DeviceNotFoundError","PermissionError","OpenError","ParityError","FramingError","BreakConditionError"
                        "WriteError","ReadError","ResourceError","UnsupportedOperationError","UnknownError"};
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //вывод ошибок в log
    connect(&port,SIGNAL(error(QString)),this,SLOT(printErrorMessage(QString)));

    connect(ui->send_pushButton,SIGNAL(clicked()),this,SLOT(sendMessage()));
    connect(ui->run_button,SIGNAL(clicked()),this,SLOT(runScript()));
    connect(ui->comPort_comboBox,SIGNAL(currentTextChanged(QString)),&port,SLOT(serialPortChanged(QString)));

    //получение списка всех портов и добавление их в comPort_comboBox
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
       ui->comPort_comboBox->addItem(info.portName(),Qt::DisplayRole);

    //привязка изменения настроек в интерфейсе к сетерам
    connect(ui->bitsRate_comboBox,SIGNAL(currentTextChanged(QString)),&port,SLOT(baudRateChanged(QString)));
    connect(ui->parity__comboBox,SIGNAL(currentTextChanged(QString)),&port,SLOT(parityChanged(QString)));
    connect(ui->dataBits_comboBox,SIGNAL(currentTextChanged(QString)),&port,SLOT(dataBitsChanged(QString)));
    connect(ui->stopBits_comboBox,SIGNAL(currentTextChanged(QString)),&port,SLOT(stopBitsChanged(QString)));
    connect(ui->flowControl_comboBox,SIGNAL(currentTextChanged(QString)),&port,SLOT(flowControlChanged(QString)));
    connect(ui->comPort_comboBox,SIGNAL(currentTextChanged(QString)),this,SLOT(setDefault(QString)));
    //ввывод ошибок в log
    connect(&port,SIGNAL(error(QSerialPort::SerialPortError)),this,SLOT(error(QSerialPort::SerialPortError)));
    //добавление в всех возможных вариантов настроек в интерфейс
    ui->bitsRate_comboBox->addItems(comPortSettings::bitsRates);
    ui->dataBits_comboBox->addItems(comPortSettings::dataBits);
    ui->parity__comboBox->addItems(comPortSettings::parityBits);
    ui->stopBits_comboBox->addItems(comPortSettings::stopBits);
    ui->flowControl_comboBox->addItems(comPortSettings::flowControl);
    setDefault("");

    QFileDialog* fileDialog = new QFileDialog(this,QString("Open Script"),QString(""),QString("*.txt"));
    connect(ui->open_button, SIGNAL(clicked()), fileDialog, SLOT(open()));       //TODO: роскоментить в финальном варианте (а то система тормозит)
    connect(fileDialog, SIGNAL(fileSelected(QString)), ui->filePath_lineEdit,    //поєднання підтверження вибору файлу та завантаження
            SLOT(setText(QString)));
    //привязка действий к кнопкам выбора режима
    connect(ui->hex_radioButton,SIGNAL(clicked()),this,SLOT(setHexMode()));
    connect(ui->text_radioButton,SIGNAL(clicked()),this,SLOT(setTextMode()));
    emit ui->hex_radioButton->clicked();
    //слушаем порт
    connect(&port,SIGNAL(readData(QString)),this,SLOT(printReceivedMessage(QString)));
    loadSettings();
}

MainWindow::~MainWindow()
{
    saveSettings();
    delete ui;
}

void MainWindow::saveSettings()
{
    QSettings settings("settings.ini", QSettings::IniFormat);
    settings.setValue("comPort", ui->comPort_comboBox->currentText());
    settings.setValue("bitsRate", ui->bitsRate_comboBox->currentText());
    settings.setValue("dataBits", ui->dataBits_comboBox->currentText());
    settings.setValue("stopBits", ui->stopBits_comboBox->currentText());
    settings.setValue("parity", ui->parity__comboBox->currentText());
    settings.setValue("flowControl", ui->flowControl_comboBox->currentText());
}

void MainWindow::loadSettings()
{
    if (!QFile::exists("settings.ini")) {
        printErrorMessage("No previous settings");
        return;
    }
    QSettings settings("settings.ini", QSettings::IniFormat);
    ui->comPort_comboBox->setCurrentText(settings.value("comPort").toString());
    ui->bitsRate_comboBox->setCurrentText(settings.value("bitsRate").toString());
    ui->dataBits_comboBox->setCurrentText(settings.value("dataBits").toString());
    ui->stopBits_comboBox->setCurrentText(settings.value("stopBits").toString());
    ui->parity__comboBox->setCurrentText(settings.value("parity").toString());
    ui->flowControl_comboBox->setCurrentText(settings.value("flowControl").toString());
}

void  MainWindow::printErrorMessage(QString message)
{
    ui->log_textBrowser->append("<font  color=\"red\">" + QTime::currentTime().toString("H:m:s") +
                                " Error: " + message + "<//font>" );
}

void  MainWindow::printSentMessage(QString message)
{
    ui->log_textBrowser->append("<font  color=\"blue\">" + QTime::currentTime().toString("H:m:s") +
                                " Send: " + message + "<//font>" );
}

//вывод данных с скрипта в одном формате в зависимости от настроек
void  MainWindow::printMessageFromScrip(QString message)
{
    QString newText;
    if (ui->hex_radioButton->isChecked())
        for(int i=0; i<message.length();i++){
           newText +=QString::number((message[i].toLatin1()),16);
           newText += " ";
        }
    else newText = message;
    printSentMessage(newText);
}

void  MainWindow::printReceivedMessage(QString message)
{
    QString newText = message.trimmed();
    if (ui->hex_radioButton->isChecked()) {
        newText.clear();
        newText = textToHEX(message,1);
    }
    ui->log_textBrowser->append("<font  color=\"orange\">" + QTime::currentTime().toString("H:m:s") +
                                " Answer: " + newText + "<//font>" );
}

QString MainWindow::textToHEX(QString text,int mode)
{
    QString hex;
    //проходим по всем символам и получаем из них чар. Из чара как из числа получаем строку
    for(int i=0; i<text.length();i++){
       hex +=QString::number((text[i].toLatin1()),16);
       if (mode == 1) hex += " ";
    }
    return hex;
}

//отключает выбраную radioButton что б не вызвать себя повторно. Устанавливает новую маску для
//набратого сообщения. Так же меняет текст на другой формат.
void MainWindow::setHexMode()
{
    QString originalText,tmp;
    originalText = (ui->send_text_lineEdit->displayText()).trimmed();
    tmp = textToHEX(originalText,0);
    ui->send_text_lineEdit->setInputMask(">hh hh hh hh hh hh hh hh hh hh hh hh hh hh hh hh  "
                                         " hh hh hh hh hh hh hh hh hh hh hh hh hh hh hh hh  "
                                         " hh hh hh hh hh hh hh hh hh hh hh hh hh hh hh hh  "
                                         " hh hh hh hh hh hh hh hh hh hh hh hh hh hh hh hh ;"); //TODO: не красиво
    ui->send_text_lineEdit->clear();
    ui->send_text_lineEdit->setText(tmp);
    ui->send_text_lineEdit->setCursorPosition(0);
    //отключает выбраную radioButton что б не вызвать себя повторно.
    ui->text_radioButton->setDisabled(false);
    ui->hex_radioButton->setDisabled(true);
    setWindowTitle("Serial HEX Console");

    QStringList messanges = ui->log_textBrowser->toPlainText().split('\n');
    tmp.clear();
    ui->log_textBrowser->clear();
    //построчно парсим лог. Найденые сообщения меняем на другой формат
    //так как получили чистый тескст добавляем теги цветов
    //и выводим обратно
    for (int i=0;i<messanges.length();i++)
    {
        if (messanges[i].contains("Send: ")) {
            //находим место где начинается наше сообщение
            int index = messanges[i].indexOf(": ")+2;
            //получаем его и переводим в другой формат
            tmp = textToHEX(messanges[i].mid(index),1);
            //обрезаем лишнее. Добавляем преобразованое сообщение, а так же теги
            messanges[i].truncate(index);
            messanges[i].append(tmp).prepend("<font  color=\"blue\">").append("<//font>");
        }
        if (messanges[i].contains("Answer: ")) {
            int index = messanges[i].indexOf(": ")+2;
            tmp = textToHEX(messanges[i].mid(index),1);
            messanges[i].truncate(index);
            messanges[i].append(tmp).prepend("<font  color=\"orange\">").append("<//font>");
        }
        if (messanges[i].contains(" Error: ")) messanges[i].prepend("<font  color=\"red\">").append("<//font>");
        ui->log_textBrowser->append(messanges[i]);
    };
}

//отключает выбраную radioButton что б не вызвать себя повторно. Устанавливает новую маску для
//набратого сообщения. Так же меняет текст на другой формат.
void MainWindow::setTextMode()
{
    QString tmp =  (ui->send_text_lineEdit->text()).trimmed();

    ui->send_text_lineEdit->setInputMask("nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn"
                                         "nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn");
    setWindowTitle("Serial Text Console");
    ui->send_text_lineEdit->clear();    
    ui->send_text_lineEdit->setCursorPosition(0);
    //отключает выбраную radioButton что б не вызвать себя повторно.
    ui->text_radioButton->setDisabled(true);
    ui->hex_radioButton->setDisabled(false);

    if (!hexToString(tmp)) return;
    ui->send_text_lineEdit->setText(tmp);
    ui->send_text_lineEdit->setCursorPosition(0);

    QStringList messanges = ui->log_textBrowser->toPlainText().split('\n');
    tmp.clear();
    ui->log_textBrowser->clear();
    //построчно парсим лог. Найденые сообщения меняем на другой формат
    //так как получили чистый тескст добавляем теги цветов
    //и выводим обратно
    for (int i=0;i<messanges.length();i++)
    {
        if (messanges[i].contains("Send: ")) {
            //находим место где начинается наше сообщение
            int index = messanges[i].indexOf(": ")+2;
            //получаем его и переводим в другой формат
            tmp = messanges[i].mid(index);
            //ecли возникла ошибка при преобразовании - выходим
            if (!hexToString(tmp)) return;
            //обрезаем лишнее. Добавляем преобразованое сообщение, а так же теги
            messanges[i].truncate(index);
            messanges[i] = messanges[i].append(tmp).prepend("<font  color=\"blue\">").append("<//font>");
        }
        if (messanges[i].contains("Answer: ")) {
            int index = messanges[i].indexOf(": ")+2;
            tmp = messanges[i].mid(index);
            if (!hexToString(tmp)) return;
            messanges[i].truncate(index);
            messanges[i] = messanges[i].append(tmp).prepend("<font  color=\"orange\">").append("<//font>");
        }
        if (messanges[i].contains(" Error: ")) {
            messanges[i].prepend("<font  color=\"red\">").append("<//font>");
        }
        ui->log_textBrowser->append(messanges[i]);
    };
}

//интерфейс между enum и string. Так же убирает навязчивую NoError
void MainWindow::error(QSerialPort::SerialPortError error)
{
    if (error != QSerialPort::NoError) printErrorMessage(comPortSettings::errors[error]);
}

void MainWindow::sendMessage()
{
    QString message = ui->send_text_lineEdit->displayText();
    printSentMessage(message.trimmed());
    if (ui->hex_radioButton->isChecked())
        if (!hexToString(message)){
             printErrorMessage("Messange can't be send");
             return;
        };
    port.sendData(message.trimmed() + "\r");

}

bool MainWindow::hexToString(QString &string)
{
    bool ok;
    QChar tmp;
    //розбиваем строку на отдельные байты
    QStringList bytes = string.split(" ");
    string.clear();
    //проходим по каждому байту
    for(int i=0; i<bytes.length();i++){
        //если пустое место
        if (bytes[i] == "") continue;
        tmp = QChar(bytes[i].toShort(&ok,16));
        //ecли не вышло преобразовать
        if (ok) string += tmp;
        else {
            printErrorMessage("Inappropriate HEX");
            return false;
        }
    }
    return true;
}

void MainWindow::runScript()
{
    //проверяем есть ли файл настроек
    QFile file(ui->filePath_lineEdit->text());
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        printErrorMessage("Can't open file");
        printErrorMessage("Script aborted");
        return;
    }
    QTextStream script(&file);
    QString tmp;
    //проходим по каждой строчке скрипта
    while (!script.atEnd()) {
        script>>tmp;
        if (tmp.contains("SendSTR")) {
            tmp.clear();
            //считываем все до конца строки
            tmp = script.readLine();
            //обрезаем все до "
            tmp.remove(0,tmp.indexOf('\"',0)+1);
            //обрезаем все после "
            tmp.truncate(tmp.lastIndexOf('\"'));
            printMessageFromScrip(tmp);
            port.sendData(tmp + '\r');
            continue;
        }
        if (tmp.contains("SendHEX")) {
            tmp.clear();
            tmp = script.readLine();
            tmp.remove(0,tmp.indexOf('\"',0)+1);
            tmp.truncate(tmp.lastIndexOf('\"'));
            QString tmp_message_at_hex = tmp;
            if (!hexToString(tmp)) {
                printErrorMessage("Inappropriate script. Error at \""
                                  + tmp_message_at_hex + "\" . Script aborted");
                file.close();
                return;
            }
            printMessageFromScrip(tmp);
            port.sendData(tmp);
            continue;
        }
        if (tmp.contains("DELAY")) {
            bool ok = false;
            tmp.clear();
            tmp = script.readLine().trimmed();
            quint32 ms = tmp.toUInt(&ok,10);
            if (!ok ) {
                printErrorMessage("Inappropriate value for delay. Error at \""
                                  + tmp + "\" . Script aborted");
                return;
            }
            QThread::msleep(ms);
            continue;
        }
        printErrorMessage("Inappropriate script. Error at \"" + tmp + "\" . Script aborted");
        return;
    }
    file.close();
}

//установка настроек по умолчанию. Выполняется после каждой смены порта
void MainWindow::setDefault(QString)
{
    ui->bitsRate_comboBox->setCurrentIndex(2);
    ui->dataBits_comboBox->setCurrentIndex(3);
    ui->parity__comboBox->setCurrentIndex(0);
    ui->stopBits_comboBox->setCurrentIndex(0);
    ui->flowControl_comboBox->setCurrentIndex(0);
}
