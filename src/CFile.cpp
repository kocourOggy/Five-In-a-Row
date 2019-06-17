 
 //*****************************************************************

#include "CFile.h"

//*****************************************************************

CFile::CFile()
{

}

CFile::~CFile()
{
	closeStream();
}

void CFile::closeStream()
{
	fin.close();
	fout.close();
}

bool CFile::openFileRead(std::ifstream & fin, const char * file)
{
  fin.open(file, std::ios_base::in);

  if (fin.is_open()) return true;
  return false;
}

bool CFile::openFileWrite(std::ofstream & fout, const char * file)
{
  fout.open(file, std::ios_base::out | std::ios_base::trunc);
  if (fout.is_open()) return true;
  return false;
}

bool CFile::readBasicData(MenuInfo & menuInfo)
{
	int arr[4];
	std::string str2;

	int i = 0;
	while ( std::getline(fin, str2, ':') )
	{
		arr[i] = ( atoi(str2.c_str()) );
		str2.clear();
		++i;
	}	
		
	if (i != 4) return false;
	menuInfo.row = arr[0];
	menuInfo.column = arr[1];
	menuInfo.typeGame = arr[2];
	menuInfo.nmove = arr[3];

	fin.close();
	return true;
}

bool CFile::loadBasicData(MenuInfo & menuInfo)
{
	if ( !openFileRead(fin, FILE_BASIC.c_str()) ) throw ("Cannot open file" + FILE_BASIC ).c_str();
	if ( !readBasicData(menuInfo) ) throw ("Cannot load file" + FILE_BASIC).c_str();
	return true;
}

bool CFile::writeBasicData(MenuInfo & menuInfo)
{
	fout << menuInfo.row << ":";
	fout << menuInfo.column << ":";
	fout << menuInfo.typeGame << ":";
	fout << menuInfo.nmove;
	fout.close();
	return true;
}

bool CFile::saveBasicData(MenuInfo & menuInfo)
{
	if ( !openFileWrite(fout, FILE_BASIC.c_str()) )
	{
		throw ("Cannot open file " + FILE_BASIC).c_str();
		return false;	
	}

	if ( !writeBasicData(menuInfo) )
	{
		throw ("Cannot write data to " + FILE_BASIC).c_str();
		return false;	
	}

	return true;	
}

bool CFile::writeVec3D(vect3D & myVec)
{
	uint X = myVec.size();
	uint Y = (myVec[0]).size();
	uint Z = (myVec[0][0]).size();

	std::string str1;

	for (uint i = 0; i < X; ++i)
	{
		for (uint j = 0; j < Y; ++j)
		{
			for (uint k = 0; k < Z; ++k)
			{
				str1 += std::to_string(i) + ":" + std::to_string(j) + ":" + std::to_string(k)
				+ ":" + std::to_string(myVec[i][j][k])  + ",";
				
    			
			}

		}
	}
	fout << str1;
	fout.close();
	return true;
}

bool CFile::readVec3D(vect3D & myVec)
{
	int arr[4];
	std::string str1;
	std::istringstream input1;
	bool correct = false;

	while( std::getline(fin, str1, ',') )
	{
		std::istringstream input;
		input.str(str1);

		std::string str2;
		int i = 0;		
		while (std::getline(input, str2, ':'))
		{
			arr[i] = ( atoi(str2.c_str()) );
			str2.clear();
			++i;
		}
		if (i != 4) return false;
		myVec[ arr[0] ][ arr[1] ][ arr[2] ] = arr[3];
		correct = true;
	}
	fin.close();
	return correct;
}

bool CFile::loadVec3D(vect3D & myVec)
{
	if ( !openFileRead(fin, FILE_VECT3.c_str()) )
	{
		throw ("Cannot open file " + FILE_VECT3).c_str();
		return false;
	}
	if ( !readVec3D(myVec) )
	{
		throw ("Cannot load file " + FILE_VECT3).c_str();
		return false;
	}
	return true;
}

bool CFile::saveVec3D(vect3D & myVec)
{
	if ( !openFileWrite(fout, FILE_VECT3.c_str()) )
	{
		throw ("Cannot open file " + FILE_VECT3).c_str();
		return false;
	}
	if ( !writeVec3D(myVec) )
	{
		throw ("Cannot save file " + FILE_VECT3).c_str();
		return false;
	}
	return true;	
}

bool CFile::readVec2D(vect2D & myVec)
{
	int arr[2];
	std::string str1;
	std::istringstream input;
	bool correct = false;

	while( std::getline(fin, str1, ',') )
	{
		std::istringstream input;
		input.str(str1);

		std::string str2;
		if( !std::getline(input, str2, ':') ) return false;
		arr[0] = atoi( str2.c_str() );
		str2.clear();

		if( !std::getline(input, str2, ':') ) return false;
		arr[1] = atoi( str2.c_str() );
		str2.clear();

		if( !std::getline(input, str2, ':') ) return false;

		myVec[ arr[0] ][ arr[1] ] = (char) atoi( str2.c_str() );
		correct = true;
	}
	fin.close();
	return correct;
}


bool CFile::loadVec2D(vect2D & myVec)
{
	if ( !openFileRead(fin, FILE_VECT2.c_str()) )
	{
		throw ("Cannot open file:" +  FILE_VECT2).c_str();
		return false;
	}
	if ( !readVec2D(myVec) )
	{
		throw ("Cannot load file:" +  FILE_VECT2).c_str();		
		return false;
	}
	return true;
}

bool CFile::writeVec2D(vect2D & myVec)
{
	uint X = myVec.size();
	uint Y = (myVec[0]).size();

	std::string str1;

	for (uint i = 0; i < X; ++i)
	{
		for (uint j = 0; j < Y; ++j)
		{
			str1 += std::to_string(i) + ":" + std::to_string(j) + ":" +
			std::to_string(myVec[i][j]) + ",";
		}
	}
	fout << str1;
	fout.close();
	return true;
}

bool CFile::saveVec2D(vect2D & myVec)
{
	if ( !openFileWrite(fout, FILE_VECT2.c_str()) )
	{
		throw ("Cannot open file " + FILE_VECT2).c_str();
		return false;
	}
	if ( !writeVec2D(myVec) )
	{
		throw ("Cannot save file" + FILE_VECT2).c_str();
		return false;
	}
	return true;	
}


bool CFile::readVec4D(vect4D & myVec)
{
	int arr[5];
	std::string str1;
	std::istringstream input1;
	bool correct = false;
	while( std::getline(fin, str1, ',') )
	{
		std::istringstream input;
		input.str(str1);

		std::string str2;
		int i = 0;		
		while (std::getline(input, str2, ':'))
		{
			arr[i] = ( atoi(str2.c_str()) );
			str2.clear();
			++i;
		}
		if (i != 5) return false;
		myVec[ arr[0] ][ arr[1] ][ arr[2] ][ arr[3] ] = arr[4];
		correct = true;
	}
	fin.close();
	return correct;
}

bool CFile::loadVec4D(vect4D & myVec)
{
	if ( !openFileRead(fin, FILE_VECT4.c_str()) )
	{
		throw ("Cannot open file:" +  FILE_VECT4).c_str();
		return false;
	}
	if ( !readVec4D(myVec) )
	{
		throw ("Cannot load file:" +  FILE_VECT4).c_str();
		return false;
	}
	return true;
}

bool CFile::writeVec4D(vect4D & myVec)
{
	uint X = myVec.size();
	uint Y = (myVec[0]).size();
	uint Z = (myVec[0][0]).size();
	uint Q = (myVec[0][0][0]).size();

	std::string str1;

	for (uint i = 0; i < X; ++i)
	{
		for (uint j = 0; j < Y; ++j)
		{
			for (uint k = 0; k < Z; ++k)
			{
				for (uint l = 0; l < Q; ++l)
				{
					str1 += std::to_string(i) + ":" + std::to_string(j) + ":" + std::to_string(k) + ":"
					+ std::to_string(l) + ":" + std::to_string(myVec[i][j][k][l])  + ",";
				}
			}

		}
	}
	fout << str1;
	fout.close();
	return true;
}

bool CFile::saveVec4D(vect4D & myVec)
{
	if ( !openFileWrite(fout, FILE_VECT4.c_str()) )
	{
		throw "Cannot open file " + FILE_VECT4;
		return false;
	}
	if ( !writeVec4D(myVec) )
	{
		throw "Cannot open file " + FILE_VECT4;
		return false;
	}
	return true;	
}


bool CFile::controlData()
{
	MenuInfo testInfo;
	vect2D test2D(MAXROW, std::vector<char>(MAXCOLUMN, BLANK_SYMBOL) );

	vect3D test3D(MAXROW,
	std::vector< std::vector<int> > (MAXCOLUMN,
	std::vector <int>(3, 0) ) );

	vect4D test4D(MAXROW,
	std::vector< std::vector < std::vector<int> > >(MAXCOLUMN,
	std::vector< std::vector<int> >(4,
	std::vector<int>(3, 0) ) ) );

	loadBasicData(testInfo);
	loadVec2D(test2D);
	loadVec3D(test3D);
	loadVec4D(test4D);

	return true;

}