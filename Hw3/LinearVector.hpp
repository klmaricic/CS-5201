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
  m_size = vect.getSize();
  m_data_ptr = new T[m_size];
  
  vectCopy(vect);
}

template <class T>
LinearVector<T>::~LinearVector()
{
  delete [] m_data_ptr;
}

/************************** Operators **************************/
template <class T>
T& LinearVector<T>::operator[](const int i)
{
  return m_data_ptr[i];
}

template <class T>
const T& LinearVector<T>::operator[](const int i) const
{
  return m_data_ptr[i];
}

template <class T>
LinearVector<T> LinearVector<T>::operator+(const LinearVector<T>& rhs) const
{
  LinearVector<T> result(*this);
  
  for(int i = 0; i < result.getSize(); i++)
    result[i] += rhs[i];
  
  return result;   
}

template <class T>
LinearVector<T> LinearVector<T>::operator-(const LinearVector<T>& rhs) const
{
  LinearVector<T> result(*this);
  
  for(int i = 0; i < result.getSize(); i++)
    result[i] -= rhs[i];
  
  return result;   
}

template <class T>
LinearVector<T> LinearVector<T>::operator-() const
{
  LinearVector<T> result(*this);
  
  for(int i = 0; i < result.getSize(); i++)
    result[i] = -result[i];
  
  return result;   
}

template <class T>
T LinearVector<T>::operator*(const LinearVector<T>& rhs) const
{
  T result = 0;
  
  for(int i = 0; i < m_size; i++)
    result += ((*this)[i])*(rhs[i]);
	
  return result;
}

template <class T>
LinearVector<T> LinearVector<T>::operator*(const T rhs) const
{
  LinearVector<T> result(*this);
  
  for(int i = 0; i < result.getSize(); i++)
    result[i] *= rhs;
  
  return result;
}

template <class T>
LinearVector<T>& LinearVector<T>::operator=(const LinearVector<T>& rhs)
{
  if(m_data_ptr != rhs.m_data_ptr)
  {
    setSize(rhs.getSize());
	vectCopy(rhs);
  }
  
  return *this;
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
const int LinearVector<T>::getSize() const
{
  return m_size;
}

template <class T>
void LinearVector<T>::setSize(int n)
{
  if(n != m_size)
  {
    delete [] m_data_ptr;
	m_size = n;
	m_data_ptr = new T[n];
  }
}

template <class T>
void LinearVector<T>::vectCopy(const LinearVector<T>& vect)
{
  T* p = m_data_ptr + m_size;
  T* q = vect.m_data_ptr + m_size;
  
  for(int i = 0; i < m_size; i++)
    m_data_ptr[i] = vect.m_data_ptr[i];
}