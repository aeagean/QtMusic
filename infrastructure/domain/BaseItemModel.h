#ifndef CPP_BASE_ITEM_MODEL_H
#define CPP_BASE_ITEM_MODEL_H

#include <QObject>

class BaseItemModel : public QObject
{
    Q_OBJECT
public:
    BaseItemModel(QObject* parent = 0);

    Q_INVOKABLE virtual void submit();
    Q_INVOKABLE virtual void revert();

    virtual void operator=(BaseItemModel &item) { Q_UNUSED(item); }

signals:
    void submited(QObject *model);
};

#endif // CPP_BASE_ITEM_MODEL_H
