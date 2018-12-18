#ifndef CPP_DOMAIN_OBJECT_H
#define CPP_DOMAIN_OBJECT_H

#include <QJsonObject>

class DomainObject
{
public:
    DomainObject();

    virtual void fromJson(const QJsonObject data) = 0;
    virtual QJsonObject toJson() = 0;
};

#endif // CPP_DOMAIN_OBJECT_H
