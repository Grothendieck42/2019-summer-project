#pragma once
#include "../../Common/Command.h"

class ViewModel;
class LightContrastCommand: public Command 
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
    int old_light;
    int old_contrast;
    int light;
    int contrast;
public:
    LightContrastCommand(ViewModel* view_model);
	~LightContrastCommand();
    void setParameter(std::any params);
    void exec();
};
