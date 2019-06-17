 //*****************************************************************

#include "Menu.h"

//*****************************************************************

Menu::Menu(const int x, const int y)
{
	m_Size.m_Row = x;
	m_Size.m_Column = y;
}

Menu::~Menu()
{

}

void Menu::clearLine(const int line)
{
	for (int col = 0; col < m_Size.m_Column; ++col)
	{
		mvaddch(line, col, ' ');
	}
}

void Menu::clearMenu()
{
	for (int line = 0; line < m_Size.m_Row; ++line)
	{
		clearLine(line);
	}
}