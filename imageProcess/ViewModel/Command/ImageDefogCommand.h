#pragma once
#include "../../Common/Command.h"

class ViewModel;
class ImageDefogCommand: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
public:
    ImageDefogCommand(ViewModel* view_model);
    ~ImageDefogCommand();
    void setParameter(std::any params);
    bool exec();
};
