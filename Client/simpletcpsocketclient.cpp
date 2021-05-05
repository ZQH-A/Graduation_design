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
//    qDebug() <<QString(byteArray);
//    qDebug() << byteArray.size();

    sendHeader(0,byteArray.size());// 发送操作和将要发送数据的大小
    m_pTcpSocket->write(byteArray); //发送账号密码

    //接收服务器的回应
    ReceiveHeader();
    m_pTcpSocket->waitForReadyRead();
    QByteArray message = m_pTcpSocket->read(m_len);
    QString login_state = QString(message);
//    qDebug() << login_state;
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
    }else if(type == 2)
    {
        header = QString::number(RECE_USER_INFO);
    }else if(type == 3)
    {
        header = QString::number(ADD_TENNANTS);
    }else if(type ==4)
    {
        header = QString::number(RECE_TENNANT_INFO);
    }else if(type == 5)
    {
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
    }else if(symbol == ADD_TENNANTS)
    {
        m_type =3;
    }else if(symbol == RECE_TENNANT_INFO)
    {
        m_type =4;
    }else if(symbol == RECE_OWNER_INFO)
    {
        m_type =5;
    }else if(symbol == RECE_REAL_ESTATE_INFO)
    {
        m_type =6;
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
    m_pTcpSocket->waitForReadyRead();


    QByteArray message = m_pTcpSocket->read(m_len);
    QString register_state = QString(message);
    if(register_state == "success")
    {
        return true;
    }
    return false;
}

QList<Manger > SimpleTcpSocketClient::receive_Manger_info(QString account,QString name,QString tel,QString sex)
{
    QJsonObject json;
    json.insert("ACCOUNT",account);
    json.insert("NAME",name);
    json.insert("TEL",tel);
    json.insert("SEX",sex);

    QJsonDocument document_;
    document_.setObject(json);
    QByteArray byteArray = document_.toJson(QJsonDocument::Compact);

    sendHeader(2,byteArray.size());
    m_pTcpSocket->write(byteArray); //将需要筛选条件发送到服务器

    QList<Manger > manger;

    //接收服务器的回应
    ReceiveHeader();
    m_pTcpSocket->waitForReadyRead();

    QByteArray message = m_pTcpSocket->read(m_len);
    //解析json格式
    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(message, &jsonError);//转化为json 文档
    if(!document.isNull() && (jsonError.error == QJsonParseError::NoError))//解析未发生错误
    {
        if(document.isObject()) //json 文档为对象
        {
            QJsonObject obj = document.object(); //获取对象
//            qDebug() << "object size:"<< obj.size();

            if(obj.contains("ARRAYS"))
            {
//                qDebug() << "ARRAYS";
                QJsonArray arr = obj["ARRAYS"].toArray();
                for(int i=0;i<arr.count();i++)
                {
                    QJsonObject arrojb =arr[i].toObject();
                    Manger m(arrojb["ACCOUNT"].toString(),arrojb["PASSWORD"].toString(),arrojb["NAME"].toString(),arrojb["TEL"].toString(),arrojb["SEX"].toString());
                    manger.push_back(m);
                }
            }
        }
    }

    return manger;
}

QList<Tennant> SimpleTcpSocketClient::receive_Tennant_info(QString search)//
{
    QJsonObject json;
    json.insert("SEARCH",search);

    QJsonDocument document_;
    document_.setObject(json);
    QByteArray byteArray = document_.toJson(QJsonDocument::Compact);

    sendHeader(4,byteArray.size());
    m_pTcpSocket->write(byteArray); //将筛选条件发送

    QList<Tennant> tennant;

    //接收服务器的回应
    ReceiveHeader();
    m_pTcpSocket->waitForReadyRead();

    QByteArray message = m_pTcpSocket->read(m_len);

    //解析json 格式

    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(message, &jsonError);//转化为json 文档
    if(!document.isNull() && (jsonError.error == QJsonParseError::NoError))//解析未发生错误
    {
        if(document.isObject()) //json 文档为对象
        {
            QJsonObject obj = document.object(); //获取对象
//            qDebug() << "object size:"<< obj.size();

            if(obj.contains("ARRAYS"))
            {
//                qDebug() << "ARRAYS";
                QJsonArray arr = obj["ARRAYS"].toArray();
                for(int i=0;i<arr.count();i++)
                {
                    QJsonObject arrojb =arr[i].toObject();
                    Tennant t(arrojb["NAME"].toString(),arrojb["Real_estate"].toString(),arrojb["House_id"].toString(),arrojb["TEL"].toString(),arrojb["END"].toString(),arrojb["CYCLE"].toString(),arrojb["Month_rent"].toInt(),arrojb["BEGIN"].toString(),arrojb["Payment_time"].toInt(),"");
                    tennant.push_back(t);
                }
            }
        }
    }
    return tennant;
}

QList<Owner> SimpleTcpSocketClient::receive_Owner_info()
{
    sendHeader(5,0);

    QList<Owner> owner;

    //接收服务器回应
    ReceiveHeader();

    m_pTcpSocket->waitForReadyRead();

    QByteArray message = m_pTcpSocket->read(m_len);
    qDebug() << QString(message);

    //解析json 格式

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
                {
                    QJsonObject arrojb =arr[i].toObject();
                    Owner o(arrojb["NAME"].toString(),arrojb["Payment_account"].toString(),arrojb["TEL"].toString(),arrojb["Real_estate"].toString(),arrojb["BEGIN"].toString(),arrojb["END"].toString(),arrojb["DEPOSIT"].toInt(),arrojb["CYCLE"].toString(),arrojb["Month_rent"].toInt(),arrojb["NOTE"].toString());
                    owner.push_back(o);
                }
            }
        }
    }
    return owner;
}

QList<Real_estate> SimpleTcpSocketClient::receive_Real_estate_info()
{
    sendHeader(6,0);

    QList<Real_estate> real_estate;

    //接收服务器回应
    ReceiveHeader();

    m_pTcpSocket->waitForReadyRead();

    QByteArray message = m_pTcpSocket->read(m_len);
    qDebug() << QString(message);

    //解析json 格式

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
                {
                    QJsonObject arrojb =arr[i].toObject();
                    Real_estate r(arrojb["Real_estate_id"].toInt(),arrojb["NAME"].toString(),arrojb["ADDRESS"].toString(),arrojb["TYPE"].toString());
                    real_estate.push_back(r);
                }
            }
        }
    }
    return real_estate;
}

bool SimpleTcpSocketClient::add_tennants(QString Real_estate, QString House_id, QString name, QString tel, QString ID_number, QString begin, QString end,QString cycle,int month_rent, int deposit)
{//添加租客
    QJsonObject json;
    json.insert("Real_estate",Real_estate);
    json.insert("House_id",House_id);
    json.insert("NAME",name);
    json.insert("TEL",tel);
    json.insert("ID_number",ID_number);
    json.insert("BEGIN",begin);
    json.insert("END",end);
    json.insert("Month_rent",month_rent);
    json.insert("DEPOSIT",deposit);
    json.insert("CYCLE",cycle);
    QJsonDocument document_;
    document_.setObject(json);
    QByteArray byteArray = document_.toJson(QJsonDocument::Compact);

    sendHeader(3,byteArray.size());
    m_pTcpSocket->write(byteArray);

    ReceiveHeader();
    m_pTcpSocket->waitForReadyRead();

    QByteArray message = m_pTcpSocket->read(m_len);
    QString state = QString(message);
    if(state == "success")
    {
        return true;
    }
    return false;
}
