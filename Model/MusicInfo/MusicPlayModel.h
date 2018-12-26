/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/
#ifndef MUSICMODEL_H
#define MUSICMODEL_H

#include "BaseItemModel.h"
#include "MusicBase.h"

class MusicPlayModel : public BaseItemModel
{
    Q_OBJECT
public:
    MusicPlayModel(QObject* parent = NULL);
    MusicPlayModel(MusicBase* musicBase, QObject* parent = NULL);

    Q_PROPERTY(QString id READ getId NOTIFY statusChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY statusChanged)

    QString getId();
    void setId(QString id);

    QString getName();
    void setName(QString name);

    void operator=(const MusicPlayModel& model);

signals:
    void statusChanged();

private:
    QString m_id;
    QString m_name;
};

#endif // MUSICMODEL_H
