#ifndef __NCURGAMEBOARD_H__
#define __NCURGAMEBOARD_H__

#include <ncurses.h>
#include <vector>
#include <string>
#include "Player.h"
#include "ScreenInfo.h"
#include "Coordinate.h"


//*****************************************************************

class NCurGameBoard
{
	friend class NCurCursor;
public:
	/**Constructor*/
	NCurGameBoard();
	/**Destructor*/
	~NCurGameBoard();
	/**Destructor
	 * @param[in] reference to object ScreenInfo where info about proportions are saved*/
	void createWin(const ScreenInfo & screen);
	/**Method which fill board with BLANK SYMBOL from constants.h*/
	void fillBoard();
	/**Method which fill board according to vector with data (used where we load save game)
	 * @param[in] 2D vector with information which symbols are in specific row and column*/
	void loadBoard(const std::vector< std::vector<char> > & board );
	/**Method write Coordinate(row, column) to a game board
	 * @param[in] Player object
	 * @param[in] Coordinate where player made move*/
	void writeMove(const Player & player, const Coordinate & move);
	/**Method will update window with game board (not all screen!)*/
	void updateWin();


	
private:
	/** Pointer to ncurses window*/
	WINDOW *m_WGameBoard;
	/**Row and column where data will be drawn*/
	int rowData, colData;
};




#endif /* __NCURGAMEBOARD_H__ */