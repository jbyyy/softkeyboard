#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H
 
#include <QApplication>
#include <QEvent>
 
class MyApplication : public QApplication
{
public:
    MyApplication(int & argc, char ** argv);
 
public:
    bool notify(QObject *receiver, QEvent *e);
};
 
#endif