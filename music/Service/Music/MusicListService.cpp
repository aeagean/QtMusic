#include "MusicListService.h"

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

