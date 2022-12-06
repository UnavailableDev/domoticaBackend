#include "portr.h"

#include <QDebug>
#include <QtSerialPort/QSerialPort>
//#include <QString>

PortR::PortR(){
    this->_serial = new QSerialPort;

    _serial->setPortName("/Users/jregnier/ttypx");
    if(!_serial->setBaudRate(QSerialPort::Baud9600))
        qDebug() << _serial->errorString();
    if(!_serial->setDataBits(QSerialPort::Data8)) // data is 8 bits
        qDebug() << _serial->errorString();
    if(!_serial->setParity(QSerialPort::NoParity))
        qDebug() << _serial->errorString();
    if(!_serial->setFlowControl(QSerialPort::NoFlowControl)) // default: QSerialPort::NoFlowControl
        qDebug() << _serial->errorString();
    if(!_serial->setStopBits(QSerialPort::OneStop)) //default
        qDebug() << _serial->errorString();

}

PortR::~PortR(){
    delete this->_serial;
}

void PortR::action(){
    //this is called when readyRead();
    int bytes = _serial->bytesAvailable();
    if(bytes > 0){
        qDebug() << "new Data arived" << _serial->bytesAvailable();
        _msg = _serial->readAll();
        qDebug() << _msg;
    }
}

void PortR::write(QByteArray msg){
    _serial->write(msg);
    qDebug() << _serial->errorString();
}

void PortR::connect(){

//    QIODevice::ReadOnly
    if(!_serial->open(QIODevice::ReadWrite))
        qDebug() << _serial->errorString();

    QObject::connect(_serial, &QSerialPort::readyRead, [&]
    {
        //this is called when readyRead();
        action();
    });

}

void PortR::disconnect(){
    // WIP?
}


QByteArray PortR::getData(){
    return _msg;
}
