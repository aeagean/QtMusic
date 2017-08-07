#ifndef FILEBROWSERMODEL_H
#define FILEBROWSERMODEL_H

#include "BaseItemModel.h"

class FileBrowserModel : public BaseItemModel
{
    Q_OBJECT
public:
    FileBrowserModel(QObject* parent = 0);

    Q_PROPERTY(QString pathName READ getPathName WRITE setPathName NOTIFY statusChanged)

    QString getPathName();
    void setPathName(QString pathName);

    void operator=(const FileBrowserModel& model);

signals:
    void statusChanged();

private:
    QString m_pathName;
};

#endif // FILEBROWSERMODEL_H
