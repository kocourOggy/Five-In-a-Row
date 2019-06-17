 //*****************************************************************


#include "NCurCursor.h"
#include "NCurGameBoard.h"

//*****************************************************************

NCurGameBoard::NCurGameBoard()
{
	m_WGameBoard = nullptr;
}

NCurGameBoard::~NCurGameBoard()
{

}


void NCurGameBoard::createWin(const ScreenInfo & screen)
{
	rowData = screen.rowBoard - (2 * BOARD_EDGE_HOR);
	colData = screen.colBoard - (2 * BOARD_EDGE_VER);

	m_WGameBoard = newwin(screen.rowBoard, screen.colBoard, screen.boardPosY, screen.boardPosX);
	box(m_WGameBoard, 0 , 0);
	/*wborder(m_WGameBoard, SCREEN_BORDER_VER, SCREEN_BORDER_VER,
		SCREEN_BORDER_HOR, SCREEN_BORDER_HOR, LU_CORN, RU_CORN, LD_CORN, RD_CORN);*/
	keypad(m_WGameBoard, TRUE);
	wrefresh(m_WGameBoard);
}

void NCurGameBoard::fillBoard()
{
	std::string oneLine;
	for (int i = 0; i < colData; ++i)
	{
		oneLine.push_back(BLANK_SYMBOL);
	}
	for (int i = 1; i < colData; i+=2)
	{
		oneLine[i] = BLANK_SPACE;
	}
	//oneLine.pop_back();
	/*
	mvwprintw( m_GameBoard, i+1, 0+2, "%s", oneLine.c_str() )
	i+1 print from the first line (if we start with 0th position we erase window border)
	0+2 print from the second column:
		0th column is border of window
		1th column is free space (inner edge)
		so print data from the second column...
	*/
	for (int i = 0; i < rowData; ++i)
	{
		mvwprintw( m_WGameBoard, i+BOARD_EDGE_HOR, 0+BOARD_EDGE_VER, "%s", oneLine.c_str() );
	}
}

void NCurGameBoard::updateWin()
{
	wrefresh(m_WGameBoard);
}

void NCurGameBoard::writeMove(const Player & player, const Coordinate & move)
{
	char symbol = player.getSymbol();
	//int color = player.getColor();
	Coordinate turn;

	turn.m_Row = move.m_Row + 1;
	turn.m_Column = (2 * move.m_Column) + 2;

	mvwaddch(m_WGameBoard, turn.m_Row, turn.m_Column, symbol);
	wrefresh(m_WGameBoard);
	refresh();
}

void NCurGameBoard::loadBoard(const std::vector< std::vector<char> > & board )
{
	std::string oneLine1;
	std::string oneLine2;
	for (int i = 0; i < colData; ++i)
	{
		oneLine1.push_back(BLANK_SPACE);
	}
	oneLine2 = oneLine1;

	for (uint line = 0; line < board.size(); ++line)
	{
		uint i = 0;
		for (uint col = 0; col < board[0].size(); ++col)
		{
			oneLine1[i] = board[line][col];
			mvwprintw( m_WGameBoard, line+BOARD_EDGE_HOR, 0+BOARD_EDGE_VER, "%s", oneLine1.c_str() );
			i += 2;
		}
		oneLine1 = oneLine2;
	}
}