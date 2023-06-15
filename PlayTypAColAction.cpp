#include "PlayTypAColAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

PlayTypAColAction::PlayTypAColAction(ApplicationManager* pApp) :Action(pApp)
{}

void PlayTypAColAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//pOut->PrintMessage("Choose a figure!");
	pIn->GetPointClicked(P.x, P.y);

}

//Execute the action
void PlayTypAColAction::Execute(bool skip_param)
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	int chosen_shape = pManager->SelectRandomFig()->GetShapeID();
	int chosen_color = pManager->SelectRandomFig()->GetColorID();

	// Choose Color randomly
	string colormsg;
	switch (chosen_color) {
	case BLACK_:
		colormsg = "Pick All The Black ";
		break;

	case YELLOW_:
		colormsg = "Pick All The Yellow ";
		break;

	case ORANGE_:
		colormsg = "Pick All The Orange ";
		break;

	case RED_:
		colormsg = "Pick All The Red ";
		break;

	case GREEN_:
		colormsg = "Pick All The Green ";
		break;

	case BLUE_:
		colormsg = "Pick All The Blue ";
		break;
	}
	// Choose Shape randomly
	string shapemsg;
	switch (chosen_shape) {
	case RECTANGLE:
		shapemsg ="Rectangles";
		break;

	case SQUARE:
		shapemsg = "Squares";
		break;

	case TRIANGLE:
		shapemsg = "Triangles";
		break;

	case HEXAGON:
		shapemsg = "Hexagons";
		break;

	case CIRCLE:
		shapemsg = "Circles";
		break;
	}
	string msg = colormsg + shapemsg;
	pOut->PrintMessage(msg);

	// Start the game until it ends
	int points_to_win = pManager->GetShapeAndColorCount(chosen_shape, chosen_color);
	int correct = 0, incorrect = 0;
	while (correct != points_to_win) {
		ReadActionParameters();
		auto fig = pManager->GetFigure(P.x, P.y);
		if (fig != NULL) {
			if (fig->GetShapeID() == chosen_shape && fig->GetColorID() == chosen_color) correct++;
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