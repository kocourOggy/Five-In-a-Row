#ifndef __OPENING_MENU_H__
#define __OPENING_MENU_H__

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <ncurses.h>

#include "MenuInfo.h"
#include "OptionVal.h"
#include "OptionNumber.h"
#include "OptionString.h"
#include "Menu.h"
#include "MainMenu.h"



//*****************************************************************

class OpeningMenu : public Menu
{
public:
	/** Constructor
	 * @param[in] width menu
     * @param[in] height menu
     * @param[in] pointer to struct MenuInfo which is altered according to users option in menu*/
	OpeningMenu(const int x, const int y, MenuInfo * info);

	/**Virtual Constructor*/
	virtual ~OpeningMenu();

	/**Add options to menu*/
	void initOptions();

	/**Let users to choose from one of the option*/
	int chooseOption();
	/**Show menu in screen*/
	void showMenu();
	/**write menu title*/
	void writeTitle();

protected:
	/** Opening menu contains also menu with settings*/
	MainMenu m_InnerMenu;
	/** Pointer to variable which is altered in menu*/
	MenuInfo * m_Info;
	/** Vector where we save every option which user can do*/
	std::vector< Option* > m_Opt;
};




#endif /*__OPENING_MENU_H__ */