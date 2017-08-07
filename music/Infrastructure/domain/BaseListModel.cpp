#include "BaseListModel.h"

BaseListModel::BaseListModel(QObject* parent) : QAbstractListModel(parent)
{

}

QHash<int, QByteArray> BaseListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ModelDataRole] = "modelData";
    return roles;
}

