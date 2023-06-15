#include "PlayColorAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

PlayColorAction::PlayColorAction(ApplicationManager* pApp) :Action(pApp)
{}

void PlayColorAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//pOut->PrintMessage("Choose a figure!");
	pIn->GetPointClicked(P.x, P.y);

}

//Execute the action
void PlayColorAction::Execute(bool skip_param)
{
	
	Output* pOut = pManager->GetOutput();
	// Choose color randomly
	int chosen_color = pManager->SelectRandomFig()->GetColorID();
	switch (chosen_color) {
	case BLACK_:
		pOut->PrintMessage("Pick All The Black figures. Gooo!");
		break;

	case YELLOW_:
		pOut->PrintMessage("Pick All The Yellow figures. Gooo!");
		break;

	case ORANGE_:
		pOut->PrintMessage("Pick All The Orange figures. Gooo!");
		break;

	case RED_:
		pOut->PrintMessage("Pick All The Red figures. Gooo!");
		break;

	case GREEN_:
		pOut->PrintMessage("Pick All The Green figures. Gooo!");
		break;

	case BLUE_:
		pOut->PrintMessage("Pick All The Blue figures. Gooo!");
		break;
	}
	//pOut->ClearStatusBar();

	// Start the game until it ends
	int points_to_win = pManager->GetColorCount(chosen_color);
	int correct = 0, incorrect = 0;
	while (correct != points_to_win) {
		ReadActionParameters();
		auto fig = pManager->GetFigure(P.x, P.y);
		if (fig != NULL) {
			if (fig->GetColorID() == chosen_color) correct++;
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
