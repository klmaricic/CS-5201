//////////////////////////////////////////////////////////////////////
/// @file GaussSeidel.hpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement the GaussSeidel iteration Method
//////////////////////////////////////////////////////////////////////

template <class T>
void GaussSeidel<T>::operator()(const std::vector<LinearVector<T> > vect) const
{
  bool depDetermined = false;
  double maxDiff;
  const double C = vect[0][0]/vect[1][0];
  const double TOLERANCE = 0.000001;
  const int MAX_ITERATIONS = 10000;
  int sysSize = 1;
  int numIterations = 0;
  LinearVector<T> aOld (0);
  LinearVector<T> aNew (0);
  LinearVector<T> vectSum ();
  
  for(int i = 0; i < vect[0].getSize(); i++)
  {
    if(vect[0][i]/vect[1][i] != C)
	  break;
	else if(i == vect[0].getSize()-1)
	  depDetermined = true;
  }
  
  if(!depDetermined)
  {
    sysSize++;
	
    while((sysSize < vect.size()) && (!depDetermined))
	{
	  while((numIterations < MAX_ITERATIONS) && (!depDetermined))
	  {
	    for(int i = 0; i < sysSize; i++)
	    {
	      aNew[i] = vect[sysSize][i];
		
		  for(int j = 0; j < sysSize; j++)
		  {
		    if(j != i)
		      aNew[i] -= (aNew[j])*(vect[j][i]);
		  }
		
		  aNew[i] /= vect[i][i];
	    }
	  
	    if(numIterations > 0)
	    {
	      maxDiff = abs(aNew[0]-aOld[0])/abs(aNew[0]);
		  vectSum = aNew[0]*vect[0];
		
		  for(int i = 1; i < sysSize; i++)
		  {
		    double currentDiff = abs(aNew[i]-aOld[i])/abs(aNew[i]);
		    vectSum = vectSum + a[i]*vect[i]; 
		  
		    if(currentDiff > maxDiff)
		      maxDiff = currentDiff;
		  }
		
		  if(maxDiff <= TOLERANCE)
		  {
		    for(int i = 0; i < sysSize; i++)
		    {
		      if(vect[sysSize][i] - vectSum[i] > TOLERANCE)
			    break;
	          else if(i == sysSize-1)
	            depDetermined = true;
		    }
		  }
	    }
		
		aOld = aNew;
		numIterations++;
	  }

	  sysSize++;
	}
	
	if(depDetermined)
	{
	  std::cout << "The system is linearly dependent" << std::endl;
	}
  }
	  
}