#include "FileBrowserListModel.h"
#include "FileBrowserService.h"
#include "MusicListService.h"
#include <QDebug>

FileBrowserListModel::FileBrowserListModel()
{
    this->reload();
    connect(this, SIGNAL(statusChanged()), this, SLOT(reload()));
}

void FileBrowserListModel::cdNextPath(QString pathName)
{
    FileBrowserService::instance()->cdNextPath(pathName);
    emit statusChanged();
}

void FileBrowserListModel::cdPath(int index)
{
    QString pathName;
    for (int i = 0; i < index+1; i++) {
        if (getDisplayPathNameList().at(i) == "")
            pathName += ("/");
        else
            pathName += (getDisplayPathNameList().at(i) + "/");
    }

    FileBrowserService::instance()->cdPath(pathName);
    emit statusChanged();
}

void FileBrowserListModel::save()
{
    MusicListService::instance()->add(this->getSelectedPathNameList());
}

QStringList FileBrowserListModel::getDisplayPathNameList()
{
    return m_displayPathNameList;
}

void FileBrowserListModel::setDisplayPathNameList()
{
    QString fullPathName = FileBrowserService::instance()->getCurrentFullPathNameList();
    QDir dir(fullPathName);
    this->m_displayPathNameList.clear();
    do {
        this->m_displayPathNameList.insert(0, dir.dirName());
    }
    while (dir.cdUp());

    emit statusPathNameChanged();
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

QStringList FileBrowserListModel::getSelectedPathNameList()
{
    QStringList selectedPathNameList;

    for (int i = 0; i < this->size(); i++) {
        FileBrowserModel* model = this->getItemList().at(i);
        if (model->getIsSelected() == true) {
            selectedPathNameList.append(model->getPathName());
        }
    }

    return selectedPathNameList;
}

void FileBrowserListModel::reload()
{
    QStringList currentPathNameList = FileBrowserService::instance()->getCurrentPathNameList();
    QList<FileBrowserModel* > modelList = QList<FileBrowserModel* >();

    for (int i = 0; i < currentPathNameList.count(); i++) {
        QString fullPathName = FileBrowserService::instance()->getCurrentFullPathNameList();

        FileBrowserModel* model = new FileBrowserModel(this);
        model->setPathName(fullPathName);
        model->setDisplayPathName(currentPathNameList.at(i));
        model->setIsSelected(this->getIsAllSelected());
        modelList.append(model);
    }

    notifyResetList(modelList);

    this->setDisplayPathNameList();
}
