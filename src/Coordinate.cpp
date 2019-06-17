 
 //*****************************************************************

#include "Coordinate.h"

//*****************************************************************

Coordinate::Coordinate () { }

Coordinate::~Coordinate () { }


Coordinate::Coordinate (int row, int column) 
{
	m_Row = row;
	m_Column = column;
}


Coordinate::Coordinate ( const Coordinate & other ) 
{
	m_Row = other.m_Row;
	m_Column = other.m_Column;
}


bool Coordinate::operator == (Coordinate other) 
{
	return ( m_Row == other.m_Row && m_Column == other.m_Column );
}

Coordinate & Coordinate::operator = (const Coordinate & other)
{
	if ( &other == this ) return *this;
	m_Row = other.m_Row;
	m_Column = other.m_Column;
	return *this;
}

Coordinate  Coordinate::operator - (const Coordinate & other) const
{
	return Coordinate( m_Row - other.m_Row, m_Column - other.m_Column );
}

Coordinate  Coordinate::operator + (const Coordinate & other) const
{
	return Coordinate( m_Row + other.m_Row, m_Column + other.m_Column );
}

std::ostream& operator << (std::ostream & os, const Coordinate x)
{
	os << "row: " << x.m_Row << ", column: " << x.m_Column;
	return os;
}

Coordinate operator * (int n, const Coordinate& other)
{
	return Coordinate( n * other.m_Row, n * other.m_Column );
}
