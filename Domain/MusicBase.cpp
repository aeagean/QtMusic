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

void MusicBase::fromJson(const QJsonObject &data)
{
    m_id = data.value("id").toString();
    m_name = data.value("name").toString();
    m_musicName = data.value("musicName").toString();
    m_pathName = data.value("pathName").toString();
}

QJsonObject MusicBase::toJson()
{
    QJsonObject data;
    data.insert("id", getId());
    data.insert("name", getName());
    data.insert("musicName", getMusicName());
    data.insert("pathName", getPathName());

    return data;
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

void MusicBase::setName(const QString &name)
{
    m_name = name;
}

QString MusicBase::getMusicName()
{
    return m_musicName;
}

void MusicBase::setMusicName(const QString &musicName)
{
    m_musicName = musicName;
}

QString MusicBase::getPathName()
{
    return m_pathName;
}

void MusicBase::setPathName(const QString &pathName)
{
    m_pathName = pathName;
}
