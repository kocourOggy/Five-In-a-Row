#ifndef __MAIN_MENU_H__
#define __MAIN_MENU_H__

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <ncurses.h>

#include "constants.h"
#include "MenuInfo.h"
#include "OptionVal.h"
#include "OptionNumber.h"
#include "OptionString.h"
#include "Menu.h"



//*****************************************************************

class MainMenu : public Menu
{
public:

	/** Constructor
	 * @param[in] width menu
     * @param[in] height menu
     * @param[in] pointer to struct MenuInfo which is altered according to users option in menu*/
	MainMenu(const int x, const int y, MenuInfo * info);

	/**Virtual destructor*/
	virtual ~MainMenu();
	/**Add options to menu*/
	void initOptions();
	/**Let users to choose from one of the option*/
	void chooseOption();
	/**Show menu on screen*/
	void showMenu();

protected:
	/** Pointer to variable which is altered in menu*/
	MenuInfo * m_Info;
	/** Vector where we save every option which user can do*/
	std::vector< OptionVal* > m_Opt;
};



#endif /*__MAIN_MENU_H__ */