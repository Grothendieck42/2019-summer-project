#pragma once
#include "../../Common/Command.h"

class ViewModel;
class ImageGuidedCommand: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
    float eps;
public:
    ImageGuidedCommand(ViewModel* view_model);
    ~ImageGuidedCommand();
    void setParameter(std::any params);
    bool exec();
};
