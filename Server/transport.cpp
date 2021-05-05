#include "transport.h"
#include <QJsonObject>
#include <QJsonDocument>


Transport::Transport(qintptr SocketDescriptor)
{
    socket = new QTcpSocket();
    db = new DataBase("info");
    if(!socket->setSocketDescriptor(SocketDescriptor))
    {
        qDebug() << "socket.setSocketDescriptor error";
    }else {//处理来自客户端的请求
        qDebug() <<"处理来自客户端的请求";
    }
}

void Transport::ReceiveHeader()
{//接收 从客户端发送的要进行的操作和 以及客户端发送数据的大小
    while(!socket->waitForReadyRead())
    {
        qDebug() << "wait data...";
    }
    qDebug() << "SERVER RECEIVEHEADER";
    int symbol = QString(socket->read(10)).toInt();
    int length = QString(socket->read(10)).toInt();
    if(symbol == LOGIN)
    {
        m_type =0;

    }else if(symbol == REGISTER)
    {
        m_type =1;
    }else if(symbol == DISCONNECT)
    {
        m_type = -1;
    }else if(symbol == RECE_USER_INFO)
    {
        m_type =2;
    }else if(symbol == ADD_TENNANTS)
    {
        m_type =3;
    }else if(symbol == RECE_TENNANT_INFO)
    {
        m_type =4;
    }else if(symbol == RECE_OWNER_INFO)
    {
        m_type = 5;
    }else if(symbol == RECE_REAL_ESTATE_INFO)
    {
        m_type =6;
    }
    m_len = length;
    qDebug() << m_type<<"                " <<length;
}

void Transport::sendHeader(int type, int length)
{//向客户端发送接下来要进行的操作 和客户端将要接收的字节数
    QString message;
    QString len;
    QString header;
    QString m_len;
    QString m_header;
    len =QString::number(length);
    m_len.fill('0',10);
    m_len.push_back(len);
    m_len = m_len.right(10);
    //构造两个 10位的字符串来存储length 和 标志符
    if(type == 0) //回应客户端的登录 和返回登录是否成功
    {
        header =QString::number(LOGIN);
    }else if(type ==1)
    { //回应客户端的注册 和返回注册是否成功
        header = QString::number(REGISTER);
    }else if(type ==2)
    {
        header = QString::number(RECE_USER_INFO);
    }else if(type ==3)
    { // 回应客户端的 租客添加是否成功
        header = QString::number(ADD_TENNANTS);
    }else if(type ==4)
    { //发送 租客信息
        header = QString::number(RECE_TENNANT_INFO);
    }else if(type == 5)
    { //发送业主信息
        header = QString::number(RECE_OWNER_INFO);
    }else if(type == 6)
    {
        header = QString::number(RECE_REAL_ESTATE_INFO);
    }

    m_header.fill('0',10);
    m_header.push_back(header);
    m_header = m_header.right(10);

    message = m_header+m_len;
    QByteArray ba = message.toUtf8();
    //发送数据
    socket->write(ba);
    //不缓存直接发送
    socket->flush();
}

void Transport::ReceiveLogin()
{
    socket->waitForReadyRead();

    QString account,password;
    QByteArray message =socket->read(m_len);

    qDebug() << QString(message);

    //进行解析
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(message,&jsonError); //转化为json 文档
    if(!document.isNull() && (jsonError.error == QJsonParseError::NoError))// 解析未发生错误
    {
        if(document.isObject())
        {
            QJsonObject obj = document.object();// 转化为对象
            if(obj.contains("ACCOUNT"))// 包含指定的 key
            {
                QJsonValue value = obj.value("ACCOUNT");
                if(value.isString())
                {
                    account = value.toString();
                }
            }
            if(obj.contains("PASSWORD"))
            {
                QJsonValue value = obj.value("PASSWORD");
                if(value.isString())
                {
                    password = value.toString();
                }
            }

        }
    }
    //解析完毕 ====
    //在数据库中进行验证
    QString login_state;
    if(db->DB_login(account,password))
    {
        login_state = "success";
        QByteArray login_success = login_state.toUtf8();
        qDebug() <<"success"<< login_state.size();
        sendHeader(0,login_state.size());
        socket->write(login_success);
        qDebug() << "登录成功";
    }else{
        login_state = "fail";
        QByteArray login_fail = login_state.toUtf8();
        qDebug() << "fail"<<login_state.size();
        sendHeader(0,login_state.size());
        socket->write(login_fail);
        qDebug() <<"登录失败";
    }
}

void Transport::ReceiveRegister()
{
    socket->waitForReadyRead();
    QString account,password,name,tel;

    QByteArray message = socket->read(m_len);
    qDebug()<< QString(message);

    //进行解析
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(message,&jsonError); //转化为json 文档
    if(!document.isNull() && (jsonError.error == QJsonParseError::NoError))// 解析未发生错误
    {
        if(document.isObject())
        {
            QJsonObject obj = document.object();// 转化为对象
            if(obj.contains("ACCOUNT"))// 包含指定的 key
            {
                QJsonValue value = obj.value("ACCOUNT");
                if(value.isString())
                {
                    account = value.toString();
                }
            }
            if(obj.contains("PASSWORD"))
            {
                QJsonValue value = obj.value("PASSWORD");
                if(value.isString())
                {
                    password = value.toString();
                }
            }
            if(obj.contains("NAME"))
            {
                QJsonValue value = obj.value("NAME");
                if(value.isString())
                {
                    name = value.toString();
                }
            }
            if(obj.contains("TEL"))
            {
                QJsonValue value = obj.value("TEL");
                if(value.isString())
                {
                    tel = value.toString();
                }
            }
        }
    }
    //解析完毕 ===
    //在数据库中进行验证
    QString register_state;
    if(db->DB_insert_manger(account,password,name,tel))
    {
        register_state = "success";
        QByteArray register_success = register_state.toUtf8();
        qDebug() << "success"<< register_state.size();
        sendHeader(1,register_state.size());
        socket->write(register_success);
        qDebug()<<"注册成功";
    }else{
        register_state = "fail";
        QByteArray register_fail = register_state.toUtf8();
        qDebug()<< "fail"<< register_state.size();
        sendHeader(1,register_state.size());
        socket->write(register_fail);
        qDebug() << "注册失败";
    }
}

void Transport::send_manger_info()
{
    socket->waitForReadyRead();
    QString account,name,tel,sex;
    QByteArray message = socket->read(m_len);

    //进行解析
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(message,&jsonError); //转化为json 文档
    if(!document.isNull() && (jsonError.error == QJsonParseError::NoError))// 解析未发生错误
    {
        if(document.isObject())
        {
            QJsonObject obj = document.object();// 转化为对象
            if(obj.contains("ACCOUNT"))// 包含指定的 key
            {
                QJsonValue value = obj.value("ACCOUNT");
                if(value.isString())
                {
                    account = value.toString();
                }
            }
            if(obj.contains("NAME"))
            {
                QJsonValue value = obj.value("NAME");
                if(value.isString())
                {
                    name = value.toString();
                }
            }
            if(obj.contains("TEL"))
            {
                QJsonValue value = obj.value("TEL");
                if(value.isString())
                {
                    tel = value.toString();
                }
            }
            if(obj.contains("SEX"))
            {
                QJsonValue value = obj.value("SEX");
                if(value.isString())
                {
                    sex = value.toString();
                }
            }
        }
    }


    QByteArray byteArray  = db->DB_manger_info(account,name,tel,sex);
    qDebug() << byteArray.size();
    sendHeader(2,byteArray.size());
    socket->write(byteArray);
    socket->flush();
}

void Transport::send_tennant_info()
{
    socket->waitForReadyRead();
    QString search;
    QByteArray message = socket->read(m_len);

    //进行解析
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(message,&jsonError); //转化为json 文档
    if(!document.isNull() && (jsonError.error == QJsonParseError::NoError))// 解析未发生错误
    {
        if(document.isObject())
        {
            QJsonObject obj = document.object();// 转化为对象
            if(obj.contains("SEARCH"))
            {
                QJsonValue value = obj.value("SEARCH");
                if(value.isString())
                {
                    search = value.toString();
                }
            }
        }
    }

    QByteArray byteArray = db->DB_tennant_info(search);
    qDebug() <<byteArray.size();
    sendHeader(4,byteArray.size());
    socket->write(byteArray);
    socket->flush();
}

void Transport::send_owner_info()
{
    QByteArray byteArray = db->DB_owner_info();
    qDebug() << byteArray.size();
    sendHeader(5,byteArray.size());
    socket->write(byteArray);
    socket->flush();
}

void Transport::send_real_estate_info()
{
    QByteArray byteArray = db->DB_Real_estate_info();
    qDebug() << byteArray.size();
    sendHeader(6,byteArray.size());
    socket->write(byteArray);
    socket->flush();
}

int Transport::Type()
{
    return m_type;
}

void Transport::add_tennants()
{
    socket->waitForReadyRead();
    QString Real_estate, House_id, name, tel,ID_number,begin,end,cycle;
    int month_rent,deposit;

    QByteArray message = socket->read(m_len);
    qDebug()<< QString(message);

    //进行解析
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(message,&jsonError); //转化为json 文档
    if(!document.isNull() && (jsonError.error == QJsonParseError::NoError))// 解析未发生错误
    {
        if(document.isObject())
        {
            QJsonObject obj = document.object();// 转化为对象
            if(obj.contains("Real_estate"))// 包含指定的 key
            {
                QJsonValue value = obj.value("Real_estate");
                if(value.isString())
                {
                    Real_estate = value.toString();
                }
            }
            if(obj.contains("House_id"))
            {
                QJsonValue value = obj.value("House_id");
                if(value.isString())
                {
                    House_id = value.toString();
                }
            }
            if(obj.contains("NAME"))
            {
                QJsonValue value = obj.value("NAME");
                if(value.isString())
                {
                    name = value.toString();
                }
            }
            if(obj.contains("TEL"))
            {
                QJsonValue value = obj.value("TEL");
                if(value.isString())
                {
                    tel = value.toString();
                }
            }
            if(obj.contains("ID_number"))
            {
                QJsonValue value = obj.value("ID_number");
                if(value.isString())
                {
                    ID_number = value.toString();
                }
            }
            if(obj.contains("BEGIN"))
            {
                QJsonValue value = obj.value("BEGIN");
                if(value.isString())
                {
                    begin = value.toString();
                }
            }
            if(obj.contains("END"))
            {
                QJsonValue value = obj.value("END");
                if(value.isString())
                {
                    end = value.toString();
                }
            }
            if(obj.contains("Month_rent"))
            {
                QJsonValue value = obj.value("Month_rent");
                if(value.isDouble())
                {
                    month_rent = value.toInt();
                }
            }
            if(obj.contains("DEPOSIT"))
            {
                QJsonValue value = obj.value("DEPOSIT");
                if(value.isDouble())
                {
                    deposit = value.toInt();
                }
            }
            if(obj.contains("CYCLE"))
            {
                QJsonValue value = obj.value("CYCLE");
                if(value.isString())
                {
                    cycle = value.toString();
                }
            }
        }
    }

    //判断是否插入成功
    QString state;
    QByteArray add_state;
    if(db->DB_add_tennants(Real_estate,House_id,name,tel,ID_number,begin,end,cycle,month_rent,deposit))
    {
        state = "success";
        add_state = state.toUtf8();
        qDebug() << "success"<< add_state.size();
        sendHeader(3,add_state.size());
        socket->write(add_state);
    }else
    {
        state = "fail";
        add_state = state.toUtf8();
        qDebug() << "fail" << add_state.size();
        sendHeader(3,add_state.size());
        socket->write(add_state);
    }
}

Transport::~Transport()
{
    socket->disconnectFromHost();
    socket->waitForDisconnected();
    delete socket;
}
