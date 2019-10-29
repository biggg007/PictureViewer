#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTranslator>
#include <QDebug>
#include <QQmlContext>

#include "imagefilemsg.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

//    qmlRegisterType<ImageFileMsg>("ImageFileMdr", 1, 0, "ImageFileMsg");

    QQmlApplicationEngine engine;

    ImageFileMsg image_deal;
    engine.rootContext()->setContextProperty("IMAGEHANDLE", &image_deal);

    const QUrl url(QStringLiteral("qrc:///main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
