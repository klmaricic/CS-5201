//////////////////////////////////////////////////////////////////////
/// @file findiff.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement Gaussian Elimination
//FIXME
//////////////////////////////////////////////////////////////////////

#ifndef FINDIFF_H
#define FINDIFF_H

#include "parammatrix.h"

#include <string.h>
#include <math.h>

template<class T, class T_func>
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
    void operator()( const T lower, const T upper, const int n );
    int map( const int k, const int j, const int n );
};
#include "findiff.hpp"
#endif

