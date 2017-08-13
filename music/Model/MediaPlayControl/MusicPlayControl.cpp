#include "MusicListService.h"
#include "MusicPlayControl.h"

MusicPlayControl::MusicPlayControl()
{
    m_playList = MusicListService::instance()->getMediaPlayList();
    m_progressBarValue = 0;
    m_leftTime = QTime(0, 0, 0);
    m_rightTime = QTime(0, 0, 0);
    m_musicName = "Music";

    this->setPlaylist(this->m_playList);
    this->setVolume(100);
    connect(this, SIGNAL(positionChanged(qint64)), this, SIGNAL(statusChanged()));
}

void MusicPlayControl::nextMusic()
{
    m_playList->next();
}

void MusicPlayControl::prevMusic()
{
    m_playList->previous();
}

bool MusicPlayControl::getIsStart()
{
    return m_isStart;
}

void MusicPlayControl::setIsStart(bool status)
{
    m_isStart = status;
    if (m_isStart == true) {
        this->play();
    }
    else {
        this->pause();
    }
    emit statusChanged();
}

QString MusicPlayControl::getLeftTimeStr()
{
    m_leftTime.setHMS(0, 0, 0);
    m_leftTime = m_leftTime.addMSecs(this->position());

    return m_leftTime.toString("mm:ss");
}

QString MusicPlayControl::getRightTimeStr()
{
    m_rightTime.setHMS(0, 0, 0);
    m_rightTime = m_rightTime.addMSecs(this->duration());
    return m_rightTime.toString("mm:ss");
}

double MusicPlayControl::getProgressBarValue()
{
    return (double)this->position()/this->duration();
}

void MusicPlayControl::setProgressBarValue(double progressBarValue)
{
    this->setPosition(progressBarValue*this->duration());
    if (this->position() == this->duration())
        this->m_isStart = false;
    emit statusChanged();
}

QString MusicPlayControl::getMusicName()
{
    return m_musicName;
}

void MusicPlayControl::setMusicName(QString musicName)
{
    m_musicName = musicName;
    emit statusChanged();
}


