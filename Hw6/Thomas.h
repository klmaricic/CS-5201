//////////////////////////////////////////////////////////////////////
/// @file GaussianSolver.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement the Thomas algorithm
//////////////////////////////////////////////////////////////////////

#ifndef __Thomas_H_INCLUDED
#define __Thomas_H_INCLUDED

#include <math.h>
#include <string.h>

template<class T>
class Thomas
{
  public:
    /************************** Operator **************************/
    /* Purpose: Parenthesis operator
       Pre:     T=T must be defined
       Pre:     T/T must be defined
       Pre:     T -= T must be defined
       Pre:     T*T must be defined
       Pre:     T-T must be defined
       Post:    Prints out the solution to the system using Cholesky decomposition
    */
    void operator()(TridiagonalMatrix<T>& matrix, LinearVector<T>& vector) const;
};
#include "Thomas.hpp"
#endif

