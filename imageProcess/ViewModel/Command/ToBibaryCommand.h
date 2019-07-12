#pragma once
#include <string>
#include "../../Common/Command.h"

class ViewModel;
class ToBinaryCommand: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
    int threshold;
public:
    ToBinaryCommand(ViewModel* view_model);
    ~ToBinaryCommand();
    void setParameter(std::any params);
    void exec();
};
