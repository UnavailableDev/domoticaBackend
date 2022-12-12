#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "portr.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serialPort = new PortR();
}

MainWindow::~MainWindow()
{
    delete serialPort;
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    QByteArray msg = "haod\n";
    serialPort->write(msg);

}


void MainWindow::on_pushButton_clicked()
{
    serialPort->printError();
}


void MainWindow::on_pushButton_3_clicked()
{
    serialPort->connect();
}

