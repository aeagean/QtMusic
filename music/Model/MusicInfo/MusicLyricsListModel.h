#ifndef MUSICLYRICSLISTMODEL_H
#define MUSICLYRICSLISTMODEL_H

#include "ObjectListModel.h"
#include "MusicLyricsModel.h"

class MusicLyricsListModel : public ObjectListModel<MusicLyricsModel>
{
    Q_OBJECT
public:
    MusicLyricsListModel();
    virtual ~MusicLyricsListModel();

private slots:
    void reload();
};

#endif // MUSICLYRICSLISTMODEL_H
