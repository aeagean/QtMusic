#ifndef FILEBROWSERLISTMODEL_H
#define FILEBROWSERLISTMODEL_H

#include "ObjectListModel.h"
#include "FileBrowserModel.h"

class FileBrowserListModel: public ObjectListModel<FileBrowserModel>
{
    Q_OBJECT
public:
    FileBrowserListModel();

    Q_PROPERTY(QString pathName READ getPathName WRITE setPathName NOTIFY statusChanged)

    QString getPathName();
    void setPathName(QString pathName);

public slots:
    void reload();

signals:
    void statusChanged();

private:
    QString m_pathName;
};

#endif // FILEBROWSERLISTMODEL_H
