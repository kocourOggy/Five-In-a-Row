#ifndef __TERMINAL_H__
#define __TERMINAL_H__
 
#include <unistd.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <string>
#include <cstdio>
#include <cstdlib>

#include "Coordinate.h"

//*****************************************************************

class Terminal
{
public:
	/** Constructor. */
	Terminal();
	/** Destructor. */
	~Terminal();
	
	/** Method to resize terminal
     * @param[in] how many rows
     * @param[in] how many columns */
	void resize(const int x, const int y);

	/** If we resize menu, we should also turn it back at the end of program.*/
	void resizeToOrig();
	/** Find out size of terminal.*/
	Coordinate getSize(void);

private:
	/** Size of terminal before resizing.*/
	Coordinate m_OrigTermSize;
	/** New size of terminal.*/
	Coordinate m_NewTermSize;
};

#endif /* __TERMINAL_H__ */