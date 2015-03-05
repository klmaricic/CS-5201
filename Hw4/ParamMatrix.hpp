//////////////////////////////////////////////////////////////////////
/// @file ParamMatrix.hpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement a parameterized matrix
//////////////////////////////////////////////////////////////////////

/************************** Constructors/Destructor  **************************/
template <class T>
ParamMatrix<T>::ParamMatrix()
{
  m_dataPtr = 0; //Check on this
  m_rowSize = 0;
}

template <class T>
ParamMatrix<T>::ParamMatrix(int numRows, int numCols)
{
  m_dataPtr = new T[numRows*numCols];
  m_rowSize = numCols;
  m_numRows = numRows;
}

template <class T>
ParamMatrix<T>::ParamMatrix(const ParamMatrix<T>& matrix)
{

}

template <class T>
ParamMatrix<T>::~ParamMatrix()
{

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

template <class T>
ParamMatrix<T> ParamMatrix<T>::operator-(const ParamMatrix<T>& rhs) const
{
  ParamMatrix<T> result(*this);
  
  for(int i = 0; i < result.getSize(); i++)
    result[i] -= rhs[i]; //Check if should instead do result(r,c)
  
  return result;   
}

/************************** Stream Operators **************************/
template <class T>
std::ostream& operator<<(std::ostream & stream, const ParamMatrix<T>& matrix)
{
  for(int i = 0; i < matrix.numRows(); i++)
  {
    stream << "<";
	
    for(int j = 0; j < matrix.rowSize() - 1; j++)
      stream << matrix[i*j+1] << ", ";

    stream << matrix[matrix.getSize()-1] << ">" << std::endl;
  }
  
  return stream;
}

/************************** Other **************************/
template <class T>
int ParamMatrix<T>::rowSize() const
{
  return m_rowSize;
}

template <class T>
int ParamMatrix<T>::numRows() const
{
  return m_numRows;
}
