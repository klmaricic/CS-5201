//////////////////////////////////////////////////////////////////////
/// @file gaussiansolver.hpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement Gaussian Elimination
//////////////////////////////////////////////////////////////////////

template <class T>
void GaussianSolver<T>::operator()(ParamMatrix<T>& matrix, LinearVector<T>& vector) const
{
  LinearVector<T> scaleVect(matrix.numRows());
  LinearVector<int> indexVect(matrix.numRows());
  LinearVector<T> xVect(matrix.numRows());
  double mult;

  for(int i = 0; i < matrix.numRows(); i++)
  {
    T max = 0;
    indexVect[i] = i;

    for(int j = 0; j < matrix.rowSize(); j++)
    {
      if(fabs(matrix(i,j)) > max)
        max = fabs(matrix(i,j));
    }

    if(max == 0)
      throw std::string("There is a zero row in the matrix, so the system has no unique solution.");

    scaleVect[i] = max;
  }

  for(int i = 0; i < matrix.rowSize()-1; i++)
  {
    double ratioMax = 0;
    int ratioMaxIndex = 0;

    for(int j = i; j < matrix.numRows(); j++)
    { 
      if(fabs(matrix(indexVect[j],i)/scaleVect[indexVect[j]]) > ratioMax)
      {
        ratioMax = fabs(matrix(indexVect[j],i)/scaleVect[indexVect[j]]);
        ratioMaxIndex = j;
      }
    }
    int temp = indexVect[i];
    indexVect[i] = indexVect[ratioMaxIndex];
    indexVect[ratioMaxIndex] = temp;

    for(int k = i+1; k < matrix.numRows(); k++)
    {
      mult = matrix(indexVect[k],i)/matrix(indexVect[i],i);
      vector[indexVect[k]] -= vector[indexVect[i]]*mult;

      for(int m = i; m < matrix.rowSize(); m++)
        matrix(indexVect[k],m) -= matrix(indexVect[i],m)*mult;  
    }
  }

  for(int i = indexVect.getSize()-1; i >= 0; i--)
  {
    xVect[i] = vector[indexVect[i]];

    for(int j = i+1; j < matrix.rowSize(); j++)  
      xVect[i] -= matrix(indexVect[i],j)*xVect[j];

    xVect[i] /= matrix(indexVect[i],i);
  }
  std::cout <<"The solution of the given system (aka vector x) is given below:" <<std::endl;
  std::cout <<xVect << std::endl;
}

