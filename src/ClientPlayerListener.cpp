 //*****************************************************************

#include "ClientPlayerListener.h"

//******************************************************************

ClientPlayerListener::ClientPlayerListener(const std::string name, const char symbol, const int color, Client * client)
:	Player(name, symbol, color)
{
	m_Client = client;
}

ClientPlayerListener::~ClientPlayerListener()
{

}

Coordinate ClientPlayerListener::makeMove()
{
	Coordinate coor;
	coor = m_Client->listenCoor();
	if (coor.m_Row == -1 && coor.m_Column == -1)
	{
		m_State = STATE_QUIT;
		m_Client->closeConnection();
	}
	else
	{
		m_lastMove = coor;
	}

	return m_lastMove;
}