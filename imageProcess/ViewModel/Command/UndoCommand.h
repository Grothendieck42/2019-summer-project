#pragma once
#include "../../Common/Command.h"

class ViewModel;
class UndoCommand : public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
public:
    UndoCommand(ViewModel* viewModel);
    ~UndoCommand();
    void setParameter(std::any params);
    bool exec();
};
