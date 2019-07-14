#ifndef BEAUTIFYFACESCOMMAND_H
#define BEAUTIFYFACESCOMMAND_H
#pragma once
#include <string>
#include "../../Common/Command.h"

class ViewModel;
class BeautifyFaces: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
public:
    BeautifyFaces(ViewModel* view_model);
    ~BeautifyFaces();
    void setParameter(std::any params);
    void exec();
};
#endif // BEAUTIFYFACESCOMMAND_H
