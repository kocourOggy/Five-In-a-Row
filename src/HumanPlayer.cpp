
//*****************************************************************

#include "Player.h"
#include "HumanPlayer.h"

//*****************************************************************
HumanPlayer::HumanPlayer(const std::string name, const char symbol, const int color, NCurCursor * cursor )
:	Player::Player(name, symbol, color)
{
	m_Cursor = cursor;
}

HumanPlayer::~HumanPlayer() { } // virtual



Coordinate HumanPlayer::makeMove(void) // virtual
{
	m_lastMove = m_Cursor->moveCursor();
	m_State = m_Cursor->getState();
	return m_lastMove;
}
