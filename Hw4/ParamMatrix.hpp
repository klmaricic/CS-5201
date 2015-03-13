//////////////////////////////////////////////////////////////////////
/// @file ParamMatrix.hpp
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
    result[i] += rhs[i];
  
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
      stream << matrix[i*j+1] << ", ";

    stream << matrix[matrix.getSize()-1] << ">" << std::endl;
  }
  
  return stream;
}

template <class T>
std::ifstream& operator>>(std::ifstream & file, ParamMatrix<T> &rhs)
{
  int dimensions;
  int numEntries = 0;
  
  file >> dimensions;

  if(rhs.rowSize() != dimensions+1 || rhs.numRows() != dimensions)	
    rhs.setSize(dimensions, dimensions+1);

  for(std::string line; std::getline(file, line); )   //read stream line by line
  {	
    if(numEntries < rhs.getSize())
	{
      if(!line.empty())
	  {
	    for(int i = 0; i < dimensions; i++)
        {
          file >> rhs[numEntries]; 
		  std::cout << rhs[numEntries] << ", ";
		  numEntries++;
        }
	    numEntries++; //Leave open spot in the row for b
	    std::cout <<std::endl;
	  }
	}
	else if(numEntries == rhs.getSize()) //If it has inserted all of the rows of the matrix and only has b left
	{
	std::cout << "numEntries: " << numEntries << std::endl;
      if(!line.empty())
	  {
	    for(int i = 0; i < dimensions; i++)
		{
		  //file >> rhs[(i*rhs.rowSize()+rhs.rowSize()-1)];
		  //std::cout << rhs[(i*rhs.rowSize()+rhs.rowSize()-1)] << ", ";
		}
		
		numEntries++;
	  }
	}
    else
      break;	
  }
  
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
