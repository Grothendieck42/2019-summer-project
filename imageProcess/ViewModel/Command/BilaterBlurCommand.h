#pragma once
#include "../../Common/Command.h"

class ViewModel;
class BilaterBlurCommand : public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
public:
    BilaterBlurCommand(ViewModel* viewModel);
    ~BilaterBlurCommand();
    void setParameter(std::any params);
    void exec();
};
