#include "ClearAll.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ClearAll::ClearAll(ApplicationManager* pApp) :Action(pApp)
{}



 void ClearAll::ReadActionParameters()
{ }


 void ClearAll::Execute(bool skip_param)
 {
	 

	 //Get a Pointer to the Output Interfaces
	 Output* pOut = pManager->GetOutput();

	 //pManager->Clearpactions();  //clear action list of recording
	 pManager->ApplicationManager::ClearFigList(); //clear Fig list by Application manager
	 pOut->ClearDrawArea();
	 pOut->ClearStatusBar();
	 pManager->AddActionToRec(this);
}