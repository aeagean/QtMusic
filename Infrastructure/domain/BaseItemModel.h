/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/
#ifndef CPP_BASE_ITEM_MODEL_H
#define CPP_BASE_ITEM_MODEL_H

#include <QObject>

class BaseItemModel : public QObject
{
    Q_OBJECT
public:
    BaseItemModel(QObject* parent = nullptr);

    Q_INVOKABLE virtual void submit();
    Q_INVOKABLE virtual void revert();

    virtual void operator=(BaseItemModel &item) { Q_UNUSED(item); }

signals:
    void submited(QObject *model);
};

#endif // CPP_BASE_ITEM_MODEL_H
