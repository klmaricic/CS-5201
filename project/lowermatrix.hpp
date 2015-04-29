//////////////////////////////////////////////////////////////////////
/// @file lowermatrix.hpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement a parameterized matrix
//////////////////////////////////////////////////////////////////////

/************************** Constructors/Destructor  **************************/
template <class T>
LowerMatrix<T>::LowerMatrix()
{
  m_dataPtr = 0;
  m_rowSize = 0;
}

template <class T>
LowerMatrix<T>::LowerMatrix(int numRows, int numCols)
{
  m_dataPtr = new T[numRows*(numRows+1)/2];
  m_rowSize = numCols;
  m_numRows = numRows;

  for(int i = 0; i < numRows*(numRows+1)/2; i++)
    m_dataPtr[i] = 0;
}

template <class T>
LowerMatrix<T>::LowerMatrix(const LowerMatrix<T>& matrix)
{
  m_rowSize = matrix.rowSize();
  m_numRows = matrix.numRows();
  m_dataPtr = new T[matrix.actualSize()];

  for(int i = 0; i < actualSize(); i++)
    m_dataPtr[i] = matrix[i];
}

template <class T>
LowerMatrix<T>::LowerMatrix(const ParamMatrix<T>& matrix)
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
LowerMatrix<T>::LowerMatrix(const SymmetricMatrix<T>& matrix)
{
  m_rowSize = matrix.rowSize();
  m_numRows = matrix.numRows();
  m_dataPtr = new T[matrix.actualSize()];

  for(int i = 0; i < actualSize(); i++)
    m_dataPtr[i] = matrix[i];
}


template <class T>
LowerMatrix<T>::~LowerMatrix()
{
  delete[] m_dataPtr;
}

/************************** Operators **************************/
template <class T>
const T LowerMatrix<T>::operator()(const int row, const int col) const
{
  if( row >= numRows() || col >= rowSize() || row < 0 || col < 0 )
    throw std::out_of_range( "An argument is outside of the matrix." );

  if(row < col)
    return 0;

  return m_dataPtr[col + (row+1)*row/2];
}

template <class T>
T& LowerMatrix<T>::operator()(const int row, const int col)
{
  if( row >= numRows() || col >= rowSize() || row < 0 || col < 0 )
    throw std::out_of_range( "An argument is outside of the matrix." );

  return m_dataPtr[col + (row+1)*row/2];
}

template <class T>
LowerMatrix<T> LowerMatrix<T>::operator+(const LowerMatrix<T>& rhs) const
{
  LowerMatrix<T> result(*this);

  for(int i = 0; i < result.actualSize(); i++)
    result[i] += rhs[i];

  return result;
}

template <class T>
LowerMatrix<T> LowerMatrix<T>::operator+(const DiagonalMatrix<T>& rhs) const
{
  return rhs+(*this);
}

template <class T>
ParamMatrix<T> LowerMatrix<T>::operator+(const BaseMatrix<T>& rhs) const
{
  ParamMatrix<T> result(rhs);

  return result+(*this);
}

template <class T>
LowerMatrix<T> LowerMatrix<T>::operator-(const LowerMatrix<T>& rhs) const
{
  LowerMatrix<T> result(*this);

  for(int i = 0; i < result.actualSize(); i++)
    result[i] -= rhs[i];

  return result;
}

template <class T>
LowerMatrix<T> LowerMatrix<T>::operator-(const DiagonalMatrix<T>& rhs) const
{
  return (-rhs)+(*this);
}

template <class T>
ParamMatrix<T> LowerMatrix<T>::operator-(const BaseMatrix<T>& rhs) const
{
  ParamMatrix<T> result(rhs);
  result = -result;

  return result+(*this);
}

template <class T>
LowerMatrix<T> LowerMatrix<T>::operator-() const
{
  LowerMatrix<T> result(*this);

  for(int i = 0; i < result.actualSize(); i++)
    result[i] = -result[i];

  return result;
}

template <class T>
LowerMatrix<T> LowerMatrix<T>::operator*(const LowerMatrix<T>& rhs) const
{
  if(m_rowSize != rhs.numRows())
    throw std::invalid_argument("The number of columns in the first matrix does not equal the number of rows in the second matrix, so multiplication can't be done.");

  LowerMatrix<T> result(m_numRows, rhs.m_rowSize);

  for(int i = 0; i < result.m_numRows; i++)
  {
    for(int j = 0; j <= i; j++)
    {
      result(i,j) = 0;
      for(int k = 0; k <= i; k++)
      {
        result(i,j) += (*this)(i,k)*rhs(k,j);
      }
    }
  }

  return result;
}

template <class T>
LowerMatrix<T> LowerMatrix<T>::operator*(const DiagonalMatrix<T>& rhs) const
{
  if(m_rowSize != rhs.numRows())
    throw std::invalid_argument("The number of columns in the first matrix does not equal the number of rows in the second matrix, so multiplication can't be done.");

  LowerMatrix<T> result(m_numRows, rhs.rowSize());

  for(int i = 0; i < result.m_numRows; i++)
  {
    for(int j = 0; j <= i; j++)
      result(i,j) = (*this)[j]*rhs(i,j);
  }

  return result;
}

template <class T>
ParamMatrix<T> LowerMatrix<T>::operator*(const BaseMatrix<T>& rhs) const
{
  if(m_rowSize != rhs.numRows())
    throw std::invalid_argument("The number of columns in the first matrix does not equal the number of rows in the second matrix, so multiplication can't be done.");


  ParamMatrix<T> result(m_numRows, rhs.rowSize());

  for(int i = 0; i < result.numRows(); i++)
  {
    for(int j = 0; j < result.rowSize(); j++)
    {
      result(i,j) = 0;
      for(int k = 0; k <= i; k++)
      {
        result(i,j) += (*this)(i,k)*rhs(k,j);
      }
    }
  }

  return result;
}

template <class T>
LowerMatrix<T> LowerMatrix<T>::operator*(const T rhs) const
{
  LowerMatrix<T> result(*this);

  for(int i = 0; i < result.getSize(); i++)
    result[i] *= rhs;

  return result;
}

template <class T>
ParamMatrix<T> LowerMatrix<T>::operator*(const LinearVector<T>& rhs) const
{
  if(m_rowSize != rhs.getSize())
    throw std::invalid_argument("The number of columns in the matrix does not equal the number of entries in the vector, so multiplication can't be done.");

  ParamMatrix<T> result(m_numRows, 1);

  for(int i = 0; i < result.numRows(); i++)
  {
    result(i,0) = 0;
    for(int j = 0; j <= i; j++)
      result(i,0) += (*this)(i,j)*rhs[j];
  }
  return result;
}

template <class T>
T& LowerMatrix<T>::operator[](const int i)
{
  return m_dataPtr[i];
}

template <class T>
const T& LowerMatrix<T>::operator[](const int i) const
{
  return m_dataPtr[i];
}

/************************** Stream Operators **************************/
template <class T>
std::ostream& operator<<(std::ostream & stream, const LowerMatrix<T>& matrix)
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
std::ifstream& operator>>(std::ifstream & file, LowerMatrix<T>& matrix)
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
int LowerMatrix<T>::rowSize() const
{
  return m_rowSize;
}

template <class T>
int LowerMatrix<T>::numRows() const
{
  return m_numRows;
}

template <class T>
void LowerMatrix<T>::setSize(int numRows, int numCols)
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
int LowerMatrix<T>::actualSize() const
{
  return m_rowSize*(m_rowSize+1)/2;
}

template <class T>
int LowerMatrix<T>::theoSize() const
{
  return m_rowSize*m_numRows;
}

template <class T>
UpperMatrix<T> LowerMatrix<T>::transpose() const
{
  UpperMatrix<T> result(m_rowSize, m_numRows);

  for(int i = 0; i < m_numRows; i++)
  {
    for(int j = 0; j <= i; j++)
      result(j,i) = (*this)(i,j);
  }

  return result;
}


