#ifndef CHANGE_FILL_COLOR_ACTION_H
#define CHANGE_FILL_COLOR_ACTION_H

#include "Action.h"

class ChangeFillColorAction : public Action
{
private:
	color chosen_color;

public:
	ChangeFillColorAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute(bool skip_param = false);

};

#endif