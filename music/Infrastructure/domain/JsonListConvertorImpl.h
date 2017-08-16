#include "JsonListConvertor.h"
#include <QObject>
#include <cassert>
#include <QDebug>

template <class T>
JsonListConvertor<T>::JsonListConvertor()
{

}

template <class T>
QList<T *> JsonListConvertor<T>::toList(const QJsonObject *jsonList)
{
    QList<T *> resultList;

    if (jsonList == NULL || jsonList->type != QJsonObject_Array) {
        qDebug("Error: JsonListConvertor::toList(): param is NULL or not Array!");
        return resultList;
    }

    for (int i = 0; i < QJsonObject_GetArraySize((QJsonObject*)jsonList); i++) {
        T * item = new T();

        DomainObject *domainObj = dynamic_cast<DomainObject *>(item);
        assert(domainObj);
        domainObj->fromJson(QJsonObject_GetArrayItem((QJsonObject*)jsonList, i));

        resultList.append(item);
    }

    return resultList;
}

template <class T>
QList<T> JsonListConvertor<T>::toListWithValue(const QJsonObject *jsonList)
{
    QList<T> resultList;

    if (jsonList == NULL || jsonList->type != QJsonObject_Array) {
        qDebug("Error: JsonListConvertor::toListWithValue(): param is NULL or not Array!");
        return resultList;
    }

    for (int i = 0; i < QJsonObject_GetArraySize((QJsonObject*)jsonList); i++) {
        T item;

        DomainObject& domainObj = dynamic_cast<DomainObject&>(item);
//        assert(domainObj);
        domainObj.fromJson(QJsonObject_GetArrayItem((QJsonObject*)jsonList, i));

        resultList.append(item);
    }

    return resultList;
}

template <class T>
QList<QObject *> JsonListConvertor<T>::toObjectList(const QJsonObject *jsonList)
{
    QList<T *> list = this->toList(jsonList);
    QList<QObject *> resultList;

    for (int i = 0; i < list.size(); i++) {
        resultList.append( qobject_cast<QObject *>(list.at(i)) );
    }

    return resultList;
}

template <class T>
QJsonObject * JsonListConvertor<T>::toJson(QList<T *> list)
{
    QJsonObject *jsonList = QJsonObject_CreateArray();

    for (int i = 0; i < list.size(); i++) {
        DomainObject *domainObj = dynamic_cast<DomainObject *>(list.at(i));
        if (domainObj)
            QJsonObject_AddItemToArray(jsonList, domainObj->toJson());
    }

    return jsonList;
}

template <class T>
QJsonObject* JsonListConvertor<T>::toJsonWithValue(QList<T> list)
{
    QJsonObject *jsonList = QJsonObject_CreateArray();

    for (int i = 0; i < list.size(); i++) {
        DomainObject& domainObj = dynamic_cast<DomainObject&>((DomainObject&)list.at(i));
//        if (domainObj)
        QJsonObject_AddItemToArray(jsonList, domainObj.toJson());
    }

    return jsonList;
}
