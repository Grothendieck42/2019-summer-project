#ifndef TRAINEIGENMODEL_H
#define TRAINEIGENMODEL_H

#pragma once
#include <string>
#include "../../Common/Command.h"

class ViewModel;
class TrainEigenModel: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
public:
    TrainEigenModel(ViewModel* view_model);
    ~TrainEigenModel();
    void setParameter(std::any params);
    void exec();
};

#endif // TRAINEIGENMODEL_H
