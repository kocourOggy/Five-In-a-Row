#ifndef __HUMANPLAYER_H__
#define __HUMANPLAYER_H__

#include <string>

#include "Coordinate.h"
#include "Player.h"
#include "NCurCursor.h"

//*****************************************************************
class HumanPlayer : public Player
{
public:

    /** Constructor
     * @param[in] Player Name
     * @param[in] Player Symbol
     * @param[in] Player Color
     * @param[in] pointer to cursor which control player */
	HumanPlayer(const std::string name, const char symbol, const int color, NCurCursor * cursor );

	/** Virtual destructor*/
	virtual ~HumanPlayer();

	/** Virtual method for player's move*/
	virtual Coordinate makeMove(void) override;

protected:
	/** Pointer for player cursor*/
	NCurCursor * m_Cursor;
	/** Variable for state*/
	char state;

};

#endif  /* __HUMANPLAYER_H__ */