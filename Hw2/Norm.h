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
    /************************** Constructors/Destructor  **************************/
	Norm() {}
	~Norm() {}
	
	/************************** Operator **************************/
	/* Purpose:	Subtraction operator
	   Pre: 	None
	   Post:	Returns the reflection of the calling object through the origin or pole
	*/
	T operator()(std::vector<CylindricalCoord<double> > vect) const;

};
#include "Norm.hpp"
#endif