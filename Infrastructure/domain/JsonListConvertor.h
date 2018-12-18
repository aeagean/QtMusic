#ifndef CPP_JSON_LIST_CONVERTOR_H
#define CPP_JSON_LIST_CONVERTOR_H

#include <QJsonValue>
#include <QList>
#include "DomainObject.h"

/* WARNING: T MUST be subclass of DomainObject */
template <class T>
class JsonListConvertor
{
public:
    JsonListConvertor();

    QList<T *> toList(const QJsonValue jsonList);
    QList<T> toListWithValue(const QJsonValue jsonList);
    QList<QObject *> toObjectList(const QJsonValue jsonList);

    QJsonValue toJson(QList<T *> list);
    QJsonValue toJsonWithValue(QList<T> list);
};

#include "JsonListConvertorImpl.h"

#endif // CPP_JSON_LIST_CONVERTOR_H
