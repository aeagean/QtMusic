/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/
#ifndef MUSICREPERTORY_H
#define MUSICREPERTORY_H

#include <QObject>
#include "MusicBase.h"
#include <QMediaPlaylist>

class MusicRepertory : public QObject
{
    Q_OBJECT
public:
    static MusicRepertory* instance();
    QList<MusicBase *> getList();

    MusicBase *get(QString id);

    void add(MusicBase *musicBase);
    void remove(QString id);
    void update(MusicBase *musicBase);
    QMediaPlaylist* getMediaPlayList();

private:
    MusicRepertory();

private:
    void save();
    void reload();
    QString generateRandomId();

private:
    static MusicRepertory* _instance;
    QList<MusicBase* > m_musicBaseList;
    QMediaPlaylist* m_mediaPlayList;
};

#endif // MUSICREPERTORY_H
