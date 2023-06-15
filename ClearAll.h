#ifndef CLEAR_ALL_ACTION_H
#define CLEAR_ALL_ACTION_H
#include "Action.h"


class ClearAll: public Action
{	 
public: 
		ClearAll(ApplicationManager* pApp);

		//pure virtual function should be implemented
		virtual void ReadActionParameters();

		
		virtual void Execute(bool skip_param = false);

};

#endif

