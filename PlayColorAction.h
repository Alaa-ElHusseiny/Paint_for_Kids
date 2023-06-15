#ifndef PLAY_COLOR_ACTION_H
#define PLAY_COLOR_ACTION_H

#include "Action.h"

//Add Play COLOR Action class
class PlayColorAction : public Action
{
private:
	Point P;
public:
	PlayColorAction(ApplicationManager* pApp);

	//Implement the pure virtual function
	virtual void ReadActionParameters();

	//Output the Play Mode Task Bar
	virtual void Execute(bool skip_param);

};
#endif
