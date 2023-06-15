#include "PlayR.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


PlayR::PlayR(ApplicationManager* papp) :Action(papp) {}

void PlayR::ReadActionParameters() {
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();


	pOut->PrintMessage("Last recording is shown ");

}
void PlayR::Execute(bool skip_param)
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();

	ReadActionParameters();
	pManager->ExecuteR();

}