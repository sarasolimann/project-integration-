#include "MatchingPairs.h"
#include"Actions/Action.h"
#include"ApplicationManager.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"Figures/CFigure.h"

MatchingPairs::MatchingPairs(ApplicationManager* pApp):Action(pApp)
{
}
void MatchingPairs::ReadActionParameters()
{

}

void MatchingPairs::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int score = 0;
	int remaining = pManager->getFigCount();
	int x, y;
	CFigure* fig1 = pManager->GetFigure(x, y);
	while (remaining > 1) {
		pOut->PrintMessage("Click the first figure...");
		int x1, y1;
		pIn->GetPointClicked(x1, y1);
		CFigure* fig1 = pManager->GetFigure(x1, y1);
		if (!fig1 || fig1->isMatched())
			continue;

		fig1->SetSelected(true);
		pManager->UpdateInterface();
	}
	pOut->PrintMessage("Select the second figure");
	int x2, y2;
	pIn->GetPointClicked(x2, y2);
	CFigure* fig2 = pManager->GetFigure(x2, y2);
	fig2->SetSelected(true);
	pManager->UpdateInterface();

	if (fig1->getType() == fig2->getType() &&
		fig1->getFillColor() == fig2->getFillColor()) {
		fig1->setMatched(true);
		fig2->setMatched(true);
		pManager->Deletefigure(fig1);
		pManager->Deletefigure(fig2);
		score++;
		remaining -= 2;
	}
	else {
		fig1->SetSelected(false);
		fig2->SetSelected(false);
		score--;
		pOut->PrintMessage("Not a match. Score: ");
	}

	pManager->UpdateInterface();
	}

