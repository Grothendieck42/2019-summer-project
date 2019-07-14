#pragma once
#include <string>
#include "../../Common/Command.h"

class ViewModel;
class LaplaceCommand: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
public:
    LaplaceCommand(ViewModel* view_model);
    ~LaplaceCommand();
    void setParameter(std::any params);
    void exec();
};
