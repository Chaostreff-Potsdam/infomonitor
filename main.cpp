#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "wilappost.h"

#include <QQmlEngine>
#include <QQmlContext>
#include <QFont>

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);


    QFont font("Orbitron");
    app.setFont(font);

    QQmlApplicationEngine engine;
    WilapPost *post = new WilapPost();
    engine.rootContext()->setContextProperty("_post", post);



    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
