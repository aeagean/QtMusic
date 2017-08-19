#include "MusicLyricsListModel.h"
#include <QFile>
#include <QRegExp>

MusicLyricsListModel::MusicLyricsListModel()
{
    this->reload();
    QFile file("/home/strong/Music/Lyric/不朽之罪.lrc");
    file.open(QIODevice::ReadOnly);
    qDebug()<<file.readAll().data();
}

MusicLyricsListModel::~MusicLyricsListModel()
{

}

void MusicLyricsListModel::reload()
{
    QList<MusicLyricsModel *> musicLyricsListModel = QList<MusicLyricsModel *>();

    QFile file("/home/strong/Music/Lyric/不朽之罪.lrc");
    file.open(QIODevice::ReadOnly);

    while (!file.atEnd()) {
        QString lineStr = file.readLine().data();

        QRegExp reg("[\[]([0-9]+)[\:]([0-9]+)[\.]([0-9]+)[\]]");
        int index = reg.indexIn(lineStr);

        MusicLyricsModel* model = new MusicLyricsModel(this);
        model->setTime(QTime(0, reg.cap(1).toInt(), reg.cap(2).toInt(), 10*reg.cap(3).toInt()));
        model->setContent(lineStr.remove(reg));
        musicLyricsListModel.append(model);
    }

    notifyResetList(musicLyricsListModel);
}
