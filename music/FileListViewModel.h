#ifndef FILELISTVIEWMODEL_H
#define FILELISTVIEWMODEL_H

#include <QDir>

class FileListViewModel
{
public:
    FileListViewModel();

private:
    QDir m_dir;
};

#endif // FILELISTVIEWMODEL_H
