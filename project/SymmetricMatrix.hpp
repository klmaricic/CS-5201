//////////////////////////////////////////////////////////////////////
/// @file SymmetricMatrix.hpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement a parameterized matrix
//////////////////////////////////////////////////////////////////////

/************************** Constructors/Destructor  **************************/
template <class T>
SymmetricMatrix<T>::SymmetricMatrix()
{
  m_dataPtr = 0;
  m_rowSize = 0;
}

template <class T>
SymmetricMatrix<T>::SymmetricMatrix(int numRows, int numCols)
{
  m_dataPtr = new T[numRows*(numRows+1)/2];
  m_rowSize = numCols;
  m_numRows = numRows;
}

template <class T>
SymmetricMatrix<T>::SymmetricMatrix(const SymmetricMatrix<T>& matrix)
{
  m_rowSize = matrix.rowSize();
  m_numRows = matrix.numRows();
  m_dataPtr = new T[matrix.actualSize()];

  for(int i = 0; i < actualSize(); i++)
    m_dataPtr[i] = matrix[i];
}

template <class T>
SymmetricMatrix<T>::SymmetricMatrix(const ParamMatrix<T>& matrix)
{
  int index = 0;
  int rowNum = 0;

  m_rowSize = matrix.rowSize();
  m_numRows = matrix.numRows();
  m_dataPtr = new T[m_numRows*(m_numRows+1)/2];

  for(int i = 0; i < theoSize(); i++)
  {
    if(i%rowSize() <= rowNum)
    {
      m_dataPtr[index] = matrix[i];
      index++;
    }

    if(i%rowSize() == rowSize()-1)
      rowNum++;
  }
}

template <class T>
SymmetricMatrix<T>::~SymmetricMatrix()
{
  delete[] m_dataPtr;
}

/************************** Operators **************************/
template <class T>
const T SymmetricMatrix<T>::operator()(const int row, const int col) const
{
  if(row < col)
    return m_dataPtr[row + (col+1)*col/2];

  return m_dataPtr[col + (row+1)*row/2];
}

template <class T>
T& SymmetricMatrix<T>::operator()(const int row, const int col)
{
  if(row < col)
    return m_dataPtr[row + (col+1)*col/2];

  return m_dataPtr[col + (row+1)*row/2];
}

template <class T>
SymmetricMatrix<T> SymmetricMatrix<T>::operator+(const SymmetricMatrix<T>& rhs) const
{
  SymmetricMatrix<T> result(*this);

  for(int i = 0; i < result.actualSize(); i++)
    result[i] += rhs[i];

  return result;
}

template <class T>
SymmetricMatrix<T> SymmetricMatrix<T>::operator+(const DiagonalMatrix<T>& rhs) const
{
  return rhs+(*this);
}

template <class T>
ParamMatrix<T> SymmetricMatrix<T>::operator+(const BaseMatrix<T>& rhs) const
{
  ParamMatrix<T> result(rhs);

  return result+(*this);
}

template <class T>
SymmetricMatrix<T> SymmetricMatrix<T>::operator-(const SymmetricMatrix<T>& rhs) const
{
  SymmetricMatrix<T> result(*this);

  for(int i = 0; i < result.actualSize(); i++)
    result[i] -= rhs[i];

  return result;
}

template <class T>
SymmetricMatrix<T> SymmetricMatrix<T>::operator-(const DiagonalMatrix<T>& rhs) const
{
  return (-rhs)+(*this);
}

template <class T>
ParamMatrix<T> SymmetricMatrix<T>::operator-(const BaseMatrix<T>& rhs) const
{
  ParamMatrix<T> result(rhs);

  return (-result)+(*this);
}

template <class T>
SymmetricMatrix<T> SymmetricMatrix<T>::operator-() const
{
  SymmetricMatrix<T> result(*this);

  for(int i = 0; i < result.actualSize(); i++)
    result[i] = -result[i];

  return result;
}

template <class T>
ParamMatrix<T> SymmetricMatrix<T>::operator*(const DiagonalMatrix<T>& rhs) const
{
  if(m_rowSize != rhs.numRows())
    throw std::invalid_argument("The number of columns in the first matrix does not equal the number of rows in the second matrix, so multiplication can't be done.");

  ParamMatrix<T> result(m_numRows, rhs.rowSize());

  for(int i = 0; i < result.m_numRows; i++)
  {
    for(int j = 0; j < result.m_rowSize; j++)
      result(i,j) = (*this)[j]*rhs(i,j);
  }

  return result;
}

template <class T>
ParamMatrix<T> SymmetricMatrix<T>::operator*(const BaseMatrix<T>& rhs) const
{
  if(m_rowSize != rhs.numRows())
    throw std::invalid_argument("The number of columns in the first matrix does not equal the number of rows in the second matrix, so multiplication can't be done.");


  ParamMatrix<T> result(m_numRows, rhs.rowSize());

  for(int i = 0; i < result.numRows(); i++)
  {
    for(int j = 0; j < result.rowSize(); j++)
    {
      result(i,j) = 0;
      for(int k = 0; k < result.rowSize(); k++)
      {
        result(i,j) += (*this)(i,k)*rhs(k,j);
      }
    }
  }

  return result;
}

template <class T>
SymmetricMatrix<T> SymmetricMatrix<T>::operator*(const T rhs) const
{
  SymmetricMatrix<T> result(*this);

  for(int i = 0; i < result.getSize(); i++)
    result[i] *= rhs;

  return result;
}

template <class T>
ParamMatrix<T> SymmetricMatrix<T>::operator*(const LinearVector<T>& rhs) const
{
  if(m_rowSize != rhs.getSize())
    throw std::invalid_argument("The number of columns in the matrix does not equal the number of entries in the vector, so multiplication can't be done.");

  ParamMatrix<T> result(m_numRows, 1);

  for(int i = 0; i < result.numRows(); i++)
  {
    result(i,0) = 0;
    for(int j = 0; j < m_rowSize; j++)
      result(i,0) += (*this)(i,j)*rhs[j];
  }
  return result;
}

template <class T>
T& SymmetricMatrix<T>::operator[](const int i)
{
  return m_dataPtr[i];
}

template <class T>
const T& SymmetricMatrix<T>::operator[](const int i) const
{
  return m_dataPtr[i];
}

/************************** Stream Operators **************************/
template <class T>
std::ostream& operator<<(std::ostream & stream, const SymmetricMatrix<T>& matrix)
{
  for(int row = 0; row < matrix.numRows(); row++)
  {
    std::cout << "<";

    for(int col = 0; col < matrix.rowSize()-1; col++)
      stream << matrix(row, col) << ", ";

    stream << matrix(row, matrix.rowSize()-1) << ">" << std::endl;
  }

  return stream;
}

template <class T>
std::ifstream& operator>>(std::ifstream & file, SymmetricMatrix<T>& matrix)
{
  int index = 0;
  double temp;
  int rowNum = 0;

  for(int i = 0; i < matrix.theoSize(); i++)
  {
    if(i%matrix.rowSize() <= rowNum)
    {
      file >> matrix[index];
      index++;
    }
    else
      file >> temp;

    if(i%matrix.rowSize() == matrix.rowSize()-1)
      rowNum++;
  }

  return file;
}

/************************** Other **************************/
template <class T>
int SymmetricMatrix<T>::rowSize() const
{
  return m_rowSize;
}

template <class T>
int SymmetricMatrix<T>::numRows() const
{
  return m_numRows;
}

template <class T>
void SymmetricMatrix<T>::setSize(int numRows, int numCols)
{
  if(numRows != m_numRows || numCols != m_rowSize)
  {
    delete [] m_dataPtr;
    m_dataPtr = new T[numRows*(numRows+1)/2];
    m_rowSize = numCols;
    m_numRows = numRows;
  }
}

template <class T>
int SymmetricMatrix<T>::actualSize() const
{
  return m_rowSize*(m_rowSize+1)/2;
}

template <class T>
int SymmetricMatrix<T>::theoSize() const
{
  return m_rowSize*m_numRows;
}


