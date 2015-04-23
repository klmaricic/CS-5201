//////////////////////////////////////////////////////////////////////
/// @file GaussianSolver.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement Cholesky decomposition
//////////////////////////////////////////////////////////////////////

#ifndef __Cholesky_H_INCLUDED
#define __Cholesky_H_INCLUDED

#include <math.h>
#include <string.h>

template<class T>
class Cholesky
{
  public:
    /************************** Operator **************************/
    /* Purpose: Parenthesis operator
       Pre:     T = int must be defined
       Pre:     T += T must be defined
       Pre:     T*T must be defined
       Pre:     T-T must be defined
       Pre:     T/T must be defined
       Pre:     sqrt(T) must be defined
       Pre:     T -= T must be defined
       Post:    Prints out the solution to the system using Cholesky decomposition
    */
    void operator()(SymmetricMatrix<T>& matrix, LinearVector<T>& vector) const;
};
#include "Cholesky.hpp"
#endif

