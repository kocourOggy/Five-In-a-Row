#ifndef __OPTION_VAL_H__
#define __OPTION_VAL_H__

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>

#include "Option.h"



//*****************************************************************
class OptionVal : public Option
{
public:

    /** Constructor
     * @param[in] Option name
     * @param[in] Option index
     * @param[in] number of digit to be readed during input from user */
	OptionVal(const std::string & text, const int num, const int n);

	/*Virtual destructor**/
	virtual ~OptionVal();

	/**Abstract method for reading input
	* @return returns bool if input is valid*/
	virtual bool readInput() =0;
	/**Abstract method for changing value*/
	virtual void changeRealVal() =0;
	/**Abstract method for changing value
	* @return returns value of option as a string (for easier showing its value in screen)*/
	virtual std::string getRealVal() =0;

protected:
	/**Variable for number of digit which we catch*/
	int m_ReadN;
	/** Recv buffer*/
	char m_Buffer[20];
};


#endif /*__OPTION_VAL_H__ */