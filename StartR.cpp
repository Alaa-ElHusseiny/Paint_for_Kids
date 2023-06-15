#include "StartR.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#define MaxOperations 20

StartR::StartR(ApplicationManager* pApp) :Action(pApp)
{
 
}

void StartR::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();

	if (pManager->GetCleardone() == 1)
	{
		pOut->PrintMessage("Recording has started ");
	}
	else
		pOut->PrintMessage("Error! Clear all or restart the program to record ");

}
void StartR::Execute(bool skip_param)
{
	ReadActionParameters();
	pManager->Clearpactions();

}
 