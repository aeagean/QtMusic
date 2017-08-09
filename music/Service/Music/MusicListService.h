#ifndef MUSICLISTSERVICE_H
#define MUSICLISTSERVICE_H

#include "MusicRepertory.h"
#include <QDir>

class MusicListService : public QObject
{
    Q_OBJECT
public:
    static MusicListService* instance();

    QList<MusicBase *> getList();

    MusicBase *get(QString id);

    void add(MusicBase *musicBase);
    void remove(QString id);
    void update(MusicBase *musicBase);

    void add(QStringList pathList); //Gets the list of paths where the music is located.

private:
    MusicListService();
    QStringList getMusicTypeFilter();

private:
    static MusicListService* _instance;
    QDir m_musicDir;
    QFileInfo m_fileInfo;
};

#endif // MUSICLISTSERVICE_H
