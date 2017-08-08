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
    return m_musicBaseList;
}

MusicBase *MusicRepertory::getMusicBase(QString id)
{
    for (int i = 0; i < m_musicBaseList.count(); i++) {
        if (m_musicBaseList.at(i)->getId() == id) {
            return m_musicBaseList.at(i);
        }
    }

    return NULL;
}

void MusicRepertory::addMusicBase(MusicBase *musicBase)
{
    if (musicBase == NULL)
        return;

    musicBase->setId(generateRandomId());
    m_musicBaseList.append(musicBase);

    this->save();
}

void MusicRepertory::rmMusicBase(QString id)
{
    for (int i = 0; i < m_musicBaseList.count(); i++) {
        if (m_musicBaseList.at(i)->getId() == id) {
            m_musicBaseList.removeAt(i);
            break;
        }
    }

    this->save();
}

void MusicRepertory::updateMusicBase(MusicBase *musicBase)
{
    if (musicBase == NULL)
        return;

    for (int i = 0; i < m_musicBaseList.count(); i++) {
        MusicBase * oldMusicBase = m_musicBaseList.at(i);
        if (oldMusicBase->getId() == musicBase->getId()) {
            delete oldMusicBase;

            m_musicBaseList.replace(i, musicBase);
            break;
        }
    }

    this->save();
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