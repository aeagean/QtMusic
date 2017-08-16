#ifndef CPP_DOMAIN_OBJECT_H
#define CPP_DOMAIN_OBJECT_H

#include <QJsonValue>

class DomainObject
{
public:
    DomainObject();

    virtual void fromJson(const QJsonValue *data) = 0;
    virtual QJsonValue * toJson() = 0;
};

#endif // CPP_DOMAIN_OBJECT_H
