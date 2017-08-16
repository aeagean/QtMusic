#include "MusicBase.h"
#include <QJsonObject>

MusicBase::MusicBase()
{
    m_id = "";
    m_name = QString::fromUtf8("Undefined");
    m_pathName = "/";
    m_musicName = QString::fromUtf8("Undefined");
}

MusicBase::~MusicBase()
{

}

void MusicBase::fromJson(const QJsonValue *data)
{
    QJsonObject jsonObj = data->toObject();
    m_id = jsonObj.value("id").toString();
    m_name = jsonObj.value("name").toString();
    m_musicName = jsonObj.value("musicName").toString();
    m_pathName = jsonObj.value("pathName").toString();
}

QJsonValue *MusicBase::toJson()
{
    QJsonObject jsonObj;
    jsonObj.insert("id", getId());
    jsonObj.insert("name", getName());
    jsonObj.insert("musicName", getMusicName());
    jsonObj.insert("pathName", getPathName());
    QJsonValue* jsonValue = new QJsonValue(jsonObj);

    return jsonValue;
}

QString MusicBase::getId()
{
    return m_id;
}

void MusicBase::setId(QString id)
{
    m_id = id;
}

QString MusicBase::getName()
{
    return m_name;
}

void MusicBase::setName(QString name)
{
    m_name = name;
}

QString MusicBase::getMusicName()
{
    return m_musicName;
}

void MusicBase::setMusicName(QString musicName)
{
    m_musicName = musicName;
}

QString MusicBase::getPathName()
{
    return m_pathName;
}

void MusicBase::setPathName(QString pathName)
{
    m_pathName = pathName;
}
