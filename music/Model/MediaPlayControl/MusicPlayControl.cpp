#include "MusicPlayControl.h"
#include <QMediaPlaylist>

MusicPlayControl::MusicPlayControl()
{
    this->setMedia(QMediaContent(QUrl("qrc:/Resource/Imiss.mp3")));
    this->setVolume(100);
    m_progressBarValue = 0;
    m_leftTime = QTime(0, 0, 0);
    m_rightTime = QTime(0, 0, 0);

    connect(this, SIGNAL(positionChanged(qint64)), this, SIGNAL(statusChanged()));
}

bool MusicPlayControl::getIsStart()
{
    if (this->position() == this->duration()) m_isStart = false;
    else
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
    emit statusChanged();
}

