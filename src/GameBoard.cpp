
//*****************************************************************

#include "GameBoard.h"

//*****************************************************************

GameBoard::GameBoard(const int row, const int column)
 :
  m_Board(row, std::vector<char>(column, BLANK_SYMBOL) ),
  m_Values {0,0,4,20,100,500,0},
  m_Dir {Coordinate(0, -1), Coordinate(-1,-1), Coordinate(-1,0), Coordinate(-1, 1)},
  
 
  m_ValueBlock(row,
  	std::vector< std::vector<int> > (column,
  	std::vector <int>(3, 0) ) ),


  m_LineStone(row,
  	std::vector< std::vector < std::vector<int> > >(column,
  	std::vector< std::vector<int> >(4,
  	std::vector<int>(3, 0) ) ) )

{
	m_Row = row;
	m_Column = column;
}


GameBoard::~GameBoard() { }


void GameBoard::writeStone(const Player & player, const Coordinate & coor)
{
	char symbol = player.getSymbol();

	m_Board[coor.m_Row][coor.m_Column] = symbol;
}

bool GameBoard::validMove (const Coordinate & coor)
{
	if (coor.m_Row >= m_Row || coor.m_Column >= m_Column) return false;
	return ( m_Board[coor.m_Row][coor.m_Column] == BLANK_SYMBOL );
}

//m_LineStone[row, col, direction, player]
bool GameBoard::incrementLineStone(int & stoneInRow)
{
	++stoneInRow;

	if (stoneInRow == SIZELINE) return true;
	return false;
}


void GameBoard::updateBlockValue(const int stoneInRowPlayer, const int stoneInRowOpponent,
								 int & blockValuePlayer, int & blockValueOpponent)
{
	if ( stoneInRowOpponent == 0 ) // protihrac nema zadne policko
 	{
  		blockValuePlayer += (m_Values[stoneInRowPlayer+1] - m_Values[stoneInRowPlayer]);
 	}
 	else  if (stoneInRowPlayer == 1)
 	{
   		blockValueOpponent -= (m_Values[stoneInRowOpponent]);
 	}
}


bool GameBoard::updateLine(const Player & player, const Coordinate & curMove)
{
	int playerIndex = player.getIndex();
	int opponentIndex; 
	if ((player.getIndex() == 1))	{opponentIndex = 2;}
	else                            {opponentIndex = 1;}
	int row1, col1, row2, col2;

	row1 = 0;
	col1 = 0;
	row2 = 0;
	col2 = 0;

	//std::cout << "curmove: " << curMove << "  board: " << m_Row << " " << m_Column << std::endl;
	// { (-1,0), (-1,-1), (0,-1), (1,-1) }
	// { (0,-1), (-1,-1), (-1,0), (-1,1) }
	for (uint direction = 0; direction < m_Dir.size(); ++direction)
	{
		//std::cout << "direction: " << m_Dir[direction] << std::endl;
		for (int i = 0; i < SIZELINE; ++i)
		{
			int horizDir = m_Dir[direction].m_Column;
			int verDir = m_Dir[direction].m_Row;
			row1 = curMove.m_Row + (i * verDir);
			col1 = curMove.m_Column + (i * horizDir);
  			
  			if ( (( horizDir == -1 && col1 >= 0 && col1 <= m_Column - SIZELINE ) ||
			     ( horizDir == 1 && col1 >= SIZELINE -1 && col1 < m_Column ) ||
			     ( horizDir == 0 ) ) &&			

			     (( verDir == -1 && row1 >= 0 && row1 <= m_Row - SIZELINE ) ||
			     ( verDir == 1 && row1 >= SIZELINE -1 &&  row1 < m_Row ) ||
			     ( verDir == 0 )) )

			{
				//std::cout << i <<" .row1/col1:  " << Coordinate(row1, col1) << std::endl;
				if (incrementLineStone( m_LineStone[row1][col1][direction][playerIndex])) return true;

				for (int j = 0; j < SIZELINE; ++j)
				{
					row2 = row1 - (j * verDir);
					col2 = col1 - (j * horizDir);
					updateBlockValue(m_LineStone[row1][col1][direction][playerIndex],
		                             m_LineStone[row1][col1][direction][opponentIndex],
		                             m_ValueBlock[row2][col2][playerIndex],
		                             m_ValueBlock[row2][col2][opponentIndex] );
				}



			}
		}
	}
	return false;
}



