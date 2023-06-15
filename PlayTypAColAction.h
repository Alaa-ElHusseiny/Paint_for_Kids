#ifndef PLAY_TYP_A_COL_ACTION_H
#define PLAY_TYP_A_COL_ACTION_H

#include "Action.h"

//Add Play Type and color Action class
class PlayTypAColAction : public Action
{
private:
	Point P;
public:
	PlayTypAColAction(ApplicationManager* pApp);

	//Implement the pure virtual function
	virtual void ReadActionParameters();

	//Output the Play Mode Task Bar
	virtual void Execute(bool skip_param);

};

#endif