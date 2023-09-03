
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "contactsmodel.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    ContactsModel::registerMe("Contacts");
    const QUrl url(u"qrc:/Messenger/Qml/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
