//////////////////////////////////////////////////////////////////////
/// @file GaussSeidel.hpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement the GaussSeidel iteration Method
//////////////////////////////////////////////////////////////////////

template <class T>
void GaussSeidel<T>::operator()(const std::vector<LinearVector<T> > vect) const
{
  bool depDetermined = false;
  double c = vect[0][0]/vect[1][0];
  int sysSize = 1;
  LinearVector<T> aOld = 0;
  LinearVector<T> aNew = 0;
  
  for(int i = 0; i < vect[0].getSize(); i++)
  {
    if(vect[0][i]/vect[1][i] != c)
	  break;
	else if(i == vect[0].getSize()-1)
	  depDetermined = true;
  }
  
  if(!depDetermined)
  {
    sysSize++;
	
    while((sysSize < vect.size()) && (!depDetermined))
	{
	  for(int i = 0; i < sysSize; i++)
	  {
	    aNew[i] = vect[sysSize][i];
		
		for(int j = 0; j < sysSize; j++)
		{
		  if(j != i)
		    aNew[i] -= (aNew[j][i])*(vect[j][i]);
		}
		
		aNew[i] /= vect[i][i];
	  }
	  
	  if(sysSize != 2)
	    //calculate difference
		
	  sysSize++;
	
	}
  }
	  
}