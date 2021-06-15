#ifndef SENDER_H
#define SENDER_H

#include <QWidget>
#include <iostream>

//QT_BEGIN_NAMESPACE

class QUdpSocket;
//QT_END_NAMESPACE

class Sender : public QWidget
{
    Q_OBJECT

public:
    Sender(QWidget *parent = 0);
    void broadcastDatagram(float x, float y , float z);

private:
    QUdpSocket *udpSocket;
    int agent_number;
};

#endif
