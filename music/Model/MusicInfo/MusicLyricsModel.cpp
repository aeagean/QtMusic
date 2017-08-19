#include "MusicLyricsModel.h"

MusicLyricsModel::MusicLyricsModel(QObject *parent) :
    BaseItemModel(parent)
{
    m_id = "";
    m_timeStr = "";
    m_time = QTime(0, 0, 0);
    m_content = "";
}

MusicLyricsModel::MusicLyricsModel(QString content, QObject *parent) :
    BaseItemModel(parent)
{
    m_content = content;
}

QString MusicLyricsModel::getId()
{
    return m_id;
}

void MusicLyricsModel::setId(QString id)
{
    m_id = id;
    emit statusChanged();
}

QString MusicLyricsModel::getTimeStr()
{
    return m_timeStr;
}

void MusicLyricsModel::setTimeStr(QString timeStr)
{
    m_timeStr = timeStr;
    emit statusChanged();
}

QTime MusicLyricsModel::getTime()
{
    return m_time;
}

void MusicLyricsModel::setTime(QTime time)
{
    m_time = time;
    emit statusChanged();
}

QString MusicLyricsModel::getContent()
{
    return m_content;
}

void MusicLyricsModel::setContent(QString content)
{
    m_content = content;
    emit statusChanged();
}

void MusicLyricsModel::operator=(const MusicLyricsModel &model)
{
    this->m_id = model.m_id;
    this->m_timeStr = model.m_timeStr;
    this->m_time = model.m_time;
    this->m_content = model.m_content;

    emit statusChanged();
}
