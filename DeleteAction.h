#ifndef DELETE_ACTION_H
#define DELETE_ACTION_H

#include "Action.h"

//Add Circle Action class
class DeleteAction : public Action
{
private:
	Point P; //Circle center
	GfxInfo SelGfxInfo;
public:
	DeleteAction(ApplicationManager* pApp);

	//Reads select parameters
	virtual void ReadActionParameters();

	//Set selected figure in the ApplicationManager
	virtual void Execute(bool skip_param = false);

};

#endif