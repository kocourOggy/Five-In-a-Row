 //*****************************************************************

#include "Option.h"

//*****************************************************************

Option::Option(const std::string & text, const int num)
{
	m_Text += ( std::to_string(num) + ") " );
	for (uint i = 0; i < text.size(); ++i)
	{
		m_Text.push_back( text[i] );
	}
	m_Order = num;
}


Option::~Option()
{

}

int Option::getLen() const
{
	return m_Text.size();
}

std::string Option::getText() const
{
	return m_Text;
}