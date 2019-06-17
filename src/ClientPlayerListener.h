#ifndef __CLIENTPLAYER_LISTENER_H__
#define __CLIENTPLAYER_LISTENER_H__

#include <string>

#include "Coordinate.h"
#include "Player.h"
#include "Client.h"


//*****************************************************************

class ClientPlayerListener : public Player
{
public:
	/** Constructor
     * @param[in] Player Name
     * @param[in] Player Symbol
     * @param[in] Player Color
     * @param[in] pointer to cursor which control player
     * @param[in] pointer to Server */
	ClientPlayerListener(const std::string name, const char symbol, const int color, Client * client);

	/** Virtual destructor*/
	virtual ~ClientPlayerListener();

	/** Virtual method for player (opponent) move (client is listening server moves)*/
	virtual Coordinate makeMove() override;

protected:
	/**Pointer to CLient*/
	Client * m_Client;
};


#endif /* __CLIENTPLAYER_LISTENER_H__ */