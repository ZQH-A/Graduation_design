#ifndef SERVERHANDLETHREAD_H
#define SERVERHANDLETHREAD_H

#include <QThread>

//继承QThread类，重载 run()方法，
//在run()方法中完成对客户端请求的处理
class ServerHandleThread: public QThread
{
public:
    ServerHandleThread(qintptr SocketDescriptor);

    virtual void run();

private:
    qintptr m_SocketDescriptor;//套接字标识符
    //用来在新线程中继续用刚才连接进来的套接字
};

#endif // SERVERHANDLETHREAD_H
