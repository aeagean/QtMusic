#ifndef FILEBROWSERSERVICE_H
#define FILEBROWSERSERVICE_H

#include <QDir>
#include <QObject>

class FileBrowserService : public QObject
{
    Q_OBJECT
public:
    static FileBrowserService* instance();

    QStringList getCurrentPathNameList();
    QString getCurrentFullPathNameList();
    void cdNextPath(QString currentPathName);
    void cdPath(QString pathName);

private:
    FileBrowserService();

private:
    static FileBrowserService* _instance;
    QDir m_dir;
};

#endif // FILEBROWSERSERVICE_H
