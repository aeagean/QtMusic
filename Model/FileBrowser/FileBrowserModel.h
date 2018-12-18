#ifndef FILEBROWSERMODEL_H
#define FILEBROWSERMODEL_H

#include "BaseItemModel.h"

class FileBrowserModel : public BaseItemModel
{
    Q_OBJECT
public:
    FileBrowserModel(QObject* parent = 0);

    /*/home/user/Music/*/

    /*Current full path -> "/home/user/Music"*/
    Q_PROPERTY(QString pathName READ getPathName WRITE setPathName NOTIFY statusChanged)

    /*Display path name -> "Music"*/
    Q_PROPERTY(QString displayPathName READ getDisplayPathName WRITE setDisplayPathName NOTIFY statusChanged)
    Q_PROPERTY(bool isSelected READ getIsSelected WRITE setIsSelected NOTIFY statusChanged)

    QString getPathName();
    void setPathName(QString pathName);

    QString getDisplayPathName();
    void setDisplayPathName(QString displayPathName);

    bool getIsSelected();
    void setIsSelected(bool status);

    void operator=(const FileBrowserModel& model);

signals:
    void statusChanged();

private:
    QString m_pathName;
    QString m_displayPathName;
    bool m_isSelected;
};

#endif // FILEBROWSERMODEL_H
