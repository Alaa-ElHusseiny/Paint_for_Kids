#include "DeleteAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteAction::DeleteAction(ApplicationManager* pApp) :Action(pApp)
{}

void DeleteAction::ReadActionParameters()
{
}

//Execute the action
void DeleteAction::Execute(bool skip_param)
{
	pManager->DeleteSelectedFig();
}

