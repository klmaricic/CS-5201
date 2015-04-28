//////////////////////////////////////////////////////////////////////
/// @file cholesky.hpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement Cholesky decomposition
//////////////////////////////////////////////////////////////////////

template <class T>
void Cholesky<T>::operator()(SymmetricMatrix<T>& matrix, LinearVector<T>& vector) const
{
  LowerMatrix<T> decomp(matrix);
  LinearVector<T> vect(vector);
  LinearVector<T> tempVect(vector.getSize());
  LinearVector<T> solVect(vector.getSize());
  T sum;

  for(int k = 0; k < decomp.rowSize(); k++)
  {
    for(int i = 0; i < k; i++)
    {
      sum = 0;
      for(int j = 0; j < i; j++)
        sum += decomp(i,j)*decomp(k,j);

      decomp(k,i) = (decomp(k,i)-sum)/decomp(i,i);
    }
    sum = 0;

    for(int j = 0; j < k; j++)
      sum += decomp(k,j)*decomp(k,j);

    decomp(k,k) = sqrt(decomp(k,k)-sum);
  }

  std::cout << "The symmetric matrix can be broken down into the 2 following matrices through the use of Cholesky decomposition:" << std::endl;
  UpperMatrix<T> transpose(decomp.transpose());
  std::cout << decomp << std::endl;
  std::cout << transpose << std::endl << std::endl;

  for(int j = 0; j < decomp.numRows(); j++)
  {
    tempVect[j] = vect[j]/decomp(j,j);
    for(int i = j+1; i < decomp.numRows(); i++)
      vect[i] -= decomp(i,j)*tempVect[j];
  }

  for(int j = tempVect.getSize()-1; j >= 0; j--)
  {
    solVect[j] = tempVect[j]/transpose(j,j);

    for(int i = 0; i < j; i++)
      tempVect[i] -= transpose(i,j)*solVect[j];
  }

  std::cout << "The solution to the symmetric system is:"<<std::endl;
  std::cout << solVect <<std::endl <<std::endl;
}
