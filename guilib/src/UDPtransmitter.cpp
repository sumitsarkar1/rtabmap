#include <QtWidgets>
#include <QtNetwork>

#include "rtabmap/gui/UDPtransmitter.h"

Sender::Sender(QWidget *parent)
    : QWidget(parent)
{
    agent_number = 2;
    a_ = QString::number(agent_number);		
    udpSocket = new QUdpSocket(this);			
}

void Sender::broadcastDatagram(float x, float y, float z)
{

    //std::cout << x <<" "<< y <<" "<<z <<std::endl;

    /*std::string s_x, s_y, s_z , agent_number_s, s;

    s_x = std::to_string(x);
    s_y = std::to_string(y);
    s_z = std::to_string(z);
    agent_number_s = std::to_string(agent_number);*/

    x_ = QString::number(x);	
    y_ = QString::number(y);	    
    z_ = QString::number(z);

    QString s = a_ + "," + x_ + "," + y_ + "," + z_ ;

    //QByteArray datagram = agent_number_s + "," + s_x + "," + s_y + "," + s_z ;
    //QByteArray datagram(s.c_str(), s.length());

    QByteArray datagram = s.toUtf8();
    udpSocket->writeDatagram(datagram,QHostAddress("192.168.1.75"), 45454);
}
