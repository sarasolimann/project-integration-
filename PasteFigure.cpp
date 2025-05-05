#include "PasteFigure.h"
#include <string>
#include"ApplicationManager.h"
PasteFigure::PasteFigure(ApplicationManager* F):Action(F)
{
}

void PasteFigure::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* Pin = pManager->GetInput();
}

void PasteFigure::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->getClipboard() == NULL) {
		pOut->PrintMessage("Copy or cut a figure first");
		return;
	}
	else {
		string CBStatus = pManager->getCBStatus();
		if (CBStatus == "copy") {
			pOut->PrintMessage("click on a point to paste");
			pIn->GetPointClicked(x, y);
			CFigure* shifted = (pManager->getClipboard())->Shift(x, y, pOut);
			pManager->AddFigure(shifted);
			shifted->Draw(pOut);
			shifted->SetSelected(false);
			shifted->ChngDrawClr(BLUE);
			pManager->unselect(shifted);
		}
		else {
			pOut->PrintMessage("click on a point to paste");
			pIn->GetPointClicked(x, y);
			CFigure* shifted = (pManager->getClipboard())->Shift(x, y, pOut);
			CFigure* CutFig = (pManager->getSelectedFigure());
			pManager->AddFigure(shifted);
			shifted->Draw(pOut);
			shifted->SetSelected(false);
			shifted->ChngDrawClr(pManager->getDrawBef());
			shifted->ChngFillClr(pManager->getFillBef());
			pManager->unselect(shifted);
			pManager->unselect(CutFig);
			pManager->Deletefigure(CutFig);
		}
	}

};
