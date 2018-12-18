#ifndef MUSICLYRICSMODEL_H
#define MUSICLYRICSMODEL_H

#include "BaseItemModel.h"
#include <QTime>

class MusicLyricsModel : public BaseItemModel
{
    Q_OBJECT
public:
    MusicLyricsModel(QObject* parent = NULL);
    MusicLyricsModel(QString content, QObject* parent = NULL);

    Q_PROPERTY(QString id READ getId NOTIFY statusChanged)
    Q_PROPERTY(QString timeStr READ getTimeStr NOTIFY statusChanged)
    Q_PROPERTY(QTime time READ getTime NOTIFY statusChanged)
    Q_PROPERTY(QString content READ getContent NOTIFY statusChanged)

    QString getId();
    void setId(QString id);

    QString getTimeStr();
    void setTimeStr(QString timeStr);

    QTime getTime();
    void setTime(QTime time);

    QString getContent();
    void setContent(QString content);

    void operator=(const MusicLyricsModel& model);

signals:
    void statusChanged();

private:
    QString m_id;
    QString m_timeStr;
    QTime m_time;
    QString m_content;
};

#endif // MUSICLYRICSMODEL_H
