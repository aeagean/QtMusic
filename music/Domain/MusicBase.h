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

private:
    QString m_id;
    QString m_name;
};

#endif // MUSICBASE_H
