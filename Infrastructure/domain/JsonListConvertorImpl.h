/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/
#include "JsonListConvertor.h"
#include <QObject>
#include <cassert>
#include <QJsonArray>
#include <QDebug>

template <class T>
JsonListConvertor<T>::JsonListConvertor()
{

}

template <class T>
QList<T *> JsonListConvertor<T>::toList(const QJsonValue jsonList)
{
    QList<T *> resultList;

    if (jsonList.isArray() == false) {
        qDebug("Error: JsonListConvertor::toList(): param is not Array!");
        return resultList;
    }

    for (int i = 0; i < jsonList.toArray().count(); i++) {
        T * item = new T();

        DomainObject *domainObj = dynamic_cast<DomainObject *>(item);
        assert(domainObj);
        domainObj->fromJson(jsonList.toArray().at(i).toObject());

        resultList.append(item);
    }

    return resultList;
}

template <class T>
QList<T> JsonListConvertor<T>::toListWithValue(const QJsonValue jsonList)
{
    QList<T> resultList;

    if (jsonList.isArray() == false) {
        qDebug("Error: JsonListConvertor::toListWithValue(): param is NULL or not Array!");
        return resultList;
    }

    for (int i = 0; i < jsonList.toArray().count(); i++) {
        T item;

        DomainObject& domainObj = dynamic_cast<DomainObject&>(item);
        domainObj.fromJson(jsonList.toArray().at(i).toObject());

        resultList.append(item);
    }

    return resultList;
}

template <class T>
QList<QObject *> JsonListConvertor<T>::toObjectList(const QJsonValue jsonList)
{
    QList<T *> list = this->toList(jsonList);
    QList<QObject *> resultList;

    for (int i = 0; i < list.size(); i++) {
        resultList.append( qobject_cast<QObject *>(list.at(i)) );
    }

    return resultList;
}

template <class T>
QJsonValue JsonListConvertor<T>::toJson(QList<T *> list)
{
    QJsonArray jsonList;
    for (int i = 0; i < list.size(); i++) {
        DomainObject *domainObj = dynamic_cast<DomainObject *>(list.at(i));
        if (domainObj)
            jsonList.append(domainObj->toJson());
    }

    return QJsonValue(jsonList);
}

template <class T>
QJsonValue JsonListConvertor<T>::toJsonWithValue(QList<T> list)
{
    QJsonArray jsonList;

    for (int i = 0; i < list.size(); i++) {
        DomainObject& domainObj = dynamic_cast<DomainObject&>((DomainObject&)list.at(i));
        jsonList.append(domainObj.toJson());
    }

    return QJsonValue(jsonList);
}
