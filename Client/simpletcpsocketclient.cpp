#include "simpletcpsocketclient.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

SimpleTcpSocketClient::SimpleTcpSocketClient()
{
    m_pTcpSocket = new QTcpSocket();
}

SimpleTcpSocketClient::~SimpleTcpSocketClient()
{
    delete m_pTcpSocket;
}

void SimpleTcpSocketClient::Connect()// 与服务器进行连接
{
    m_pTcpSocket->abort(); //取消已有连接
    m_pTcpSocket->connectToHost("127.0.0.1",6666);
    if(!m_pTcpSocket->waitForConnected(3000))
    {
        qDebug()<<"连接服务器失败，请重新操作！";
    }else{
        qDebug()<<"连接服务器成功！";
    }
}

bool SimpleTcpSocketClient::login(QString account, QString password)
{//管理员点击登录按钮，发送管理员 账号 密码 到服务器端进行验证，接收服务器端返回的数据，判断是否登录成功
    //使用json格式化 账号 和密码
    QJsonObject json;
    json.insert("ACCOUNT",account);
    json.insert("PASSWORD",password);

    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
    qDebug() <<QString(byteArray);
    qDebug() << byteArray.size();

    sendHeader(0,byteArray.size());// 发送操作和将要发送数据的大小
    m_pTcpSocket->write(byteArray); //发送账号密码

    //接收服务器的回应
    ReceiveHeader();
    m_pTcpSocket->waitForReadyRead();
    QByteArray message = m_pTcpSocket->read(m_len);
    QString login_state = QString(message);
    qDebug() << login_state;
    if(login_state == "success")
    {
        return true;
    }
    return false;
}

void SimpleTcpSocketClient::sendHeader(int type,int length)
{//向服务器发送接下来要进行的操作 和服务器将要接收的字节数
    QString message;
    QString len;
    QString header;
    QString m_len;
    QString m_header;
    len =QString::number(length);
    m_len.fill('0',10);
    m_len.push_back(len);
    m_len = m_len.right(10);
    if(type == 0) //客户端将要进行登录操作 向服务器发送登录符号 和用户的账号密码的长度
    {//构造两个 10位的字符串来存储length 和 LOGIN

        header =QString::number(LOGIN);

    }else if(type == 1)
    {
        header = QString::number(REGISTER);
    }else if(type == -1)
    {
        header = QString::number(DISCONNECT);
    }
    m_header.fill('0',10);
    m_header.push_back(header);
    m_header = m_header.right(10);
    message = m_header+m_len;
    QByteArray ba = message.toUtf8();
    //发送数据
    m_pTcpSocket->write(ba);
    //不缓存直接发送
    m_pTcpSocket->flush();
}

void SimpleTcpSocketClient::ReceiveHeader()
{//接收从 服务器发送的操作 以及服务器发送的数据大小
    while(!m_pTcpSocket->waitForReadyRead())
    { //当有数据到来时才接收
        qDebug() << "wait data.........";
    }
    qDebug()<< "Client RECEIVE";
    int symbol = QString(m_pTcpSocket->read(10)).toInt();
    int length = QString(m_pTcpSocket->read(10)).toInt();
    if(symbol == LOGIN)
    {
        m_type = 0;

    }else if(symbol == REGISTER)
    {
        m_type =1;
    }else if(symbol == RECE_USER_INFO)
    {
        m_type =2;
    }
    m_len = length;
    qDebug()<< m_type<< "     "<<length;
}

void SimpleTcpSocketClient::disconnect()
{
    sendHeader(-1,0);
    m_pTcpSocket->disconnectFromHost();
    m_pTcpSocket->waitForDisconnected();
}

bool SimpleTcpSocketClient::insert_manger(QString account, QString password, QString name, QString tel)
{//管理员点击注册按钮，发送管理员账号 密码 姓名 电话号码 到服务器进行验证，接收服务器端返回的数据， 判断是否注册成功
    //使用json 格式化 账号  密码 姓名 电话号码
    QJsonObject json;
    json.insert("ACCOUNT",account);
    json.insert("PASSWORD",password);
    json.insert("NAME",name);
    json.insert("TEL",tel);

    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
    qDebug() <<QString(byteArray);
    qDebug() << byteArray.size();

    sendHeader(1,byteArray.size()); //发送操作和将要发送的数据大小
    m_pTcpSocket->write(byteArray);

    //接收服务器的回应
    ReceiveHeader();
    while(!m_pTcpSocket->waitForReadyRead())
    {
    }
    QByteArray message = m_pTcpSocket->read(m_len);
    QString register_state = QString(message);
    if(register_state == "success")
    {
        return true;
    }
    return false;
}

QList<Manger > SimpleTcpSocketClient::receive_Manger_info()
{
    QList<Manger > manger;

    //接收服务器的回应
    ReceiveHeader();
    m_pTcpSocket->waitForReadyRead();
//    while(!m_pTcpSocket->waitForReadyRead())
//    {
//        qDebug()<<"wait data....";
//    }
    QByteArray message = m_pTcpSocket->read(m_len);
    qDebug() << QString(message);
    //解析json格式
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(message, &jsonError);//转化为json 文档
    if(!document.isNull() && (jsonError.error == QJsonParseError::NoError))//解析未发生错误
    {
        if(document.isObject()) //json 文档为对象
        {
            QJsonObject obj = document.object(); //获取对象
            qDebug() << "object size:"<< obj.size();

            if(obj.contains("ARRAYS"))
            {
                qDebug() << "ARRAYS";
                QJsonArray arr = obj["ARRAYS"].toArray();
                for(int i=0;i<arr.count();i++)
                {   qDebug() <<"count:"<<i;
                    QJsonObject arrojb =arr[i].toObject();
                    qDebug() << "ACCOUNT:"<<arrojb["ACCOUNT"].toString()<<"PASSWORD"<<arrojb["PASSWORD"].toString()<<"NAME"<<arrojb["NAME"].toString()<<"TEL"<<arrojb["TEL"].toString();
                    Manger m(arrojb["ACCOUNT"].toString(),arrojb["PASSWORD"].toString(),arrojb["NAME"].toString(),arrojb["TEL"].toString());
                    manger.push_back(m);
                }
            }
        }
    }

    return manger;
}
