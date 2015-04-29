//////////////////////////////////////////////////////////////////////
/// @file boundfunction.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement the boundary functions
//FIXME
//////////////////////////////////////////////////////////////////////

#ifndef BOUNDFUNCTION_H
#define BOUNDFUNCTION_H


template <class T>
class BoundFunction
{
  public:
    T operator()(T lhs, T rhs);
};
#include "boundfunction.hpp"
#endif

