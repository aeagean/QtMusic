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
    Q_PROPERTY(bool isAllSelected READ getIsAllSelected WRITE setIsAllSelected NOTIFY statusChanged)

    Q_INVOKABLE void changedPath(int index);
    Q_INVOKABLE void save();

    QString getPathName();
    void setPathName(QString pathName);

    QStringList getPathNameList();

    bool getIsAllSelected();
    void setIsAllSelected(bool status);

public slots:
    void reload();

signals:
    void statusChanged();
    void statusPathNameChanged();
    void isAllSelectedChanged();

private:
    QString m_pathName;
    QStringList m_pathNameList;
    bool m_isAllSelected;
};

#endif // FILEBROWSERLISTMODEL_H
