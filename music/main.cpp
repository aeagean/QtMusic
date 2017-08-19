#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDir>
#include <iostream>
#include <QtQml>

#include "MusicPlayControl.h"
#include "FileBrowserListModel.h"
#include "MusicPlayListModel.h"

#include "MusicRepertory.h"
#include "MusicListService.h"
#include "MusicSearchService.h"
#include "FileBrowserService.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<MusicPlayControl>("MusicPlayControl", 1, 0, "MusicPlayControl");
    qmlRegisterType<FileBrowserListModel>("FileBrowserListModel", 1, 0, "FileBrowserListModel");
    qmlRegisterType<MusicPlayListModel>("MusicPlayListModel", 1, 0, "MusicPlayListModel");

    MusicRepertory::instance();
    MusicSearchService::instance();

    QFile file("/home/strong/Music/Lyric/不朽之罪.lrc");
    file.open(QIODevice::ReadOnly);
    qDebug()<<file.readAll().data();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/Qml/MainWin/main.qml")));



    return app.exec();
}
