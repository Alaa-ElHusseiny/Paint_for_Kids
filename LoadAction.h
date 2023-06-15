#ifndef LOAD_ACTION_H
#define LOAD_ACTION_H
#include <fstream>
#include "Action.h"


// Save Action Class
class LoadAction : public Action
{
private:
	string graph;
public:

	LoadAction(ApplicationManager* pApp);

	//Reads Save parameters
	virtual void ReadActionParameters();

	//Add Hexagon to the ApplicationManager
	virtual void Execute(bool skip_param = false);

};
#endif

