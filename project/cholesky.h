//////////////////////////////////////////////////////////////////////
/// @file cholesky.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement Cholesky decomposition
//////////////////////////////////////////////////////////////////////

#ifndef CHOLESKY_H
#define CHILESKY_H

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
#include "cholesky.hpp"
#endif

