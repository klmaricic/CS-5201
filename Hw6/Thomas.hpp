//////////////////////////////////////////////////////////////////////
/// @file Cholesky.hpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement the Thomas algorithm
//////////////////////////////////////////////////////////////////////

template <class T>
void Thomas<T>::operator()(TridiagonalMatrix<T>& matrix, LinearVector<T>& vector) const
{
  LinearVector<T> solVect(vector.getSize());
  LinearVector<T> vectCopy(vector);
  TridiagonalMatrix<T> matrixCopy(matrix);

  for(int i = 1; i < matrixCopy.numRows(); i++)
  {
    matrixCopy(i,i-1) = matrixCopy(i,i-1)/matrixCopy(i-1,i-1);
    matrixCopy(i,i) -= matrixCopy(i,i-1)*matrixCopy(i-1,i);
  }

  for(int j = 1; j < matrixCopy.numRows(); j++)
    vectCopy[j] -= matrixCopy(j,j-1)*vectCopy[j-1]; 

  solVect[solVect.getSize()-1] = vectCopy[vectCopy.getSize()-1]/matrixCopy(matrixCopy.numRows()-1, matrixCopy.numRows()-1);

  for(int k = solVect.getSize()-2; k >= 0; k--)
    solVect[k] = (vectCopy[k]-matrixCopy(k,k+1)*solVect[k+1])/matrixCopy(k,k);

  std::cout << std::endl << "The solution of the tridiagonal system using the Thomas algorithm is: "<< std::endl;

  std::cout << solVect << std::endl << std::endl;
}
