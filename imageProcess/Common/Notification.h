#pragma once
#include <any>
class Notification
{
public:
	virtual void notify() = 0;
	virtual ~Notification() = 0;
};
