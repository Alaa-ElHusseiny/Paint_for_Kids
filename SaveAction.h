#ifndef SAVE_ACTION_H
#define SAVE_ACTION_H
#include <fstream>
#include "Action.h"


// Save Action Class
class SaveAction : public Action
{
private:
	string graph;
public:

	SaveAction(ApplicationManager* pApp);

	//Reads Save parameters
	virtual void ReadActionParameters();

	//Add Hexagon to the ApplicationManager
	virtual void Execute(bool skip_param = false);

};
#endif

