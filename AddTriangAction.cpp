#include "AddTriangAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriangAction::AddTriangAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddTriangAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at the first point");

	//Read first point and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at the second point");

	//Read second point and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	pOut->PrintMessage("New Triangle: Click at the third point");

	//Read third point and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);

	if (pOut->getCrntFillColor() == maps.id_to_color(DEFAULT_))
		TriangGfxInfo.isFilled = false;	// As long as the fill color is not set
	else TriangGfxInfo.isFilled = true;
	//get drawing, filling colors and pen width from the interface
	TriangGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriangGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriangAction::Execute(bool skip_param)
{
	//This action needs to read some parameters first
	if(!skip_param)
		ReadActionParameters();

	//Create a Triangle with the parameters read from the user
	CTriangle* T = new CTriangle(P1, P2, P3, TriangGfxInfo);

	//Add the triangle to the list of figures
	pManager->AddFigure(T);
	pManager->AddActionToRec(this);
}

