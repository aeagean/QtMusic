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

    Q_INVOKABLE void setCurrentPlayMusicId(QString musicId);

signals:
    void statusChanged();

private slots:
    void reload();

private:

};

#endif // MUSICLISTMODEL_H
