#include "MusicPlayControl.h"
#include <QMediaPlaylist>

MusicPlayControl::MusicPlayControl()
{
    this->setMedia(QMediaContent(QUrl("qrc:/resource/Imiss.mp3")));
    this->setVolume(100);
    this->play();
}

bool MusicPlayControl::getIsStart()
{
    return m_isStart;
}

void MusicPlayControl::setIsStart(bool status)
{
    m_isStart = status;
    if (m_isStart == true) this->play();
    else this->pause();
    emit statusChanged();
}
