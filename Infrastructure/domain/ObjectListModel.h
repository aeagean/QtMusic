#ifndef CPP_OBJECT_LIST_MODEL_H
#define CPP_OBJECT_LIST_MODEL_H

#include "BaseListModel.h"

template <class M>
class ObjectListModel : public BaseListModel
{
public:
    ObjectListModel(QObject* parent = 0) : BaseListModel(parent) {}

    QVariant at(int index);
    QVariant last();
    int size();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;

protected:
    const QList<M *> getItemList();
    void notifyAppend(M *item);
    void notifyRemove(M *index);
    void notifyRemove(int index);
    void notifyRemoveLast();
    void notifyResetList(QList<M *> & itemList);

private:
    QList<M *> m_itemList;
};

#include "ObjectListModelImpl.h"

#endif // CPP_OBJECT_LIST_MODEL_H

