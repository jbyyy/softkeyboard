#include "focuslineedit.h"
#include <QDebug>
focusLineEdit::focusLineEdit(QWidget *parent) : QLineEdit(parent)
{

}

void focusLineEdit::focusInEvent(QFocusEvent *e)
{
    QLineEdit::focusInEvent(e);
    this->setFocus();
    //qDebug() << "focusInEvent";
    emit focusIn();
}

void focusLineEdit::focusOutEvent(QFocusEvent *e)
{
    QLineEdit::focusOutEvent(e);
    //qDebug() << "focusOutEvent";
    //emit signalFocusOut();
}

void focusLineEdit::showEvent(QShowEvent *event)
{
    setEnabled(true);
    setFocus();
    QLineEdit::showEvent(event);
}
