#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "portr.h"
#include "main.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fuck = new PortR;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //do shit here
    fuck->connect();
}


void MainWindow::on_pushButton_2_clicked()
{
    QByteArray msg = "haod\n";
    fuck->write(msg);

}

