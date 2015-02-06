template <class T>
CylindricalCoord<T> CylindricalCoord<T>::operator-(const CylindricalCoord<T>& b) const
{

}

template <class T>
bool CylindricalCoord<T>::operator==(const CylindricalCoord<T>& b) const
{
  return((m_r == b.m_r)&&(PUT THETA HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1 )&&(m_z == b.m_z));
}

template <class T>
bool CylindricalCoord<T>::operator!=(const CylindricalCoord<T>& b) const
{
  return !((m_r == b.m_r)&&(PUT THETA HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1 )&&(m_z == b.m_z));
}