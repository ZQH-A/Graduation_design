#include "multithreadtcpsocketserver.h"
#include "serverhandlethread.h"

MultiThreadTcpSocketServer::MultiThreadTcpSocketServer()
{

}

void MultiThreadTcpSocketServer::incomingConnection(qintptr handle)
{//当有一个新的连接到来时，新创建一个线程 将套接字符传入
    ServerHandleThread* pThread = new ServerHandleThread(handle);
    connect(pThread,&ServerHandleThread::finished,pThread,&ServerHandleThread::deleteLater);
    pThread->start();
}
