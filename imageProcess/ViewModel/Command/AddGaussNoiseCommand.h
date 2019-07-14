#pragma once
#include <string>
#include "../../Common/Command.h"

class ViewModel;
class AddGaussNoiseCommand: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
public:
    AddGaussNoiseCommand(ViewModel* view_model);
    ~AddGaussNoiseCommand();
    void setParameter(std::any params);
    bool exec();
};
