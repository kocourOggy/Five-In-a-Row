 //*****************************************************************

#include "OptionVal.h"

//*****************************************************************

OptionVal::OptionVal(const std::string & text, const int num, const int n)
:	Option::Option(text, num)
{
	m_ReadN = n;
}

OptionVal::~OptionVal()
{

}
