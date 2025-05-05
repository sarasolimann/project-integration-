#include "Clearall.h"

Clearall::Clearall(ApplicationManager* pApp): Action(pApp)
{

}

void Clearall::ReadActionParameters() 
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->ClearStatusBar();
	pOut->ClearDrawArea();
}

void Clearall::Execute()
{
	ReadActionParameters();
	pManager->ClearAll();
}
