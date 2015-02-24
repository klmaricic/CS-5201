//////////////////////////////////////////////////////////////////////
/// @file LinearVector.hpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement vector analysis
//////////////////////////////////////////////////////////////////////

/************************** Constructors/Destructor  **************************/
template <class T>
LinearVector<T>::LinearVector(int n)
{
  m_size = n;
  m_data_ptr = new T[n];
}

template <class T>
LinearVector<T>::LinearVector()
{
  m_size = 0;
  m_data_ptr = 0;
}

/************************** Operators **************************/
template <class T>
LinearVector<T>& LinearVector<T>::operator=(const T rhs)
{
  T* p = m_data_ptr + m_size;
  
  for(int i = 0; i < m_size; i++)
    m_data_ptr[i] = rhs;
	
  return *this;
}

/************************** Stream Operators **************************/
template <class T>
std::ostream& operator<<(std::ostream & stream, const CylindricalCoord<T> &rhs)
{
  stream << "<";
  for(int i = 0; i < m_size-1; i++)
    stream << rhs[i] << ", ";

  stream << rhs[m_size-1] << ">";
  return stream;
}

template <class T>
std::istream& operator>>(std::istream & stream, CylindricalCoord<T> &rhs)
{
  for(int i = 0; i <m_size; i++)
  {
    std::cout << "Enter the value for vector entry " << i << ": ";
	stream >> rhs[i];
  }
  
  return stream;
}