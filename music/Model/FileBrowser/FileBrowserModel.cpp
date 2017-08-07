#include "FileBrowserModel.h"

FileBrowserModel::FileBrowserModel(QObject *parent):
    BaseItemModel(parent)
{
    m_pathName = "";
}

QString FileBrowserModel::getPathName()
{
    return m_pathName;
}

void FileBrowserModel::setPathName(QString pathName)
{
    m_pathName = pathName;
    emit statusChanged();
}

void FileBrowserModel::operator=(const FileBrowserModel &model)
{
    this->m_pathName = model.m_pathName;
    emit statusChanged();
}
