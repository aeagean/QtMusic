#ifndef MUSICBASE_H
#define MUSICBASE_H

#include <QString>

class MusicBase
{
public:
    MusicBase();
    virtual ~MusicBase();

    QString getId();
    void setId(QString id);

    QString getName();
    void setName(QString name);

    QString getPathName();
    void setPathName(QString pathName);

private:
    QString m_id;
    QString m_name;
    QString m_pathName;
};

#endif // MUSICBASE_H
