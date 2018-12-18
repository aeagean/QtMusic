#include "MusicPlayModel.h"

MusicPlayModel::MusicPlayModel(QObject* parent) :
    BaseItemModel(parent)
{
    m_id = "";
    m_name = "Undefined";
}

MusicPlayModel::MusicPlayModel(MusicBase *musicBase, QObject* parent) :
    BaseItemModel(parent)
{
    m_id = musicBase->getId();
    m_name = musicBase->getMusicName();
}

QString MusicPlayModel::getId()
{
    return m_id;
}

void MusicPlayModel::setId(QString id)
{
    m_id = id;
    emit statusChanged();
}

QString MusicPlayModel::getName()
{
    return m_name;
}

void MusicPlayModel::setName(QString name)
{
    m_name = name;
    emit statusChanged();
}

void MusicPlayModel::operator=(const MusicPlayModel &model)
{
    this->m_id = model.m_id;
    this->m_name = model.m_name;

    emit statusChanged();
}
