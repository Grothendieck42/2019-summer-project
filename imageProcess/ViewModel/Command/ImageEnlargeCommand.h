#pragma once
#include <string>
#include "../../Common/Command.h"

class ViewModel;
class ImageEnlargeCommand: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
public:
    ImageEnlargeCommand(ViewModel* view_model);
    ~ImageEnlargeCommand();
    void setParameter(std::any params);
    void exec();
};
