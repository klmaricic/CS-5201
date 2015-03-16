//////////////////////////////////////////////////////////////////////
/// @file ParamMatrix.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement a parameterized matrix
//////////////////////////////////////////////////////////////////////

#ifndef __ParamMatrix_H_INCLUDED
#define __ParamMatrix_H_INCLUDED

#include <stdexcept>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "LinearVector.h"

template<class T>
class ParamMatrix
{
  public:
    /************************** Constructors/Destructor  **************************/
    /* Purpose: Constructor
       Pre:     none
       Post:    Creates an empty ParamMatrix object
    */
    ParamMatrix();

    /* Purpose: Constructor
       Pre:     none
       Post:    Creates an empty ParamMatrix object
    */
    ParamMatrix(int numRows, int numCols);
    
    /* Purpose: Constructor
       Pre:     none
       Post:    Creates a ParamMatrix object that is a copy of the argument
    */
    ParamMatrix(const ParamMatrix<T>& matrix);
    
    /* Purpose: Destructor
       Pre:     none
       Post:    Destructs the  ParamMatrix object
    */
    ~ParamMatrix();
	
    /************************** Operators **************************/
    /* Purpose: Parentheses operator
       Pre:     Row and col must be in the range of the ParamMatrix
       Post:    Returns the element located at row, col inside the ParamMatrix that can't be altered
    */
    const T& operator()(const int row, const int col) const;

    /************************** Operators **************************/
    /* Purpose: Parentheses operator
       Pre:     Row and col must be in the range of the ParamMatrix
       Post:    Returns the element located at row, col inside the ParamMatrix that can be altered
    */
    T& operator()(const int row, const int col);

    /************************** Operators **************************/
    /* Purpose: Addition operator
       Pre:     T += T must be defined
       Post:    Returns the sum of the two ParamMatrices
    */
    ParamMatrix<T> operator+(const ParamMatrix<T>& rhs) const;
	
    /* Purpose: Subtraction operator
       Pre:     T-=T must be defined
       Post:    Returns the difference of the two ParamMatrices
    */
    ParamMatrix<T> operator-(const ParamMatrix<T>& rhs) const;

    /* Purpose: Multiplication operator
       Pre:     T*T must be defined
       Pre:     T+=T must be defined
       Post:    Returns the product of the two ParamMatrices
    */
    ParamMatrix<T> operator*(const ParamMatrix<T>& rhs) const;   


    /* Purpose: Multiplication operator
       Pre:     T*=T must be defined
       Post:    Returns the product of paramMatrix*T
    */
    ParamMatrix<T> operator*(const T rhs) const;


    /* Purpose: Multiplication operator
       Pre:     T*=T must be defined
       Pre:     T+=T must be defined
       Post:    Returns the product of the two ParamMatrices
    */
    ParamMatrix<T> operator*(const LinearVector<T>& rhs) const;

    /* Purpose: Brackets operator
       Pre:     i must be in the range of the ParamMatrix
       Pre:     T* (pointer) must be defined
       Pre:     T*[int] must be defined
       Post:    Returns the element located at index i in the ParamMatrix. The returned value can be modified.
    */
    T& operator[](const int i);
	
    /* Purpose: Brackets operator
       Pre:     i must be in the range of the ParamMatrix
       Pre:     T* (pointer) must be defined
       Pre:     T*[int] must be defined
       Post:    Returns the element located at index i in the ParamMatrix. The returned value cannot be modified.
    */
    const T& operator[](const int i) const;
	
    /************************** Stream Operators **************************/
    /* Purpose:	Ostream operator
       Pre:     << T (stream) must be defined
       Post:    Returns an ostream that represents the given ParamMatrix
    */
    template<class U> 
    friend std::ostream& operator<< (std::ostream & stream, const ParamMatrix<T>& matrix);
	
    /* Purpose:	Ifstream operator
       Pre:     >> T (stream assignment) must be defined
       Post:    Returns an ifstream that represents the given ParamMatrix
    */
    template<class U> 
    friend std::ifstream& operator>> (std::ifstream & stream, ParamMatrix<T> &rhs);
	
    /************************** Other **************************/	
    /* Purpose: Gets the size of the rows (number of columns)
       Pre:     None
       Post:    Returns the row size/number of columns of the given ParamMatrix
    */
    int rowSize() const;
	
    /* Purpose: Gets the number of rows (size of the columns)
       Pre:     None
       Post:    Returns the number of rows/size of the  columns of the given ParamMatrix
    */
    int numRows() const;
	
    /* Purpose:	Sets the size of the calling ParamMatrix
       Pre:     delete [] T must be defined
       Pre:     T* = new T[int] must be defined
       Post:    If the calling ParamMatrix's size did not match the setSize parameter values, then it deletes all of its old elements, sets its size, and allocates new elements
    */
    void setSize(int numRows, int numCols);
	
        
    /* Purpose: Returns the size of the calling ParamMatrix
       Pre:     None
       Post:    Returns the size of the calling ParamMatrix
    */
    int getSize() const;

    /* Purpose: Returns the transpose of the calling ParamMatrix
       Pre:     T=T must be defined
       Post:    Returns the transpose of the calling ParamMatrix
    */
    ParamMatrix<T> transpose() const;	
	
  private:
    T* m_dataPtr;
    int m_rowSize;
    int m_numRows;
};
#include "ParamMatrix.hpp"
#endif
