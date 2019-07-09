#include "FileParameter.h"

FileParameter::FileParameter(std::string name) : file_name(name)
{

}

std::any FileParameter::get(int index)
{
    if(index == 0)
    {
        return std::any(file_name);
    }
    else
    {
        return std::any(nullptr);
    }
}

FileParameter::~FileParameter()
{

}
