 
 //*****************************************************************


#include "Player.h"

//*****************************************************************


//-------------------------------------
Player::Player(const std::string name, const char symbol, const int color)
{
	m_Index = 0;
	m_State = ' ';
	m_Symbol = symbol;
	m_Name = name;
	if (m_Symbol == CIRCLE) m_Index = 2;
	else					m_Index = 1;
}


Player::~Player() { }

int Player::getColor() const
{
	return m_Color;
}

char Player::getSymbol() const 
{ 
	return m_Symbol;
}

int Player::getIndex() const 
{ 
	return m_Index;
}

std::string Player::getName() const
{ 
	return m_Name;
}

void Player::setData (int row, int column)
{
	m_Row = row - 1;
	m_Column = column - 1;
}

char Player::getState(void) const
{
	return ( m_State );
}


//-------------------------------------