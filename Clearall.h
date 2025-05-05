#pragma once
#include"ApplicationManager.h"
#include"Actions/Action.h"
class Clearall :public Action {
public:
	Clearall(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
