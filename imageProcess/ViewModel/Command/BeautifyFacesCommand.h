#ifndef BEAUTIFYFACESCOMMAND_H
#define BEAUTIFYFACESCOMMAND_H
#pragma once
#include <string>
#include "../../Common/Command.h"

class ViewModel;
class BeautifyFacesCommand: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
public:
    BeautifyFacesCommand(ViewModel* view_model);
    ~BeautifyFacesCommand();
    void setParameter(std::any params);
    void exec();
};
#endif // BEAUTIFYFACESCOMMAND_H
