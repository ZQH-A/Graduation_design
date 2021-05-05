#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "treeviewcontroller.h"
#include "simpletcpsocketclient.h"
#include "dataencapsulation.h"
#include "mangermodel.h"
#include "workermanager.h"
#include "tennantmodel.h"
#include "ownermodel.h"
#include "real_estatemodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    qRegisterMetaType<QList<Manger>>("QList<Manger>");//注册新类型
    qRegisterMetaType<QList<Tennant>>("QList<Tennant>");
    qRegisterMetaType<QList<Owner>> ("QList<Owner>");
    qRegisterMetaType<QList<Real_estate>> ("QList<Real_estate>");

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    TreeViewController treeViewController;	//理解析构顺序很重要


    MangerModel mangermodel;
    TennantModel tennantmodel;  //所有tennant 信息
    OwnerModel ownermodel;
    Real_estateModel real_estatemodel;

    WorkerManager *workerManager = new WorkerManager();
    workerManager->push_back_manger(&mangermodel);
    workerManager->push_back_tennant(&tennantmodel);
    workerManager->push_back_owner(&ownermodel);
    workerManager->push_back_real_estate(&real_estatemodel);
    //qml 与 c++ 交互
    engine.rootContext()->setContextProperty("mControl", &treeViewController);
    engine.rootContext()->setContextProperty("mModel",&mangermodel);
    engine.rootContext()->setContextProperty("tModel",&tennantmodel);
    engine.rootContext()->setContextProperty("worker",workerManager);
    engine.rootContext()->setContextProperty("oModel",&ownermodel);
    engine.rootContext()->setContextProperty("rModel",&real_estatemodel);

    workerManager->init();

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    workerManager->showMangers("","","","");
    workerManager->showTennants("");
    workerManager->showOwners();
    workerManager->showReal_estate();
    qDebug() << "Main thread : " << QThread::currentThreadId();
    if (engine.rootObjects().isEmpty())
        return -1;

    int ret= app.exec();
    workerManager->disconnect_from_sever();//与服务器断开连接
    return ret;
}
