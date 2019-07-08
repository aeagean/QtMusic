/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/
#ifndef MUSICBASE_H
#define MUSICBASE_H

#include <QString>
#include <QObject>
#include "DomainObject.h"

class MusicBase : public QObject, public DomainObject
{
    Q_OBJECT
public:
    MusicBase();
    virtual ~MusicBase() override;

    void fromJson(const QJsonObject& data) override;
    QJsonObject toJson() override;

    QString getId();
    void setId(QString id);

    /*"/Music/I miss.mp3"*/

    QString getName();      /*I miss.mp3*/
    void setName(const QString& name);

    QString getMusicName(); /*I miss*/
    void setMusicName(const QString& musicName);

    QString getPathName();  /*/Music/I miss.mp3*/
    void setPathName(const QString& pathName);

private:
    QString m_id;
    QString m_name;
    QString m_pathName;
    QString m_musicName;
};

#endif // MUSICBASE_H
