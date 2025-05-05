#include "CutFigure.h"

CutFigure::CutFigure(ApplicationManager* F):Action(F)
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
}

void CutFigure::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
}

void CutFigure::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (pManager->getSelectedFigure() == NULL || pManager->getSelectedCount() > 1) {
		pOut->PrintMessage("Please select one figure");
		return;
	}
	else
	{
		pManager->set_Clipboard(pManager->getSelectedFigure());
		pManager->setFillBef((pManager->getSelectedFigure())->getFillColor());
		pManager->setDrawBef((pManager->getSelectedFigure())->getDrawColor());
		(pManager->getSelectedFigure())->ChngDrawClr(GREY);
		(pManager->getSelectedFigure())->ChngFillClr(GREY);
		pManager->SetCBStatus("cut");
		pOut->PrintMessage("The figure is cut");
	}

}
