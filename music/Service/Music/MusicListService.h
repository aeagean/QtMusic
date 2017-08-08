#ifndef MUSICLISTSERVICE_H
#define MUSICLISTSERVICE_H

#include "MusicRepertory.h"

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

    void add(QStringList pathNameList);

private:
    MusicListService();

private:
    static MusicListService* _instance;
};

#endif // MUSICLISTSERVICE_H
