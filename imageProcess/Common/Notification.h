#pragma once
#include <any>
class Notification
{
public:
	virtual void notify() = 0;
    virtual void setParameter(std::any params) = 0;
	virtual ~Notification() = 0;
};
