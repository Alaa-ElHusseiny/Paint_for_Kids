#ifndef SELECT_ONE_ACTION_H
#define SELECT_ONE_ACTION_H

#include "Action.h"

//Add Circle Action class
class SelectOneAction : public Action
{
private:
	Point P; //Circle center
	GfxInfo SelGfxInfo;
public:
	SelectOneAction(ApplicationManager* pApp);

	//Reads select parameters
	virtual void ReadActionParameters();

	//Set selected figure in the ApplicationManager
	virtual void Execute(bool skip_param = false);

};

#endif