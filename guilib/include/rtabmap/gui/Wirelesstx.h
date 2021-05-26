#ifndef WIRELESSTX_H
#define WIRELESSTX_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

#include <iostream>
#include <string>

class wirelesstx : public QObject
{
    Q_OBJECT
public:
    explicit wirelesstx(QObject *parent = nullptr);

    void Connect();
    void sendXYZ(float, float, float);

private :
    QTcpSocket *mysocket;

};
#endif // WIRELESSTX_H
