#pragma once
#include <string>
#include "../../Common/Command.h"

class ViewModel;
class AddSaltNoiseCommand: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
    int n;
public:
    AddSaltNoiseCommand(ViewModel* view_model);
    ~AddSaltNoiseCommand();
    void setParameter(std::any params);
    bool exec();
};
