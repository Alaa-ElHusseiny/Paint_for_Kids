#include "AddSquareAction.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSquareAction::AddSquareAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSquareAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at the center point");

	//Read center point and store in point P
	pIn->GetPointClicked(P.x, P.y);


	if (pOut->getCrntFillColor() == maps.id_to_color(DEFAULT_))
		SquareGfxInfo.isFilled = false;	// As long as the fill color is not set
	else SquareGfxInfo.isFilled = true;
	//get drawing, filling colors and pen width from the interface
	SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquareGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddSquareAction::Execute(bool skip_param)
{
	//This action needs to read some parameters first
	if(!skip_param)
		ReadActionParameters();

	//Create a Square with the parameters read from the user
	CSquare* S = new CSquare(P, SquareGfxInfo);

	//Add the square to the list of figures
	pManager->AddFigure(S);
	pManager->AddActionToRec(this);
}

