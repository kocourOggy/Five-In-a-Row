#ifndef __GAMEBOARD_H__
#define __GAMEBOARD_H__

#include <vector>

#include "constants.h"
#include "Coordinate.h"
#include "Player.h"

//*****************************************************************

typedef std::vector< std::vector <std::vector<int> > > vect3D;
typedef std::vector < std::vector< std::vector< std::vector<int > > > > vect4D;

class GameBoard
{
friend class MoveAdvisor;
friend class Game;

public:
    /** Constructor
     * @param[in] row of game grid
     * @param[in] column of game grid */
	GameBoard(const int row, const int column );

	/**Destructor*/
	~GameBoard();

    /** Method which write move (symbol 'x' or 'o') into m_Board
     * @param[in] constant reference to player
     * @param[in] constant reference to player's move */
	void writeStone(const Player & player, const Coordinate & coor);

    /** Method checks if the move is valid
     * @param[in] constant reference to player's move
     * @return returns true the move is valid */
	bool validMove (const Coordinate & coor);

	bool updateLine(const Player & player, const Coordinate & curMove);

    /** Method increment number of stone in a row
     * @param[in] reference to a number of player"s stone in a specific row, column and specific direction
     * @return returns true if number of stone is equal to SIZELINE (5) */
	bool incrementLineStone(int & stoneInRow);

    /** Method update value of 5 block in a row according to in-paramaters
     * @param[in] number of player's stone in specific direction
     * @param[in] number of opponent's stone in specific direction
     * @param[in] value in player's block
     * @param[in] value in opponent's block
     * @return returns true the move is valid */
	void updateBlockValue(const int stoneInRowPlayer, const int stoneInRowOpponent,
						  int & blockValuePlayer, int & blockValueOpponent);


private:
	/** 2D vector where data tells where the player make a move (tells 'x' or 'o' or '.' in specific row and col)*/
	std::vector< std::vector<char> > m_Board;
	/** 1D vector where data about values of blocks are saved*/
	std::vector <int> m_Values;
	/**vector of directions*/
	std::vector <Coordinate> m_Dir;
	/** 3D vector where are saved data for both player which tells value of each block in grid*/
	vect3D m_ValueBlock;
	/** 4D vector where are saved data for both player which tells whether there is a 5 stones in a row*/
	vect4D m_LineStone; // [x,y, direction, symbol]*/
	/**row and column of gameBoard*/
	int m_Row, m_Column;
};

#endif /*__GAMEBOARD_H__ */