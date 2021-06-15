#include <QtWidgets>
#include <QtNetwork>

#include "rtabmap/gui/UDPtransmitter.h"

Sender::Sender(QWidget *parent)
    : QWidget(parent)
{
    agent_number = 2;
    udpSocket = new QUdpSocket(this);			
}

void Sender::broadcastDatagram(float x, float y, float z)
{
    std::string s_x, s_y, s_z , agent_number_s, s;

    s_x = std::to_string(x);
    s_y = std::to_string(y);
    s_z = std::to_string(z);
    agent_number_s = std::to_string(agent_number);

    s = agent_number_s + "," + s_x + "," + s_y + "," + s_z ;

    udpSocket->writeDatagram(s.data(), s.size(),
                             QHostAddress("192.168.1.157"), 45454);

}
