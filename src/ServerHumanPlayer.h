#ifndef __SERVERPLAYER_H__
#define __SERVERPLAYER_H__

#include <string>

#include "Coordinate.h"
#include "HumanPlayer.h"
#include "NCurCursor.h"
#include "Server.h"


//*****************************************************************

class ServerHumanPlayer : public HumanPlayer
{
public:

    /** Constructor
     * @param[in] Player Name
     * @param[in] Player Symbol
     * @param[in] Player Color
     * @param[in] pointer to cursor which control player
     * @param[in] pointer to Server */
	ServerHumanPlayer(const std::string & name, const char symbol, const int color,
					  NCurCursor * cursor  , Server * server);

	/** Virtual destructor*/
	virtual ~ServerHumanPlayer();

	/** Virtual method for players move using network via server (server send Coordinate to client)*/
	virtual Coordinate makeMove() override;

protected:
	/** Pointer to server*/
	Server * m_Server;
	/** Variable coordinate*/
	Coordinate coordinate;
};

#endif /* __SERVERPLAYER_H__ */