#include "FileBrowserListModel.h"
#include "FileBrowserService.h"
#include <QDebug>

FileBrowserListModel::FileBrowserListModel()
{
    connect(this, SIGNAL(statusChanged()), this, SLOT(reload()));
}

void FileBrowserListModel::changedPath(int index)
{
    if (index == 0) {
        this->setPathName("/");
    }
    else {
        while (m_pathNameList.size() > index) {
            m_pathNameList.removeLast();
        }
        this->setPathName("/"+m_pathNameList.join("/"));
    }
}

QString FileBrowserListModel::getPathName()
{
    return m_pathName;
}

void FileBrowserListModel::setPathName(QString pathName)
{
    m_pathName = pathName;
    emit statusChanged();
}

QStringList FileBrowserListModel::getPathNameList()
{
    return m_pathNameList;
}

bool FileBrowserListModel::getIsAllSelected()
{
    return m_isAllSelected;
}

void FileBrowserListModel::setIsAllSelected(bool status)
{
    m_isAllSelected = status;
    emit statusChanged();
}

void FileBrowserListModel::reload()
{
    this->m_pathNameList.clear();
    QStringList pathList = FileBrowserService::instance()->getNamePathList(m_pathName);
    m_pathNameList = FileBrowserService::instance()->getCurrentPathNameList();
    QList<FileBrowserModel* > modelList = QList<FileBrowserModel* >();

    for (int i = 0; i < pathList.count(); i++) {
        FileBrowserModel* model = new FileBrowserModel(this);
        model->setPathName(pathList.at(i));
        model->setIsSelected(this->getIsAllSelected());
        modelList.append(model);
    }

    notifyResetList(modelList);
    emit statusPathNameChanged();
}
