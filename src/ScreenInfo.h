#ifndef __SCREENINFO_H__
#define __SCREENINFO_H__
 
//*****************************************************************

struct ScreenInfo
{
	/** Real row entered by user or used from constants.h*/
	int mainRow;
	/** Real column entered by user or used from constants.h*/
	int mainCol;

	/** Compute nededed row for gameBoard*/
	int rowBoard;
	/** Compute nededed column for gameBoard*/
	int colBoard;

	/** Compute nededed row for game screen*/
	int rowGameScreen;
	/** Compute nededed column for game screen*/
	int colGameScreen;

	/** Position X of game board (grid) on screen*/
	int boardPosX;
	/** Position Y of game board (grid) on screen*/
	int boardPosY;

	/** Number of row where basic text will be written*/
	int textPosRow;
	/** Number of column where basic text will be written*/
	int textPosCol;

	/** Distance from screen border*/
	int screenEdge;

	/** Compute basic proportions for screen according to row and column
	 * @param[in] entered row
     * @param[in] entered column */
	void computeGameBoard(const int row, const int column);
};

#endif /* __SCREENINFO_H__ */