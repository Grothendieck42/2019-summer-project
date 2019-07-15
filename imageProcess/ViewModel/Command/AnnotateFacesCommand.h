#pragma once
#include "../../Common/Command.h"
#include <string>

class ViewModel;
class AnnotateFacesCommand: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
    std::string modelPath;
public:
    AnnotateFacesCommand(ViewModel* view_model);
    ~AnnotateFacesCommand();
    void setParameter(std::any params);
    bool exec();
};
