#include "SelectOneAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectOneAction::SelectOneAction(ApplicationManager* pApp) :Action(pApp)
{}

void SelectOneAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click on the Figure to be selected");

	//Read center point and store in point P
	pIn->GetPointClicked(P.x, P.y);

	pOut->ClearStatusBar();
}

//Execute the action
void SelectOneAction::Execute(bool skip_param)
{
	//This action needs to read some parameters first
	if(!skip_param)
		ReadActionParameters();

	//Detect which figure to select
	auto fig = pManager->GetFigure(P.x, P.y);
	if (fig != NULL) {
		pManager->SetSelectedFig(fig);
	}
	pManager->AddActionToRec(this);
}

