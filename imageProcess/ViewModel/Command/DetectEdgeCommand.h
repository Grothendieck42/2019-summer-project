#pragma once
#include <string>
#include "../../Common/Command.h"

class ViewModel;
class DetectEdgeCommand: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
    int threshold;
public:
    DetectEdgeCommand(ViewModel* view_model);
    ~DetectEdgeCommand();
    void setParameter(std::any params);
    bool exec();
};
