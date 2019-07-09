#pragma once
#include <any>
class Parameter
{
public:
    // 根据参数的位置寻找
    virtual std::any get(int index) = 0;
    virtual ~Parameter() = 0;
};
