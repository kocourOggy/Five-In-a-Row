#ifndef __CPUPLAYER_H__
#define __CPUPLAYER_H__

#include <string>

#include "Coordinate.h"
#include "Player.h"
#include "GameBoard.h"
#include "MoveAdvisor.h"


//*****************************************************************

class CPUPlayer : public Player
{
public:

    /** Constructor
     * @param[in] Player Name
     * @param[in] Player Symbol
     * @param[in] Player Color
     * @param[in] pointer to gameData for AI
     * @param[in] Attack which is atribute of AI defining its agresivity in game*/
	CPUPlayer(const std::string & name, const char symbol, const int color, GameBoard * gameData, int Attack);

	/**Virtual destructor*/
	virtual ~CPUPlayer();

	/**Virtual method for making a move in game*/
	virtual Coordinate makeMove(void) override;
	//void cti();

	

private:
	/** MoveAdvisor tells CPUPlayer which move should do*/
	MoveAdvisor m_AI;
	/** Private method for generating random Coordinate
	* @return returns generate Coordinate*/
	Coordinate generateRandCoor();

	/** Private method for generating random number
	* @return returns generated random number*/
	int generateRandNum (int from, int to);
};

#endif /* __CPUPLAYER_H__ */