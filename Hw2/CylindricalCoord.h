//////////////////////////////////////////////////////////////////////
/// @file CylindricalCoord.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement cylindrical coordinates
//////////////////////////////////////////////////////////////////////

template<class T>
class CylindricalCoord
{
  public:
    CylindricalCoord<T>::CylindricalCoord(): m_r(0), m_theta(0), m_z(0) {}
	CylindricalCoord<T>::CylindricalCoord(const T& r, const T& theta, const T& z): m_r(r), m_theta(theta), m_z(z) {}
	CylindricalCoord<T>::CylindricalCoord(const CylindricalCoord<T> &coord): m_r(coord.m_r), m_theta(coord.m_theta), m_z(coord.m_z) {}
	~CylindricalCoord() {}
	
	/**************************Operators**************************/
	/* Purpose:	Subtraction operator
	   Pre: 	None
	   Post:	Returns the reflection through the origin or pole
	*/
	CylindricalCoord<T> CylindricalCoord<T>::operator-(const CylindricalCoord<T>& b) const;
	
	/* Purpose:	Assignment operator
	   Pre:		None
	   Post:	Copies b onto the calling object
	*/
	T CylindricalCoord<T>::operator=(const CylindricalCoord<T>& b);
	
	/* Purpose:	Equal to operator
	   Pre: 	None
	   Post:	Returns if b has the same values as the calling object or not
	*/
	bool CylindricalCoord<T>::operator==(const CylindricalCoord<T>& b) const;
	
	/* Purpose:
	   Pre:
	   Post:
	*/
	bool CylindricalCoord<T>::operator!=(const CylindricalCoord<T>& b) const
	
  private:
    T m_r;		//Radial distance
	T m_theta;	//Angle	
	T m_z;		//Height
};