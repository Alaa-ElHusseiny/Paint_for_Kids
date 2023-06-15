#ifndef PLAY_TYPE_ACTION_H
#define PLAY_TYPE_ACTION_H

#include "Action.h"

//Add Play Type Action class
class PlayTypeAction : public Action
{
private:
	Point P;
public:
	PlayTypeAction(ApplicationManager* pApp);

	//Implement the pure virtual function
	virtual void ReadActionParameters();

	//Output the Play Mode Task Bar
	virtual void Execute(bool skip_param);

};

#endif