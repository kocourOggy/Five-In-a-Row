#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ncurses.h>
#include <string>
#include <random>

#include "constants.h"
#include "MenuInfo.h"
#include "ScreenInfo.h"
#include "Coordinate.h"

#include "MoveAdvisor.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "CPUPlayer.h"
#include "Server.h"
#include "Client.h"
#include "ServerHumanPlayer.h"
#include "ClientHumanPlayer.h"
#include "ServerPlayerListener.h"
#include "ClientPlayerListener.h"

#include "Terminal.h"
#include "NCurCursor.h"
#include "NCurGameBoard.h"
#include "GameBoard.h"

#include "Option.h"
#include "OptionVal.h"
#include "OptionNumber.h"
#include "OptionString.h"

#include "Menu.h"
#include "OpeningMenu.h"
#include "MainMenu.h"
#include "CFile.h"

#include "Game.h"

/**
 * @mainpage Tic-Tac-Toe
 *
 * <b>Program description:</b>
 * - Tic-tac-toe (also known as Noughts and crosses or Xs and Os) is a game
 *   for two players, X and O, who take turns marking the spaces in a grid.
 *   Classic Noughts and crosses is played on 3x3 grid and the goal of a game is to get
 *   3 stones in a row. Other variation of game (called Gomoku, known as 5-in-line) is
 *   on the other way played with 5 stones in a row.
 *   The player who succeeds in placing three (or five) of their marks in a horizontal, vertical, or
 *   diagonal row wins the game. Since classic Tic-Tac-Toe 3x3 is not too complex
 *   we focus mainly on variation with 5 marks in a row.
 *
 * <b>Types of Game:</b>
 *
 * Player vs. AI
 * - There is two type of AI - Level 1 and Level 2. Level 1 search for opponent winning moves
 *   and its own winning moves and choose best move according to intersection opponents a its own moves.
 *   Level 2 work the same way, but rather than defend, AI prefers attacks, since it is better to get 5
 *   in line yourself than to prevent the opponent from getting it
 *
 * Player vs. Player on PC
 * - Simply two players are playing on one board on one pc.
 *
 * Player vs. Player on Network
 * - One player is hosting and the second is a client that joins to the hosted player. It works
 *   locally with information about IP and port via game menu, where you can change it.
 *   */


/** Function to open main menu for choosing which type of game is gonna be played
     * @param[in] parameter which is initialize inside the function according Menu value
     * @return returns the number of chosen option*/
int menuHandler(MenuInfo & menuInfo);

/** Function which operates with menu option and set information for a future play
	* @param[in] parameter from menuHandler to decide what game we should play
  * @param[in]  parameter which is initialize inside the function according Menu value
  * @return returns true when we can continue to play game if false we go back to menu or end program*/
bool optionHandler(int choose, MenuInfo & menuInfo, Server & pServer, Client & pClient);

/** Function which operates with menu option and set information for a future play
	* @param[in] parameter menuInfo where we operate with information for chosen game
  * @param[in]  set Server variable
  * @param[in]  set Client variable */
void gameHandler(MenuInfo & menuInfo, Server & pServer, Client &pClient);



void gameHandler(MenuInfo & menuInfo, Server & pServer, Client &pClient)
{
	ScreenInfo screenInfo;
	screenInfo.computeGameBoard(menuInfo.row, menuInfo.column);


	Game game( &screenInfo, &menuInfo);
	//game.setTerminal();
	// it resize terminal but after init ncurses it sometime make a mess
	//(we resize terminal only at the beginning of program)
	game.setGameScreen();
	game.startGame(pServer, pClient);
	getch();
}

int menuHandler(MenuInfo & menuInfo)
{
	OpeningMenu menu(MENU_ROW, MENU_COL, &menuInfo);
	menu.initOptions();
	menu.clearMenu();
	menu.showMenu();
	int choose = menu.chooseOption();
	menu.clearMenu();
	refresh();

	return choose;
}

bool optionHandler(int choose, MenuInfo & menuInfo, Server & pServer, Client & pClient)
{
	if (choose == 0) { menuInfo.typeGame = 0; return true; }
	//----------------------------------------------------

	else if (choose == 1) { menuInfo.typeGame = 1; return true; }
	//----------------------------------------------------

	else if (choose == 2) // Server vs Client
	{
		menuInfo.typeGame = 2;
		try
		{
			mvprintw(0,0, "Waiting for client.");
			refresh();			
			pServer.setServer(std::to_string(YOUR_TCP));
			pServer.ReadytoConnect();
			pServer.sendCoor( Coordinate(menuInfo.row, menuInfo.column) );
		}
		catch(const char* str)
		{
			mvprintw(0,1, "%s", str);
			getch();
			return false;
			// terminate game and return to menu
		}
		mvprintw(0,0, "                   ");
		return true;

	}
	//----------------------------------------------------

	else if (choose == 3) // Client vs Server
	{
		menuInfo.typeGame = 3;
		Coordinate sizeServerBoard;
		try
		{
			mvprintw(0,0, "Waiting for server.");
			refresh();
			pClient.setClient();
			pClient.connectToServer(IPADDRES, std::to_string(OTHER_TCP));
			sizeServerBoard = pClient.listenCoor();
			menuInfo.row = sizeServerBoard.m_Row;
			menuInfo.column = sizeServerBoard.m_Column;

		}
		catch(const char* str)
		{
			mvprintw(0,1, "%s", str);
			getch();
			return false;
			// terminate game and return to menu
		}
		mvprintw(0,0, "                   ");
		return true;
	}
	//----------------------------------------------------

	else if (choose == 4) // loading data
	{
		CFile file;
		try
		{
			file.controlData();
		}
		catch(const char * str)
		{
			mvprintw(0,1, "%s", str);
			getch();
			menuInfo.loadGame = false;
			return false;
		}

		file.loadBasicData(menuInfo);
		menuInfo.loadGame = true;
		return true;
	}

	else if (choose == 6)
	{
		menuInfo.typeGame = END;
		return true; // terminates the whole program because user is leaving
	}
	//----------------------------------------------------

	return false;
	//----------------------------------------------------
}


int main()
{
	// INIT SCREEN FOR MENU
	Terminal menuScreen;
	menuScreen.resize(MENU_ROW, MENU_COL);

	Server pServer;
	Client pClient;

	initscr();
   	cbreak();
   	keypad(stdscr, TRUE);
	while(1)
	{


	MenuInfo menuInfo;


	int choose = menuHandler(menuInfo);



	if ( !optionHandler(choose, menuInfo, pServer, pClient) ) continue;
	if (menuInfo.typeGame == END) break;

	gameHandler(menuInfo, pServer, pClient);

	}
	endwin();

	menuScreen.resizeToOrig();
	
	
	return 0;
}

