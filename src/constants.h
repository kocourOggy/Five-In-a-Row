#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

#include <string>
 
//*****************************************************************

// GAMEBOARD INFO

/** Number of row in grid. */
static const int ROW = 20;
/** Number of column in grid. */
static const int COLUMN = 25;
/** How many winning row */
static const int SIZELINE = 5;

/** Mas number of row in grid. */
static const int MAXROW = 35;
/** Mas number of column in grid. */
static const int MAXCOLUMN = 35;

/** Free space in game grid. */
static const int BOARD_EDGE_HOR = 1;
/** Free space in game grid. */
static const int BOARD_EDGE_VER = 2;
/** Position of game grid in screen */
static const int POS_BOARD_X = 1;
/** Position of game grid in screen */
static const int POS_BOARD_Y = 1;

/** Border for game board. */
static const char SCREEN_BORDER_HOR = '-';
/** Border for game board. */
static const char SCREEN_BORDER_VER = '|';
/** Border for game board. */
static const char LU_CORN = '+';
/** Border for game board. */
static const char RU_CORN = '+';
/** Border for game board. */
static const char LD_CORN = '+';
/** Border for game board. */
static const char RD_CORN = '+';

/** Symbol for empty space. */
static const char BLANK_SPACE = ' ';
/** Symbol for empy block in grid. */
static const char BLANK_SYMBOL = '.';


// MAIN SCREEN

/** Menu lines. */
static const int MENU_ROW = 50;
/** Menu columns. */
static const int MENU_COL = 90;
/** Size of edge from the main screen. */
static const int SCREEN_EDGE = 2;


// STONE SYMBOLS

/** Symbol for cross. */
static const char CROSS = 'x';
/** Symbol for circle. */
static const char CIRCLE = 'o';


// NETWORK
/** Size of buffer for receiving information via network. */
static const int BUFSIZE1 = 20;
/** Size of buffer for receiving coordinate (moves) via network. */
static const int BUFSIZE2 = 2;
/** How long should client or server wait than disconnect. */
static const double WAITTIME = 30; // seconds
/** Origin parameter for our TCP. */
static const int YOUR_TCP = 3000;
/** Origin parameter for TCP to connect. */
static const int OTHER_TCP = 3000;
/** Ip adress to connect. */
static const std::string IPADDRES = "127.0.0.1";

// FILES
/** File path for loading save data. */
static const std::string FILE_BASIC = "basic.txt";
/** File path for loading save data. */
static const std::string FILE_VECT2 = "vec2D.txt";
/** File path for loading save data. */
static const std::string FILE_VECT3 = "vec3D.txt";
/** File path for loading save data. */
static const std::string FILE_VECT4 = "vec4D.txt";

/** Number which mean end of program. */
static const int END = 10;


// PLAYER PROPERTIES

/** Level of AI. */
static const int AI = 1;
/** Name player 1. */
static const std::string PLAYER1_NAME = "player 1";
/** Name player 2. */
static const std::string PLAYER2_NAME = "player 2";

/** Symbol for player state which means do nothing. */
static const char STATE_NOTHING = ' ';
/** Symbol which means that player is quiting game. */
static const char STATE_QUIT = 'q';
/** Symbol which is used for save game. */
static const char STATE_SAVE = 's';

// AI
/** Origin variable for AI agresivity. */
static const int ATTACK = 0;

/** Player 1 color. */
static const int PLAYER1_COLOR = 3;
/** Player 1 color. */
static const int PLAYER2_COLOR = 6;
/** Gameboard color. */
static const int GAMEBOARD_COLOR = 7;
/** Background color. */
static const int BACKGROUND_COLOR = 0;
/** Text color. */
static const int TEXT_COLOR = 6;
/** Title color. */
static const int TITLE_COLOR = 6;

/** Array of strings for logo. */
static const std::string LOGO[] =
{

{"               |           |"},
{"               |           |"},
{"------------------------------------------"},
{"       oooo    |  xx  xx   |   oooo"},
{"      o    o   |    xx     |  o    o"},
{"      o    o   |    xx     |  o    o"},
{"       oooo    |  xx  xx   |   oooo"},
{"------------------------------------------"},
{"      xx  xx   |   oooo    |   oooo"},
{"        xx     |  o    o   |  o    o"},
{"        xx     |  o    o   |  o    o"},
{"      xx  xx   |   oooo    |   oooo"},
{"------------------------------------------"},
{"       oooo    |  xx  xx   |  xx  xx"},
{"      o    o   |    xx     |    xx"},
{"      o    o   |    xx     |    xx"},
{"       oooo    |  xx  xx   |  xx  xx"},
{"------------------------------------------"},
{"               |           |"},
{"               |           |"}

};

/** Array of strings for title. */
static const std::string TITLE[] =
{
{"=================================================================="},
{"\n"},
{"  ----------  --     ------      ----------   ----      ------  "},
{"  ----------  ||    ||------     ----------  ------    ||------"},
{"      ||      ||   ||--              ||     ||    ||  ||--"},
{"      ||      ||   ||--              ||     ||----||  ||--"},
{"      ||      ||    ||------         ||     ||----||   ||------"},
{"      ||      ||     ------          ||     ||    ||    ------"},
{"\n"},
{"=================================================================="},
/*
{"----------   ----      ------  "},
{"----------  ------    ||------"},
{"    ||     ||    ||  ||--"},
{"    ||     ||----||  ||--"},
{"    ||     ||----||   ||------"},
{"    ||     ||    ||    ------"}
*/
};


#endif /*__CONSTANTS_H__*/