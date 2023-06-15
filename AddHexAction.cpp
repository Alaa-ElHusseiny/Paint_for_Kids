#include "AddHexAction.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexAction::AddHexAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at the center point");

	//Read center point and store in point P
	pIn->GetPointClicked(P.x, P.y);

	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();
	if (pOut->getCrntFillColor() == maps.id_to_color(DEFAULT_))
		HexGfxInfo.isFilled = false;	// As long as the fill color is not set
	else HexGfxInfo.isFilled = true;

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexAction::Execute(bool skip_param)
{
	//This action needs to read some parameters first
	if(!skip_param)
		ReadActionParameters();

	//Create a hexagon with the parameters read from the user
	CHexagon* H = new CHexagon(P, HexGfxInfo);

	//Add the hexagon to the list of figures
	pManager->AddFigure(H);
	pManager->AddActionToRec(this);
}

