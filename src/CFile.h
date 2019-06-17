#ifndef __CFILE_H__
#define __CFILE_H__

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>

#include "MenuInfo.h"
#include "constants.h"

//*****************************************************************
typedef std::vector< std::vector <std::vector<int> > > vect3D;
typedef std::vector < std::vector< std::vector< std::vector<int> > > > vect4D;
typedef std::vector< std::vector<char> > vect2D;

class CFile
{
public:
	/** Constructor*/
	CFile();
	/** Destructor*/
	~CFile();

	/** Method for closing ofstream a ifstream*/
	void closeStream();

	 /** Method for opening file in read mode
     * @param[in] Name of path*/
	bool openFileRead(std::ifstream & fin, const char * file);

	/** Method for opening file in save mode
     * @param[in] Name of path*/
	bool openFileWrite(std::ofstream & fout, const char * file);

	/** Method for reading basic data where row, col or type of game is saved
     * @param[in] Variable menuInfo where we write the information from file*/
	bool readBasicData(MenuInfo & menuInfo);

	/** Method which include openFileRead() and readBasicData()
    * @param[in] Variable menuInfo where we write the information from file*/
	bool loadBasicData(MenuInfo & menuInfo);

	/** Method for writing basic data where row, col or type of game is saved
     * @param[in] Variable menuInfo from where we write the information to file*/
	bool writeBasicData(MenuInfo & menuInfo);

	/** Method which include openFileRead() and writeBasicData()
    * @param[in] Variable menuInfo from where we write the information to file*/
	bool saveBasicData(MenuInfo & menuInfo);

	/** Method for reading 4D vector where info about value of block is saved (info for AI)
     * @param[in] Variable menuInfo where we write the information from file*/
	bool readVec4D(vect4D & myVec);

	/** Method which include openFileRead and readVec4D
    * @param[in] Variable menuInfo where we write the information from file*/
	bool loadVec4D(vect4D & myVec);

	/** Method for writing 4D vector where info about value of block is saved (info for AI)
     * @param[in] Variable menuInfo from where we write the information to file*/
	bool writeVec4D(vect4D & myVec);

	/** Method which include openFileWrite and writeVec4D
    * @param[in] Variable menuInfo from where we write the information to file*/
	bool saveVec4D(vect4D & myVec);

	/** Method for reading 3D vector where info about stones in row is saved (info for checking winner)
     * @param[in] Variable menuInfo where we write the information from file*/
	bool readVec3D(vect3D & myVec);

	/** Method which include openFileRead and readVec3D
    * @param[in] Variable menuInfo where we write the information from file*/
	bool loadVec3D(vect3D & myVec);

	/** Method for writing 3D vector where info about stones in row is saved (info for checking winner)
     * @param[in] Variable menuInfo from where we write the information to file*/
	bool writeVec3D(vect3D & myVec);

	/** Method which include openFileWrite and writeVec3D
    * @param[in] Variable menuInfo from where we write the information to file*/
	bool saveVec3D(vect3D & myVec);

	/** Method for reading 2D vector where info about draw symbols are (info for gamescreen)
     * @param[in] Variable menuInfo where we write the information from file*/
	bool readVec2D(vect2D & myVec);

	/** Method which include openFileRead and readVec2D
    * @param[in] Variable menuInfo from where we write the information to file*/
	bool loadVec2D(vect2D & myVec);

	/** Method for writing 4D vector where info about value of block is saved (info for AI)
     * @param[in] Variable menuInfo from where we write the information to file*/
	bool writeVec2D(vect2D & myVec);

	/** Method which include openFileWrite and writeVec2D
    * @param[in] Variable menuInfo from where we write the information to file*/
	bool saveVec2D(vect2D & myVec);

	/** Method controls if data are not corrupted
	* @return returns true if every file is ok*/
	bool controlData();


private:
	/** Variable for output (writing/saving)*/
	std::ofstream fout;
	/** Variable for input (reading/loading)*/
	std::ifstream fin;
};

#endif /*__CFILE_H__*/





