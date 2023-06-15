#ifndef SWITCH_TO_PLAY_ACTION_H
#define SWITCH_TO_PLAY_ACTION_H

#include "Action.h"

//Add Switch To Play Action class
class SwitchToPlayAction : public Action
{
public:
	SwitchToPlayAction(ApplicationManager* pApp);

	//Implement the pure virtual function, but no parameters needed
	virtual void ReadActionParameters();

	//Output the Play Mode Task Bar
	virtual void Execute(bool skip_param = false);

};

#endif