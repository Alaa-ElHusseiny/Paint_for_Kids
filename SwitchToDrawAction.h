#ifndef SWITCH_TO_DRAW_ACTION_H
#define SWITCH_TO_DRAW_ACTION_H

#include "Action.h"

//Add Switch To Draw Action class
class SwitchToDrawAction : public Action
{
public:
	SwitchToDrawAction(ApplicationManager* pApp);

	//Implement the pure virtual function, but no parameters needed
	virtual void ReadActionParameters();

	//Output the Play Mode Task Bar
	virtual void Execute(bool skip_param = false);

};

#endif
