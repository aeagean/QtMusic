#include "MusicLyricsListModel.h"
#include "MusicListService.h"
#include "MusicPlayControl.h"
#include <QFile>
#include <QRegExp>

MusicLyricsListModel::MusicLyricsListModel()
{
    this->reload();
    connect(MusicPlayControl::instance(), SIGNAL(positionChanged(qint64)), this, SLOT(currentIndexChangedSlot(qint64)));
    connect(MusicListService::instance()->getMediaPlayList(), SIGNAL(currentIndexChanged(int)), this, SLOT(reload()));
}

MusicLyricsListModel::~MusicLyricsListModel()
{

}

int MusicLyricsListModel::getCurrentIndex()
{
    return m_currentIndex;
}

void MusicLyricsListModel::setCurrentIndex(int index)
{
    m_currentIndex = index;
    emit statusChanged();
}

void MusicLyricsListModel::reload()
{
    QList<MusicLyricsModel *> musicLyricsListModel = QList<MusicLyricsModel *>();

//    QFile file("/home/strong/Music/Lyric/不朽之罪.lrc");
    int index = MusicListService::instance()->getMediaPlayList()->currentIndex();
    MusicBase* musicBase = MusicListService::instance()->get(index);
    int i = musicBase->getName().length();
    int count = musicBase->getPathName().length();
    qDebug()<<musicBase->getPathName().remove(count-i, i)<<i;
    QDir dir(musicBase->getPathName().remove(count-i, i) + "/lyric");
    dir.setNameFilters(QStringList("*.lrc"));
    dir.setSorting(QDir::Name);
    qDebug()<<dir.entryList()<<musicBase->getPathName().remove(count-i, i) + "/lyric";

//    file.open(QIODevice::ReadOnly);

//    while (!file.atEnd()) {
//        QString lineStr = file.readLine().data();

//        QRegExp reg("[\[]([0-9]+)[\:]([0-9]+)[\.]([0-9]+)[\]]");
//        reg.indexIn(lineStr);

//        MusicLyricsModel* model = new MusicLyricsModel(this);
//        model->setTime(QTime(0, reg.cap(1).toInt(), reg.cap(2).toInt(), 10*reg.cap(3).toInt()));
//        model->setContent(lineStr.remove(reg));
//        musicLyricsListModel.append(model);
//    }
//    file.close();
    notifyResetList(musicLyricsListModel);
}

void MusicLyricsListModel::currentIndexChangedSlot(qint64 position)
{
    for (int i = 0; i < this->size(); i++) {
        if (this->getItemList().at(i)->getTime().msecsSinceStartOfDay() >= position) {
            this->setCurrentIndex(i);
            break;
        }
    }
}
