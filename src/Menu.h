#ifndef __MENU_H__
#define __MENU_H__

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <ncurses.h>

#include "Coordinate.h"
#include "OptionVal.h"



//*****************************************************************

class Menu
{
public:

	/** Constructor
	 * @param[in] width menu
     * @param[in] height menu*/
	Menu(const int x, const int y);

	/**VIrtual destructor*/
	virtual ~Menu();

	/**Method clears concrete row
	 * @param[in] width menu*/
	void clearLine(const int line);

	/**Method clears whole menu*/
	void clearMenu();

protected:
	/** Variable for savind size of menu*/
	Coordinate m_Size;
	/** Variable for smenu title*/
	std::string m_Title;

};


#endif /*__MENU_H__ */