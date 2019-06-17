#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>

#include "constants.h"
#include "Coordinate.h"



//*****************************************************************
class Player
{
public:
    /** Constructor
     * @param[in] Player Name
     * @param[in] Player Symbol 'o' or 'x'
     * @param[in] Player Color */
	Player(const std::string name, const char symbol, const int color);
	/** Virtual destructor */
	virtual ~Player();

	/** Constant method which return player's symbol
	  * @return returns players symbol.*/
	char getSymbol() const;

    /** Constant method which return player's index
	  * @return returns players index.*/
	int getIndex() const;
	/** Constant method which return player's color
	  * @return returns players color.*/
	int getColor() const;

	/** Constant method which return player's name
	  * @return returns players name.*/
	std::string getName() const;
	void setData (int row, int column);

	/** Constant method which return player's state
	  * @return returns players state (save game, quit game, do nothing).*/
	char getState(void) const;
	/** Abstract method for making move
	  * @return returns Coordinate of move.*/
	virtual Coordinate makeMove(void) = 0;


protected:
	/**Player's symbol*/
	char m_Symbol;
	/**Player's name*/
	std::string m_Name;
	/**Player's m_Row and m_Column*/
	int m_Row, m_Column;
	/**Player's index*/
	int m_Index;
	/**Player's last move*/
	Coordinate m_lastMove;
	/**Player's state*/
	char m_State;
	/**Player's color*/
	int m_Color;


};

#endif /*__PLAYER_H__ */