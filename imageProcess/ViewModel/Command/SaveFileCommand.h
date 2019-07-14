#pragma once
#include <string>
#include "../../Common/Command.h"

class ViewModel;
class SaveFileCommand: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
    std::string file_name;
public:
    SaveFileCommand(ViewModel* view_model);
    ~SaveFileCommand();
    void setParameter(std::any params);
    bool exec();
};
