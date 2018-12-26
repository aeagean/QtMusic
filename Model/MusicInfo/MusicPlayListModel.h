/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/
#ifndef MUSICLISTMODEL_H
#define MUSICLISTMODEL_H

#include "ObjectListModel.h"
#include "MusicPlayModel.h"

class MusicPlayListModel : public ObjectListModel<MusicPlayModel>
{
    Q_OBJECT
public:
    MusicPlayListModel();
    virtual ~MusicPlayListModel();

    Q_INVOKABLE void setCurrentPlayMusicId(QString musicId);

signals:
    void statusChanged();

private slots:
    void reload();

private:

};

#endif // MUSICLISTMODEL_H
