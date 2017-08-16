#ifndef CPP_JSON_LIST_CONVERTOR_H
#define CPP_JSON_LIST_CONVERTOR_H

#include <QJsonObject>
#include <QList>
#include "DomainObject.h"

/* WARNING: T MUST be subclass of DomainObject */
template <class T>
class JsonListConvertor
{
public:
    JsonListConvertor();

    QList<T *> toList(const QJsonObject *jsonList);
    QList<T> toListWithValue(const QJsonObject *jsonList);
    QList<QObject *> toObjectList(const QJsonObject *jsonList);

    QJsonObject * toJson(QList<T *> list);
    QJsonObject * toJsonWithValue(QList<T> list);
};

#include "JsonListConvertorImpl.h"

#endif // CPP_JSON_LIST_CONVERTOR_H
