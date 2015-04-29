//////////////////////////////////////////////////////////////////////
/// @file parammatrix.hpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement a parameterized matrix
//////////////////////////////////////////////////////////////////////

/************************** Constructors/Destructor  **************************/
template <class T>
ParamMatrix<T>::ParamMatrix()
{
  m_dataPtr = 0;
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
  m_rowSize = matrix.rowSize();
  m_numRows = matrix.numRows();
  m_dataPtr = new T[m_numRows*m_rowSize];

  for(int i = 0; i < getSize(); i++)
    m_dataPtr[i] = matrix[i];  
}

template <class T>
ParamMatrix<T>::ParamMatrix(const BaseMatrix<T>& matrix)
{
  m_rowSize = matrix.rowSize();
  m_numRows = matrix.numRows();
  m_dataPtr = new T[m_numRows*m_rowSize];

  for(int row = 0; row < m_numRows; row++)
  {
    for(int col = 0; col < m_rowSize; col++)
      (*this)(row, col) = matrix(row, col);
  }
}

template <class T>
ParamMatrix<T>::~ParamMatrix()
{
  delete[] m_dataPtr;
}

/************************** Operators **************************/
template <class T>
const T ParamMatrix<T>::operator()(const int row, const int col) const
{
  if( row >= numRows() || col >= rowSize() || row < 0 || col < 0 )
    throw std::out_of_range( "An argument is outside of the matrix." );

  return m_dataPtr[m_rowSize*row+col];
}

template <class T>
T& ParamMatrix<T>::operator()(const int row, const int col)
{
  if( row >= numRows() || col >= rowSize() || row < 0 || col < 0 )
    throw std::out_of_range( "An argument is outside of the matrix." );

  return m_dataPtr[m_rowSize*row+col];
}

template <class T>
ParamMatrix<T> ParamMatrix<T>::operator+(const ParamMatrix<T>& rhs) const
{
  ParamMatrix<T> result(*this);
  
  for(int i = 0; i < result.getSize(); i++)
    result[i] += rhs[i];
  
  return result;   
}

template <class T>
ParamMatrix<T> ParamMatrix<T>::operator+(const UpperMatrix<T>& rhs) const
{
  ParamMatrix<T> result(*this);

  for(int row = 0; row < m_numRows; row++)
  {
    for(int col = row; col < m_rowSize; col++)
      result(row, col) += rhs(row, col);
  }

  return result;
}

template <class T>
ParamMatrix<T> ParamMatrix<T>::operator+(const LowerMatrix<T>& rhs) const
{
  ParamMatrix<T> result(*this);

  for(int row = 0; row < m_numRows; row++)
  {
    for(int col = 0; col <= row; col++)
      result(row, col) += rhs(row, col);
  }

  return result; 
}

template <class T>
ParamMatrix<T> ParamMatrix<T>::operator+(const SymmetricMatrix<T>& rhs) const
{
  ParamMatrix<T> result(*this);

  for(int row = 0; row < m_numRows; row++)
  {
    for(int col = 0; col < m_rowSize; col++)
      result(row, col) += rhs(row, col);
  }

  return result;
}

template <class T>
ParamMatrix<T> ParamMatrix<T>::operator-(const ParamMatrix<T>& rhs) const
{
  ParamMatrix<T> result(*this);
  
  for(int i = 0; i < result.getSize(); i++)
    result[i] -= rhs[i];
 
  return result;   
}

template <class T>
ParamMatrix<T> ParamMatrix<T>::operator-(const UpperMatrix<T>& rhs) const
{
  ParamMatrix<T> result(*this);

  for(int row = 0; row < m_numRows; row++)
  {
    for(int col = row; col < m_rowSize; col++)
      result(row, col) -= rhs(row, col);
  }

  return result;
}

template <class T>
ParamMatrix<T> ParamMatrix<T>::operator-(const LowerMatrix<T>& rhs) const
{
  ParamMatrix<T> result(*this);

  for(int row = 0; row < m_numRows; row++)
  {
    for(int col = 0; col <= row; col++)
      result(row, col) -= rhs(row, col);
  }

  return result;
}

template <class T>
ParamMatrix<T> ParamMatrix<T>::operator-(const SymmetricMatrix<T>& rhs) const
{
  ParamMatrix<T> result(*this);

  for(int row = 0; row < m_numRows; row++)
  {
    for(int col = 0; col < m_rowSize; col++)
      result(row, col) -= rhs(row, col);
  }

  return result;
}

template <class T>
ParamMatrix<T> ParamMatrix<T>::operator-() const
{
  ParamMatrix<T> result(*this);

  for(int i = 0; i < result.getSize(); i++)
    result[i] = -result[i];

  return result;
}

template <class T>
ParamMatrix<T> ParamMatrix<T>::operator*(const BaseMatrix<T>& rhs) const
{
  if(m_rowSize != rhs.numRows())
    throw std::invalid_argument("The number of columns in the first matrix does not equal the number of rows in the second matrix, so multiplication can't be done.");
  
  ParamMatrix<T> result(m_numRows, rhs.rowSize());

  for(int i = 0; i < result.m_numRows; i++)
  {
    for(int j = 0; j < result.m_rowSize; j++)
    {
      result(i,j) = 0;
      for(int k = 0; k < m_rowSize; k++)
      {
        result(i,j) += (*this)(i,k)*rhs(k,j);        
      }
    }
  } 

  return result; 
} 

template <class T>
ParamMatrix<T> ParamMatrix<T>::operator*(const T rhs) const
{
  ParamMatrix<T> result(*this);

  for(int i = 0; i < result.getSize(); i++)
    result[i] *= rhs;

  return result;
}

template <class T>
ParamMatrix<T> ParamMatrix<T>::operator*(const LinearVector<T>& rhs) const
{
  if(m_rowSize != rhs.getSize())
    throw std::invalid_argument("The number of columns in the matrix does not equal the number of entries in the vector, so multiplication can't be done.");

  ParamMatrix<T> result(m_numRows, 1);

  for(int i = 0; i < result.m_numRows; i++)
  {
    result(i,0) = 0;
    for(int j = 0; j < m_rowSize; j++)
      result(i,0) += (*this)(i,j)*rhs[j];
  } 
  return result;
}

template <class T>
T& ParamMatrix<T>::operator[](const int i)
{
  return m_dataPtr[i];
}

template <class T>
const T& ParamMatrix<T>::operator[](const int i) const
{
  return m_dataPtr[i];
}

/************************** Stream Operators **************************/
template <class T>
std::ostream& operator<<(std::ostream & stream, const ParamMatrix<T>& matrix)
{
  for(int i = 0; i < matrix.numRows(); i++)
  {
    stream << "<";
	
    for(int j = 0; j < matrix.rowSize() - 1; j++)
      stream << matrix[i*matrix.rowSize()+j] << ", ";

    stream << matrix[i*matrix.rowSize()+matrix.rowSize()-1] << ">" << std::endl;
  }
  
  return stream;
}

template <class T>
std::ifstream& operator>>(std::ifstream & file, ParamMatrix<T> &rhs)
{
  for(int i = 0; i < rhs.getSize(); i++)  	
    file >> rhs[i]; 
 
  return file;
}

/************************** Other **************************/
template <class T>
int ParamMatrix<T>::rowSize() const
{
  return m_rowSize;
}

template <class T>
void ParamMatrix<T>::setSize(int numRows, int numCols)
{
  if(numRows != m_numRows || numCols != m_rowSize)
  {
    delete [] m_dataPtr;
    m_dataPtr = new T[numRows*numCols];
    m_rowSize = numCols;
    m_numRows = numRows;
  }
}

template <class T>
int ParamMatrix<T>::numRows() const
{
  return m_numRows;
}

template <class T>
int ParamMatrix<T>::getSize() const
{
  return m_rowSize*m_numRows;;
}

template <class T>
ParamMatrix<T> ParamMatrix<T>::transpose() const
{
  ParamMatrix<T> result(m_rowSize, m_numRows);

  for(int i = 0; i < m_numRows; i++)
  {  
    for(int j = 0; j <m_rowSize; j++)
      result(j,i) = (*this)(i,j);
  }

  return result;
}
