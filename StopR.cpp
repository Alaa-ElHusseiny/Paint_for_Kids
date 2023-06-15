#include "StopR.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

StopR::StopR(ApplicationManager* papp):Action(papp){}

void StopR::ReadActionParameters() {
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();
	

	pOut->PrintMessage("Recording has stopped ");

}
void StopR::Execute(bool skip_param)
{
	ReadActionParameters();

}