 
 //*****************************************************************

#include "MoveAdvisor.h"

//*****************************************************************

MoveAdvisor::MoveAdvisor(GameBoard * gameData, int Attack)
{
	m_GameData = gameData;
	m_Attack = Attack;
}

MoveAdvisor::~MoveAdvisor()
{

}

void MoveAdvisor::setPlayer(int player)
{
	m_indexPlayer = player;
	if (player == 2)
	{
		m_indexOpponent = 1;
	}
	else
	{
		m_indexOpponent = 2;
	}
}

Coordinate MoveAdvisor::findMove() const
{
	int max;
	int row = ( m_GameData->m_Row ) / 2;
	int col = ( m_GameData->m_Column ) / 2;

	if ( (m_GameData->m_Board)[row][col] == BLANK_SYMBOL )
	{
		max = 4;
		return Coordinate(row, col);
	}
	else
	{
		max = -1;
	}

	for (int i = 0; i < m_GameData->m_Row; ++i)
	{
		for (int j = 0; j < m_GameData->m_Column; ++j)
		{
			if ( (m_GameData->m_Board)[i][j] == BLANK_SYMBOL )
			{
				int blockVal = ((m_GameData->m_ValueBlock)[i][j][m_indexPlayer] * (16 + m_Attack) / 16)
								+ (m_GameData->m_ValueBlock)[i][j][m_indexOpponent];
				if (blockVal > max)
				{
				 row = i;
				 col = j;
				 max = blockVal;
				}
			}

		}
	}
	return Coordinate(row, col);
}
