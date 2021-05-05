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
        }else if(type ==2){
            tcp->send_manger_info();
        }else if(type ==3)
        {
            tcp->add_tennants();
        }else if(type ==4)
        {
            tcp->send_tennant_info();
        }else if(type == 5)
        {
            tcp->send_owner_info();
        }else if(type ==6)
        {
            tcp->send_real_estate_info();
        }
    }
    qDebug() << "client disconnect";
}
