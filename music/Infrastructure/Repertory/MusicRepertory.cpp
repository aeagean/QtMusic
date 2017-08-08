#include "MusicRepertory.h"

MusicRepertory * MusicRepertory::_instance = NULL;

MusicRepertory *MusicRepertory::instance()
{
    if (_instance == NULL) {
        _instance = new MusicRepertory();
    }
    return _instance;
}

QList<MusicBase *> MusicRepertory::getMusicBaseList()
{

}

MusicBase *MusicRepertory::getMusicBase(QString id)
{

}

void MusicRepertory::addMusicBase(MusicBase *musicBase)
{

}

void MusicRepertory::rmMusicBase(QString id)
{

}

void MusicRepertory::updateMusicBase(MusicBase *musicBase)
{

}

MusicRepertory::MusicRepertory()
{

}

void MusicRepertory::save()
{

}

void MusicRepertory::reload()
{

}

QString MusicRepertory::generateRandomId()
{
    int randId = rand();
    for (int i = 0; i < m_musicBaseList.count(); i++)
    {
        MusicBase* model = m_musicBaseList.at(i);
        if (model->getId().toInt() == randId)
            return generateRandomId();
    }
    return QString::number(randId);
}
