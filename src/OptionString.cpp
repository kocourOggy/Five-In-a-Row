 //*****************************************************************

#include "OptionString.h"

//*****************************************************************

OptionString::OptionString(std::string * realVal, const std::string & text, const int num, const int n)
:	OptionVal::OptionVal(text, num, n)
{
	m_RealVal = realVal;
}

OptionString::~OptionString()
{

}

bool OptionString::readInput() // virtual
{
	echo();
	getnstr(m_Buffer, m_ReadN);
	return 1;
}

std::string OptionString::getString() const
{
	return std::string(m_Buffer);
}

void OptionString::changeRealVal()
{
	* m_RealVal = getString();
}

std::string OptionString::getRealVal()
{
	return *m_RealVal;
}