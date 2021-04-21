#ifndef MULTITHREADTCPSOCKETSERVER_H
#define MULTITHREADTCPSOCKETSERVER_H

#include <QTcpServer>

class MultiThreadTcpSocketServer: public QTcpServer
{
public:
    MultiThreadTcpSocketServer();
    //每当有一个新的tcp连接到来时，都会触发该函数
    virtual void incomingConnection(qintptr handle);
};

#endif // MULTITHREADTCPSOCKETSERVER_H
