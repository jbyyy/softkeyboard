#ifndef FOCUSLINEEDIT_H
#define FOCUSLINEEDIT_H

#include <QObject>
#include <QLineEdit>

class focusLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit focusLineEdit(QWidget *parent = 0);

protected:
    void focusInEvent(QFocusEvent *e) ;
    void focusOutEvent(QFocusEvent *e) ;
    void showEvent(QShowEvent *event);
signals:
    void focusIn();
public slots:
};

#endif // FOCUSLINEEDIT_H
