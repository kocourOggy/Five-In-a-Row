 //*****************************************************************

#include "Game.h"

//******************************************************************

Game::Game(ScreenInfo * screenInfo, MenuInfo * menuInfo)
:
    m_GameData(menuInfo->row, menuInfo->column )
{
   m_ScrInfo = screenInfo;
   m_MenuInfo = menuInfo;

   m_Winner = NULL;

   if (menuInfo->loadGame)
   {
      try{
      (!file.loadVec2D(m_GameData.m_Board)); // break;
      (!file.loadVec3D(m_GameData.m_ValueBlock));// break;
      (!file.loadVec4D(m_GameData.m_LineStone));// break;
      }
      catch(const char* str){
         endwin();
         std::cout << "ne v pohode" << std::endl;
         std::cout << str << std::endl;
         initscr();
      }


   }
}

Game::~Game()
{
   
   // gameScreen.resizeToOrig();
   delete m_Players[0];
   delete m_Players[1];
}

/*
void Game::setTerminal()
{
   
   Terminal gameScreen;
   endwin();
   std::cout << "row: " << m_ScrInfo->rowGameScreen << std::endl;
   std::cout << "col: " << m_ScrInfo->colGameScreen << std::endl;
   gameScreen.resize( m_ScrInfo->rowGameScreen, m_ScrInfo->colGameScreen );
   initscr();
   
}*/

void Game::setGameScreen()
{
   /*initscr();
   cbreak();
   keypad(stdscr, TRUE);*/
   curs_set(1);
   refresh();

   m_GameBoard.createWin(*m_ScrInfo);
   if (m_MenuInfo->loadGame)  m_GameBoard.loadBoard(m_GameData.m_Board);
   else                       m_GameBoard.fillBoard();

   m_GameBoard.updateWin();
}



void Game::startGame(Server & server, Client & client)
{

   // INIT PLAYERS
   NCurCursor cursorP1(&m_GameBoard, *m_ScrInfo, &m_GameData, 1 ); // 1 = CROSS
   NCurCursor cursorP2(&m_GameBoard, *m_ScrInfo, &m_GameData, 2 ); // 2 = CIRCLE

   /*vect4D copy1( m_MenuInfo->row,
   std::vector< std::vector < std::vector<int> > >(m_MenuInfo->column,
   std::vector< std::vector<int> >(4,
   std::vector<int>(3, 666) ) ) );

   vect3D copy2 (m_MenuInfo->row,
   std::vector< std::vector<int> > (m_MenuInfo->column,
   std::vector <int>(3, 666) ) );*/


   if (m_MenuInfo->typeGame == 3) // Client vs Server
   {
      m_Turn = 1;
      m_Players[0] = new ClientHumanPlayer("ClientPlayer", CROSS, PLAYER1_COLOR, &cursorP1, &client); // our moves
      m_Players[1] = new ClientPlayerListener("ServerPlayer", CIRCLE, PLAYER2_COLOR, &client); // opponent moves
   }
   else if (m_MenuInfo->typeGame == 2) // Server vs Client
   {
      m_Turn = 0;
      m_Players[0] = new ServerHumanPlayer("ServerPlayer", CIRCLE, PLAYER1_COLOR, &cursorP2, &server); // our moves
      m_Players[1] = new ServerPlayerListener("ClientPlayer", CROSS, PLAYER2_COLOR, &server); // opponent moves    
   }
   else if (m_MenuInfo->typeGame == 1) // Player 1 vs AI
   {
      int attack = ATTACK;
      if (m_MenuInfo->ai == 2) attack = 4;
      m_Turn = 1;
      m_Players[0] = new HumanPlayer(m_MenuInfo->player1, CROSS, PLAYER1_COLOR, &cursorP1);
      m_Players[1] = new CPUPlayer("CPU Player", CIRCLE, PLAYER2_COLOR, &m_GameData, attack);
      // to do
   }
   else if (m_MenuInfo->typeGame == 0) // Player 1 vs. Player 2
   {
      m_Turn = 1;
      m_Players[0] = new HumanPlayer(m_MenuInfo->player1, CROSS, PLAYER1_COLOR, &cursorP1);
      m_Players[1] = new HumanPlayer(m_MenuInfo->player2, CIRCLE, PLAYER2_COLOR, &cursorP2);
   }



   int totalMoves = (m_MenuInfo->row * m_MenuInfo->column);
   int nMove = m_MenuInfo->nmove;
   m_Turn += m_MenuInfo->nmove; m_Turn %= 2;


   // START GAME
   //-------------------------------------------------------------------------   

  /* int nMoves = (m_MenuInfo->row * m_MenuInfo->column) - m_MenuInfo->nmove;
   m_Turn += m_MenuInfo->nmove; m_Turn %= 2;*/
   Coordinate coor;
   m_GameBoard.updateWin();
   refresh();
   
   while (nMove < totalMoves)
   {
      /*init_pair(1, BACKGROUND_COLOR, m_Players[m_Turn]->getColor());
      wattron(m_GameBoard.m_WGameBoard, COLOR_PAIR(1));*/
      cleanLine(m_ScrInfo->textPosRow);
      mvprintw(m_ScrInfo->textPosRow, m_ScrInfo->textPosCol, "Waiting for move ( %c ): %s",
               m_Players[m_Turn]->getSymbol(), (m_Players[m_Turn]->getName().c_str()));
      cleanLine(m_ScrInfo->textPosRow + 1);
      mvprintw(m_ScrInfo->textPosRow + 1, m_ScrInfo->textPosCol, "Moves: %d", nMove);
      refresh();



      try { coor = m_Players[m_Turn]->makeMove(); }
      catch(const char * str)
      {
            
            m_Winner = m_Players[(m_Turn+1) % 2];
            break;
      }

      // player request to save game
      //-----------------------------------------------------
      if ( m_Players[m_Turn]->getState() == STATE_SAVE )
      {
      try
         {
            if (m_MenuInfo->typeGame == 2 || m_MenuInfo->typeGame == 3)
            {
               m_MenuInfo->typeGame = 0;
            }

            m_MenuInfo->nmove = nMove;
            file.saveBasicData(*m_MenuInfo);
            file.saveVec2D(m_GameData.m_Board);
            file.saveVec3D(m_GameData.m_ValueBlock);
            file.saveVec4D(m_GameData.m_LineStone);
            /*file.loadVec4D(copy1);
            file.loadVec3D(copy2);
            if (!control4D(m_GameData.m_LineStone, copy1)) {break; curs_set(0); }
            if (!control3D(m_GameData.m_ValueBlock, copy2)) {break; curs_set(0); }*/
         }
         catch (const char * str)
         {
            
            std::cout << str << std::endl;
            break;
         }
         continue;
      }

      // player request to quit game
      //--------------------------------------------------------
      if ( m_Players[m_Turn]->getState() == STATE_QUIT )
      {
         m_Winner = m_Players[(m_Turn+1) % 2];
         break;
      }

      if ( ! m_GameData.validMove(coor) ) continue;

      m_GameData.writeStone(*m_Players[m_Turn], coor);
      m_GameBoard.writeMove(*m_Players[m_Turn], coor);
      refresh();
      if ( m_GameData.updateLine(*m_Players[m_Turn], coor) )
      {
         m_Winner = m_Players[m_Turn];
         break;
      }
         endwin();

      ++nMove;
      ++m_Turn; m_Turn %= 2;
   }

   if (m_Winner)
   {
      cleanLine(m_ScrInfo->textPosRow);
      mvprintw(m_ScrInfo->textPosRow, m_ScrInfo->textPosCol,
               "%s ( %c )  - WIN!!!", m_Winner->getName().c_str(), m_Winner->getSymbol());
      mvprintw(m_ScrInfo->textPosRow + 1, m_ScrInfo->textPosCol, "Moves: %d", nMove);
      refresh();
   }
   if (m_Winner == NULL && nMove >= totalMoves)
   {
      cleanLine(m_ScrInfo->textPosRow);
      refresh();
      mvprintw(m_ScrInfo->textPosRow, m_ScrInfo->textPosCol,
               "IT IS A TIE!!!");
      mvprintw(m_ScrInfo->textPosRow + 1, m_ScrInfo->textPosCol, "Moves: %d", nMove); 
      refresh(); 
   }
   refresh();
   getch();

   /*endwin();
   std::cout << "celkem: "  << (m_MenuInfo->row * m_MenuInfo->column) << std::endl;
   std::cout << "m_turn: "  << m_Turn << std::endl;
   std::cout << "left menu nmoves: "  << m_MenuInfo->nmove << std::endl;
   initscr();*/
}


void Game::cleanLine(int row)
{
   std::string line;
   for (int i = 0; i < m_ScrInfo->colGameScreen; ++i)
   {
      line += " ";
   }
   mvprintw(row, 0, "%s", line.c_str());
   refresh();
}

bool Game::control4D(vect4D & orig, vect4D copy)
{
   endwin();
   bool fool = true;
   uint X = orig.size();
   uint Y = (orig[0]).size();
   uint Z = (orig[0][0]).size();
   uint Q = (orig[0][0][0]).size();
   for (uint i = 0; i < X; ++i)
   {
      for (uint j = 0; j < Y; ++j)
      {
         for (uint k = 0; k < Z; ++k)
         {
            for (uint l = 0; l < Q; ++l)
            {
               if ( orig[i][j][k][l]  != copy[i][j][k][l] ) 
                  {
                     std::cout << i << ":" << j << ":" << k << ":" << l << std::endl;
                     std::cout << "copy: " << copy[i][j][k][l] << std::endl;
                     fool = false;                     
                  }
            }
         }

      }
   }
   initscr();
   return fool;
}

bool Game::control3D(vect3D & orig, vect3D copy)
{
   endwin();
   bool fool = true;
   uint X = orig.size();
   uint Y = (orig[0]).size();
   uint Z = (orig[0][0]).size();
   for (uint i = 0; i < X; ++i)
   {
      for (uint j = 0; j < Y; ++j)
      {
         for (uint k = 0; k < Z; ++k)
         {
            

               if ( orig[i][j][k]  != copy[i][j][k] ) 
                  {
                     std::cout << i << ":" << j << ":" << k  << std::endl;
                     std::cout << "copy: " << copy[i][j][k] << std::endl;
                     fool = false;
                     
                  }
            
         }

      }
   }
   initscr();
   return fool;
}

/*   std::vector< std::vector<char> > m_Board;

   std::vector <int> m_Values;

   std::vector <Coordinate> m_Dir;

   vect3D m_ValueBlock;
   vect4D m_LineStone; // [x,y, direction, symbol]*/
