#ifndef GENERATEHEADSHOTSCOMMAND_H
#define GENERATEHEADSHOTSCOMMAND_H

#pragma once
#include <string>
#include "../../Common/Command.h"

class ViewModel;
class GenerateHeadshotsCommand: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
public:
    GenerateHeadshotsCommand(ViewModel* view_model);
    ~GenerateHeadshotsCommand();
    void setParameter(std::any params);
    void exec();
};

#endif // GENERATEHEADSHOTSCOMMAND_H
