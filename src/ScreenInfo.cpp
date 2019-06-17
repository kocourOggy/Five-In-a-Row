 
 //*****************************************************************

#include "constants.h"
#include "ScreenInfo.h"

//*****************************************************************


void ScreenInfo::computeGameBoard(const int row, const int column)
{
	mainRow = row;
	mainCol = column;

	rowBoard = row + (2 * BOARD_EDGE_HOR);
	colBoard = ( 2*(column) -1 ) + (2 * BOARD_EDGE_VER);
	//------------------------------------------------

	boardPosX = POS_BOARD_X;
	boardPosY = POS_BOARD_Y;

	textPosRow = POS_BOARD_X + rowBoard + SCREEN_EDGE;
	textPosCol = SCREEN_EDGE;

	screenEdge = SCREEN_EDGE;


	rowGameScreen = rowBoard + SCREEN_EDGE + 10;
	colGameScreen = colBoard + SCREEN_EDGE + 10;
}