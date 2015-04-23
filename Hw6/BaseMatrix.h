
//////////////////////////////////////////////////////////////////////
/// @file BaseMatrix.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement a parameterized matrix
//////////////////////////////////////////////////////////////////////

#ifndef __BaseMatrix_H_INCLUDED
#define __BaseMatrix_H_INCLUDED

#include <stdexcept>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "LinearVector.h"



template<class T>
class BaseMatrix
{
  public:
 /************************** Constructors/Destructor  **************************/
    /* Purpose: Destructor
       Pre:     none
       Post:    Destructs the  UpperMatrix object
    */
    virtual ~BaseMatrix() {};

    /************************** Operators **************************/
    /* Purpose: Parentheses operator
       Pre:     The requested element must be in the range of the actual array
       Post:    Returns the element located at row, col inside the matrix that can't be altered
    */
    virtual const T operator()(const int row, const int col) const =0;

    /* Purpose: Parentheses operator
       Pre:     Row and col must be in the range of the UpperMatrix
       Pre:     The requested element must be in the range of the actual array
       Post:    Returns the element located at row, col inside the matrix that can be altered
    */
    virtual T& operator()(const int row, const int col) =0;

    /* Purpose: Brackets operator
       Pre:     i must be in the range of the matrix
       Post:    Returns the element located at index i in the matrix. The returned value can be modified.
    */
    virtual T& operator[](const int i) =0;

    /* Purpose: Brackets operator
       Pre:     i must be in the range of the matrix
       Post:    Returns the element located at index i in the matrix. The returned value cannot be modified.
    */
    virtual const T& operator[](const int i) const =0;

     /************************** Other **************************/
    /* Purpose: Gets the size of the rows (number of columns)
       Pre:     None
       Post:    Returns the row size/number of columns of the given matrix
    */
    virtual int rowSize() const =0;

    /* Purpose: Gets the number of rows (size of the columns)
       Pre:     None
       Post:    Returns the number of rows/size of the  columns of the given matrix
    */
    virtual int numRows() const =0;

    /* Purpose: Sets the size of the calling matrix
       Pre:     None
       Post:    If the calling matrix's size did not match the setSize parameter values, then it deletes all of its old elements, sets its size, and allocates new elements
    */
    virtual void setSize(int numRows, int numCols) =0;
};
#endif

