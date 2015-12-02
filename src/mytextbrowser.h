#ifndef MYTEXTBROWSER_H
#define MYTEXTBROWSER_H

#include <QTextBrowser>
#include <QString>

class myTextBrowser : public QTextBrowser
{
public:
    myTextBrowser();
    myTextBrowser(QWidget*&);
    void printPostedMessage(QString);
    void printErrorMessage(QString);
    void printReceivedMessage(QString);
};

#endif // MYTEXTBROWSER_H
