#ifndef START_R_ACTION_H
#define START_R_ACTION_H
#include "Action.h"

class StartR : public Action
{
	 
public:
	StartR(ApplicationManager* pApp);

	//Reads Start recording parameters
	virtual void ReadActionParameters();

	//Start recording when called by the ApplicationManager
	virtual void Execute(bool skip_param = false);
	 
};

#endif
