//////////////////////////////////////////////////////////////////////
/// @file DiagonalMatrix.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement a parameterized matrix
//////////////////////////////////////////////////////////////////////

#ifndef __DiagonalMatrix_H_INCLUDED
#define __DiagonalMatrix_H_INCLUDED

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
#include "UpperMatrix.h"
#include "SymmetricMatrix.h"
#include "TridiagonalMatrix.h"

template<class T>
class DiagonalMatrix: public BaseMatrix<T>
{
  public:
    /************************** Constructors/Destructor  **************************/
    /* Purpose: Constructor
       Pre:     none
       Post:    Creates an empty DiagonalMatrix object
    */
    DiagonalMatrix();

    /* Purpose: Constructor
       Pre:     none
       Post:    Creates an empty DiagonalMatrix object
    */
    DiagonalMatrix(int numRows, int numCols);

    /* Purpose: Constructor
       Pre:     T=T must be defined
       Post:    Creates an DiagonalMatrix object that is a copy of the argument
    */
    DiagonalMatrix(const DiagonalMatrix<T>& matrix);

    /* Purpose: Constructor
       Pre:     T=T must be defined
       Post:    Creates an DiagonalMatrix object that copies the diagonal of the argument
    */
    DiagonalMatrix(const BaseMatrix<T>& matrix);

    /* Purpose: Destructor
       Pre:     none
       Post:    Destructs the  DiagonalMatrix object
    */
    virtual ~DiagonalMatrix();

    /************************** Operators **************************/
    /* Purpose: Parentheses operator
       Pre:     Row and col must be in the range of the DiagonalMatrix
       Post:    Returns the element located at row, col inside the DiagonalMatrix that can't be altered
    */
     virtual const T operator()(const int row, const int col) const;

    /* Purpose: Parentheses operator
       Pre:     Row and col must be in the range of the DiagonalMatrix
       Pre:     The requested element must be in the diagonal of the matrix
       Post:    Returns the element located at row, col inside the DiagonalMatrix that can be altered
    */
    virtual T& operator()(const int row, const int col);

    /* Purpose: Addition operator
       Pre:     T += T must be defined
       Post:    Returns the sum of the two matrices
    */
    DiagonalMatrix<T> operator+(const DiagonalMatrix<T>& rhs) const;

    /* Purpose: Addition operator
       Pre:     ParamMatrix<T>+DiagonalMatrix<T> must be defined
       Post:    Returns the sum of the two matrices
    */
    ParamMatrix<T> operator+(const ParamMatrix<T>& rhs) const;

    /* Purpose: Addition operator
       Pre:     T += T must be defined
       Post:    Returns the sum of the two matrices
    */
    UpperMatrix<T> operator+(const UpperMatrix<T>& rhs) const;

    /* Purpose: Addition operator
       Pre:     T += T must be defined
       Post:    Returns the sum of the two matrices
    */
    LowerMatrix<T> operator+(const LowerMatrix<T>& rhs) const;

    /* Purpose: Addition operator
       Pre:     T += T must be defined
       Post:    Returns the sum of the two matrices
    */
    SymmetricMatrix<T> operator+(const SymmetricMatrix<T>& rhs) const;

    /* Purpose: Addition operator
       Pre:     T += T must be defined
       Post:    Returns the sum of the two matrices
    */
    TridiagonalMatrix<T> operator+(const TridiagonalMatrix<T>& rhs) const;

    /* Purpose: Subtraction operator
       Pre:     T-=T must be defined
       Post:    Returns the difference of the two matrices
    */
    DiagonalMatrix<T> operator-(const DiagonalMatrix<T>& rhs) const;

    /* Purpose: Subtraction operator
       Pre:     -ParamMatrix<T> must be defined
       Pre:     DiagonalMatrix<T>+ParamMatrix<T> must be defined
       Post:    Returns the difference of the two matrices
    */
    ParamMatrix<T> operator-(const ParamMatrix<T>& rhs) const;

    /* Purpose: Subtraction operator
       Pre:     -UpperMatrix<T> must be defined
       Pre:     DiagonalMatrix<T>+UpperMatrix<T> must be defined
       Post:    Returns the difference of the two matrices
    */
    UpperMatrix<T> operator-(const UpperMatrix<T>& rhs) const;

    /* Purpose: Subtraction operator
       Pre:     -LowerMatrix<T> must be defined
       Pre:     DiagonalMatrix<T>+LowerMatrix<T> must be defined
       Post:    Returns the difference of the two matrices
    */
    LowerMatrix<T> operator-(const LowerMatrix<T>& rhs) const;

    /* Purpose: Subtraction operator
       Pre:     -SymmetricMatrix<T> must be defined
       Pre:     DiagonalMatrix<T>+SymmetricMatrix<T> must be defined
       Post:    Returns the difference of the two matrices
    */
    SymmetricMatrix<T> operator-(const SymmetricMatrix<T>& rhs) const;

    /* Purpose: Subtraction operator
       Pre:     -TridiagonalMatrix<T> must be defined
       Pre:     DiagonalMatrix<T>+TridiagonalMatrix<T> must be defined
       Post:    Returns the difference of the two matrices
    */
    TridiagonalMatrix<T> operator-(const TridiagonalMatrix<T>& rhs) const;

    /* Purpose: Negation operator
       Pre:     -T (negation) must be defined
       Pre:      T = T (assignment) must be defined
       Post:     Returns the negation of the calling matrix
    */
    DiagonalMatrix<T> operator-() const;

    /* Purpose: Multiplication operator
       Pre:     T*T must be defined
       Post:    Returns the product of the two matrices
    */
    DiagonalMatrix<T> operator*(const DiagonalMatrix<T>& rhs) const;

    /* Purpose: Multiplication operator
       Pre:     T*T must be defined
       Pre:     T=T must be defined
       Post:    Returns the product of the two matrices
    */
    ParamMatrix<T> operator*(const ParamMatrix<T>& rhs) const;

    /* Purpose: Multiplication operator
       Pre:     T*T must be defined
       Pre:     T=T must be defined
       Post:    Returns the product of the two matrices
    */
    UpperMatrix<T> operator*(const UpperMatrix<T>& rhs) const;

    /* Purpose: Multiplication operator
       Pre:     T*T must be defined
       Pre:     T=T must be defined
       Post:    Returns the product of the two matrices
    */
    LowerMatrix<T> operator*(const LowerMatrix<T>& rhs) const;

    /* Purpose: Multiplication operator
       Pre:     T*=T must be defined
       Post:    Returns the product of matrix*T
    */
    DiagonalMatrix<T> operator*(const T rhs) const;

    /* Purpose: Multiplication operator
       Pre:     T*T must be defined
       Pre:     T=T must be defined
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
       Post:    Returns an ostream that represents the given matrix
    */
    template<class U>
    friend std::ostream& operator<<(std::ostream & stream, const DiagonalMatrix<T>& matrix);

    /* Purpose: Ifstream operator
       Pre:     >> T (stream assignment) must be defined
       Post:    Returns an ifstream that represents the given matrix
    */
    template<class U>
    friend std::ifstream& operator>>(std::ifstream & stream, DiagonalMatrix<T>& matrix);

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

    /* Purpose: Sets the size of the calling matrix
       Pre:     None
       Post:    If the calling DiagonalMatrix's size did not match the setSize parameter values, then it deletes all of its old elements, sets its size, and allocates new elements
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
#include "DiagonalMatrix.hpp"
#endif

