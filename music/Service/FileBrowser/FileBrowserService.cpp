#include "FileBrowserService.h"
#include <QDebug>

FileBrowserService * FileBrowserService::_instance = NULL;

FileBrowserService *FileBrowserService::instance()
{
    if (_instance == NULL) {
        _instance = new FileBrowserService();
    }
    return _instance;
}

QStringList FileBrowserService::getCurrentPathNameList()
{
    return m_dir.entryList();
}

QString FileBrowserService::getCurrentFullPathNameList()
{
    return m_dir.path();
}

void FileBrowserService::cdNextPath(QString currentPathName)
{
    if (m_dir.exists() == true )
        m_dir.cd(currentPathName);
}

void FileBrowserService::cdPath(QString pathName)
{
    m_dir.cd(pathName);
}

void FileBrowserService::cdPath(int indexPath)
{
    while(--indexPath) {
        m_dir.cdUp();
    }
}

FileBrowserService::FileBrowserService()
{
    m_dir.setPath(QDir::rootPath());
    m_dir.setFilter(QDir::Dirs|QDir::NoDotAndDotDot);
    m_dir.setSorting(QDir::Name);
}
