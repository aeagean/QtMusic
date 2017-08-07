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
    Q_PROPERTY(QStringList pathNameList READ getPathNameList NOTIFY statusPathNameChanged)

    Q_INVOKABLE void changedPath(int index);

    QString getPathName();
    void setPathName(QString pathName);

    QStringList getPathNameList();

public slots:
    void reload();

signals:
    void statusChanged();
    void statusPathNameChanged();

private:
    QString m_pathName;
    QStringList m_pathNameList;
};

#endif // FILEBROWSERLISTMODEL_H
