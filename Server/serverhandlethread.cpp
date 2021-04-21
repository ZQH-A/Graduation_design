#include "serverhandlethread.h"
#include "transport.h"

ServerHandleThread::ServerHandleThread(qintptr SocketDescriptor)
    :m_SocketDescriptor(SocketDescriptor)
{

}


void ServerHandleThread::run()//与客户端的通信
{
    //处理客户端的请求
    Transport * tcp = new Transport(m_SocketDescriptor);
    tcp->send_manger_info();
    while (1) {
        tcp->ReceiveHeader();
        int type = tcp->Type();
        if(type == 0)
        {
            tcp->ReceiveLogin();
        }else if(type ==1)
        {
            tcp->ReceiveRegister();
        }else if(type == -1)
        {
            break;
        }
    }
    qDebug() << "client disconnect";
}
