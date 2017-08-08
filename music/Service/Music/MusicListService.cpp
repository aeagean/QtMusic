#include "MusicListService.h"
#include <QFile>

MusicListService * MusicListService::_instance = NULL;

MusicListService::MusicListService()
{

}

MusicListService *MusicListService::instance()
{
    if (_instance == NULL) {
        _instance = new MusicListService();
    }
    return _instance;
}

QList<MusicBase *> MusicListService::getList()
{

}

MusicBase *MusicListService::get(QString id)
{
    return MusicRepertory::instance()->get(id);
}

void MusicListService::add(MusicBase *musicBase)
{
    MusicRepertory::instance()->add(musicBase);
}

void MusicListService::remove(QString id)
{
    MusicRepertory::instance()->remove(id);
}

void MusicListService::update(MusicBase *musicBase)
{
    MusicRepertory::instance()->update(musicBase);
}

void MusicListService::add(QStringList pathNameList)
{
    QFile file;
    for (int i = 0; i < pathNameList.count(); i++) {
        file.setFileName(pathNameList.at(i));
        if ( file.exists() == true ) {
            MusicBase* musicBase = new MusicBase();
            musicBase->setPathName(pathNameList.at(i));
            this->add(musicBase);
        }
    }
}

