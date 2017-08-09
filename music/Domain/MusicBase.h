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

    /*"/Music/I miss.mp3"*/

    QString getName();      /*I miss.mp3*/
    void setName(QString name);

    QString getMusicName(); /*I miss*/
    void setMusicName(QString musicName);

    QString getPathName();  /*/Music/I miss.mp3*/
    void setPathName(QString pathName);

private:
    QString m_id;
    QString m_name;
    QString m_pathName;
    QString m_musicName;
};

#endif // MUSICBASE_H
