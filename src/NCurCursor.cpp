 //*****************************************************************

#include <string>

#include "constants.h"
#include "NCurCursor.h"


//*****************************************************************


NCurCursor::NCurCursor(NCurGameBoard * board, const ScreenInfo & scr, GameBoard * gameData, const int index)
:	moveAdvisor(gameData, 4)
{
	/*int BOARD_EDGE_HOR = 1;
	int BOARD_EDGE_VER = 2;*/

	moveAdvisor.setPlayer(index);
	boardScreen = board;

	m_State = ' ';

	m_LU_corn.m_Row = BOARD_EDGE_HOR;
	m_LU_corn.m_Column = BOARD_EDGE_VER;
	m_RD_corn.m_Row = board->rowData + BOARD_EDGE_HOR - 1;
	m_RD_corn.m_Column = board->colData + BOARD_EDGE_VER - 1;

	m_lastMoveCur.m_Row = BOARD_EDGE_HOR + (scr.mainRow / 2) ;
	m_lastMoveCur.m_Column = BOARD_EDGE_VER + ((scr.mainCol / 2) * 2);

	wmove(boardScreen->m_WGameBoard, m_lastMoveCur.m_Row, m_lastMoveCur.m_Column);
	wrefresh(boardScreen->m_WGameBoard);
}

NCurCursor::~NCurCursor() { }

Coordinate NCurCursor::moveCursor()
{
	wmove(boardScreen->m_WGameBoard, m_lastMoveCur.m_Row, m_lastMoveCur.m_Column);
	
	refresh();
	wrefresh(boardScreen->m_WGameBoard);

	int ch = ' ';
	m_State = STATE_NOTHING;
	while( ch != '\n')
	{
		ch = getch();
		
		if ( ch == KEY_LEFT && m_lastMoveCur.m_Column > m_LU_corn.m_Column)
		{
			m_lastMoveCur.m_Column = m_lastMoveCur.m_Column - 2;
			wmove(boardScreen->m_WGameBoard, m_lastMoveCur.m_Row, m_lastMoveCur.m_Column);
		}
		else if ( ch == KEY_RIGHT && m_lastMoveCur.m_Column < m_RD_corn.m_Column )
		{
			m_lastMoveCur.m_Column = m_lastMoveCur.m_Column + 2;
			wmove(boardScreen->m_WGameBoard, m_lastMoveCur.m_Row, m_lastMoveCur.m_Column);
		}
		else if (ch == KEY_UP && m_lastMoveCur.m_Row > m_LU_corn.m_Row )
		{
			m_lastMoveCur.m_Row = m_lastMoveCur.m_Row - 1;
			wmove(boardScreen->m_WGameBoard, m_lastMoveCur.m_Row, m_lastMoveCur.m_Column);
		}
		else if (ch == KEY_DOWN && m_lastMoveCur.m_Row < m_RD_corn.m_Row )
		{
			m_lastMoveCur.m_Row = m_lastMoveCur.m_Row + 1;
			wmove(boardScreen->m_WGameBoard, m_lastMoveCur.m_Row, m_lastMoveCur.m_Column);
		}

		if (ch == 's')
		{
			m_State = STATE_SAVE;
			return Coordinate(m_lastMoveCur.m_Row - 1, (m_lastMoveCur.m_Column / 2) - 1 );
		}

		if (ch == 'q')
		{
			m_State = STATE_QUIT;
			return Coordinate(m_lastMoveCur.m_Row - 1, (m_lastMoveCur.m_Column / 2) - 1 );
		}

		if (ch == 'h')
		{
			Coordinate adviceMove;
			adviceMove = moveAdvisor.findMove();
			adviceMove.m_Row = adviceMove.m_Row + 1;
			adviceMove.m_Column = (2 * adviceMove.m_Column) + 2;
			if ( adviceMove.m_Column > m_LU_corn.m_Column && adviceMove.m_Column < m_RD_corn.m_Column
				&& adviceMove.m_Row > m_LU_corn.m_Row && adviceMove.m_Row < m_RD_corn.m_Row )
			{
				m_lastMoveCur.m_Row = adviceMove.m_Row;
				m_lastMoveCur.m_Column = adviceMove.m_Column;
			}
		}


		refresh();
		wmove(boardScreen->m_WGameBoard, m_lastMoveCur.m_Row, m_lastMoveCur.m_Column);
		
		wrefresh(boardScreen->m_WGameBoard);

	}

	return Coordinate(m_lastMoveCur.m_Row - 1, (m_lastMoveCur.m_Column / 2) - 1 );
}


char NCurCursor::getState() const
{
	return m_State;
}