#include "myapplication.h"
#include <QMouseEvent>
#include <QDebug>
#include <QLineEdit>
#include <QTextEdit>
#include <QMessageBox>
#include <SoftKeyBoard/SoftKeyBoard.h>

MyApplication::MyApplication(int & argc, char ** argv) : QApplication(argc, argv)
{
}

bool MyApplication::notify(QObject *receiver, QEvent *e)
{
    if(e->type() == QEvent::MouseButtonPress)  //receiver->parent() != NULL &&
    {
        QMouseEvent *mouseEvent=static_cast<QMouseEvent *>(e);

        if(receiver != NULL)
        {
            qDebug() << receiver->objectName();
            if(receiver->objectName().contains("lineEdit"))
            {
                if(static_cast<QLineEdit *>(receiver)->isEnabled())
                {
                    SoftKeyBoard keyBoard;
                    QString text = static_cast<QLineEdit *>(receiver)->text();
                    keyBoard.setValue(text);
                    int key = keyBoard.exec();
                    if(key == QMessageBox::Ok)
                    {
                        QString text = keyBoard.getValue();
                        static_cast<QLineEdit *>(receiver)->setText(text);
                    }
                    return QApplication::notify(receiver, e);
                }
            }
        }
    }
    return QApplication::notify(receiver, e);
}
