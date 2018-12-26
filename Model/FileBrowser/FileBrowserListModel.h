/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/
#ifndef FILEBROWSERLISTMODEL_H
#define FILEBROWSERLISTMODEL_H

#include "ObjectListModel.h"
#include "FileBrowserModel.h"
#include <QDir>

class FileBrowserListModel: public ObjectListModel<FileBrowserModel>
{
    Q_OBJECT
public:
    FileBrowserListModel();

    Q_PROPERTY(QStringList displayPathNameList READ getDisplayPathNameList NOTIFY statusPathNameChanged)
    Q_PROPERTY(bool isAllSelected READ getIsAllSelected WRITE setIsAllSelected NOTIFY statusChanged)

    Q_INVOKABLE void cdNextPath(QString pathName);
    Q_INVOKABLE void cdPath(int index);
    Q_INVOKABLE void save();

    QStringList getDisplayPathNameList();
    void setDisplayPathNameList();

    bool getIsAllSelected();
    void setIsAllSelected(bool status);

private:
    QStringList getSelectedPathNameList(); /*Selected music path*/

public slots:
    void reload();

signals:
    void statusChanged();
    void statusPathNameChanged();

private:
    QStringList m_displayPathNameList;
    bool m_isAllSelected;
    QDir m_dir;
};

#endif // FILEBROWSERLISTMODEL_H
