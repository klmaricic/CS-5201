//////////////////////////////////////////////////////////////////////
/// @file ParamMatrix.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement a parameterized matrix
//////////////////////////////////////////////////////////////////////

#ifndef __ParamMatrix_H_INCLUDED
#define __ParamMatrix_H_INCLUDED

#include <stdexcept>
#include <cmath>
#include<iostream>
#include <fstream>
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
	
	/* Purpose:	Brackets operator
	   Pre:		i must be in the range of the ParamMatrix
	   Pre:		T* (pointer) must be defined
	   Pre:		T*[int] must be defined
	   Post:	Returns the element located at index i in the ParamMatrix. The returned value can be modified.
	*/
	T& operator[](const int i);
	
	/* Purpose:	Brackets operator
	   Pre:		i must be in the range of the ParamMatrix
	   Pre:		T* (pointer) must be defined
	   Pre:		T*[int] must be defined
	   Post:	Returns the element located at index i in the ParamMatrix. The returned value cannot be modified.
	*/
	const T& operator[](const int i) const;
	
	/************************** Stream Operators **************************/
	/* Purpose:	Ostream operator
	   Pre:		<< T (stream) must be defined
	   Post:	Returns an ostream that represents the given ParamMatrix
	*/
	template<class U> 
	friend std::ostream& operator<< (std::ostream & stream, const ParamMatrix<T>& matrix);
	
	/* Purpose:	Istream operator
	   Pre:		>> T (stream assignment) must be defined
	   Post:	Returns an istream that represents the given ParamMatrix
	*/
	template<class U> 
	friend std::ifstream& operator>> (std::ifstream & stream, ParamMatrix<T> &rhs);
	
	/************************** Other **************************/	
	int rowSize() const;
	
	int numRows() const;
	
	/* Purpose:	Sets the size of the calling ParamMatrix
	   Pre:		delete [] T must be defined
	   Pre:		T* = new T[int] must be defined
	   Post:	If the calling ParamMatrix's size did not match the setSize parameter values, then it deletes all of its old elements, sets its size, and allocates new elements
	*/
	void setSize(int numRows, int numCols);
	
	int getSize() const;
	
	
  private:
    T* m_dataPtr;
    int m_rowSize;
	int m_numRows;
};
#include "ParamMatrix.hpp"
#endif