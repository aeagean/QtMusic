#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDir>
#include <iostream>
#include <QtQml>
#include "MusicPlayControl.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<MusicPlayControl>("MusicPlayControl", 1, 0, "MusicPlayControl");

    MusicPlayControl* m = new MusicPlayControl();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/MainWin/main.qml")));

    QDir dir("/");
    dir.setFilter(QDir::Dirs|QDir::Files|QDir::NoDotAndDotDot);
    dir.setSorting(QDir::Name);

    QFileInfoList list = dir.entryInfoList();
    std::cout << "     Bytes Filename" << std::endl;
    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list.at(i);
        std::cout << qPrintable(QString("%1 %2").arg(fileInfo.size(), 10)
                                                .arg(fileInfo.fileName()));
        std::cout << std::endl;
    }
    return app.exec();
}
