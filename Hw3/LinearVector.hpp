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

template <class T>
LinearVector<T>::LinearVector(const LinearVector<T>& vect)
{

}

template <class T>
LinearVector<T>::~LinearVector()
{

}

/************************** Operators **************************/
template <class T>
T& LinearVector<T>::operator[](const int i)
{

}

template <class T>
const T& LinearVector<T>::operator[](const int i) const
{

}

template <class T>
LinearVector<T>& LinearVector<T>::operator=(const LinearVector& rhs)
{

}

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
std::ostream& operator<<(std::ostream & stream, const LinearVector<T> &rhs)
{
  stream << "<";
  for(int i = 0; i < rhs.getSize() - 1; i++)
    stream << rhs[i] << ", ";

  stream << rhs[rhs.getSize()-1] << ">";
  return stream;
}

template <class T>
std::istream& operator>>(std::istream & stream, LinearVector<T> &rhs)
{
  for(int i = 0; i < rhs.getSize(); i++)
  {
    std::cout << "Enter the value for vector entry " << i << ": ";
	stream >> rhs[i];
  }
  
  return stream;
}

/************************** Other **************************/
template <class T>
int LinearVector<T>::getSize() const
{
  return m_size;
}