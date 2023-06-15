#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\AddHexAction.h"
#include "Actions\AddTriangAction.h"
#include "Actions\AddSquareAction.h"
#include "Actions\SwitchToPlayAction.h"
#include "Actions\SwitchToDrawAction.h"
#include "Actions\SelectOneAction.h"
#include "Actions\PlayTypeAction.h"
#include "Actions\PlayColorAction.h"
#include "Actions\PlayTypAColAction.h"
#include "Actions\ClearAll.h"
#include "Actions\StartR.h"
#include "Actions\PlayR.h"
#include "Actions\StopR.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"
#include "Actions\DeleteAction.h"
#include "Actions\ChangeDrawColorAction.h"
#include "Actions\ChangeFillColorAction.h"
#include <time.h>

#include<iostream>
using namespace std;

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;

	SelectedFig = NULL;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
	Cleardone = 1;
	whatActionToRec = 0;
	IsStartR = 0;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////

//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;

	case DRAW_SQU:
		pAct = new AddSquareAction(this);
		break;

	case DRAW_TRIN:
		pAct = new AddTriangAction(this);
		break;

	case DRAW_HEX:
		pAct = new AddHexAction(this);
		break;

	case DRAW_CIRC:
		pAct = new AddCircAction(this);
		break;

	case SEL:
		pAct = new SelectOneAction(this);
		break;

	case CLEAR:
		pAct = new ClearAll(this);
		Cleardone = 2;
		break;

	case DEL:
		pAct = new DeleteAction(this);
		break;

	case START:
		pAct = new StartR(this);
		IsStartR = 1;
		break;

	case STOP:
		pAct = new StopR(this);
		IsStartR = 0;
		break;

	case PLAY:
		pAct = new PlayR(this);
		break;

	case SAVE:
		pAct = new SaveAction(this);
		break;

	case UPLOAD:
		pAct = new LoadAction(this);
		break;

	case DCOL:
		pAct = new ChangeDrawColorAction(this);
		break;

	case FCOL:
		pAct = new ChangeFillColorAction(this);
		break;

	case TO_PLAY:
		pAct = new SwitchToPlayAction(this);
		break;

	case TO_DRAW:
		pAct = new SwitchToDrawAction(this);
		break;

	case TYPE:
		pAct = new PlayTypeAction(this);
		break;

	case FCOLOR:
		pAct = new PlayColorAction(this);
		break;

	case TAFC:
		pAct = new PlayTypAColAction(this);
		break;

	case EXIT:
		///create ExitAction here
		break;

	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
		Cleardone--;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount) {
		pFig->SetID(FigCount);
		FigList[FigCount++] = pFig;
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	// return the first shape to find
	Point p; p.x = x, p.y = y;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->IsPointInside(p))
			return FigList[i];

	return NULL;
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::SetSelectedFig(CFigure* fig) {
	if (SelectedFig != NULL) SelectedFig->SetSelected(false);
	if (SelectedFig == fig) {
		SelectedFig = NULL;
		return;
	}
	SelectedFig = fig;
	SelectedFig->SetSelected(true);
	SelectedFig->PrintInfo(pOut);
}


////////////////////////////////////////////////////////////////////////////////////
// Change draw color for the selected figure
void ApplicationManager::ChangeDrawColor(color col)
{
	if (SelectedFig == NULL) {
		pOut->PrintMessage("No figure is selected!");
		return;
	}
	SelectedFig->ChngDrawClr(col);
	pOut->setCrntDrawColor(col);
}

////////////////////////////////////////////////////////////////////////////////////
// Change fill color for the selected figure
void ApplicationManager::ChangeFillColor(color col)
{
	if (SelectedFig == NULL) {
		pOut->PrintMessage("No figure is selected!");
		return;
	}
	SelectedFig->ChngFillClr(col);
	pOut->setCrntFillColor(col);
}

////////////////////////////////////////////////////////////////////////////////////
//Saves All Figures in the current Figure list
void ApplicationManager::SaveAll(ofstream& fout)
{
	// Get the id of the color not its name
	fout << FigCount << "\n";
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(fout);

}

////////////////////////////////////////////////////////////////////////////////////
//Loads All Figures in the current Figure list
void ApplicationManager::LoadAll(ifstream& fin)
{
	ClearFigList();
	// Get the id of the color not its name
	int cnt;
	fin >> cnt;

	Action* pAct = NULL;
	for (int i = 0; i < cnt; i++) {
		int id;
		fin >> id;
		switch (id) {
		case(RECTANGLE):
			pAct = new AddRectAction(this);
			break;
		case(SQUARE):
			pAct = new AddSquareAction(this);
			break;
		case(TRIANGLE):
			pAct = new AddTriangAction(this);
			break;
		case(HEXAGON):
			pAct = new AddHexAction(this);
			break;
		case(CIRCLE):
			pAct = new AddCircAction(this);
			break;
		}

		//Execute the created action
		if (pAct != NULL)
		{
			pAct->Execute(true);//Execute
			delete pAct;	
			pAct = NULL;
		}

		FigList[FigCount - 1]->Load(fin); // Load the parameters for the newly added figure
	}
}


////////////////////////////////////////////////////////////////////////////////////
// Delete the selected figure
void ApplicationManager::DeleteSelectedFig()
{
	if (SelectedFig == NULL) {
		pOut->PrintMessage("No selected figure to delete.");
		return;
	}
	int idx;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i] == SelectedFig) {
			idx = i;
			break;
		}
	SelectedFig = NULL;
	for (int i = idx + 1; i < FigCount; i++)
		FigList[i - 1] = FigList[i];
	FigList[FigCount--] = NULL;
	pOut->PrintMessage("Figure Deleted.");
}

//==================================================================================//
//						Supporting Functions For Play Mode  						//
//==================================================================================//

CFigure* ApplicationManager::SelectRandomFig()
{
	srand(time(0));
	return FigList[rand() % FigCount];
}

int ApplicationManager::GetShapeCount(int shape)
{
	int cnt = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->GetShapeID() == shape) cnt++;
	return cnt;
}
int ApplicationManager::GetColorCount(int color)
{
	int cnt = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->GetColorID() == color) cnt++;
	return cnt;
}
int ApplicationManager::GetShapeAndColorCount(int shape, int color)
{
	int cnt = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->GetShapeID() == shape && FigList[i]->GetColorID() == color) cnt++;
	return cnt;
}

//==================================================================================//
//						Interface Management Functions      						//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();

	for (int i = 0; i < FigCount; i++) {
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}


//==================================================================================//
//						Clear All and Recording Functions							//
//==================================================================================//

void ApplicationManager::ClearFigList()
{
	for (int i = 0; i < FigCount; i++)

		delete FigList[i];
	FigCount = 0;

}

/////////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::GetCleardone()
{
	return Cleardone;
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::AddActionToRec(Action* padd)
{
	if ((pactionCount < Maxrecordedactions) && (IsStartR == 1)) //determine kind of action & only after start recording
	{
		pactions[pactionCount] = padd;

		pactionCount++;
	}

}

///////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::ExecuteR() //use the list of action address saved in recording
{
	for (int i = 0; i < pactionCount; i++)
	{
		pactions[i]->Execute(true);
	}
}
///////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::Clearpactions()
{
	for (int i = 0; i < pactionCount; i++)
	{
		if (pactions[i] != NULL)
			delete pactions[i];
	}
	pactionCount = 0;

}


////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];

	for (int i = 0; i < pactionCount; i++)
		delete pactions[i];

	delete pIn;
	delete pOut;

}