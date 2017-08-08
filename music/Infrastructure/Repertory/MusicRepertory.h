#ifndef MUSICREPERTORY_H
#define MUSICREPERTORY_H

#include <QObject>
#include "MusicBase.h"

class MusicRepertory : public QObject
{
    Q_OBJECT
public:
    static MusicRepertory* instance();
    QList<MusicBase *> getMusicBaseList();

    MusicBase *getMusicBase(QString id);

    void addMusicBase(MusicBase *musicBase);
    void rmMusicBase(QString id);
    void updateMusicBase(MusicBase *musicBase);

private:
    MusicRepertory();

private:
    void save();
    void reload();
    QString generateRandomId();

private:
    static MusicRepertory* _instance;
    QList<MusicBase* > m_musicBaseList;
};

#endif // MUSICREPERTORY_H
