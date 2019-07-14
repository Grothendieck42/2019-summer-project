#ifndef ANNOTATEFACESCOMMAND_H
#define ANNOTATEFACESCOMMAND_H

#pragma once
#include <string>
#include "../../Common/Command.h"

class ViewModel;
class AnnotateFacesCommand: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
public:
    AnnotateFacesCommand(ViewModel* view_model);
    ~AnnotateFacesCommand();
    void setParameter(std::any params);
    void exec();
};
#endif // ANNOTATEFACESCOMMAND_H
