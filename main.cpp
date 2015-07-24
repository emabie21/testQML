//main.cpp by Eva Mabie 7/23/15
//Register the qml type ( allowing for interaction between C++/qml )
//Loads the gui appliaction, and qml engine and starts the appliaction


#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

//The custum C++ class that does the work
#include "cpuinfo.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<cpuinfo>("com.cpuInfo.test", 1, 0, "cpuinfo");
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
