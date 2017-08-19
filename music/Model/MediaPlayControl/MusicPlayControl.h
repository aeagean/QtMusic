#ifndef MUSICPLAYCONTROL_H
#define MUSICPLAYCONTROL_H

#include <QTime>
#include <QObject>
#include <QMediaPlaylist>
#include <QMediaPlayer>

class MusicPlayControl : public QMediaPlayer
{
    Q_OBJECT
public:
    MusicPlayControl();
    Q_PROPERTY(QString musicName READ getMusicName NOTIFY statusChanged)
    Q_PROPERTY(bool isStart READ getIsStart WRITE setIsStart NOTIFY statusChanged)  
    Q_PROPERTY(double progressBarValue READ getProgressBarValue WRITE setProgressBarValue NOTIFY statusChanged)  /*0 - 1*/
    Q_PROPERTY(QString leftTimeStr READ getLeftTimeStr NOTIFY statusChanged)
    Q_PROPERTY(QString rightTimeStr READ getRightTimeStr NOTIFY statusChanged)
    Q_PROPERTY(QString playbackModeStr READ getPlaybackModeStr NOTIFY statusChanged)

    Q_INVOKABLE void nextMusic();
    Q_INVOKABLE void prevMusic();
    Q_INVOKABLE void changedPlaybackMode();

    QString getMusicName();

    bool getIsStart();
    void setIsStart(bool status);

    QString getLeftTimeStr();
    QString getRightTimeStr();
    QString getPlaybackModeStr();

    double getProgressBarValue();
    void setProgressBarValue(double progressBarValue);

signals:
    void statusChanged();

private:
    bool m_isStart;
    double m_progressBarValue;
    QMediaPlaylist* m_playList;
    QTime m_leftTime;
    QTime m_rightTime;
    QString m_musicName;
};

#endif // MUSICPLAYCONTROL_H
