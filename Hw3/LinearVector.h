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
	/* Purpose:	constructor
	   Pre:		none
	   Post:	Creates a LinearVector object of size n
	*/
	LinearVector(int n);
	
	/* Purpose:	constructor
	   Pre:		none
	   Post:	Creates a LinearVector object of size 0
	*/
	LinearVector();
	
	/* Purpose:	constructor
	   Pre:		T[int] must be defined
	   Pre:		vectCopy(LinearVector<T>) must be defined
	   Post:	Creates a LinearVector object that is a copy of vect's size and content
	*/
	LinearVector(const LinearVector<T>& vect);
	
	/* Purpose:	destructor
	   Pre:		none
	   Post:	destructs the LinearVector object
	*/
	~LinearVector();
	
	/************************** Operators **************************/
	/* Purpose:	Brackets operator
	   Pre:		i must be in the range of the LinearVector
	   Pre:		T* (pointer) must be defined
	   Pre:		T*[int] must be defined
	   Post:	Returns the element located at index i in the LinearVector. The returned value can be modified.
	*/
	T& operator[](const int i);
	
	/* Purpose:	Brackets operator
	   Pre:		i must be in the range of the LinearVector
	   Pre:		T* (pointer) must be defined
	   Pre:		T*[int] must be defined
	   Post:	Returns the element located at index i in the LinearVector. The returned value cannot be modified.
	*/
	const T& operator[](const int i) const;
	
	/* Purpose:	Addition operator
	   Pre:		T += T (in place addition) must be defined
	   Post:	Returns the resulting sum of the calling LinearVector and rhs
	*/
	LinearVector<T> operator+(const LinearVector<T>& rhs) const;
	
	/* Purpose:	Subtraction operator
	   Pre:		T -= T (in place subtraction) must be defined
	   Post:	Returns the resulting difference of the calling LinearVector and rhs
	*/
	LinearVector<T> operator-(const LinearVector<T>& rhs) const;
	
	/* Purpose:	Negation operator
	   Pre:		-T (negation) must be defined
	   Pre:		T = T (assignment) must be defined
	   Post:	Returns the negation of the calling LinearVector
	*/
	LinearVector<T> operator-() const;
	
	/* Purpose:	Dot product operator
	   Pre:		T = int (assignment) must be defined
	   Pre:		T*T (multiplication) must be defined
	   Pre:		T += T (in place addition) must be defined
	   Post:	Returns the dot product of the calling LinearVector and rhs
	*/
	T operator*(const LinearVector<T>& rhs) const;
	
	/* Purpose:	Scalar multiply operator
	   Pre:		T *= T (in place multiplication) must be defined
	   Post:	Returns the result of multiplying the calling LinearVector with the scalar rhs
	*/
	LinearVector<T> operator*(const T rhs) const;
	
	/* Purpose:	LinearVector assignment operator
	   Pre: 	T* (pointer) must be defined
	   Pre:		T* != T* (negative comparison) must be defined
	   Pre:		vectCopy(LinearVector<T>) must be defined
	   Post:	Returns the calling LinearVector after it has been transformed to have all of the same values as rhs
	*/
	LinearVector<T>& operator=(const LinearVector<T>& rhs);
	
	/* Purpose:	Scalar assignment operator	 
	   Pre:		T*[int] = T (assignment) must be defined
	   Post:	Returns the calling LinearVector after it has had all of its elements assigned to the value of rhs
	*/
	LinearVector<T>& operator=(const T rhs);
	
	/************************** Stream Operators **************************/
	/* Purpose:	Ostream operator
	   Pre:		<< T (stream) must be defined
	   Post:	Returns an ostream that represents the given LinearVector
	*/
	template<class U> 
	friend std::ostream& operator<< (std::ostream & stream, const LinearVector<T> &rhs);
	
	/* Purpose:	Istream operator
	   Pre:		>> T (stream assignment) must be defined
	   Post:	Returns an istream that represents the given LinearVector
	*/
	template<class U> 
	friend std::istream& operator>> (std::istream & stream, LinearVector<T> &rhs);
	
	/************************** Other **************************/
	/* Purpose:	Gets the size of the LinearVector
	   Pre:		None
	   Post:	Returns the value of m_size of the calling LinearVector
	*/
	int getSize() const;
	
	/* Purpose:	Sets the size of the calling LinearVector
	   Pre:		delete [] T must be defined
	   Pre:		T* = new T[int] must be defined
	   Post:	If the calling LinearVector's size did not match the setSize parameter value, then it deletes all of its old elements, sets its size, and allocates new elements
	*/
	void setSize(int n);

  private:
    T* m_data_ptr;
	int m_size;
	
	/* Purpose:	Copies the elements of vect into the calling object
	   Pre:		T*[int] = T*[int] must be defined
	   Post:	Changes all of the calling LinearVector's elements to match vect's elements
	*/
	void vectCopy(const LinearVector<T>& vect);
};
#include "LinearVector.hpp"
#endif
	
	