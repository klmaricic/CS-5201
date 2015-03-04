//////////////////////////////////////////////////////////////////////
/// @file ParamMatrix.hpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement a parameterized matrix
//////////////////////////////////////////////////////////////////////

/************************** Constructors/Destructor  **************************/
template <class T>
ParamMatrix<T>::ParamMatrix(int n)
{
  m_dataPtr = 0; //Check on this
  m_rowSize = 0;
}

template <class T>
ParamMatrix<T>::ParamMatrix(int numRows, int numCols)
{
  m_dataPtr = new T[numRows*numCols];
  m_rowSize = numCols;
}

/************************** Operators **************************/
template <class T>
const T& ParamMatrix<T>::operator()(const int row, const int col) const
{
  return m_dataPtr[m_rowSize*row+col];
  //check to make sure in bounds of the matrix
}

template <class T>
ParamMatrix<T> ParamMatrix<T>::operator+(const ParamMatrix<T>& rhs) const
{
  ParamMatrix<T> result(*this);
  
  for(int i = 0; i < result.getSize(); i++)
    result[i] += rhs[i]; //Check if should instead do result(r,c)
  
  return result;   
}





