#ifndef ADD_TRIANG_ACTION_H
#define ADD_TRIAND_ACTION_H

#include "Action.h"

//Add Triangle Action class
class AddTriangAction : public Action
{
private:
	Point P1; //Triangle corner 1
	Point P2; //Triangle corner 2
	Point P3; //Triangle corner 3
	GfxInfo TriangGfxInfo;
public:
	AddTriangAction(ApplicationManager* pApp);

	//Reads triangle parameters
	virtual void ReadActionParameters();

	//Add triangle to the ApplicationManager
	virtual void Execute(bool skip_param = false);

};

#endif