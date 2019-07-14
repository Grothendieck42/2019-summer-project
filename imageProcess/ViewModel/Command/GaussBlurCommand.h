#pragma once
#include "../../Common/Command.h"

class ViewModel;
class GaussBlurCommand : public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
public:
    GaussBlurCommand(ViewModel* viewModel);
    ~GaussBlurCommand();
    void setParameter(std::any params);
    void exec();
};
