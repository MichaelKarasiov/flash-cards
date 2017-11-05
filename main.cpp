#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
#include <QScreen>
#include <QDebug>
#include <QQuickStyle>
#include <QSettings>

#include "AppActivity.h"

int main(int argc, char *argv[])
{
    QGuiApplication::setApplicationName("Tester");
    QGuiApplication::setOrganizationName("MKarasov");
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterSingletonType<AppActivity>("Tester", 1, 0, "MainActivity", &AppActivity::get_instance);

    QSettings settings;
    QString style = QQuickStyle::name();
    if (!style.isEmpty())
        settings.setValue("style", style);
    else
        QQuickStyle::setStyle(settings.value("style").toString());
    //TODO test
    QQuickStyle::setStyle("Material");
    //TODO end test
    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/AppMainWindow.qml"));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
