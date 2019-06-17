 //*****************************************************************

#include "ClientHumanPlayer.h"

//******************************************************************

ClientHumanPlayer::ClientHumanPlayer(const std::string & name, const char symbol, const int color,
	                                 NCurCursor * cursor  , Client * client)
:	HumanPlayer(name, symbol, color, cursor)
{
	m_Client = client;
}

ClientHumanPlayer::~ClientHumanPlayer() { }

Coordinate ClientHumanPlayer::makeMove()
{
	m_lastMove = m_Cursor->moveCursor();
	m_State = m_Cursor->getState();
	if ( m_State == STATE_NOTHING  )
	{
		m_Client->sendCoor(m_lastMove);
	}
	if (m_State == STATE_QUIT)
	{
		m_Client->sendCoor(Coordinate(-1,-1));
		m_Client->closeConnection();
	}

	return m_lastMove;
}