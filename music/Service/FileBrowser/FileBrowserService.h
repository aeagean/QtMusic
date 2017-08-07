#ifndef FILEBROWSERSERVICE_H
#define FILEBROWSERSERVICE_H

#include <QObject>

class FileBrowserService : public QObject
{
    Q_OBJECT
public:
    static FileBrowserService* instance();

private:
    FileBrowserService();

private:
    static FileBrowserService* _instance;
};

#endif // FILEBROWSERSERVICE_H
