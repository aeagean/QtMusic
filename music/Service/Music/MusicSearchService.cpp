#include "MusicSearchService.h"
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

MusicSearchService * MusicSearchService::_instance = NULL;


MusicSearchService *MusicSearchService::instance()
{
    if (_instance == NULL) {
        _instance = new MusicSearchService();
    }
    return _instance;
}

QList<MusicBase *> MusicSearchService::getMusicSearchList(QString musicName)
{

}

MusicSearchService::MusicSearchService()
{
    readJson();
}

void MusicSearchService::readJson()
{
}
