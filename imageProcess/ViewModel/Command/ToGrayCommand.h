#pragma once
#include <string>
#include "../../Common/Command.h"

class ViewModel;
class ToGrayCommand: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
public:
    ToGrayCommand(ViewModel* view_model);
    ~ToGrayCommand();
    void setParameter(std::any params);
    bool exec();
};
