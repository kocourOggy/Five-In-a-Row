#ifndef __OPTION_H__
#define __OPTION_H__

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>



//*****************************************************************
class Option
{
public:

    /** Constructor
     * @param[in] Option name
     * @param[in] Option index */
	Option(const std::string & text, const int num);

	/** Virtual destructor*/
	virtual ~Option();

    /** Method for getting option text
     * @return returns string containing text*/
	std::string getText() const;

    /** Method for getting option text size
     * @return returns number of size of text*/
	int getLen() const;


protected:
	/** variable for saving text*/
	std::string m_Text;
	/** variable for ordering option in menu*/
	int m_Order;
	
};


#endif /*__OPTION_H__ */