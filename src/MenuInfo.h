#ifndef __MENU_INFO_H__
#define __MENU_INFO_H__

#include <iostream>
#include <string>
#include "Client.h"
#include "Server.h"


//*****************************************************************

struct MenuInfo
{
	/**entered row*/
	int row;
	/**entered column*/
	int column;
	/**name of player 1*/
	std::string player1;
	/**name of player 2*/
	std::string player2;
	/**Level of AI*/
	int ai;
	/**Our tcp port*/
	int yourTCP;
	/**TCP port to connect (server TCP)*/
	int otherTCP;
	/**IP adress where we connect*/
	std::string IPAddress;
	/**Type game (0 - player vs player, 1 - player vs CPU)*/
	int typeGame;
	/**Number of already played moves*/
	int nmove;
	/**boolean value if we should load game (true) or not (false)*/
	bool loadGame;

};


#endif /*__MENU_INFO_H__ */