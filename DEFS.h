#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,//Draw Rectangle
	DRAW_SQUARE,
	DRAW_TRI,
	DRAW_HEX,
	DRAW_CIRCLE,
	SELECT,
	FIGURE_DELETE,
	CLEAR_ALL,
	COPY,
	CUT,
	PASTE,
	ROTATE,
	SWAP,
	BACK_FRONT,
	SAVE,
	LOAD,
	EXIT,			//Exit
	TO_DRAW,//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS,		//A click on the status bar
	OPEN_COLOURS,
	CHOOSE_BLACK,
	CHOOSE_YELLOW,
	CHOOSE_ORANGE,
	CHOOSE_RED,
	CHOOSE_GREEN,
	CHOOSE_BLUE,
	


	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif