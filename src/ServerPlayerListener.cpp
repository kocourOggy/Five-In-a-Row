 //*****************************************************************

#include "ServerPlayerListener.h"

//******************************************************************

ServerPlayerListener::ServerPlayerListener(const std::string name, const char symbol, const int color, Server * server)
:	Player(name, symbol, color)
{
	m_Server = server;
}

ServerPlayerListener::~ServerPlayerListener()
{

}

Coordinate ServerPlayerListener::makeMove()
{
	Coordinate coor;
	coor = m_Server->listenCoor();
	if (coor.m_Row == -1 && coor.m_Column == -1)
	{
		m_State = STATE_QUIT;
		m_Server->closeConnection();
	}
	else
	{
		m_lastMove = coor;
	}

	return m_lastMove;
}