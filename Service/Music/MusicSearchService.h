#ifndef MUSICSEARCHSERVICE_H
#define MUSICSEARCHSERVICE_H

#include "MusicBase.h"
#include <QObject>

/*get online music service*/

class MusicSearchService : public QObject
{
    Q_OBJECT
public:
    static MusicSearchService* instance();
    QList<MusicBase*> getMusicSearchList(QString musicName);

private:
    MusicSearchService();
    void readJson();

private:
    static MusicSearchService* _instance;
};

#endif // MUSICSEARCHSERVICE_H
