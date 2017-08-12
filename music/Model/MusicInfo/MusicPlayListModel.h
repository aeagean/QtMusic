#ifndef MUSICLISTMODEL_H
#define MUSICLISTMODEL_H

#include "ObjectListModel.h"
#include "MusicPlayModel.h"

class MusicPlayListModel : public ObjectListModel<MusicPlayModel>
{
    Q_OBJECT
public:
    MusicPlayListModel();
    virtual ~MusicPlayListModel();

    Q_PROPERTY(QString currentPlayMusicId READ getCurrentPlayMusicId WRITE setCurrentPlayMusicId NOTIFY statusChanged)

    QString getCurrentPlayMusicId();
    void setCurrentPlayMusicId(QString musicId);

signals:
    void statusChanged();

private slots:
    void reload();

private:
    QString m_currentPlayMusicId;
};

#endif // MUSICLISTMODEL_H
