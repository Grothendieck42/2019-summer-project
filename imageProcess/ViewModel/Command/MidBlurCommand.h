#pragma once
#include "../../Common/Command.h"

class ViewModel;
class MidBlurCommand: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
public:
    MidBlurCommand(ViewModel* view_model);
    ~MidBlurCommand();
    void setParameter(std::any params);
    bool exec();
};
