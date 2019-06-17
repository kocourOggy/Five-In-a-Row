#ifndef __MOVE_ADVISOR_H__
#define __MOVE_ADVISOR_H__

#include <vector>

#include "constants.h"
#include "Coordinate.h"
#include "GameBoard.h"
#include "Player.h"

//*****************************************************************

class MoveAdvisor
{
public:
	/**Constructor
	 * @param[in] Pointer to gameData (to control where we can move)
     * @param[in] Agresivity of AI */
	MoveAdvisor(GameBoard * gameData, int Attack);
	/**Destructor*/
	~MoveAdvisor();
	/**Method which set player and opponent (AI has to know for who do the move)
	 * @param[in] player index */
	void setPlayer(int player);
	/** Method which choose the best move according to value of individual block
     * @return returns Coordinate of move*/
	Coordinate findMove() const;

private:
	/**Pointer to game data*/
	GameBoard * m_GameData;
	/**index player (in our case the AI), index of opponent*/
	int m_indexPlayer, m_indexOpponent;
	/**agresivity of AI*/
	int m_Attack;

};

#endif /*__MOVE_ADVISOR_H__ */


