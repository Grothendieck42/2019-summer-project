#pragma once
#include "../../Common/Command.h"

class ViewModel;
class GammaCorrectCommand: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
    float fGamma;
public:
    GammaCorrectCommand(ViewModel* view_model);
    ~GammaCorrectCommand();
    void setParameter(std::any params);
    bool exec();
};
