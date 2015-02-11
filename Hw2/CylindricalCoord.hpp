//////////////////////////////////////////////////////////////////////
/// @file CylindricalCoord.hpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement cylindrical coordinates
//////////////////////////////////////////////////////////////////////

template <class T>
CylindricalCoord<T> CylindricalCoord<T>::operator-() const
{
  return CylindricalCoord<T>(m_r, static_cast<T>(fmod(m_theta+ M_PI, 2*M_PI)), -m_z);
}

template <class T>
T CylindricalCoord<T>::operator~() const
{
  return sqrt(pow(m_r,2)+pow(m_z,2));
}

template<class T>
CylindricalCoord<T> CylindricalCoord<T>::operator!() const
{
  return CylindricalCoord<T>(m_r, static_cast<T>(fmod(m_theta+ M_PI, 2*M_PI)), m_z);
}

template <class T>
T CylindricalCoord<T>::operator=() const
{
  m_r = b.m_r;
  m_theta = b.m_theta;
  m_z = b.m_z;
  return *this;
}

template <class T>
bool CylindricalCoord<T>::operator==(const CylindricalCoord<T>& b) const
{
  return cartesianCoord(*this) == cartesianCoord(b);
}

template <class T>
bool CylindricalCoord<T>::operator!=(const CylindricalCoord<T>& b) const
{
  return !cartesianCoord(*this) == cartesianCoord(b);
}

template <class T>
bool operator<(const CylindricalCoord<T>& a, const CylindricalCoord<T>& b)
{
  T mag1, mag2;
  mag1 = ~a;
  mag2 = ~b;
  
  return mag1 < mag2;
}

template <class T>
bool operator>(const CylindricalCoord<T>& a, const CylindricalCoord<T>& b)
{
  T mag1, mag2;
  mag1 = ~a;
  mag2 = ~b;
  
  return mag1 > mag2;
}

template <class T>
string CylindricalCoord<T>::cartesianCoord(const CylindricalCoord<T>& b) const
{
/*
  std::stringstream stream;
  std::string cartCoord;
  stream<<"("<<(b.m_r*cos(m_theta))<<","<<(b.m_r*sin(m_theta))<<","<<b.m_r<<")";
  cartCoord = stream.str();
  return cartCoord;
  */
}