#pragma once
#include "Actions/Action.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"
class PasteFigure :
    public Action
{
private:
    int x, y;
public:
    PasteFigure(ApplicationManager* F);
    virtual void ReadActionParameters();
    virtual void Execute();
};

