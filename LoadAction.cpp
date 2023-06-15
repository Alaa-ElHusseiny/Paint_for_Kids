#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<fstream>

LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{}
void LoadAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Loading the graph, enter the file name");
	graph = pIn->GetSrting(pOut);


	pOut->ClearStatusBar();

}
void LoadAction::Execute(bool skip_param)
{

	ReadActionParameters();

	ifstream fin(graph);
	
	Output* pOut = pManager->GetOutput();
	int id;
	fin >> id;
	pOut->setCrntDrawColor(maps.id_to_color(id));
	fin >> id;
	pOut->setCrntFillColor(maps.id_to_color(id));

	pManager->LoadAll(fin);
	fin.close();
}