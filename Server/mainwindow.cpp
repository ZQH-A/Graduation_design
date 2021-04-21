#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "multithreadtcpsocketserver.h"
#include <QMessageBox>
#include "database.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DataBase * db = new DataBase("info");
    db->DB_create();//创建基本表
    //1. 建立服务器端套接字
    MultiThreadTcpSocketServer * m_pTcpServer = new MultiThreadTcpSocketServer();
    //2. 启动服务端
    if(!m_pTcpServer->listen(QHostAddress::Any,6666))
    {
        ui->textEdit->append(tr("m_pTcpServer->listen() error"));
    }
    else
    {
        ui->textEdit->append(tr("m_pTcpServer->listen() success"));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
