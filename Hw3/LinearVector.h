//////////////////////////////////////////////////////////////////////
/// @file LinearVector.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement vector analysis
//////////////////////////////////////////////////////////////////////

#ifndef __LinearVector_H_INCLUDED
#define __LinearVector_H_INCLUDED

#include <stdexcept>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>

template<class T>
class LinearVector
{
  public:
    /************************** Constructors/Destructor  **************************/
	LinearVector(int n);
	LinearVector();
	LinearVector(const LinearVector<T>&);
	~LinearVector();
	
	/************************** Operators **************************/
	/* Purpose:	Brackets operator
	   Pre:		The calling object has initialized values
	   Post:	Returns the element located at index i in the vector. The returned value can be modified.
	*/
	T& operator[](const int i);
	
	/* Purpose:	Brackets operator
	   Pre:		The calling object has initialized values
	   Post:	Returns the element located at index i in the vector. The returned value cannot be modified.
	*/
	const T& operator[](const int i) const;
	
	LinearVector<T>& operator=(const LinearVector& rhs);
	
	LinearVector<T>& operator=(const T rhs);

  private:
    T* m_data_ptr;
	int m_size;
};
#include "LinearVector.hpp"
#endif
	
	