#ifndef __COORDINATE_H__
#define __COORDINATE_H__
 
 #include <iostream>

//*****************************************************************
struct Coordinate
{
	/** Constructor. */
	Coordinate ();
	/** Constructor with parameters. */
	Coordinate (int row, int column);
	/** Copy constructor. */
	Coordinate ( const Coordinate & other );
	/** Destructor. */
	~Coordinate(); 

	
	/** Operator ==. */
	bool operator == (Coordinate other);

	/** Operator =. */
	Coordinate & operator = (const Coordinate & other);
	/** Operator - with another Coordinate struct. */
	Coordinate  operator - (const Coordinate & other) const;
	/** Operator + with another Coordinate struct. */
	Coordinate  operator + (const Coordinate & other) const;

	/** Friend operator * with another Coordinate class. */
	friend Coordinate operator * (int n, const Coordinate& other);
	/** Friend operator << for reading. */
	friend std::ostream& operator << (std::ostream & os, const Coordinate x);

	/** Struct variable is two dimensional vector (row, col). */
	int m_Row, m_Column;
};

#endif /* __COORDINATE_H__ */