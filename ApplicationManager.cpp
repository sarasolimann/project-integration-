#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"Actions/Action.h"
#include"Figures/CFigure.h"
#include<string>

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	 FigCount = 0;
	 SelectedCount =0 ;
	Clipboard = NULL;
		
	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++) {
		FigList[i] = NULL;
		SelectedFig[i] = NULL;
		
	}

}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
void ApplicationManager::Deletefigure(CFigure* Sel)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == Sel)
		{
			FigList[i] = NULL;
			pOut->PrintMessage("deleted");
			for (int j = i; j < FigCount; j++)
			{
				FigList[j] = FigList[j + 1];
			}
			i--;
			FigCount--;
		}
	}

	pOut->ClearDrawArea();
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
void ApplicationManager::unselect(CFigure* Fig)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (SelectedFig[i] == Fig) {
			for (int j = i; j < FigCount; j++)
			{
				SelectedFig[j] = SelectedFig[j + 1];
			}
			SelectedCount--;
		}
	}
}
void ApplicationManager::ClearAll()
{
	for (int i = 0; i < FigCount; i++)
	{
		pOut->PrintMessage("Clear");
		for (int j = i; j < FigCount; j++)
		{
			FigList[j] = FigList[j + 1];
		}
		i--;
		FigCount--;
	}
	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
CFigure* ApplicationManager::getSelectedFigure() { return SelectedFig[0]; }

////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
void ApplicationManager::set_Clipboard(CFigure* Fig)
{
	Clipboard = Fig;
}
CFigure* ApplicationManager::getClipboard()
{
	return Clipboard;
}
void ApplicationManager::SetCBStatus(string s)
{
	ClipboardStat = s;
}

string ApplicationManager::getCBStatus()
{
	return ClipboardStat;
}

void ApplicationManager::setFillBef(color c)
{
	FillColBeforeCut = c;
}

void ApplicationManager::setDrawBef(color c)
{
	DrawColBeforeCut = c;
}

color ApplicationManager::getFillBef()
{
	return FillColBeforeCut;;
}

color ApplicationManager::getDrawBef()
{
	return  FillColBeforeCut;;
}

int ApplicationManager::getSelectedCount()
{
	return SelectedCount;
}

void ApplicationManager::ClearSelection()
{
	for (int i = 0; i < FigCount; i++) {
		FigList[i]->SetSelected(false);
	}
}

int ApplicationManager::getFigCount()
{
	return FigCount;
}









////////////////////////////////////////////////////////////////////////////////////

//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
