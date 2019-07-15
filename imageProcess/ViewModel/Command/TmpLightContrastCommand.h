#pragma once
#include "../../Common/Command.h"

class ViewModel;
class TmpLightContrastCommand: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
    int light;
    int contrast;
public:
    TmpLightContrastCommand(ViewModel* view_model);
    ~TmpLightContrastCommand();
    void setParameter(std::any params);
    bool exec();
};

