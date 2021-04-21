#include "mainwindow.h"
#include <QApplication>
#include "connectionpool.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    int ret = a.exec();
    ConnectionPool::release();//程序结束时关闭连接，以免造成连接泄露
    return ret;
}
