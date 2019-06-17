#ifndef __NCURCURSOR_H__
#define __NCURCURSOR_H__

#include <ncurses.h>

#include "constants.h"
#include "ScreenInfo.h"
#include "NCurGameBoard.h"
#include "GameBoard.h"
#include "MoveAdvisor.h"

//*****************************************************************

class NCurCursor
{
public:
    /** Constructor
     * @param[in] Pointer to graphic game board (we have to draw cursor on board)
     * @param[in] reference to ScreenInfo where info about screen proportion are saved (to know borders where we cant move)
     * @param[in] Pointer to GameBoard where are saved game data for function MoveAdvisor
     * @param[in] index Player which decide who MoveAdvisor help*/
	NCurCursor(NCurGameBoard * board, const ScreenInfo & scr, GameBoard * gameData, const int index);
	/** Destructor*/
	~NCurCursor();
	/**Method which move cursor on game board
	* @return returns Coordinate where we move*/
	Coordinate moveCursor();
	/** Method which get cursor state (save mode, quit mode, or just moving the cursor)
	 * @return returns state as char 's' - save mode, 'q' - quit mode*/
	char getState() const;

private:
	/**Variable where last move is saved*/
	Coordinate m_lastMoveCur;
	/**Pointer to a game screen where we draw cursor*/
	NCurGameBoard * boardScreen;
	/**Variable with lef-tup corner and right-up corner for controling boards*/
	Coordinate m_LU_corn, m_RD_corn;
	/** Variable where current state is saved*/
	char m_State;
	/** Object that hints player a move*/
	MoveAdvisor moveAdvisor;
};





#endif /* __NCURCURSOR_H__ */