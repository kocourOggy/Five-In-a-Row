 //*****************************************************************

#include "ServerHumanPlayer.h"

//******************************************************************

ServerHumanPlayer::ServerHumanPlayer(const std::string & name, const char symbol, const int color,
					  NCurCursor * cursor  , Server * server)
:	HumanPlayer(name, symbol, color, cursor)
{
	m_Server = server;
}

ServerHumanPlayer::~ServerHumanPlayer() //virtual
{

}

Coordinate ServerHumanPlayer::makeMove() //virtual
{
	m_lastMove = m_Cursor->moveCursor();
	m_State = m_Cursor->getState();
	if ( m_State == STATE_NOTHING  )
	{
		m_Server->sendCoor(m_lastMove);
	}
	else if (m_State ==STATE_QUIT)
	{
		m_Server->sendCoor(Coordinate(-1, - 1));
		m_Server->closeConnection();
	}

	return m_lastMove;
}