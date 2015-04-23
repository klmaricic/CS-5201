//////////////////////////////////////////////////////////////////////
/// @file DiagonalMatrix.hpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement a parameterized matrix
//////////////////////////////////////////////////////////////////////

/************************** Constructors/Destructor  **************************/
template <class T>
DiagonalMatrix<T>::DiagonalMatrix()
{
  m_dataPtr = 0;
  m_rowSize = 0;
}

template <class T>
DiagonalMatrix<T>::DiagonalMatrix(int numRows, int numCols)
{
  m_dataPtr = new T[numRows];
  m_rowSize = numCols;
  m_numRows = numRows;
}

template <class T>
DiagonalMatrix<T>::DiagonalMatrix(const DiagonalMatrix<T>& matrix)
{
  m_rowSize = matrix.rowSize();
  m_numRows = matrix.numRows();
  m_dataPtr = new T[m_numRows];

  for(int i = 0; i < actualSize(); i++)
    m_dataPtr[i] = matrix[i];
}

template <class T>
DiagonalMatrix<T>::DiagonalMatrix(const BaseMatrix<T>& matrix)
{
  m_rowSize = matrix.rowSize();
  m_numRows = matrix.numRows();
  m_dataPtr = new T[m_numRows];

  for(int i = 0; i < actualSize(); i++)
  {
    m_dataPtr[i] = matrix(i,i);
  }
}

template <class T>
DiagonalMatrix<T>::~DiagonalMatrix()
{
  delete[] m_dataPtr;
}

/************************** Operators **************************/
template <class T>
const T DiagonalMatrix<T>::operator()(const int row, const int col) const
{ 
  if(row != col)
    return 0;

  return m_dataPtr[row];
}


template <class T>
T& DiagonalMatrix<T>::operator()(const int row, const int col)
{
  return m_dataPtr[row];
}

template <class T>
DiagonalMatrix<T> DiagonalMatrix<T>::operator+(const DiagonalMatrix<T>& rhs) const
{
  DiagonalMatrix<T> result(*this);
  
  for(int i = 0; i < result.actualSize(); i++)
    result[i] += rhs[i];

  return result;
}

template <class T>
ParamMatrix<T> DiagonalMatrix<T>::operator+(const ParamMatrix<T>& rhs) const
{
  ParamMatrix<T> result(rhs);

  return result+(*this);
}

template <class T>
UpperMatrix<T> DiagonalMatrix<T>::operator+(const UpperMatrix<T>& rhs) const
{
  UpperMatrix<T> result(rhs);

  for(int i = 0; i < rhs.rowSize(); i++)
    result(i,i) += (*this)[i];  
}

template <class T>
LowerMatrix<T> DiagonalMatrix<T>::operator+(const LowerMatrix<T>& rhs) const
{
  LowerMatrix<T> result(rhs);

  for(int i = 0; i < rhs.rowSize(); i++)
    result(i,i) += (*this)[i];
}

template <class T>
SymmetricMatrix<T> DiagonalMatrix<T>::operator+(const SymmetricMatrix<T>& rhs) const
{
  SymmetricMatrix<T> result(rhs);

  for(int i = 0; i < rhs.rowSize(); i++)
    result(i,i) += (*this)[i];
}

template <class T>
TridiagonalMatrix<T> DiagonalMatrix<T>::operator+(const TridiagonalMatrix<T>& rhs) const
{
  TridiagonalMatrix<T> result(rhs);

  for(int i = 0; i < rhs.rowSize(); i++)
    result(i,i) += (*this)[i];
}

template <class T>
DiagonalMatrix<T> DiagonalMatrix<T>::operator-(const DiagonalMatrix<T>& rhs) const
{
  DiagonalMatrix<T> result(*this);

  for(int i = 0; i < result.actualSize(); i++)
    result[i] -= rhs[i];

  return result;
}

template <class T>
ParamMatrix<T> DiagonalMatrix<T>::operator-(const ParamMatrix<T>& rhs) const
{
  ParamMatrix<T> result(-rhs);

  return (*this)+result;
}

template <class T>
UpperMatrix<T> DiagonalMatrix<T>::operator-(const UpperMatrix<T>& rhs) const
{
  UpperMatrix<T> result(-rhs);

  return (*this)+result;
}

template <class T>
LowerMatrix<T> DiagonalMatrix<T>::operator-(const LowerMatrix<T>& rhs) const
{
  LowerMatrix<T> result(-rhs);

  return (*this)+result;
}

template <class T>
SymmetricMatrix<T> DiagonalMatrix<T>::operator-(const SymmetricMatrix<T>& rhs) const
{
  SymmetricMatrix<T> result(-rhs);

  return (*this)+result;
}

template <class T>
TridiagonalMatrix<T> DiagonalMatrix<T>::operator-(const TridiagonalMatrix<T>& rhs) const
{
  TridiagonalMatrix<T> result(-rhs);

  return (*this)+result;
}

template <class T>
DiagonalMatrix<T> DiagonalMatrix<T>::operator-() const
{
  DiagonalMatrix<T> result(*this);

  for(int i = 0; i < result.actualSize(); i++)
    result[i] = -result[i];

  return result;
}


template <class T>
DiagonalMatrix<T> DiagonalMatrix<T>::operator*(const DiagonalMatrix<T>& rhs) const
{ 
  if(m_rowSize != rhs.numRows())
    throw std::invalid_argument("The number of columns in the first matrix does not equal the number of rows in the second matrix, so multiplication can't be done.");

  DiagonalMatrix<T> result(*this);

  for(int i = 0; i < result.actualSize(); i++)
    result[i] *= rhs[i];

  return result;
}

template <class T>
ParamMatrix<T> DiagonalMatrix<T>::operator*(const ParamMatrix<T>& rhs) const
{
  if(m_rowSize != rhs.numRows())
    throw std::invalid_argument("The number of columns in the first matrix does not equal the number of rows in the second matrix, so multiplication can't be done.");


  ParamMatrix<T> result(m_numRows, rhs.rowSize());

  for(int i = 0; i < result.numRows(); i++)
  {
    for(int j = 0; j < result.rowSize(); j++)
      result(i,j) = (*this)[i]*rhs(i,j);
  }

  return result;  
}

template <class T>
LowerMatrix<T> DiagonalMatrix<T>::operator*(const LowerMatrix<T>& rhs) const
{
  if(m_rowSize != rhs.numRows())
    throw std::invalid_argument("The number of columns in the first matrix does not equal the number of rows in the second matrix, so multiplication can't be done.");

  LowerMatrix<T> result(m_numRows, rhs.rowSize());
 
  for(int i = 0; i < result.m_numRows; i++)
  {
    for(int j = 0; j <= i; j++)
      result(i,j) = (*this)[i]*rhs(i,j);
  }

  return result;
}

template <class T>
UpperMatrix<T> DiagonalMatrix<T>::operator*(const UpperMatrix<T>& rhs) const
{
  if(m_rowSize != rhs.numRows())
    throw std::invalid_argument("The number of columns in the first matrix does not equal the number of rows in the second matrix, so multiplication can't be done.");

  UpperMatrix<T> result(m_numRows, rhs.rowSize());

  for(int i = 0; i < result.m_numRows; i++)
  {
    for(int j = i; j < result.rowSize(); j++)
      result(i,j) = (*this)[i]*rhs(i,j);
  }


  return result;
}

template <class T>
DiagonalMatrix<T> DiagonalMatrix<T>::operator*(const T rhs) const
{
  DiagonalMatrix<T> result(*this);

  for(int i = 0; i < result.getSize(); i++)
    result[i] *= rhs;

  return result;
}

template <class T>
ParamMatrix<T> DiagonalMatrix<T>::operator*(const LinearVector<T>& rhs) const
{
  if(m_rowSize != rhs.getSize())
    throw std::invalid_argument("The number of columns in the matrix does not equal the number of entries in the vector, so multiplication can't be done.");

  ParamMatrix<T> result(m_numRows, 1);

  for(int i = 0; i < result.numRows(); i++)
    result(i,0) = m_dataPtr[i]*rhs[i];

  return result; 
}

template <class T>
T& DiagonalMatrix<T>::operator[](const int i)
{
  return m_dataPtr[i];
}

template <class T>
const T& DiagonalMatrix<T>::operator[](const int i) const
{
  return m_dataPtr[i];
}

/************************** Stream Operators **************************/
template <class T>
std::ostream& operator<<(std::ostream & stream, const DiagonalMatrix<T>& matrix)
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
std::ifstream& operator>>(std::ifstream & file, DiagonalMatrix<T>& matrix)
{
  int index = 0;
  double temp;
  int rowNum = 0;

  for(int i = 0; i < matrix.theoSize(); i++)
  {
    if(i%matrix.rowSize() == rowNum)
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
int DiagonalMatrix<T>::rowSize() const
{
  return m_rowSize;
}

template <class T>
int DiagonalMatrix<T>::numRows() const
{
  return m_numRows;
}

template <class T>
void DiagonalMatrix<T>::setSize(int numRows, int numCols)
{
  if(numRows != m_numRows || numCols != m_rowSize)
  {
    delete [] m_dataPtr;
    m_dataPtr = new T[numRows];
    m_rowSize = numCols;
    m_numRows = numRows;
  }
}

template <class T>
int DiagonalMatrix<T>::actualSize() const
{
  return m_rowSize;
}

template <class T>
int DiagonalMatrix<T>::theoSize() const
{
  return m_rowSize*m_numRows;
}

