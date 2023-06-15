#ifndef CHANGE_DRAW_COLOR_ACTION_H
#define CHANGE_DRAW_COLOR_ACTION_H

#include "Action.h"

class ChangeDrawColorAction : public Action
{
private:
	color chosen_color;

public:
	ChangeDrawColorAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute(bool skip_param = false);

};

#endif