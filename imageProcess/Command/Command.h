#pragma once
#include <iostream>
#include "../Parameter/Parameter.h"
// interface
// 各种Command需要继承这一接口
class Command
{
public:
    virtual void exec() = 0;
    virtual void setParameter(const std::shared_ptr<Parameter> &param) = 0;
    virtual ~Command() = 0;
};
