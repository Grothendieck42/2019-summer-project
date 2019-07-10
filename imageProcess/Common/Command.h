#pragma once
#include <any>
// interface
// 各种Command需要继承这一接口
class Command
{
public:
    virtual void exec() = 0;
    virtual void setParameter(std::any params) = 0;
    virtual ~Command() = 0;
};
