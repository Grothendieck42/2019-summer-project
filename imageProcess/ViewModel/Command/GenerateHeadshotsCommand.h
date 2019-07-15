#pragma once
#include "../../Common/Command.h"
#include <string>
class ViewModel;
class GenerateHeadshotsCommand: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
    std::string outputdir;
public:
    GenerateHeadshotsCommand(ViewModel* view_model);
    ~GenerateHeadshotsCommand();
    void setParameter(std::any params);
    bool exec();
};

