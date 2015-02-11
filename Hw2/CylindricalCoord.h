//////////////////////////////////////////////////////////////////////
/// @file CylindricalCoord.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement cylindrical coordinates
//////////////////////////////////////////////////////////////////////

#ifndef __CylindricalCoord_H_INCLUDED
#define __CylindricalCoord_H_INCLUDED

#include <stdexcept>
#include <cmath>
#include <string>

template<class T>
class CylindricalCoord
{
  public:
    /************************** Constructors/Destructor  **************************/
    CylindricalCoord(): m_r(0), m_theta(0), m_z(0) {}
	CylindricalCoord(const T& r, const T& theta, const T& z): m_r(r), m_theta(theta), m_z(z) {}
	CylindricalCoord(const CylindricalCoord<T> &coord): m_r(coord.m_r), m_theta(coord.m_theta), m_z(coord.m_z) {}
	~CylindricalCoord() {}
	
	/************************** Operators **************************/
	/* Purpose:	Subtraction operator
	   Pre: 	None
	   Post:	Returns the reflection of the calling object through the origin or pole
	*/
	CylindricalCoord<T> CylindricalCoord<T>::operator-() const
	
	/* Purpose:	Bitwise NOT operator
	   Pre: 	None
	   Post:	Returns the magnitude of the calling object
	*/
	T CylindricalCoord<T>::operator~() const
	
	/* Purpose:	Bang operator
	   Pre: 	None
	   Post:	Returns the reflection of the calling object through the z-axis
	*/
	CylindricalCoord<T> CylindricalCoord<T>::operator!() const
	
	/* Purpose:	Basic assignment operator
	   Pre:		None
	   Post:	Copies b onto the calling object
	*/
	T CylindricalCoord<T>::operator=() const
	
	/* Purpose:	Equal to operator
	   Pre: 	None
	   Post:	Returns true if b represents the same point in space as the calling object. Returns false otherwise.
	*/
	bool CylindricalCoord<T>::operator==(const CylindricalCoord<T>& b) const;
	
	/* Purpose:	Not equal to operator
	   Pre: 	None
	   Post: 	Returns true if b does not represent the same point in space as the calling object. Returns false otherwise.
	*/
	bool CylindricalCoord<T>::operator!=(const CylindricalCoord<T>& b) const
	
	/* Purpose:	Greater than operator
	   Pre: 	None
	   Post: 	Returns true if the calling object is farther from the origin than b. Returns false otherwise.
	*/
	bool CylindricalCoord<T>::operator>(const CylindricalCoord<T>& a, const CylindricalCoord<T>& b)
	
	/* Purpose:	Less than operator
	   Pre:		None
	   Post:	Returns true if the calling object is closer to the origin than b. Returns false otherwise.
	*/
	bool CylindricalCoord<T>::operator<(const CylindricalCoord<T>& a, const CylindricalCoord<T>& b)
	
	/* Purpose:	Converts the cylindrical coordinates to cartesian values
	   Pre:		None
	   Post:	Returns a string that represents the converted cartesian values
	*/
	string CylindricalCoord<T>::cartesianCoord(const CylindricalCoord<T>& b) const
	
  private:
    T m_r;		//Radial distance
	T m_theta;	//Angle	
	T m_z;		//Height
};
#include "CylindricalCoord.hpp"
#endif