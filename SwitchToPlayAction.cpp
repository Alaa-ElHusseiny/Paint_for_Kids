#include "SwitchToPlayAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SwitchToPlayAction::SwitchToPlayAction(ApplicationManager* pApp) :Action(pApp)
{}

void SwitchToPlayAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Switching to Play Mode!");
}

//Execute the action
void SwitchToPlayAction::Execute(bool skip_param)
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Draw play toolbar
	Output* pOut = pManager->GetOutput();
	pOut->CreatePlayToolBar();
	pOut->ClearStatusBar();
}

