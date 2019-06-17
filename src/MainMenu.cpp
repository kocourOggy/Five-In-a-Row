 //*****************************************************************

#include "MainMenu.h"

//*****************************************************************

MainMenu::MainMenu(const int x, const int y, MenuInfo * info)
:	Menu::Menu(x, y)
{
	m_Info = info;
	initOptions();
}

MainMenu::~MainMenu()
{
	for (auto itr = m_Opt.begin(); itr != m_Opt.end(); ++itr)
	{
		delete *itr;
	}

}

void MainMenu::initOptions()
{

	m_Opt.push_back( new OptionNumber( &(m_Info->row), "row (5-35): ", 0, 2, 5, 35) );
	m_Opt.push_back( new OptionNumber( &(m_Info->column),"column (5-35): ", 1, 2, 5, 35) );
	m_Opt.push_back( new OptionString( &(m_Info->player1),"Player 1 name: ", 2, 10) );
	m_Opt.push_back( new OptionString( &(m_Info->player2), "Player 2 name: ", 3, 10) );
	m_Opt.push_back( new OptionNumber( &(m_Info->ai), "difficulty AI (1 = 'normal', 2 = 'hard'): ", 4, 1, 2, 10) );
	m_Opt.push_back( new OptionNumber( &(m_Info->yourTCP), "your TCP port (2000-9999): ", 5, 4, 2000, 9999) );
	m_Opt.push_back( new OptionNumber( &(m_Info->otherTCP), "TCP port to connect (2000-9999): ", 6, 4, 2000, 9999) );
	m_Opt.push_back( new OptionString( &(m_Info->IPAddress), "IP adresss to connect: ", 7, 15) );
}

void MainMenu::chooseOption()
{
	int ch = ' ';
	uint i = 0;
	while (ch != 'q')
	{
		curs_set(0);
		noecho();

		ch = getch();
		
		if ( !isdigit(ch) )	continue;
		i = ch - 48;
		if ( i >= m_Opt.size() ) continue;
		//-------------------------------
		mvaddch(i+1, 1, '*');
		refresh();

		move( i+1, 2 + m_Opt[i]->getLen() );
		curs_set(1);
		echo();

	 	if ( m_Opt[i]->readInput() )
 		{
 			// do something
 			m_Opt[i]->changeRealVal();
 			mvprintw( i+1, m_Size.m_Column-20, "[ %s ]", m_Opt[i]->getRealVal().c_str() );
 			
 		}
 		clearLine(i+1);
 		mvprintw( i+1, 2, "%s", m_Opt[i]->getText().c_str() );
 		mvprintw( i+1, m_Size.m_Column-20, "[ %s ]", m_Opt[i]->getRealVal().c_str() );
 		
 		refresh();
 		continue;	
	}
}

void MainMenu::showMenu()
{
	for (uint i = 0; i < m_Opt.size(); ++i)
	{
		mvprintw( i+1, 2, "%s", m_Opt[i]->getText().c_str() );
		mvprintw( i+1, m_Size.m_Column-20, "[ %s ]", m_Opt[i]->getRealVal().c_str() );
	}
}