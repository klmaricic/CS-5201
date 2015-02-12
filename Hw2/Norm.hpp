//////////////////////////////////////////////////////////////////////
/// @file Norm.hpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement the norm function on cylindrical coordinates
//////////////////////////////////////////////////////////////////////

template <class T>
T Norm<T>::operator()(std::vector<CylindricalCoord<double> > vect) const
{
  T sum = 0;
  
  for(std::vector<int>::size_type i = 0; i != vect.size(); i++) {
    sum += ~vect.at(i);  
  }
  
  return sum;
}