#include "MusicModel.h"

MusicModel::MusicModel()
{
    m_id = "";
    m_name = "Undefined";
}

QString MusicModel::getId()
{
    return m_id;
}

void MusicModel::setId(QString id)
{
    m_id = id;
    emit statusChanged();
}

QString MusicModel::getName()
{
    return m_name;
}

void MusicModel::setName(QString name)
{
    m_name = name;
    emit statusChanged();
}

void MusicModel::operator=(const MusicModel &model)
{
    this->m_id = model.m_id;
    this->m_name = model.m_name;

    emit statusChanged();
}
