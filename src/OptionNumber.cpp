 //*****************************************************************

#include "OptionNumber.h"

//*****************************************************************

OptionNumber::OptionNumber(int * realVal, const std::string & text, const int num, const int n, const int min, const int max)
:	OptionVal::OptionVal(text, num, n)
{
	m_Max = max;
	m_Min = min;
	m_RealVal = realVal;
}

OptionNumber::~OptionNumber()
{

}

bool OptionNumber::readInput() // virtual
{
	for (int i = 0; i < 20; ++i)
	{
		m_Buffer[i] = '\0';
	}

	echo();
	getnstr(m_Buffer, m_ReadN);
	if (!( isNumber() && inRange() )) return 0;
	m_Number = atoi(m_Buffer);
	return 1;
}

bool OptionNumber::isNumber() const
{
	int size = 0;
	while (m_Buffer[size] != '\0') {++size;}

	for (int i = 0; i < size; ++i)
	{
		if ( !isdigit(m_Buffer[i]) ) return false;
	}
	return true;
}

bool OptionNumber::inRange() const
{
	int num = atoi(m_Buffer);
	return ( (num >= m_Min) && (num <= m_Max) );
}

int OptionNumber::getNum() const
{
	return m_Number;
}

void OptionNumber::changeRealVal()
{
	* m_RealVal = m_Number;
}

std::string OptionNumber::getRealVal()
{
	return std::to_string(*m_RealVal);
}