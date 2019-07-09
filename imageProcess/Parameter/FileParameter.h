#pragma once
#include "Parameter.h"
#include <string>
class FileParameter: public Parameter
{
private:
    std::string file_name;
public:
    FileParameter(std::string name);
    std::any get(int index);
    ~FileParameter();
};
