#include "SaveAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<fstream>

SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp)
{}
void SaveAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Saving the graph, enter the file name");
	graph = pIn->GetSrting(pOut);


	pOut->ClearStatusBar();

}
void SaveAction::Execute(bool skip_param)
{

	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	ofstream fout(graph);
	fout << maps.color_to_id(pOut->getCrntDrawColor()) << " " << maps.color_to_id(pOut->getCrntFillColor()) << "\n";
	pManager->SaveAll(fout);

	fout.close();
}