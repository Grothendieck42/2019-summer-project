#pragma once
#include <string>
#include "../../Common/Command.h"

class ViewModel;
class ImageReductCommand: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
public:
    ImageReductCommand(ViewModel* view_model);
    ~ImageReductCommand();
    void setParameter(std::any params);
    void exec();
};
