#include "ChangeFillColorAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeFillColorAction::ChangeFillColorAction(ApplicationManager* pApp) :Action(pApp)
{}

void ChangeFillColorAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Choose the color");

	auto act = pManager->GetUserAction();

	switch (act)
	{
	case CBLACK:
		chosen_color = BLACK;
		break;
	case CYELLOW:
		chosen_color = YELLOW;
		break;
	case CORANGE:
		chosen_color = ORANGE;
		break;
	case CRED:
		chosen_color = RED;
		break;
	case CGREEN:
		chosen_color = GREEN;
		break;
	case CBLUE:
		chosen_color = BLUE;
		break;
	default:
		chosen_color = maps.id_to_color(DEFAULT_);
		break;
	}
	
	pOut->ClearStatusBar();
}

//Execute the action
void ChangeFillColorAction::Execute(bool skip_param)
{
	//This action needs to read some parameters first
	if (!skip_param)
		ReadActionParameters();

	if (chosen_color != maps.color_to_id(DEFAULT_))
		pManager->ChangeFillColor(chosen_color);
}

