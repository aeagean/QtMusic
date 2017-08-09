#include "MusicListService.h"
#include <QFile>
#include <QDir>
#include <QDebug>

const QString musicFilter[] = {
    "*.mp3"
};

MusicListService * MusicListService::_instance = NULL;

MusicListService *MusicListService::instance()
{
    if (_instance == NULL) {
        _instance = new MusicListService();
    }
    return _instance;
}

MusicListService::MusicListService()
{
    m_musicDir.setNameFilters(this->getMusicTypeFilter());
    m_musicDir.setSorting(QDir::Name);
}

QStringList MusicListService::getMusicTypeFilter()
{
    QStringList filterList;
    for (int i = 0; i < sizeof(musicFilter)/sizeof(musicFilter[0]); i++)
        filterList.append(musicFilter[i]);

    return filterList;
}

QList<MusicBase *> MusicListService::getList()
{
    return MusicRepertory::instance()->getList();
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

void MusicListService::add(QStringList pathList)
{    
    for (int i = 0; i < pathList.count(); i++) {
        m_musicDir.setPath(pathList.at(i));

        for (int j = 0; j < m_musicDir.entryList().count(); j++) {
            m_fileInfo.setFile(m_musicDir.entryList().at(j));

            MusicBase* musicBase = new MusicBase();
            musicBase->setName(m_fileInfo.fileName());
            musicBase->setMusicName(m_fileInfo.baseName());
            musicBase->setPathName(m_fileInfo.filePath()); /*filePath() Returns the name of the file, excluding the path*/
            this->add(musicBase);
        }
    }
}

