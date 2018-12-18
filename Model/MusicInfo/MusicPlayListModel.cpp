#include "MusicPlayListModel.h"
#include "MusicListService.h"
#include "MusicBase.h"

MusicPlayListModel::MusicPlayListModel()
{
    this->reload();
    connect(MusicListService::instance(), SIGNAL(listChanged()), this, SLOT(reload()));
}

MusicPlayListModel::~MusicPlayListModel()
{

}

void MusicPlayListModel::setCurrentPlayMusicId(QString musicId)
{
    MusicListService::instance()->setCurrentPlayMusicId(musicId);
}

void MusicPlayListModel::reload()
{
    QList<MusicBase *> musicList = MusicListService::instance()->getList();
    QList<MusicPlayModel *> musicPlayListModel = QList<MusicPlayModel *>();
    MusicBase* musicBase = NULL;

    for (int i = 0; i < musicList.count(); i++) {
        musicBase = musicList.at(i);
        if (musicBase->getMusicName() != "") {
            MusicPlayModel* model = new MusicPlayModel(musicBase, this);
            musicPlayListModel.append(model);
        }
    }

    notifyResetList(musicPlayListModel);
}
