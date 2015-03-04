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
	ParamMatrix(int n);
	ParamMatrix(const ParamMatrix<LinearVector<T> >& matrix);
	~ParamMatrix();
	
	/************************** Operators **************************/
	/* Purpose:	Parentheses operator
	   Pre:		row and col must be in the range of the ParamMatrix
	   Post:	Returns the element located at row, col inside the ParamMatrix
	*/
	const T& operator()(const int row, const int col) const
	
	ParamMatrix<T> operator+(const ParamMatrix<T>& rhs) const
	
  private:
    T* m_dataPtr;
    int m_rowSize;
};
#include "ParamMatrix.hpp"
#endif