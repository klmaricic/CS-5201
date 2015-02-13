//////////////////////////////////////////////////////////////////////
/// @file CylindricalCoord.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement cylindrical coordinates
//////////////////////////////////////////////////////////////////////

#ifndef __CylindricalCoord_H_INCLUDED
#define __CylindricalCoord_H_INCLUDED

#include <stdexcept>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>

template<class T>
class CylindricalCoord
{
  public:
    /************************** Constructors/Destructor  **************************/
    CylindricalCoord(): m_r(0), m_theta(0), m_z(0) {}
	CylindricalCoord(T r, T theta, T z): m_r(r), m_theta(theta), m_z(z) {}
	CylindricalCoord(const CylindricalCoord<T>& coord): m_r(coord.m_r), m_theta(coord.m_theta), m_z(coord.m_z) {}
	~CylindricalCoord() {}
	
	/************************** Operators **************************/
	/* Purpose:	Negation operator
	   Pre: 	The calling object has initialized values
	   Post:	Returns the reflection of the calling object through the origin or pole
	*/
	CylindricalCoord<T> operator-() const;
	
	/* Purpose:	Tilde operator
	   Pre: 	The calling object has initialized values
	   Post:	Returns the magnitude of the calling object
	*/
	T operator~() const;
	
	/* Purpose:	Bang operator
	   Pre: 	The calling object has initialized values
	   Post:	Returns the reflection of the calling object through the z-axis
	*/
	CylindricalCoord<T> operator!() const;
	
	/* Purpose:	Basic assignment operator
	   Pre:		b has initialized values
	   Post:	Copies b onto the calling object
	*/
	void operator=(const CylindricalCoord<T>& b);
	
	/* Purpose:	Equal to operator
	   Pre: 	The calling object and b have initialized values
	   Post:	Returns true if b represents the same point in space as the calling object. Returns false otherwise.
	*/
	bool operator==(const CylindricalCoord<T>& b) const;
	
	/* Purpose:	Not equal to operator
	   Pre: 	The calling object and b have initialized values
	   Post: 	Returns true if b does not represent the same point in space as the calling object. Returns false otherwise.
	*/
	bool operator!=(const CylindricalCoord<T>& b) const;
	
	/* Purpose:	Greater than operator
	   Pre: 	The calling object and b have initialized values
	   Post: 	Returns true if the calling object is farther from the origin than b. Returns false otherwise.
	*/
	bool operator>(const CylindricalCoord<T>& b) const;
	
	/* Purpose:	Less than operator
	   Pre:		The calling object and b have initialized values
	   Post:	Returns true if the calling object is closer to the origin than b. Returns false otherwise.
	*/
	bool operator<(const CylindricalCoord<T>& b) const;
	
	/* Purpose:	Brackets operator
	   Pre:		The calling object has initialized values
	   Post:	Returns m_r if i=0, m_theta if i=1, or m_z if i=2. The returned value cannot be modified.
	*/
	const T& operator[](const int i) const;
	
	/* Purpose:	Brackets operator
	   Pre:		The calling object has initialized values
	   Post:	Returns m_r if i=0, m_theta if i=1, or m_z if i=2. The returned value can be modified.
	*/
	T& operator[](const int i);
	
	/************************** Stream Operators **************************/
	/* Purpose:	Ostream operator
	   Pre:		b has initialized values
	   Post:	Returns an ostream that represents the given CylindricalCoord
	*/
	template<class U> 
	friend std::ostream& operator<< (std::ostream & stream, const CylindricalCoord<T> &b);
	
	/* Purpose:	Istream operator
	   Pre:		None
	   Post:	Returns an istream that represents the given CylindricalCoord
	*/
	template<class U> 
	friend std::istream& operator>> (std::istream & stream, CylindricalCoord<T> &b);
	
	/************************** Other **************************/
	/* Purpose:	Converts the cylindrical coordinates to Cartesian values
	   Pre:		The calling object has initialized values
	   Post:	Returns a string that represents the converted Cartesian values
	*/
	std::string cartesianCoord() const;
	
  private:
    T m_r;		//Radial distance
	T m_theta;	//Angle	
	T m_z;		//Height
};
#include "CylindricalCoord.hpp"
#endif