#ifndef __CLIENTPLAYER_H__
#define __CLIENTPLAYER_H__

#include <string>

#include "Coordinate.h"
#include "HumanPlayer.h"
#include "NCurCursor.h"
#include "Client.h"


//*****************************************************************

class ClientHumanPlayer : public HumanPlayer
{
public:
	/** Constructor
     * @param[in] Player Name
     * @param[in] Player Symbol
     * @param[in] Player Color
     * @param[in] pointer to cursor which control player
     * @param[in] pointer to Server */
	ClientHumanPlayer(const std::string & name, const char symbol, const int color,
					  NCurCursor * cursor  , Client * client);

	/** Virtual destructor*/
	virtual ~ClientHumanPlayer();

	/** Virtual method for making move (client sends Coordinate move to server)*/
	virtual Coordinate makeMove() override;

protected:
	/**pointer to client*/
	Client *m_Client;
	/**coordinate*/
	Coordinate coor;
};

#endif /* __CLIENTPLAYER_H__ */