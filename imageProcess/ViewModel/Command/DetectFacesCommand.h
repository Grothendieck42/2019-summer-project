#ifndef DETECTFACES_H
#define DETECTFACES_H

#pragma once
#include <string>
#include "../../Common/Command.h"

class ViewModel;
class DetectFacesCommand: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
public:
    DetectFacesCommand(ViewModel* view_model);
    ~DetectFacesCommand();
    void setParameter(std::any params);
    void exec();
};

#endif // DETECTFACES_H
