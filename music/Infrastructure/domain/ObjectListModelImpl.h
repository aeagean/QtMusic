#ifndef CPP_OBJECT_LIST_MODEL_IMPL_H
#define CPP_OBJECT_LIST_MODEL_IMPL_H

#include "ObjectListModel.h"
#include <QDebug>

template <class M>
int ObjectListModel<M>::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_itemList.size();
}

template <class M>
QVariant ObjectListModel<M>::data(const QModelIndex &index, int role) const
{
    if (role == ModelDataRole) {
        const M * item = m_itemList.at(index.row());
        return QVariant::fromValue((QObject *)item);
    }

    return QVariant();

}

template <class M>
QVariant ObjectListModel<M>::at(int index)
{
    if (index < 0 || index >= m_itemList.size())
        return QVariant();

    return QVariant::fromValue((QObject *) m_itemList.at(index));
}


template <class M>
QVariant ObjectListModel<M>::last()
{
    if (m_itemList.size() > 0) {
        return QVariant::fromValue((QObject *)m_itemList.last());
    }
    return QVariant();
}

template <class M>
int ObjectListModel<M>::size()
{
    return m_itemList.size();
}

template <class M>
const QList<M *> ObjectListModel<M>::getItemList()
{
    return m_itemList;
}

template <class M>
void ObjectListModel<M>::notifyAppend(M *item)
{
    int pos = m_itemList.size();

    beginInsertRows(QModelIndex(), pos, pos);
    m_itemList.append(item);
    endInsertRows();

    emit listChanged();
}

template <class M>
void ObjectListModel<M>::notifyRemove(int index)
{
    if (index < 0 || index >= m_itemList.size())
        return;

    beginRemoveRows(QModelIndex(), index, index);

    M *item = m_itemList.at(index);
    m_itemList.removeAt(index);
    delete item;
    endRemoveRows();
    emit listChanged();
}

template <class M>
void ObjectListModel<M>::notifyRemove(M *item)
{
    int index = m_itemList.indexOf(item);
    if (index == -1)
        return;

    beginRemoveRows(QModelIndex(), index, index);

    m_itemList.removeAt(index);

    endRemoveRows();
    emit listChanged();
}

template <class M>
void ObjectListModel<M>::notifyRemoveLast()
{
    if (m_itemList.size() == 0)
        return;

    int lastIndex = m_itemList.size() - 1;
    beginRemoveRows(QModelIndex(), lastIndex, lastIndex);

    M *item = m_itemList.last();
    m_itemList.removeLast();
    delete item;

    endRemoveRows();
    emit listChanged();
}


template <class M>
void ObjectListModel<M>::notifyResetList(QList<M *> & itemList)
{
    for (int i = 0; (i < m_itemList.size()) && (i < itemList.size()); i++) {
        *m_itemList.at(i) = *itemList.at(i);
    }

    if (m_itemList.size() < itemList.size()) {
        // add new items
        int pos = m_itemList.size();

        beginInsertRows(QModelIndex(), pos, itemList.size() - 1);

        for (int i = pos; i < itemList.size(); i++) {
            M *newItem = new M(this);
            *newItem = *itemList.at(i);
            m_itemList.append(newItem);
        }

        endInsertRows();

    }
    else if (m_itemList.size() > itemList.size()) {
        // del outsize items

        beginRemoveRows(QModelIndex(), itemList.size(), m_itemList.size() - 1);

        while (m_itemList.size() > itemList.size()) {
            M *item = m_itemList.last();
            m_itemList.removeLast();
            delete item;
        }

        endRemoveRows();

    }

    for (int i = 0; i < itemList.size(); i++) {
        delete itemList[i];
    }

    beginResetModel();
    itemList.clear();
    endResetModel();

    emit listChanged();
}

#endif // CPP_OBJECT_LIST_MODEL_IMPL_H

