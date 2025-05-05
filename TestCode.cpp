#include "GUI\Input.h"
#include "GUI\Output.h"

//This is a test code to test the Input and Output classes

int main()
{
	int x,y;

	//Create Input and Output objects to test
	Output *pOut = new Output();
	Input *pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	
	//			Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Drawing all the Figures with all possible states: 
	//			Non-filled, Filled, and highlighted in both cases			
	///////////////////////////////////////////////////////////////////////////////////
	
	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any figure in any state, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	GfxInfo gfxInfo;//to be used with draw function of the class Ouput
	Point P1, P2;

	/// 2.1- Rectangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Rectangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	
	// 2.1.1 - Drawing non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawRect(P1, P2, gfxInfo, false);

	// 2.1.2 - Drawing highlighted non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);


	// 2.1.3 - Drawing a filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawRect(P1, P2, gfxInfo, false);


	// 2.1.4 - Drawing a highlighted filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);



	pOut->PrintMessage("Drawing a Rectangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	//pOut->ClearDrawArea();

	/// 2.2- Square Test ///
	/// ============== 
	pOut->PrintMessage("Drawing a Square, normal and Highlighted, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	Point p3;
	pOut->PrintMessage("Drawing a Square ==> non-filled,  Click one point");
	pIn->GetPointClicked(p3.x, p3.y);	//Wait for any click
	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawSquare(p3, gfxInfo, false);
	pOut->PrintMessage("Drawing a Square ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawSquare(p3, gfxInfo, true);
	pOut->PrintMessage("Drawing a Square, filled and Highlighted, Click to Draw");
	pIn->GetPointClicked(p3.x, p3.y);	//Wait for any click
	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	// color for border
	gfxInfo.isFilled = true;	//Figure is NOT filled
	pOut->DrawSquare(p3, gfxInfo, false);
	pOut->PrintMessage("Drawing a Square, filled and Highlighted, Click to Draw");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawSquare(p3, gfxInfo, true);

	///TODO: Add code to draw Square, Normal and Highlighted

	pOut->PrintMessage("Drawing a Square Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.3- Triangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Triangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	// 2.3.1 - Drawing non-filled triangle
	pOut->PrintMessage("Drawing a Triangle ==> non-filled,  Click three points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(p3.x, p3.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawTriangles(P1, P2, p3, gfxInfo, false);

	// 2.2.2 - Drawing highlighted non-filled  triangle
	pOut->PrintMessage("Drawing a Triangle ==> non-filled,highlighted,  Click three points");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawTriangles(P1, P2, p3, gfxInfo, true);

	// 2.2.3 - Drawing filled  triangle
	pOut->PrintMessage("Drawing a Triangle ==> non-filled,highlighted,  Click three points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(p3.x, p3.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.FillClr = BLUE;//any color for filling
	gfxInfo.isFilled = true;	//Figure is NOT filled
	pOut->DrawTriangles(P1, P2, p3, gfxInfo, false);


	// 2.2.4 - Drawing highlighted filled  triangle
	pOut->PrintMessage("Drawing a Triangle ==> filled,highlighted,  Click three points");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawTriangles(P1, P2, p3, gfxInfo, true);
	///TODO: Add code to draw Triangle in all possible states

	pOut->PrintMessage("Drawing a Triangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	
	/// 2.4- Hexagon Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Hexagon, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	/// NON-FILLED HEXAGON///
	pOut->PrintMessage("Drawing a Hexagon Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->PrintMessage("Drawing a Hexagon ==> non-filled,Click centre of hexagon");
	pIn->GetPointClicked(P1.x, P1.y);
	gfxInfo.BorderWdth = 8;
	int Hexagon_L = 90;
	gfxInfo.DrawClr = BLACK;
	gfxInfo.isFilled = false;
	pOut->DrawHex(P1, Hexagon_L, gfxInfo, false);
	/// HIGHLIGHTED///
	pOut->PrintMessage("Drawing a Hexagon Test==>OK,Click anywhere to continue");
	pIn->GetPointClicked(x, y);
	pOut->DrawHex(P1, Hexagon_L, gfxInfo, true);
	///FILLED HEX///
	pOut->PrintMessage("Drawing a hexagon ==> filled, Click center of hexagon");
	pIn->GetPointClicked(P1.x, P1.y);
	gfxInfo.FillClr = TURQUOISE;
	gfxInfo.isFilled = true;
	gfxInfo.DrawClr = BLUEVIOLET;
	gfxInfo.BorderWdth = 10;
	pOut->DrawHex(P1, Hexagon_L, gfxInfo, false);
	// Highlighted fill
	pOut->PrintMessage("Drawing a Hexagon==>Highlighted filled,Click to Highlight");
	pIn->GetPointClicked(x, y);
	pOut->DrawHex(P1, Hexagon_L, gfxInfo, true);
	pOut->PrintMessage("Drawing a Hexagon test ==> OK, Click anywhere to continue");
	pIn->GetPointClicked(x, y);
	pOut->ClearDrawArea();

	///TODO: Add code to draw Hexagon in all possible states

	pOut->PrintMessage("Drawing a Hexagon Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	
	/// 2.5- Circle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing an Circle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	// 2.5.1 -Drawing a non-filled circle
	pOut->PrintMessage("drawing a circle==>non-filled,click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;
	gfxInfo.isFilled = false;
	double r;
	pOut->DrawCircles(P1, P2, gfxInfo, r = sqrt(((P1.x - P2.x) * (P1.x - P2.x)) + ((P1.y - P2.y) * (P1.y - P2.y))), false);


	// 2.5.2 - Drawing highlighted non-filled circle
	pOut->PrintMessage("Drawing a circle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawCircles(P1, P2, gfxInfo, r = sqrt(((P1.x - P2.x) * (P1.x - P2.x)) + ((P1.y - P2.y) * (P1.y - P2.y))), true);


	// 2.5.3 - Drawing a filled circle
	pOut->PrintMessage("Drawing a circle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = BLUEVIOLET;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawCircles(P1, P2, gfxInfo, r = sqrt(((P1.x - P2.x) * (P1.x - P2.x)) + ((P1.y - P2.y) * (P1.y - P2.y))), false);


	// 2.5.4 - Drawing a highlighted filled circle
	pOut->PrintMessage("Drawing a circle==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawCircles(P1, P2, gfxInfo, r = sqrt(((P1.x - P2.x) * (P1.x - P2.x)) + ((P1.y - P2.y) * (P1.y - P2.y))), true);
	///TODO: Add code to draw Circle in all possible states

	pOut->PrintMessage("Drawing a Circle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	
	pOut->PrintMessage("Testing Input ability to read strings");

	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar
	// 2- After reading the string clear the status bar
	// 3- print on the status bar "You Entered" then print the string
	pOut->PrintMessage("You entered");
	pIn->GetSrting(pOut);

	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: 
	//			Input Class : Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;
	
	///TODO:  
	//You must add a case for each action (both Draw mode and Play mode actions)
	//Add cases for the missing actions below
	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case DRAW_RECT:
				pOut->PrintMessage("Action: Draw a Rectangle , Click anywhere");
				break;

		case STATUS:
				pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
				break;
 
		case DRAWING_AREA:
				pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
				break;

		case EMPTY:
				pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
				break;

		case TO_DRAW:
				pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
				pOut->CreateDrawToolBar();
				break;

		case TO_PLAY:
				pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
				pOut->CreatePlayToolBar();
				break;
		case DRAW_SQUARE:
			pOut->PrintMessage("Action: Draw a Square, Click anywhere");
			break;
		case DRAW_TRI:
			pOut->PrintMessage("Action: Draw a Triangle, Click anywhere");
			break;
		case DRAW_HEX:
			pOut->PrintMessage("Action: Draw a Hexagon, Click anywhere");
			break;
		case DRAW_CIRCLE:
			pOut->PrintMessage("Action: Draw a Circle, Click anywhere");
			break;
		case SELECT:
			pOut->PrintMessage("Action: Select a figure, Click anywhere");
			break;
		case FIGURE_DELETE:
			pOut->PrintMessage("Action: Select a figure to delete, Click anywhere");
			break;
		case CLEAR_ALL:
			pOut->PrintMessage("Action: Clear all figures, Click anywhere");
			break;
		case COPY:
			pOut->PrintMessage("Action: Copy a figure, Click anywhere");
			break;
		case CUT:
			pOut->PrintMessage("Action: Cut a figure, Click anywhere");
			break;
		case PASTE:
			pOut->PrintMessage("Action: Paste a figure, Click anywhere");
			break;
		case SWAP:
			pOut->PrintMessage("Action:Swap a figure,Click anywhere");
		case ROTATE:
			pOut->PrintMessage("Action:Rotate a figure,Click anywhere");
		case BACK_FRONT:
			pOut->PrintMessage("Action: Back and front a figue, Click anywhere");
			break;
		case SAVE:
			pOut->PrintMessage("Action: Save graph, Click anywhere");
			break;
		case LOAD:
			pOut->PrintMessage("Action: Load graph, Click anywhere");
			break;
		
		case CHOOSE_BLACK:
			pOut->PrintMessage("Colour chosen is black,returning to draw menu");
			pOut->CreateDrawToolBar();
			break;
		case CHOOSE_YELLOW:
			pOut->PrintMessage("Colour chosen is yellow,returning to draw menu");
			pOut->CreateDrawToolBar();
			break;
		case CHOOSE_ORANGE:
			pOut->PrintMessage("Colour chosen is orange,returning to draw menu");
			pOut->CreateDrawToolBar();
			break;
		case CHOOSE_RED:
			pOut->PrintMessage("Colour chosen is red,returning to draw menu");
			pOut->CreateDrawToolBar();
			break;
		case CHOOSE_GREEN:
			pOut->PrintMessage("Colour chosen is green,returning to draw menu");
			pOut->CreateDrawToolBar();
			break;
		case CHOOSE_BLUE:
			pOut->PrintMessage("Colour chosen is blue,returning to draw menu");
			pOut->CreateDrawToolBar();
			break;


		///TODO: Add more cases for the other action types


		case EXIT:				
				break;
		}
	}while(ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x,y);


	delete pIn;
	delete pOut;	
	return 0;
}


