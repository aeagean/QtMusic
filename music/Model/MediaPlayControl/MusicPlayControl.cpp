#include "MusicPlayControl.h"
#include <QMediaPlaylist>

MusicPlayControl::MusicPlayControl()
{
    this->setMedia(QMediaContent(QUrl("qrc:/Resource/Imiss.mp3")));
    this->setVolume(100);

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
