//////////////////////////////////////////////////////////////////////
/// @file ParamMatrix.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement a parameterized matrix
//////////////////////////////////////////////////////////////////////

#ifndef __ParamMatrix_H_INCLUDED
#define __ParamMatrix_H_INCLUDED

#include <stdexcept>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>

template<class T>
class ParamMatrix
{
  public:
    /************************** Constructors/Destructor  **************************/
	ParamMatrix();
	ParamMatrix(int numRows, int numCols);
	ParamMatrix(const ParamMatrix<T>& matrix);
	~ParamMatrix();
	
	/************************** Operators **************************/
	/* Purpose:	Parentheses operator
	   Pre:		row and col must be in the range of the ParamMatrix
	   Post:	Returns the element located at row, col inside the ParamMatrix
	*/
	const T& operator()(const int row, const int col) const;
	
	ParamMatrix<T> operator+(const ParamMatrix<T>& rhs) const;
	
	ParamMatrix<T> operator-(const ParamMatrix<T>& rhs) const;
	
	/************************** Other **************************/
	int rowSize() const;
	
	int numRows() const;
	
	/************************** Stream Operators **************************/
	/* Purpose:	Ostream operator
	   Pre:		<< T (stream) must be defined
	   Post:	Returns an ostream that represents the given LinearVector
	*/
	template<class U> 
	friend std::ostream& operator<< (std::ostream & stream, const ParamMatrix<T>& matrix);
	
	
  private:
    T* m_dataPtr;
    int m_rowSize;
	int m_numRows;
};
#include "ParamMatrix.hpp"
#endif