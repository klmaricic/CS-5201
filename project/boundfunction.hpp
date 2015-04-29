//////////////////////////////////////////////////////////////////////
/// @file boundfunction.hpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement the boundary functions
//FIXME
//////////////////////////////////////////////////////////////////////


template <class T>
T BoundFunction<T>::operator()(const T lhs, const T rhs)
{
  if(lhs == 0)
    return sin(rhs);
  else if(rhs == 0)
    return sin(lhs);
  
  if(lhs != M_PI && rhs != M_PI)
    throw domain_error("Unknown parameters passed to bounds function.");
  return 0;
}
