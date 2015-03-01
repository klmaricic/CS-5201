//////////////////////////////////////////////////////////////////////
/// @file GaussSeidel.hpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement the GaussSeidel iteration Method
//////////////////////////////////////////////////////////////////////

template <class T>
void GaussSeidel<T>::operator()(const std::vector<LinearVector<T> > vect) const
{
  bool depDetermined = true;
  bool diagDom = true;
  double maxDiff = 0;
  double scalar = 0;
  const double TOLERANCE = 0.000001;
  const int MAX_ITERATIONS = 10000;
  int sysSize = 1;
  int numIterations = 0;
  LinearVector<T> aOld (vect.size());
  LinearVector<T> aNew (vect.size());
  LinearVector<T> vectSum (vect.size());
  
  aOld = 0;
  aNew = 0;
  vectSum = 0;
 

  for(int i = 0; i < vect.size(); i++)
  {
    if(vect[i][i] == 0)
	{
	  diagDom = false;
	  break;
	}
  }
  
  if(!diagDom)
  {
    std::cout << "The given entries are not diagonally dominant, so the Gauss-Seidel method could not be performed on them." << std::endl;
	std::cout << "Because of this, the set is linearly independent." << std::endl;
  }
  else
  {
    if(vect[1][0] == 0)
	  depDetermined = false;
	else
	{
      scalar = vect[0][0]/vect[1][0];
	  
      for(int i = 0; i < vect[0].getSize(); i++)
      {
        if(vect[1][i]*scalar != vect[0][i])
	    {
	      depDetermined = false;
	      break;
        }
	  }
	}
	if(depDetermined)
	{
	  std::cout << "The system is linearly dependent" << std::endl;
	  std::cout << "The linear combination is: " << scalar << "*" << vect[1] << "=" << vect[0] << std::endl;
	}
    else
    {
      sysSize++;
	
      while((sysSize < vect.size()) && (!depDetermined))
	  {
	    numIterations = 0;
	    while((numIterations < MAX_ITERATIONS) && (!depDetermined))
	    {
	      for(int i = 0; i < sysSize; i++)
	      {
	        aNew[i] = vect[sysSize][i];

		    for(int j = 0; j < sysSize; j++)
		    {
		      if(j != i)
		        aNew[i] = (aNew[i] - (aNew[j])*(vect[j][i]));
		    }
		
		    aNew[i] = (aNew[i]/vect[i][i]);
	      }

	      if(numIterations > 0)
	      {
		    if(aNew[0] == 0)
			  maxDiff = aOld[0];
			else
	          maxDiff = fabs(aNew[0]-aOld[0])/fabs(aNew[0]);
			  
		    vectSum = (vect[0]*aNew[0]);
		
		    for(int i = 1; i < sysSize; i++)
		    {
			  double currentDiff;
			  
			  if(aNew[i] == 0)
			    currentDiff = aOld[i];
			  else
		        currentDiff = fabs(aNew[i]-aOld[i])/fabs(aNew[i]);
				
		      vectSum = (vectSum + vect[i]*aNew[i]); 

		      if(currentDiff > maxDiff)
		        maxDiff = currentDiff;
				
		    }
		
		    if(maxDiff <= TOLERANCE)
		    {
		      for(int i = 0; i < vect.size(); i++)
		      {
		        if(vect[sysSize][i] - vectSum[i] > TOLERANCE)
			      break;
	            else if(i == vect.size()-1)
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
}