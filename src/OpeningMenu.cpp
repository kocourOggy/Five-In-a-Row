 //*****************************************************************

#include "OpeningMenu.h"

//*****************************************************************

OpeningMenu::OpeningMenu(const int x, const int y, MenuInfo * info)
:	Menu::Menu(x, y), m_InnerMenu(x, y, info)
{
	m_Info = info;

}

OpeningMenu::~OpeningMenu()
{
	for (auto itr = m_Opt.begin(); itr != m_Opt.end(); ++itr)
	{
		delete *itr;
	}
}

void OpeningMenu::initOptions()
{
 	m_Info->row = ROW;
	m_Info->column = COLUMN;
	m_Info->player1 = PLAYER1_NAME;
	m_Info->player2 = PLAYER2_NAME;
	m_Info->ai = AI;
	m_Info->yourTCP = 	YOUR_TCP;
	m_Info->otherTCP = OTHER_TCP;
	m_Info->IPAddress = IPADDRES;
	m_Info->nmove= 0;
	m_Info->typeGame = 0;
	m_Info->loadGame = false;

	m_Opt.push_back( new Option("Player 1 vs. Player 2", 0) );
	m_Opt.push_back( new Option("Player 1 vs. AI", 1) );
	m_Opt.push_back( new Option("TCPServer (you) vs. TCPClient", 2) );
	m_Opt.push_back( new Option("TCPClient(you) vs. TCPServer", 3) );
	m_Opt.push_back( new Option("Load game", 4) );
	m_Opt.push_back( new Option("Game settings", 5) );
}

void OpeningMenu::writeTitle()
{
	for (int i = 0; i < 10; ++i)
	{
		mvprintw(0 + m_Opt.size() + i + 5, (MENU_COL/2)-33, "%s", TITLE[i].c_str());
	}

	for (int i = 0; i < 20; ++i)
	{
		mvprintw(MENU_ROW - 25 + i, (MENU_COL/2)-20, "%s", LOGO[i].c_str());
	}
}

void OpeningMenu::showMenu()
{
	/*init_pair(1, TEXT_COLOR, BACKGROUND_COLOR);
	attron(COLOR_PAIR(1));*/
	for (uint i = 0; i < m_Opt.size(); ++i)
	{
		mvprintw( i+1, 2, "%s", m_Opt[i]->getText().c_str() );
	}
	/*attroff(COLOR_PAIR(1));*/

	writeTitle();


}

int OpeningMenu::chooseOption()
{
	int ch = ' ';
	uint i = 0;
	while (1)
	{
		curs_set(0);
		noecho();

		ch = getch();
		if (ch == 'q') return m_Opt.size();
		
		if ( !isdigit(ch) )	continue;
		i = ch - 48;
		if ( i >= m_Opt.size() ) continue;
		//-------------------------------
		mvaddch(i+1, 1, '*');
		refresh();

		//another menu
		if ( i == 5 )
		{
			clearMenu();
			writeTitle();
			refresh();
 			
 			m_InnerMenu.showMenu();
 			m_InnerMenu.chooseOption();
 			m_InnerMenu.clearMenu();

 			showMenu();
		}
		else
		{
 			break;
 		}
	}
	clearMenu();
	return i;
}