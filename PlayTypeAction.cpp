#include "PlayTypeAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

PlayTypeAction::PlayTypeAction(ApplicationManager* pApp) :Action(pApp)
{}

void PlayTypeAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//pOut->PrintMessage("Choose a figure!");
	pIn->GetPointClicked(P.x, P.y);

}

//Execute the action
void PlayTypeAction::Execute(bool skip_param)
{
	Output* pOut = pManager->GetOutput();
	// Choose shape randomly
	int chosen_shape = pManager->SelectRandomFig()->GetShapeID();
	switch (chosen_shape) {
	case RECTANGLE:
		pOut->PrintMessage("Pick All The Rectangles. Gooo!");
		break;

	case SQUARE:
		pOut->PrintMessage("Pick All The Squares. Gooo!");
		break;

	case TRIANGLE:
		pOut->PrintMessage("Pick All The Triangles. Gooo!");
		break;

	case HEXAGON:
		pOut->PrintMessage("Pick All The Hexagons. Gooo!");
		break;

	case CIRCLE:
		pOut->PrintMessage("Pick All The Circles. Gooo!");
		break;
	}
	
	
	// Start the game until it ends
	int points_to_win = pManager->GetShapeCount(chosen_shape);
	int correct = 0, incorrect = 0;
	while (correct != points_to_win) {
		ReadActionParameters();
		auto fig = pManager->GetFigure(P.x, P.y);
		if (fig != NULL) {
			if (fig->GetShapeID() == chosen_shape) correct++;
			else incorrect++;
			fig->Remove(pOut);
			string str = "Correct = " + to_string(correct) + " , Incorrect = " + to_string(incorrect);
			pOut->PrintMessage(str);
		}
	}
	string str = "Game Over! Final Score: Correct = " + to_string(correct) + " , Incorrect = " + to_string(incorrect);
	pOut->PrintMessage(str);
	Sleep(1800);
	pOut->ClearStatusBar();
}

