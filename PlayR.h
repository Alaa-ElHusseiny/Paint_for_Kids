#ifndef PLAY_R_ACTION_H
#define PLAY_R_ACTION_H
#include "Action.h"

class PlayR : public Action
{
public:
	PlayR(ApplicationManager* pApp);

	//Reads Play recording parameters
	virtual void ReadActionParameters();

	//play recording when called by the ApplicationManager
	virtual void Execute(bool skip_param = false);

};

#endif