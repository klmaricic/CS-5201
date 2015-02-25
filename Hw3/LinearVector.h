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
	
	/* Purpose:	Addition operator
	   Pre:		rhs has initialized values
	   Post:	Returns the sum of lhs and rhs
	*/
	LinearVector<T>& operator+(const LinearVector<T>& rhs) const;
	
	/* Purpose:	Subtraction operator
	   Pre:		rhs has initialized values
	   Post:	Returns the difference of lhs and rhs
	*/
	LinearVector<T>& operator-(const LinearVector<T>& rhs) const;
	
	/* Purpose:	Negation operator
	   Pre:		rhs has initialized values
	   Post:	Returns the negation of the calling LinearVector
	*/
	LinearVector<T>& operator-() const;
	
	/* Purpose:	Dot product operator
	   Pre:		rhs has initialized values
	   Post:	Returns the dot product of the calling LinearVector and rhs
	*/
	T& operator*(const LinearVector<T>& rhs) const;
	
	/* Purpose:	LinearVector assignment operator
	   Pre:		rhs has initialized values
	   Post:	Returns the calling LinearVector after it has been transformed to have all of the same values as rhs
	*/
	LinearVector<T>& operator=(const LinearVector& rhs);
	
	/* Purpose:	Scalar assignment operator
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
	   Post:	Returns the value of m_size of the calling LinearVector
	*/
	const int getSize() const;
	
	/* Purpose:	Sets the size of the calling LinearVector
	   Pre:		None
	   Post:	If the calling LinearVector's size did not match the setSize parameter value, then it deletes all of its old elements, sets its size, and allocates new elements
	*/
	void setSize(int n);

  private:
    T* m_data_ptr;
	int m_size;
	
	/* Purpose:	Copies the elements of vect into the calling object
	   Pre:		None
	   Post:	Changes all of the calling LinearVector's elements to match vect's elements
	*/
	void vectCopy(const LinearVector<T>& vect);
};
#include "LinearVector.hpp"
#endif
	
	