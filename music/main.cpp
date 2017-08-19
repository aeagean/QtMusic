#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDir>
#include <iostream>
#include <QtQml>

#include "MusicPlayControl.h"
#include "FileBrowserListModel.h"
#include "MusicPlayListModel.h"
#include "MusicLyricsListModel.h"

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
    qmlRegisterType<MusicLyricsListModel>("MusicLyricsListModel", 1, 0, "MusicLyricsListModel");

    MusicRepertory::instance();
    MusicSearchService::instance();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/Qml/MainWin/main.qml")));



    return app.exec();
}
