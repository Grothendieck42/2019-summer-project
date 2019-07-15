#pragma once
#include <string>
#include "../../Common/Command.h"

class ViewModel;
class OpenFileCommand: public Command 
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
    std::string file_name;
public:
    OpenFileCommand(ViewModel* view_model);
	~OpenFileCommand();
    void setParameter(std::any params);
    bool exec();
};
