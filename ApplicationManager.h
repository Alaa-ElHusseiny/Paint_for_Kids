#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions\Action.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures
	enum { Maxrecordedactions = 20 };	//Max no of actions that can be reccoreded

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	// Clear all and Recording Attributes
	int Cleardone;
	int IsStartR; // to mark that start recording has been executed(0/1)

	int whatActionToRec; //to defined the actions that need to be recorded 
	Action* pactions[Maxrecordedactions];
	int pactionCount;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void SetSelectedFig(CFigure* fig);		// Set the selected Figure
	void ChangeDrawColor(color col);		// Change draw color for the selected figure
	void ChangeFillColor(color col);		// Change fill color for the selected figure
	void SaveAll(ofstream& fout);
	void LoadAll(ifstream& fin);
	void DeleteSelectedFig();

	// -- Supporting Functions For Play Mode
	CFigure* SelectRandomFig();	// Returns a random figure
	int GetShapeCount(int shape);	// Get the count for a specific shape
	int GetColorCount(int color);	// Get the count for a specific color
	int GetShapeAndColorCount(int shape, int color); // Get the count for a specific shape and color

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window and set the selected figure

	// -- Clear All and Recording Functions
	void ClearFigList(); // clear Figure list not to be drown after clear all
	int GetCleardone();
	void AddActionToRec(Action* padd);
	void ExecuteR(); //use the list of action address saved in recording
	void Clearpactions();
};

#endif