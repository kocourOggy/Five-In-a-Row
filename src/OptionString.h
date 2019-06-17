#ifndef __OPTION_STRING_H__
#define __OPTION_STRING_H__

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <ncurses.h>

#include "OptionVal.h"



//*****************************************************************
class OptionString  : public OptionVal
{
public:

	/** Constructor
	 * @param[in] Pointer to variable which is altered in menu
     * @param[in] Option name
     * @param[in] Option index
     * @param[in] number of characters which be readed*/
	OptionString(std::string * realVal, const std::string & text, const int num, const int n);

	/**Virtual destructor*/
	virtual ~OptionString();

	/**Method for reading input
	* @return returns bool if input is valid*/
	virtual bool readInput();

	/**Method for changing real value*/
	virtual void changeRealVal();


	/**Method for changing value
	* @return returns value of option as a string (for easier showing its value in screen)*/
	virtual std::string getRealVal();

	/**Method for making string from buffer[]
	* @return returns buffer as a string (for easier work)*/
	std::string getString() const;


protected:
	/**Pointer to a variable which is altered in menu*/
	std::string * m_RealVal;
};

#endif /*__OPTION_STRING_H__ */