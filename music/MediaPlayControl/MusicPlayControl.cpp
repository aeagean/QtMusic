#include "MusicPlayControl.h"

MusicPlayControl::MusicPlayControl()
{
//    m_mediaPlayer->setMedia(QUrl::fromLocalFile("/Users/me/Music/coolsong.mp3"));
//    m_mediaPlayer->setVolume(50);
//    m_mediaPlayer->play();
}

bool MusicPlayControl::getIsStart()
{
    return m_isStart;
}

void MusicPlayControl::setIsStart(bool status)
{
    m_isStart = status;
    emit statusChanged();
}
