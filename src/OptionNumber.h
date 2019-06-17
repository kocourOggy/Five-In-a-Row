#ifndef __OPTION_NUM_H__
#define __OPTION_NUM_H__

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <ncurses.h>

#include "OptionVal.h"



//*****************************************************************
class OptionNumber : public OptionVal
{
public:
	/** Constructor
     * @param[in] Option name
     * @param[in] Option index
     * @param[in] number of digit to be readed during input from user
     * @param[in] allowed range min
     * @param[in] allowed range max*/
	OptionNumber(int * realVal, const std::string & text, const int num, const int n, const int min, const int max);
	
	/**Virtual destructor*/
	virtual ~OptionNumber();

	/**Method for reading input
	* @return returns bool if input is valid*/
	virtual bool readInput();

	/**Method for changing real value*/
	virtual void changeRealVal();

	/**Method for changing value
	* @return returns value of option as a string (for easier showing its value in screen)*/
	virtual std::string getRealVal();

	/**Method which tell whether input is number
	* @return returns true if input is number*/
	bool isNumber() const;

	/**Method which control if number is in min max range
	* @return returns true if number is in range*/
	bool inRange() const;

	/**Getter which tell us the number
	* @return returns number as int*/
	int getNum() const;


protected:
	/** variable which is altered in menu*/
	int * m_RealVal;
	/** variable for saving readed number*/
	int m_Number;
	/** Entered maximum from range*/
	int m_Max;
	/** Entered minimum from range*/
	int m_Min;
};


#endif /*__OPTION_NUM_H__ */