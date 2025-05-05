#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include<string>
#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "CMUgraphicsLib/jpeg/jpeglib.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	int SelectedCount;
	
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* SelectedFig[MaxFigCount];
	
	 //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	
	CFigure* Clipboard;  //Pointer to copied/cut figure
	string ClipboardStat;
	color FillColBeforeCut;
	color DrawColBeforeCut;

public:	
	ApplicationManager();
	~ApplicationManager();
	
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);  
	void Deletefigure(CFigure* Sel);
	//Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void unselect(CFigure* Fig);
	void ClearAll();
	
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	CFigure* getSelectedFigure();
	void set_Clipboard(CFigure* Fig);
	CFigure* getClipboard();
	void SetCBStatus(string s);
	string getCBStatus();
	void setFillBef(color c);
	void setDrawBef(color c);
	color getFillBef();
	color getDrawBef();
	int getSelectedCount();
	void ClearSelection();
	int getFigCount();
	
};


#endif