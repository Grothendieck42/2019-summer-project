#include "DetectEdgeCommand.h"
#include "../ViewModel.h"
#include <any>
#include <string>
#include <QDebug>

DetectEdgeCommand::DetectEdgeCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

DetectEdgeCommand::~DetectEdgeCommand()
{
    // nothing
}

void DetectEdgeCommand::exec()
{
    viewModel->detectEdge(threshold);
}

void DetectEdgeCommand::setParameter(std::any params)
{
   threshold = *std::any_cast<int>(&params);
}
