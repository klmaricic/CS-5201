//////////////////////////////////////////////////////////////////////
/// @file GaussianSolver.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement Gaussian Elimination
//////////////////////////////////////////////////////////////////////

#ifndef __GaussianSolver_H_INCLUDED
#define __GaussianSolver_H_INCLUDED

#include <math.h>
#include <string.h>

template<class T>
class GaussianSolver
{
  public:
    /************************** Operator **************************/
    /* Purpose: Parenthesis operator
       Pre:     T = int must be defined
       Pre:     fabs(T) must be defined
       Pre:     T=int must be defined
       Pre:     T==int must be defined
       Pre:     T/T must be defined
       Pre:     T-=T must be defined
       Pre:     T*double must be defined
       Pre:     T=T must be defined
       Pre:     T/=T must be defined
       Post:    Prints out the solution to the system using scaled partial pivoting and Gaussian elimination
    */
    void operator()(ParamMatrix<T>& matrix, LinearVector<T>& vector) const;
};
#include "GaussianSolver.hpp"
#endif

