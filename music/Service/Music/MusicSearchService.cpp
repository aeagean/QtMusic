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
    QString val;
    QFile file;
    file.setFileName("test.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    qDebug() << val;
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object();
    QJsonValue value = sett2.value(QString("appName"));
    qDebug() << value;
    QJsonObject item = value.toObject();
    qDebug() << tr("QJsonObject of description: ") << item;

    /* incase of string value get value and convert into string*/
    qDebug() << tr("QJsonObject[appName] of description: ") << item["description"];
    QJsonValue subobj = item["description"];
    qDebug() << subobj.toString();

    /* incase of array get array and convert into string*/
    qDebug() << tr("QJsonObject[appName] of value: ") << item["imp"];
    QJsonArray test = item["imp"].toArray();
    qDebug() << test[1].toString();
}
