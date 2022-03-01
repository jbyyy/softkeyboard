#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QDebug>
#include <SoftKeyBoard/SoftKeyBoard.h>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1280,800);
    //设置列数和列宽
    int width = 1280;
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setColumnWidth(0, width * 0.2);
    ui->tableWidget->setColumnWidth(1, width * 0.2);
    ui->tableWidget->setColumnWidth(2, width * 0.2);
    ui->tableWidget->setColumnWidth(3, width * 0.2);
    ui->tableWidget->setColumnWidth(4, width * 0.2);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(25);

    QStringList headText;
    headText << "编号" << "名称" << "IP" << "数据内容" << "上传时间";
    ui->tableWidget->setHorizontalHeaderLabels(headText);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    //设置行高
    ui->tableWidget->setRowCount(10);

    for (int i = 0; i < 10; i++) {
        ui->tableWidget->setRowHeight(i, 24);
        QTableWidgetItem *itemDeviceID = new QTableWidgetItem(QString::number(i + 1));
        QTableWidgetItem *itemDeviceName = new QTableWidgetItem(QString("测试设备%1").arg(i + 1));
        QTableWidgetItem *itemDeviceAddr = new QTableWidgetItem(QString::number(i + 1));
        QTableWidgetItem *itemContent = new QTableWidgetItem("Empty");
        QTableWidgetItem *itemTime = new QTableWidgetItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

        ui->tableWidget->setItem(i, 0, itemDeviceID);
        ui->tableWidget->setItem(i, 1, itemDeviceName);
        ui->tableWidget->setItem(i, 2, itemDeviceAddr);
        ui->tableWidget->setItem(i, 3, itemContent);
        ui->tableWidget->setItem(i, 4, itemTime);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_textEdit_selectionChanged()
{
    qDebug() << "on_textEdit_selectionChanged";
    SoftKeyBoard keyBoard;
    int key = keyBoard.exec();
    if(key == QMessageBox::Ok)
    {
        QString text = keyBoard.getValue();
        ui->textEdit->append(text);
    }
}

void MainWindow::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    SoftKeyBoard keyBoard;
    QString text = item->text();
    keyBoard.setValue(text);
    int key = keyBoard.exec();
    if(key == QMessageBox::Ok)
    {
        QString text = keyBoard.getValue();
        item->setText(text);
    }
}
