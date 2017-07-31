#ifndef MUSICPLAYCONTROL_H
#define MUSICPLAYCONTROL_H

#include <QObject>
#include <QMediaPlayer>

class MusicPlayControl : public QObject
{
    Q_OBJECT
public:
    MusicPlayControl();
    Q_PROPERTY(bool isStart READ getIsStart WRITE setIsStart NOTIFY statusChanged)

    bool getIsStart();
    void setIsStart(bool status);

signals:
    void indexChanged();
    void statusChanged();

private:
    bool m_isStart;
    QMediaPlayer m_mediaPlayer;
};

#endif // MUSICPLAYCONTROL_H
