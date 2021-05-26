#include "rtabmap/gui/Wirelesstx.h"

wirelesstx::wirelesstx(QObject *parent) : QObject(parent)
{

}

void wirelesstx::Connect()
{
    //connected
    mysocket = new QTcpSocket(this);
    mysocket->connectToHost("192.168.1.70",8088);

    if(mysocket->waitForConnected(1000))
    {
        qDebug() << "Connected";
    }
    else
        qDebug() << "Not connected" ;
}

void wirelesstx::sendXYZ(float x, float y, float z)
{
    /*std::string str_x = std::to_string(x);
    std::string str_y = std::to_string(y);
    std::string str_z = std::to_string(z);

    std::string s_full = str_x + "," + str_y + "," + str_z;
    std::cout<<s_full<<std::endl;*/

    std::string s_x, s_y, s_z ,s;

    s_x = std::to_string(x);
    s_y = std::to_string(y);
    s_z = std::to_string(z);
    s = s_x + "," + s_y + "," + s_z;

    std::cout<<s<<std::endl;
    mysocket->write(s.data());

}
