#ifndef __SERVERPLAYER_LISTENER_H__
#define __SERVERPLAYER_LISTENER_H__

#include <string>

#include "Coordinate.h"
#include "Player.h"
#include "Server.h"


//*****************************************************************

class ServerPlayerListener : public Player
{
public:
    /** Constructor
     * @param[in] Player Name
     * @param[in] Player Symbol
     * @param[in] Player Color
     * @param[in] pointer to cursor which control player
     * @param[in] pointer to Server */
	ServerPlayerListener(const std::string name, const char symbol, const int color, Server * server);

	/** VIrtual destructor*/
	virtual ~ServerPlayerListener();

	/** VIrtual method for players (opponent) move via Server (server is listening client)*/
	virtual Coordinate makeMove() override;

protected:
	/** Pointer to server*/
	Server * m_Server;
};


#endif /* __SERVERPLAYER_LISTENER_H__ */