#include "MusicPlayControl.h"
#include <QMediaPlaylist>

MusicPlayControl::MusicPlayControl()
{
//    m_mediaPlayer.setMedia(QUrl::fromLocalFile("/home/strong/android/otherspace/music/music/resource/Imiss.mp3"));
//    m_mediaPlayer.setVolume(50);

//    m_mediaPlayer.play();

    QMediaPlayer * m = new QMediaPlayer();
     QMediaPlaylist* playList=new QMediaPlaylist;
    playList->setPlaybackMode(QMediaPlaylist::Loop);
    playList->addMedia(QUrl::fromLocalFile("/home/strong/android/otherspace/music/music/resource/Imiss.mp3"));
    m->setPlaylist(playList);
//    m->setAudioRole(QAudio::MusicRole);
//    m->setMedia(QUrl::fromLocalFile("/home/strong/android/otherspace/music/music/resource/Imiss.mp3"));
    m->setVolume(50);

    m->play();
    qDebug()<<m->error()<<"+++";
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
