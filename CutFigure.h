#pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
class CutFigure :public Action{
public:
	CutFigure(ApplicationManager* F);
	virtual void ReadActionParameters();
	virtual void Execute();

};

