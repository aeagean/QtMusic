#ifndef MUSICMODEL_H
#define MUSICMODEL_H

#include "BaseItemModel.h"

class MusicModel : public BaseItemModel
{
    Q_OBJECT
public:
    MusicModel();

    Q_PROPERTY(QString id READ getId NOTIFY statusChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY statusChanged)

    QString getId();
    void setId(QString id);

    QString getName();
    void setName(QString name);

    void operator=(const MusicModel& model);

signals:
    void statusChanged();

private:
    QString m_id;
    QString m_name;
};

#endif // MUSICMODEL_H
