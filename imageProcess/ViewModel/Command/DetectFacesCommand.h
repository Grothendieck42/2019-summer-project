#pragma once
#include "../../Common/Command.h"
#include <string>
class ViewModel;
class DetectFacesCommand: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
    std::string classifierPath;
public:
    DetectFacesCommand(ViewModel* view_model);
    ~DetectFacesCommand();
    void setParameter(std::any params);
    bool exec();
};

