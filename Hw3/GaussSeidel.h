//////////////////////////////////////////////////////////////////////
/// @file GaussSeidel.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement the GaussSeidel Iteration Method
//////////////////////////////////////////////////////////////////////

#ifndef __Jacobi_H_INCLUDED
#define __Jacobi_H_INCLUDED
#include <vector>

template<class T>
class GaussSeidel
{
  public:
	/************************** Operator **************************/
	/* Purpose:	Parenthesis operator
	   Pre: 	All of the given coordinates have initialized values
	   Post:	Outputs whether the given set is linearly dependent or not. If it is dependent, then outputs the linear combination.
	*/
	void operator()(const std::vector<LinearVector<T> > vect) const;
};
#include "GaussSeidel.hpp"
#endif