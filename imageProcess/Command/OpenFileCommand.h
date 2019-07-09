#pragma once
#include "Command.h"
#include "../Parameter/FileParameter.h"

class ViewModel;
class OpenFileCommand: public Command 
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    std::shared_ptr<ViewModel> viewModel;
    std::shared_ptr<Parameter> parameter;
public:
    OpenFileCommand(std::shared_ptr<ViewModel> view_model);
	~OpenFileCommand();
    void setParameter(const std::shared_ptr<Parameter> &param);
	void exec();
};
