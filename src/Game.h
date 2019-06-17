#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include <ncurses.h>
#include <string>
#include <random>


#include "constants.h"
#include "MenuInfo.h"
#include "ScreenInfo.h"
#include "Coordinate.h"

#include "Terminal.h"
#include "NCurCursor.h"
#include "NCurGameBoard.h"
#include "GameBoard.h"
#include "CFile.h"

#include "Player.h"
#include "HumanPlayer.h"
#include "CPUPlayer.h"
#include "Server.h"
#include "Client.h"
#include "ServerHumanPlayer.h"
#include "ClientHumanPlayer.h"
#include "ServerPlayerListener.h"
#include "ClientPlayerListener.h"

#include "MoveAdvisor.h"

#include "Coordinate.h"

//*****************************************************************

class Game
{
public:
    /** Constructor
     * @param[in] screenInfo for setting the game
     * @param[in] menuInfo for setting the game */
   Game(ScreenInfo * screenInfo, MenuInfo * menuInfo);
   /**Destructor*/
   ~Game();

  /* void setTerminal();*/

   /** Method which set players, vectors that are needed for game
   * @param[in] reference to server if it is needed
   * @param[in] reference to client if it is needed */
   void startGame(Server & server, Client & client);

   /**Method create game board window and make cursor visible*/
   void setGameScreen();

   /** Method erase specific line
    * @param[in] row which will be cleaned */
   void cleanLine(int row);

   /**Method control whether we save correct game data
    * @return returns true if control vector is equal to current vector in game*/
   bool control4D(vect4D & orig, vect4D copy);
   /**Method control whether we save correct game data
    * @return returns true if control vector is equal to current vector in game*/
   bool control3D(vect3D & orig, vect3D copy);



private:
   /**Pointer to screen info*/
   ScreenInfo * m_ScrInfo;
   /**Pointer to menu info*/
   MenuInfo * m_MenuInfo;
   /**Object where data as all played moves with position and symbol are saved*/
   GameBoard m_GameData;
   /**Object for drawing a window game board*/
   NCurGameBoard m_GameBoard;
   /**Object for saving game*/
   CFile file;
   /**Array of pointer to player which are playing game*/
   Player* m_Players[2];
   /**Pointer to winner of game*/
   Player* m_Winner;
   /**Variable which says who is going to do a move on board*/
   int m_Turn;

};



#endif /* __GAME_H__ */
//--------------------------------------------------------------------

