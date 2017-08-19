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

    Q_PROPERTY(int currentIndex READ getCurrentIndex NOTIFY statusChanged)

    int getCurrentIndex();
    void setCurrentIndex(int index);

private slots:
    void reload();
    void currentIndexChangedSlot(qint64 position);

signals:
    void statusChanged();

private:
    int m_currentIndex;
};

#endif // MUSICLYRICSLISTMODEL_H
