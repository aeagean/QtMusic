/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/
#ifndef CPP_DOMAIN_OBJECT_H
#define CPP_DOMAIN_OBJECT_H

#include <QJsonObject>

class DomainObject
{
public:
    DomainObject();

    virtual void fromJson(const QJsonObject& data) = 0;
    virtual QJsonObject toJson() = 0;
    virtual ~DomainObject() {}
};

#endif // CPP_DOMAIN_OBJECT_H
