/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *settingsToolbar;
    QGridLayout *gridLayout_2;
    QLabel *settings_label;
    QFrame *line;
    QLabel *script_Label;
    QFormLayout *settings_layout;
    QLabel *comPort_label;
    QComboBox *comPort_comboBox;
    QLabel *bitsRate_label;
    QComboBox *bitsRate_comboBox;
    QLabel *dataBits_label;
    QComboBox *dataBits_comboBox;
    QLabel *parity_label;
    QComboBox *parity__comboBox;
    QLabel *stopBits_label;
    QComboBox *stopBits_comboBox;
    QLabel *flowControl_label;
    QComboBox *flowControl_comboBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *run_button;
    QSpacerItem *horizontalSpacer_5;
    QFormLayout *script_layout;
    QPushButton *open_button;
    QLineEdit *filePath_lineEdit;
    QPushButton *clear_button;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *mode_horizontal_layout;
    QLabel *mode_label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *hex_radioButton;
    QRadioButton *text_radioButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QTextBrowser *log_textBrowser;
    QGridLayout *sendEdit_layout;
    QPushButton *send_pushButton;
    QLineEdit *send_text_lineEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(628, 413);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QStringLiteral("#MainWindow {background-color: rgb(255, 255, 255);}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        settingsToolbar = new QWidget(centralWidget);
        settingsToolbar->setObjectName(QStringLiteral("settingsToolbar"));
        settingsToolbar->setMouseTracking(true);
        settingsToolbar->setAutoFillBackground(false);
        settingsToolbar->setStyleSheet(QLatin1String("#settingsToolbar { border-style: solid; border-width: 1px; border-color: rgb(0, 0, 0); }\n"
"\n"
""));
        gridLayout_2 = new QGridLayout(settingsToolbar);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        settings_label = new QLabel(settingsToolbar);
        settings_label->setObjectName(QStringLiteral("settings_label"));
        QFont font;
        font.setPointSize(16);
        settings_label->setFont(font);
        settings_label->setAutoFillBackground(false);
        settings_label->setStyleSheet(QLatin1String("border-width: 0px;\n"
"border-style: solid;\n"
"border-color: rgb(0, 0, 0);"));
        settings_label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(settings_label, 0, 0, 1, 1);

        line = new QFrame(settingsToolbar);
        line->setObjectName(QStringLiteral("line"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy1);
        line->setStyleSheet(QStringLiteral(" border-style: solid; border-width: 1px; border-color: rgb(0, 0, 0);"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 2, 0, 1, 1);

        script_Label = new QLabel(settingsToolbar);
        script_Label->setObjectName(QStringLiteral("script_Label"));
        script_Label->setFont(font);
        script_Label->setStyleSheet(QLatin1String("border-width: 0px;\n"
"border-style: solid;\n"
"border-color: rgb(0, 0, 0);"));
        script_Label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(script_Label, 3, 0, 1, 1);

        settings_layout = new QFormLayout();
        settings_layout->setSpacing(6);
        settings_layout->setObjectName(QStringLiteral("settings_layout"));
        settings_layout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        comPort_label = new QLabel(settingsToolbar);
        comPort_label->setObjectName(QStringLiteral("comPort_label"));
        comPort_label->setStyleSheet(QStringLiteral("border-width: 0px;"));
        comPort_label->setAlignment(Qt::AlignCenter);

        settings_layout->setWidget(0, QFormLayout::LabelRole, comPort_label);

        comPort_comboBox = new QComboBox(settingsToolbar);
        comPort_comboBox->setObjectName(QStringLiteral("comPort_comboBox"));
        comPort_comboBox->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-bottom-style: solid;\n"
" border-bottom-width: 1px; \n"
"border-bottom-color: rgb(0, 0, 0); "));

        settings_layout->setWidget(0, QFormLayout::FieldRole, comPort_comboBox);

        bitsRate_label = new QLabel(settingsToolbar);
        bitsRate_label->setObjectName(QStringLiteral("bitsRate_label"));
        bitsRate_label->setStyleSheet(QStringLiteral("border-width: 0px;"));
        bitsRate_label->setAlignment(Qt::AlignCenter);

        settings_layout->setWidget(1, QFormLayout::LabelRole, bitsRate_label);

        bitsRate_comboBox = new QComboBox(settingsToolbar);
        bitsRate_comboBox->setObjectName(QStringLiteral("bitsRate_comboBox"));
        bitsRate_comboBox->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        settings_layout->setWidget(1, QFormLayout::FieldRole, bitsRate_comboBox);

        dataBits_label = new QLabel(settingsToolbar);
        dataBits_label->setObjectName(QStringLiteral("dataBits_label"));
        dataBits_label->setStyleSheet(QStringLiteral("border-width: 0px;"));
        dataBits_label->setAlignment(Qt::AlignCenter);

        settings_layout->setWidget(2, QFormLayout::LabelRole, dataBits_label);

        dataBits_comboBox = new QComboBox(settingsToolbar);
        dataBits_comboBox->setObjectName(QStringLiteral("dataBits_comboBox"));
        dataBits_comboBox->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        settings_layout->setWidget(2, QFormLayout::FieldRole, dataBits_comboBox);

        parity_label = new QLabel(settingsToolbar);
        parity_label->setObjectName(QStringLiteral("parity_label"));
        parity_label->setStyleSheet(QStringLiteral("border-width: 0px;"));
        parity_label->setAlignment(Qt::AlignCenter);

        settings_layout->setWidget(3, QFormLayout::LabelRole, parity_label);

        parity__comboBox = new QComboBox(settingsToolbar);
        parity__comboBox->setObjectName(QStringLiteral("parity__comboBox"));
        parity__comboBox->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        settings_layout->setWidget(3, QFormLayout::FieldRole, parity__comboBox);

        stopBits_label = new QLabel(settingsToolbar);
        stopBits_label->setObjectName(QStringLiteral("stopBits_label"));
        stopBits_label->setStyleSheet(QStringLiteral("border-width: 0px;"));

        settings_layout->setWidget(4, QFormLayout::LabelRole, stopBits_label);

        stopBits_comboBox = new QComboBox(settingsToolbar);
        stopBits_comboBox->setObjectName(QStringLiteral("stopBits_comboBox"));
        stopBits_comboBox->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        settings_layout->setWidget(4, QFormLayout::FieldRole, stopBits_comboBox);

        flowControl_label = new QLabel(settingsToolbar);
        flowControl_label->setObjectName(QStringLiteral("flowControl_label"));
        flowControl_label->setStyleSheet(QStringLiteral("border-width: 0px;"));

        settings_layout->setWidget(5, QFormLayout::LabelRole, flowControl_label);

        flowControl_comboBox = new QComboBox(settingsToolbar);
        flowControl_comboBox->setObjectName(QStringLiteral("flowControl_comboBox"));
        flowControl_comboBox->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        settings_layout->setWidget(5, QFormLayout::FieldRole, flowControl_comboBox);


        gridLayout_2->addLayout(settings_layout, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        run_button = new QPushButton(settingsToolbar);
        run_button->setObjectName(QStringLiteral("run_button"));

        horizontalLayout->addWidget(run_button);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        gridLayout_2->addLayout(horizontalLayout, 5, 0, 1, 1);

        script_layout = new QFormLayout();
        script_layout->setSpacing(6);
        script_layout->setObjectName(QStringLiteral("script_layout"));
        open_button = new QPushButton(settingsToolbar);
        open_button->setObjectName(QStringLiteral("open_button"));
        open_button->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(open_button->sizePolicy().hasHeightForWidth());
        open_button->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setStyleStrategy(QFont::PreferAntialias);
        open_button->setFont(font1);
        open_button->setStyleSheet(QStringLiteral(""));
        open_button->setAutoDefault(false);
        open_button->setDefault(false);
        open_button->setFlat(false);

        script_layout->setWidget(0, QFormLayout::LabelRole, open_button);

        filePath_lineEdit = new QLineEdit(settingsToolbar);
        filePath_lineEdit->setObjectName(QStringLiteral("filePath_lineEdit"));
        filePath_lineEdit->setStyleSheet(QLatin1String("border-style: solid; \n"
"border-width: 1px; \n"
"border-color: rgb(0, 0, 0); "));

        script_layout->setWidget(0, QFormLayout::FieldRole, filePath_lineEdit);


        gridLayout_2->addLayout(script_layout, 4, 0, 1, 1);

        settings_label->raise();
        script_Label->raise();
        line->raise();

        gridLayout->addWidget(settingsToolbar, 0, 0, 4, 1);

        clear_button = new QPushButton(centralWidget);
        clear_button->setObjectName(QStringLiteral("clear_button"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(clear_button->sizePolicy().hasHeightForWidth());
        clear_button->setSizePolicy(sizePolicy3);
        clear_button->setAutoDefault(false);
        clear_button->setDefault(false);
        clear_button->setFlat(false);

        gridLayout->addWidget(clear_button, 1, 1, 2, 1);

        horizontalSpacer = new QSpacerItem(115, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        mode_horizontal_layout = new QHBoxLayout();
        mode_horizontal_layout->setSpacing(6);
        mode_horizontal_layout->setObjectName(QStringLiteral("mode_horizontal_layout"));
        mode_label = new QLabel(centralWidget);
        mode_label->setObjectName(QStringLiteral("mode_label"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        mode_label->setFont(font2);
        mode_label->setAlignment(Qt::AlignCenter);

        mode_horizontal_layout->addWidget(mode_label);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(true);
        sizePolicy3.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy3);
        groupBox->setStyleSheet(QStringLiteral(" border-style: solid; border-width: 0px; border-color: rgb(0, 0, 0);"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        hex_radioButton = new QRadioButton(groupBox);
        hex_radioButton->setObjectName(QStringLiteral("hex_radioButton"));
        hex_radioButton->setChecked(true);

        verticalLayout_2->addWidget(hex_radioButton);

        text_radioButton = new QRadioButton(groupBox);
        text_radioButton->setObjectName(QStringLiteral("text_radioButton"));
        text_radioButton->setCheckable(true);
        text_radioButton->setChecked(false);

        verticalLayout_2->addWidget(text_radioButton);


        mode_horizontal_layout->addWidget(groupBox);


        gridLayout->addLayout(mode_horizontal_layout, 1, 3, 2, 1);

        horizontalSpacer_2 = new QSpacerItem(114, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(115, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(114, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 4, 1, 1);

        log_textBrowser = new QTextBrowser(centralWidget);
        log_textBrowser->setObjectName(QStringLiteral("log_textBrowser"));
        log_textBrowser->setStyleSheet(QStringLiteral(" border-style: solid; border-width: 1px; border-color: rgb(0, 0, 0);"));

        gridLayout->addWidget(log_textBrowser, 0, 1, 1, 4);

        sendEdit_layout = new QGridLayout();
        sendEdit_layout->setSpacing(6);
        sendEdit_layout->setObjectName(QStringLiteral("sendEdit_layout"));
        send_pushButton = new QPushButton(centralWidget);
        send_pushButton->setObjectName(QStringLiteral("send_pushButton"));
        send_pushButton->setStyleSheet(QStringLiteral(""));

        sendEdit_layout->addWidget(send_pushButton, 0, 1, 1, 1);

        send_text_lineEdit = new QLineEdit(centralWidget);
        send_text_lineEdit->setObjectName(QStringLiteral("send_text_lineEdit"));
        send_text_lineEdit->setStyleSheet(QLatin1String("border-style: solid; \n"
"border-width: 1px; \n"
"border-color: rgb(0, 0, 0); "));
        send_text_lineEdit->setMaxLength(128);

        sendEdit_layout->addWidget(send_text_lineEdit, 0, 0, 1, 1);


        gridLayout->addLayout(sendEdit_layout, 3, 1, 1, 4);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(clear_button, SIGNAL(clicked()), log_textBrowser, SLOT(clear()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Serial HEX Console", 0));
        settings_label->setText(QApplication::translate("MainWindow", "Settings", 0));
        script_Label->setText(QApplication::translate("MainWindow", "Script", 0));
        comPort_label->setText(QApplication::translate("MainWindow", "Com port", 0));
        bitsRate_label->setText(QApplication::translate("MainWindow", "Bits rate", 0));
        dataBits_label->setText(QApplication::translate("MainWindow", "Data bits", 0));
        parity_label->setText(QApplication::translate("MainWindow", "Parity", 0));
        stopBits_label->setText(QApplication::translate("MainWindow", "Stop bits", 0));
        flowControl_label->setText(QApplication::translate("MainWindow", "Flow control", 0));
        run_button->setText(QApplication::translate("MainWindow", "Run", 0));
        run_button->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0));
        open_button->setText(QApplication::translate("MainWindow", "Open", 0));
        open_button->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        clear_button->setText(QApplication::translate("MainWindow", "Clear", 0));
        clear_button->setShortcut(QApplication::translate("MainWindow", "Ctrl+Backspace", 0));
        mode_label->setText(QApplication::translate("MainWindow", "Mode", 0));
        groupBox->setTitle(QString());
        hex_radioButton->setText(QApplication::translate("MainWindow", "HEX", 0));
        hex_radioButton->setShortcut(QApplication::translate("MainWindow", "Ctrl+H", 0));
        text_radioButton->setText(QApplication::translate("MainWindow", "TEXT", 0));
        text_radioButton->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", 0));
        send_pushButton->setText(QApplication::translate("MainWindow", "Send", 0));
        send_pushButton->setShortcut(QApplication::translate("MainWindow", "Ctrl+Return", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
