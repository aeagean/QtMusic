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

QFileInfoList FileBrowserService::getInfoPathList(QString path)
{
    m_fileInfoList.clear();
    return m_fileInfoList = m_dir.entryInfoList();
}

QStringList FileBrowserService::getCurrentPathNameList()
{
    QStringList list;
//    list.append("disk");
    list.append(m_dir.path().split("/", QString::SkipEmptyParts));
    return list;
}

QStringList FileBrowserService::getNamePathList(QString path)
{
    m_namePathList.clear();
    m_dir.setPath(path);
    m_fileInfoList.clear();
    m_fileInfoList = m_dir.entryInfoList();
    for (int i = 0; i < m_fileInfoList.count(); i++) {
        m_namePathList.append(m_fileInfoList.at(i).fileName());
    }
    return m_namePathList;
}

FileBrowserService::FileBrowserService()
{
    m_dir.setPath("/");
    m_dir.setFilter(QDir::Dirs|QDir::NoDotAndDotDot);
    m_dir.setSorting(QDir::Name);
}
