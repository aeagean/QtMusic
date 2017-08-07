#include "BaseItemModel.h"

BaseItemModel::BaseItemModel(QObject *parent) : QObject(parent)
{

}

void BaseItemModel::submit()
{
    emit submited(this);
}

void BaseItemModel::revert()
{
    // do nothing by default
}

