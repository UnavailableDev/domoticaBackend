#pragma once

#include <QtSerialPort/QSerialPort>
#include <QString>

class PortR
{
public:
    PortR();
    ~PortR();

    void write(QByteArray msg);

    void connect();
    void disconnect();

    QByteArray getData();

private:
    void action();

    QSerialPort* _serial = nullptr;
    QByteArray _msg;
};
