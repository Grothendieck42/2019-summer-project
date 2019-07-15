#include "DetectEdgeCommand.h"
#include "../ViewModel.h"
#include <any>

DetectEdgeCommand::DetectEdgeCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

DetectEdgeCommand::~DetectEdgeCommand()
{
    // nothing
}

bool DetectEdgeCommand::exec()
{
   return viewModel->detectEdge(threshold);
}

void DetectEdgeCommand::setParameter(std::any params)
{
   threshold = *std::any_cast<int>(&params);
}
