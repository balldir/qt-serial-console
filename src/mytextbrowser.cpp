#include "mytextbrowser.h"

myTextBrowser::myTextBrowser()
{
}

myTextBrowser::myTextBrowser(QWidget *&widget)
{
    QTextBrowser::QTextBrowser(widget);
}

void myTextBrowser::printErrorMessage(QString message)
{
    append(message);
}

void myTextBrowser::printPostedMessage(QString message)
{
    append(message);
}

void myTextBrowser::printReceivedMessage(QString message)
{
    append(message);
}
