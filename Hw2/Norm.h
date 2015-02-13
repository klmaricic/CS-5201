//////////////////////////////////////////////////////////////////////
/// @file Norm.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement the norm function on cylindrical coordinates
//////////////////////////////////////////////////////////////////////

#ifndef __Norm_H_INCLUDED
#define __Norm_H_INCLUDED
#include <vector>

template<class T>
class Norm
{
  public:
	/************************** Operator **************************/
	/* Purpose:	Parenthesis operator
	   Pre: 	All of the given coordinates have initialized values
	   Post:	Returns the sum of the magnitudes of all the cylindrical coordinates in the set
	*/
	T operator()(std::vector<CylindricalCoord<double> > vect) const;
};
#include "Norm.hpp"
#endif