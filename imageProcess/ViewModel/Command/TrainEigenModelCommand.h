#pragma once
#include <string>
#include "../../Common/Command.h"

class ViewModel;
class TrainEigenModelCommand: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
    std::string dataPath;
public:
    TrainEigenModelCommand(ViewModel* view_model);
    ~TrainEigenModelCommand();
    void setParameter(std::any params);
    bool exec();
};
