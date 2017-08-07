#ifndef FILEBROWSERMODEL_H
#define FILEBROWSERMODEL_H

#include "BaseItemModel.h"

class FileBrowserModel : public BaseItemModel
{
    Q_OBJECT
public:
    FileBrowserModel(QObject* parent = 0);

    Q_PROPERTY(QString pathName READ getPathName WRITE setPathName NOTIFY statusChanged)
    Q_PROPERTY(bool isSelected READ getIsSelected WRITE setIsSelected NOTIFY statusChanged)

    QString getPathName();
    void setPathName(QString pathName);

    bool getIsSelected();
    void setIsSelected(bool status);

    void operator=(const FileBrowserModel& model);

signals:
    void statusChanged();

private:
    QString m_pathName;
    bool m_isSelected;
};

#endif // FILEBROWSERMODEL_H
