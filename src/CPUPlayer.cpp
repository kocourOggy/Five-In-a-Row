
//*****************************************************************

#include <random>

#include "CPUPlayer.h"

//*****************************************************************

CPUPlayer::CPUPlayer(const std::string & name, const char symbol, const int color, GameBoard * gameData, int Attack)
:	Player::Player(name,symbol, color),
	m_AI (gameData, Attack)
{
	m_AI.setPlayer(m_Index);
}

CPUPlayer::~CPUPlayer() { }


int CPUPlayer::generateRandNum (int from, int to)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(from, to); // define the range

    return distr(eng);	
}

Coordinate CPUPlayer::generateRandCoor()
{
	return Coordinate ( generateRandNum(0, m_Row), generateRandNum(0, m_Column) );
}


Coordinate CPUPlayer::makeMove(void)
{
	return m_AI.findMove();
	//return generateRandCoor();
}

/*
void CPUPlayer::cti()
{
	for (int i = 0; i < (m_AI.m_GameData->m_Row); ++i )
	{
		for (int j = 0; j < (m_AI.m_GameData->m_Column); ++j )
		{
			std::cout << (m_AI.m_GameData->m_Board)[i][j] << " ";
		}
		std::cout<< "\n";
	}
}

*/