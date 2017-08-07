#include "FileBrowserListModel.h"
#include "FileBrowserService.h"

FileBrowserListModel::FileBrowserListModel()
{
    connect(this, SIGNAL(statusChanged()), this, SLOT(reload()));
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

void FileBrowserListModel::reload()
{
    QStringList pathList = FileBrowserService::instance()->getNamePathList(m_pathName);

    QList<FileBrowserModel* > modelList = QList<FileBrowserModel* >();

    for (int i = 0; i < pathList.count(); i++) {
        FileBrowserModel* model = new FileBrowserModel(this);
        model->setPathName(pathList.at(i));
        modelList.append(model);
    }

    notifyResetList(modelList);
}
