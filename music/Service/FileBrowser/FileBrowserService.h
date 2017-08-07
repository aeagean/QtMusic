#ifndef FILEBROWSERSERVICE_H
#define FILEBROWSERSERVICE_H

#include <QDir>
#include <QObject>

class FileBrowserService : public QObject
{
    Q_OBJECT
public:
    static FileBrowserService* instance();
    QStringList getNamePathList(QString path);
    QFileInfoList getInfoPathList(QString path);

private:
    FileBrowserService();

private:
    static FileBrowserService* _instance;
    QStringList m_namePathList;
    QDir m_dir;
    QFileInfoList m_fileInfoList;
};

#endif // FILEBROWSERSERVICE_H
