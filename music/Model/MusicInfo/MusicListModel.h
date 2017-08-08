#ifndef MUSICLISTMODEL_H
#define MUSICLISTMODEL_H

#include "ObjectListModel.h"
#include "MusicModel.h"

class MusicListModel : public ObjectListModel<MusicModel>
{
    Q_OBJECT
public:
    MusicListModel();
    virtual ~MusicListModel();

signals:
    void statusChanged();

private slots:
    void reload();
};

#endif // MUSICLISTMODEL_H
