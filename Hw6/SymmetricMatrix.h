//////////////////////////////////////////////////////////////////////
/// @file SymmetricMatrix.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement a parameterized matrix
//////////////////////////////////////////////////////////////////////

#ifndef __SymmetricMatrix_H_INCLUDED
#define __SymmetricMatrix_H_INCLUDED

#include <stdexcept>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "LinearVector.h"
#include "BaseMatrix.h"

template<class T>
class ParamMatrix;

template<class T>
class UpperMatrix;

template<class T>
class LowerMatrix;

template<class T>
class DiagonalMatrix;

template<class T>
class TridiagonalMatrix;

template<class T>
class SymmetricMatrix: public BaseMatrix<T>
{
  public:
    /************************** Constructors/Destructor  **************************/
    /* Purpose: Constructor
       Pre:     none
       Post:    Creates an empty SymmetricMatrix object
    */
    SymmetricMatrix();

    /* Purpose: Constructor
       Pre:     none
       Post:    Creates an empty SymmetricMatrix object
    */
    SymmetricMatrix(int numRows, int numCols);

    /* Purpose: Constructor
       Pre:     T=T must be defined
       Post:    Creates a SymmetricMatrix object that is a copy of the argument
    */
    SymmetricMatrix(const SymmetricMatrix<T>& matrix);

    /* Purpose: Constructor
       Pre:     T=T must be defined
       Post:    Creates a SymmetricMatrix object that copies (and doubles) the lower portion of the argument
    */
    SymmetricMatrix(const ParamMatrix<T>& matrix);

    /* Purpose: Destructor
       Pre:     none
       Post:    Destructs the SymmetricMatrix object
    */
    virtual ~SymmetricMatrix();

    /************************** Operators **************************/
    /* Purpose: Parentheses operator
       Pre:     Row and col must be in the range of the SymmetricMatrix
       Post:    Returns the element located at row, col inside the SymmetricMatrix that can't be altered
    */
     virtual const T operator()(const int row, const int col) const;

    /* Purpose: Parentheses operator
       Pre:     Row and col must be in the range of the SymmetricMatrix
       Post:    Returns the element located at row, col inside the SymmetricMatrix that can be altered
    */
    virtual T& operator()(const int row, const int col);

    /* Purpose: Addition operator
       Pre:     T += T must be defined
       Post:    Returns the sum of the two matrices
    */
    SymmetricMatrix<T> operator+(const SymmetricMatrix<T>& rhs) const;

    /* Purpose: Addition operator
       Pre:     DiagonalMatrix<T>+SymmetricMatrix<T> must be defined
       Post:    Returns the sum of the two matrices
    */
    SymmetricMatrix<T> operator+(const DiagonalMatrix<T>& rhs) const;

    /* Purpose: Addition operator
       Pre:     ParamMatrix<T>+SymmetricMatrix<T> must be defined
       Post:    Returns the sum of the two matrices
    */
    ParamMatrix<T> operator+(const BaseMatrix<T>& rhs) const;

    /* Purpose: Subtraction operator
       Pre:     T-=T must be defined
       Post:    Returns the difference of the two matrices
    */
    SymmetricMatrix<T> operator-(const SymmetricMatrix<T>& rhs) const;

    /* Purpose: Subtraction operator
       Pre:     -DiagonalMatrix<T> must be defined
       Pre:     DiagonalMatrix<T>+SymmetricMatrix<T> must be defined
       Post:    Returns the difference of the two matrices
    */
    SymmetricMatrix<T> operator-(const DiagonalMatrix<T>& rhs) const;

    /* Purpose: Subtraction operator
       Pre:     -ParamMatrix<T> must be defined
       Pre:     ParamMatrix<T>+SymmetricMatrix<T> must be defined
       Post:    Returns the difference of the two matrices
    */
    ParamMatrix<T> operator-(const BaseMatrix<T>& rhs) const;

    /* Purpose: Negation operator
       Pre:     -T (negation) must be defined
       Pre:      T = T (assignment) must be defined
       Post:     Returns the negation of the calling matrix
    */
    SymmetricMatrix<T> operator-() const;

    /* Purpose: Multiplication operator
       Pre:     T*T must be defined
       Pre:     T = T (assignment) must be defined
       Post:    Returns the product of the two matrices
    */
    ParamMatrix<T> operator*(const DiagonalMatrix<T>& rhs) const;

    /* Purpose: Multiplication operator
       Pre:     T*T must be defined
       Pre:     T+=T must be defined
       Post:    Returns the product of the two matrices
    */
    ParamMatrix<T> operator*(const BaseMatrix<T>& rhs) const;

    /* Purpose: Multiplication operator
       Pre:     T*=T must be defined
       Post:    Returns the product of matrix*T
    */
    SymmetricMatrix<T> operator*(const T rhs) const;

     /* Purpose: Multiplication operator
       Pre:     T*T must be defined
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
       Post:    Returns an ostream that represents the given SymmetricMatrix
    */
    template<class U>
    friend std::ostream& operator<<(std::ostream & stream, const SymmetricMatrix<T>& matrix);

    /* Purpose: Ifstream operator
       Pre:     >> T (stream assignment) must be defined
       Post:    Returns an ifstream that represents the given SymmetricMatrix
    */
    template<class U>
    friend std::ifstream& operator>>(std::ifstream & stream, SymmetricMatrix<T>& matrix);

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

    /* Purpose: Sets the size of the calling SymmetricMatrix
       Pre:     None
       Post:    If the calling SymmetricMatrix's size did not match the setSize parameter values, then it deletes all of its old elements, sets its size, and allocates new elements
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
#include "SymmetricMatrix.hpp"
#endif

