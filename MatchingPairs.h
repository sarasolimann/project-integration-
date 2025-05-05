#pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
class MatchingPairs :
    public Action
{
	MatchingPairs(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

