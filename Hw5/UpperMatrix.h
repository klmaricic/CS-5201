//////////////////////////////////////////////////////////////////////
/// @file UpperMatrix.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement a parameterized matrix
//////////////////////////////////////////////////////////////////////

#ifndef __UpperMatrix_H_INCLUDED
#define __UpperMatrix_H_INCLUDED

#include <stdexcept>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "LinearVector.h"
#include "BaseMatrix.h"
#include "LowerMatrix.h"
#include "ParamMatrix.h"

template<class T>
class UpperMatrix: public BaseMatrix<T>
{
  public:
    /************************** Constructors/Destructor  **************************/
    /* Purpose: Constructor
       Pre:     none
       Post:    Creates an empty UpperMatrix object
    */
    UpperMatrix();

    /* Purpose: Constructor
       Pre:     none
       Post:    Creates an empty UpperMatrix object
    */
    UpperMatrix(int numRows, int numCols);

    /* Purpose: Constructor
       Pre:     none
       Post:    Creates an UpperMatrix object that is a copy of the argument
    */
    UpperMatrix(const UpperMatrix<T>& matrix);

    /* Purpose: Constructor
       Pre:     none
       Post:    Creates an UpperMatrix object that copies the upper portion of the argument
    */
    UpperMatrix(const ParamMatrix<T>& matrix);

    /* Purpose: Destructor
       Pre:     none
       Post:    Destructs the  UpperMatrix object
    */
    virtual ~UpperMatrix();

    /************************** Operators **************************/
    /* Purpose: Parentheses operator
       Pre:     Row and col must be in the range of the UpperMatrix
       Post:    Returns the element located at row, col inside the UpperMatrix that can't be altered
    */
     virtual const T operator()(const int row, const int col) const;

    /* Purpose: Parentheses operator
       Pre:     Row and col must be in the range of the UpperMatrix
       Pre:     The requested element must not be part of the lower triangle portion of the matrix
       Post:    Returns the element located at row, col inside the UpperMatrix that can be altered
    */
    virtual T& operator()(const int row, const int col);

    /* Purpose: Addition operator
       Pre:     T += T must be defined
       Post:    Returns the sum of the two matrices
    */
    UpperMatrix<T> operator+(const UpperMatrix<T>& rhs) const;

    /* Purpose: Addition operator
       Pre:     T += T must be defined
       Post:    Returns the sum of the two matrices
    */
    ParamMatrix<T> operator+(const LowerMatrix<T>& rhs) const;

    /* Purpose: Addition operator
       Pre:     T += T must be defined
       Post:    Returns the sum of the two matrices
    */
    ParamMatrix<T> operator+(const ParamMatrix<T>& rhs) const;

    /* Purpose: Subtraction operator
       Pre:     T-=T must be defined
       Post:    Returns the difference of the two matrices
    */
    UpperMatrix<T> operator-(const UpperMatrix<T>& rhs) const;

    /* Purpose: Subtraction operator
       Pre:     T-=T must be defined
       Post:    Returns the difference of the two matrices
    */
    ParamMatrix<T> operator-(const ParamMatrix<T>& rhs) const;

    /* Purpose: Subtraction operator
       Pre:     T-=T must be defined
       Post:    Returns the difference of the two matrices
    */
    ParamMatrix<T> operator-(const LowerMatrix<T>& rhs) const;

    /* Purpose: Negation operator
       Pre:     -T (negation) must be defined
       Pre:      T = T (assignment) must be defined
       Post:     Returns the negation of the calling matrix
    */
    UpperMatrix<T> operator-() const;

    
    /* Purpose: Multiplication operator
       Pre:     T*T must be defined
       Pre:     T+=T must be defined
       Post:    Returns the product of the two matrices
    */
    UpperMatrix<T> operator*(const UpperMatrix<T>& rhs) const;

    /* Purpose: Multiplication operator
       Pre:     T*T must be defined
       Pre:     T+=T must be defined
       Post:    Returns the product of the two matrices
    */
    ParamMatrix<T> operator*(const ParamMatrix<T>& rhs) const;

    /* Purpose: Multiplication operator
       Pre:     T*T must be defined
       Pre:     T+=T must be defined
       Post:    Returns the product of the two matrices
    */
    ParamMatrix<T> operator*(const LowerMatrix<T>& rhs) const;

    /* Purpose: Multiplication operator
       Pre:     T*=T must be defined
       Post:    Returns the product of matrix*T
    */
    UpperMatrix<T> operator*(const T rhs) const;

    /* Purpose: Multiplication operator
       Pre:     T*=T must be defined
       Pre:     T+=T must be defined
       Post:    Returns the product of the matrix and vetor
    */
    ParamMatrix<T> operator*(const LinearVector<T>& rhs) const;    

    /* Purpose: Brackets operator
       Pre:     i must be in the range of the matrix
       Post:    Returns the element located at index i in the matrix. The returned value can be modified.
    */
    virtual T& operator[](const int i);

    /* Purpose: Brackets operator
       Pre:     i must be in the range of the matrix
       Post:    Returns the element located at index i in the matrix. The returned value cannot be modified.
    */
    virtual const T& operator[](const int i) const;

    /************************** Stream Operators **************************/
    /* Purpose: Ostream operator
       Pre:     << T (stream) must be defined
       Post:    Returns an ostream that represents the given UpperMatrix
    */
    template<class U>
    friend std::ostream& operator<<(std::ostream & stream, const UpperMatrix<T>& matrix);

    /* Purpose: Ifstream operator
       Pre:     >> T (stream assignment) must be defined
       Post:    Returns an ifstream that represents the given UpperMatrix
    */
    template<class U>
    friend std::ifstream& operator>>(std::ifstream & stream, UpperMatrix<T>& matrix);

    /************************** Other **************************/
    /* Purpose: Gets the size of the rows (number of columns)
       Pre:     None
       Post:    Returns the row size/number of columns of the given matrix
    */
    virtual int rowSize() const;

    /* Purpose: Gets the number of rows (size of the columns)
       Pre:     None
       Post:    Returns the number of rows/size of the  columns of the given matrix
    */
    virtual int numRows() const;

    /* Purpose: Sets the size of the calling UpperMatrix
       Pre:     None
       Post:    If the calling UpperMatrix's size did not match the setSize parameter values, then it deletes all of its old elements, sets its size, and allocates new elements
    */
    virtual void setSize(int numRows, int numCols);

    /* Purpose: Gets the actual size of the matrix
       Pre:     None
       Post:    Returns the actual size of the matrix
    */
    int actualSize() const;  

    /* Purpose: Gets the theoretical size of the matrix (size of file's matrix)
       Pre:     None
       Post:    Returns the theoretical size of the matrix
    */
    int theoSize() const;

  private:
    T* m_dataPtr;
    int m_rowSize;
    int m_numRows;
};
#include "UpperMatrix.hpp"
#endif

