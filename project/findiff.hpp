//////////////////////////////////////////////////////////////////////
/// @file findiff.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement Gaussian Elimination
//FIXME
//////////////////////////////////////////////////////////////////////

template <typename T, typename T_func>
void FinDiff<T,T_Func>::operator()( const T lower, const T upper, const int n )
{
  const T h = 1/n;
  ParamMatrix<T> A( (n-1)*(n-1), (n-1)*(n-1) );

  T xj, yk;
  for( int k=1; k<n; k++ )
  {
    for( int j=1; j<n; j++ ) // j: [1,n-1]
    {
      xj = j*h; // our coords at this iter
      yk = h*k; // ^
    }
  }


} 
