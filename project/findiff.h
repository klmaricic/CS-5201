//////////////////////////////////////////////////////////////////////
/// @file FinDiff.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement Gaussian Elimination
//FIXME
//////////////////////////////////////////////////////////////////////

#ifndef __FiniteDifference_H_INCLUDED
#define __FinitieDifference_H_INCLUDED

#include <math.h>
#include <string.h>

template<class T, typename T_func>
class FinDiff
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
    //void operator()(ParamMatrix<T>& matrix, LinearVector<T>& vector) const;
    void operator()( const T lower, const T upper, const int n );
};
#include "GaussianSolver.hpp"
#endif

