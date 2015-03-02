//////////////////////////////////////////////////////////////////////
/// @file GaussSeidel.hpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement the GaussSeidel iteration Method
//////////////////////////////////////////////////////////////////////

template <class T>
void GaussSeidel<T>::operator()(std::vector<LinearVector<T> > vect) const
{
  bool depDetermined = true;
  bool hasDiagZero = false;
  double maxDiff = 0;
  double scalar = 0;
  const double TOLERANCE = 0.000001;
  const int MAX_ITERATIONS = 10000;
  int maxIndex, maxZeros;
  int sysSize = 1;
  int numIterations = 0;
  LinearVector<T> aOld (vect.size());
  LinearVector<T> aNew (vect.size());
  LinearVector<T> vectSum (vect.size());
  LinearVector<T> numZeros (vect.size());
  LinearVector<T> temp (vect.size());
  LinearVector<T> orderedMaxZeros (vect.size());
  
  aOld = 0;
  aNew = 0;
  vectSum = 0;
  numZeros = 0;
 

  for(int i = 0; i < vect.size(); i++)
  {
    if(vect[i][i] == 0)
	{
	  hasDiagZero = true;
	  break;
	}
  }
  
  //If the system has a zero in the diagonal, it will attempt to pivot to solve the issue
  if(hasDiagZero)
  {
    hasDiagZero = false;
	
    //Adds up how many of the vectors have a zero value as their element i
    for(int i =0; i < vect.size(); i++)
	{
	  for(int j =0; j < vect.size(); j++)
      {
	    if(vect[j][i] == 0)
		{
		  numZeros[i]++;
		  
		  //if all of the vectors have a 0 value at index i, then the system cannot be pivoted to solve the issue
		  if(numZeros[i] == vect.size())
		    hasDiagZero = true;
		}
	  }
	}
	
	if(!hasDiagZero)
	{
	  int tempIndex = 0;
      //Orders by descending value which diagonal spots have the most possible zero values	
	  while(maxZeros > -1)
	  {
	    maxZeros = -1;
		
        for(int i = 0; i < numZeros.getSize(); i++)
	    {
	      if(numZeros[i] > maxZeros)
	      {
		    maxZeros = numZeros[i];
		    maxIndex = i;
		  }
        }
		
		if(tempIndex < orderedMaxZeros.getSize())
          orderedMaxZeros[tempIndex] = maxIndex;
		  
	    numZeros[maxIndex] = -1;
		tempIndex++;
	  }

	  //Attempts to pivot the system so that it has no zero values in the diagonal
	  for(int i = 0; i < orderedMaxZeros.getSize(); i++)
	  {
	    if(hasDiagZero)
	      break;
	    else if(vect[orderedMaxZeros[i]][orderedMaxZeros[i]] == 0)
	    {
	      for(int j = orderedMaxZeros.getSize()-1; j >= 0; j--)
		  {
		    if(vect[orderedMaxZeros[j]][orderedMaxZeros[i]] != 0)
		    {
			  temp = vect[orderedMaxZeros[i]];
			  vect[orderedMaxZeros[i]] = vect[orderedMaxZeros[j]];
			  vect[orderedMaxZeros[j]] = temp;
		  	  break;
		    }
		    else if(j == 0)
		      hasDiagZero = true;
		  }
		}
	  }
	  
	  //Checks if there are still zeros in the diagonal after pivoting
	  for(int i = 0; i < vect.size(); i++)
      {
        if(vect[i][i] == 0)
	    {
	      hasDiagZero = true;
	      break;
	    }
      }
	}
	
	if(!hasDiagZero)
	{
	  std::cout << "The system had to be pivoted due to a zero element in the diagonal." << std::endl;
	}
	else
    {
      std::cout << "There is a zero element in the diagonal that could not be pivoted out, so the Gauss-Seidel method could not be performed on the system." << std::endl;
	  std::cout << "Because of this, the set is linearly independent." << std::endl;
	}
  }
  
  if(!hasDiagZero)
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
	  std::cout << "The linear combination found is: " << scalar << "*" << vect[1] << "=" << vect[0] << std::endl;
	}
    else
    {
      sysSize++;
	
	  //Increase the system size until either the system size cannot be increased or the convergence is found
      while((sysSize < vect.size()) && (!depDetermined))
	  {
	    numIterations = 0;
		
		//Run through iterations on the current system size until either it reaches the iteration limit or the convergence is found
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
	    std::cout << "The system converges so it is linearly dependent." << std::endl;
		std::cout << "The linear combination found is: " << std::endl;
		
		for(int i = 0; i < sysSize-2; i++)
		{
		  if(aNew[i] != 0)
		    std::cout << aNew[i] << "*" << vect[i] << "+";
		}
		  
		std::cout << aNew[sysSize-2] << "*" << vect[sysSize-2] << "=" << vect[sysSize-1] << std::endl;
	  }
	  else
	    std::cout << "The system does not converge so it is linearly independent." << std::endl;
    }
	
	std::cout << "The tolerance used for the Gauss-Seidel iteration process was " << TOLERANCE << std::endl;
  }	  
}