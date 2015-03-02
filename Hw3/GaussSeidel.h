//////////////////////////////////////////////////////////////////////
/// @file GaussSeidel.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement the GaussSeidel Iteration Method
//////////////////////////////////////////////////////////////////////

#ifndef __GaussSeidel_H_INCLUDED
#define __GaussSeidel_H_INCLUDED
#include <vector>
#include <math.h>
#include<iostream>

template<class T>
class GaussSeidel
{
  public:
	/************************** Operator **************************/
	/* Purpose:	Parenthesis operator
	   Pre: 	T == int (compare) must be defined
	   Pre: 	T/T(division) must be defined, and results in type double (or implicitly castable to double)
	   Pre: 	T*double(multiplication) must be defined and results in type T (or implicitly castable to T)
	   Pre: 	T != T (negative comparison) must be defined
	   Pre: 	T = T (assignment) must be defined
	   Pre: 	T - T (subtraction) must be defined and results in type T (or implicitly castable to T)
	   Pre: 	fabs(T) must be defined
	   Pre: 	LinearVector<T>*T (array multiplication) must be defined and result in type LinearVector<T> (or implicitly castable to LinearVector<T>)
	   Pre: 	double = T  (assignment) must work (T must be able to be implicitly casted to double)
	   Pre: 	T > double (greater than) must be defined
	   Pre: 	<< T (stream) must be defined
	   Post:	Outputs whether the given set is linearly dependent or not. If it is dependent, then outputs the linear combination.
	   Post:	Outputs the tolerance of the process
	*/
	void operator()(std::vector<LinearVector<T> > vect) const;
};
#include "GaussSeidel.hpp"
#endif