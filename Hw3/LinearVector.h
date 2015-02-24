//////////////////////////////////////////////////////////////////////
/// @file LinearVector.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement vector analysis
//////////////////////////////////////////////////////////////////////

#ifndef __LinearVector_H_INCLUDED
#define __LinearVector_H_INCLUDED

#include <stdexcept>
#include <iostream>
#include <sstream>

template<class T>
class LinearVector
{
  public:
    /************************** Constructors/Destructor  **************************/
	LinearVector(int n);
	LinearVector();
	LinearVector(const LinearVector<T>& vect);
	~LinearVector();
	
	/************************** Operators **************************/
	/* Purpose:	Brackets operator
	   Pre:		The calling object has initialized values
	   Post:	Returns the element located at index i in the LinearVector. The returned value can be modified.
	*/
	T& operator[](const int i);
	
	/* Purpose:	Brackets operator
	   Pre:		The calling object has initialized values
	   Post:	Returns the element located at index i in the LinearVector. The returned value cannot be modified.
	*/
	const T& operator[](const int i) const;
	
	/* Purpose:	LinearVector assignment operator
	   Pre:		rhs has initialized values
	   Post:	Returns the calling LinearVector after it has been transformed to have all of the same values as rhs
	*/
	LinearVector<T>& operator=(const LinearVector& rhs);
	
	/* Purpose:	Value assignment operator
	   Pre:		rhs has initialized values
	   Post:	Returns the calling LinearVector after it has had all of its elements assigned to the value of rhs
	*/
	LinearVector<T>& operator=(const T rhs);
	
	/************************** Stream Operators **************************/
	/* Purpose:	Ostream operator
	   Pre:		rhs has initialized values
	   Post:	Returns an ostream that represents the given LinearVector
	*/
	template<class U> 
	friend std::ostream& operator<< (std::ostream & stream, const LinearVector<T> &rhs);
	
	/* Purpose:	Istream operator
	   Pre:		None
	   Post:	Returns an istream that represents the given LinearVector
	*/
	template<class U> 
	friend std::istream& operator>> (std::istream & stream, LinearVector<T> &rhs);
	
	/************************** Other **************************/
	/* Purpose:	Gets the size of the LinearVector
	   Pre:		None
	   Post:	Returns the value of m_size of the LinearVector
	*/
	int getSize() const;

  private:
    T* m_data_ptr;
	int m_size;
};
#include "LinearVector.hpp"
#endif
	
	