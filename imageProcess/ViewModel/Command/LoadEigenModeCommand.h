#ifndef LOADEIGENMODE_H
#define LOADEIGENMODE_H


#pragma once
#include <string>
#include "../../Common/Command.h"

class ViewModel;
class LoadEigenModel: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
public:
    LoadEigenModel(ViewModel* view_model);
    ~LoadEigenModel();
    void setParameter(std::any params);
    void exec();
};




#endif // LOADEIGENMODE_H
