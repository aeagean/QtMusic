#include "MusicPlayControl.h"
#include <QMediaPlaylist>

MusicPlayControl::MusicPlayControl()
{
    connect(&m_mediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    QMediaContent content(QUrl::fromLocalFile("/home/strong/workspace/music/music/resource/Imiss.mp3"));
    m_mediaPlayer.setMedia(content);
    m_mediaPlayer.setVolume(100);
//    m_mediaPlayer.play();

    qDebug()<<m_mediaPlayer.error()<<"+++";
}

bool MusicPlayControl::getIsStart()
{
    return m_isStart;
}

void MusicPlayControl::setIsStart(bool status)
{
    m_isStart = status;
    if (m_isStart == true) m_mediaPlayer.play();
    else m_mediaPlayer.pause();
    emit statusChanged();
}

void MusicPlayControl::positionChanged(qint64)
{

}
