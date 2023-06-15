#include "SwitchToDrawAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SwitchToDrawAction::SwitchToDrawAction(ApplicationManager* pApp) :Action(pApp)
{}

void SwitchToDrawAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Switching to Draw Mode!");
}

//Execute the action
void SwitchToDrawAction::Execute(bool skip_param)
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Draw Draw toolbar
	Output* pOut = pManager->GetOutput();
	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();
}

