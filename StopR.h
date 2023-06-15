#ifndef STOP_R_ACTION_H
#define STOP_R_ACTION_H
#include "Action.h"

class StopR : public Action
{
public:
	StopR(ApplicationManager* pApp);

	//Reads stop recording parameters
	virtual void ReadActionParameters();

	//stop recording when called by the ApplicationManager
	virtual void Execute(bool skip_param = false);
};

#endif