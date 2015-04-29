//////////////////////////////////////////////////////////////////////
/// @file findiff.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement Gaussian Elimination
//FIXME
//////////////////////////////////////////////////////////////////////

template <class T, double T_func(double, double)>
void FinDiff<T,T_func>::operator()( const T lower, const T upper, const int n )
{
  T h = static_cast<T>(1/n);
  ParamMatrix<T> A( (n-1)*(n-1), (n-1)*(n-1) );
  LinearVector<T> b( A.numRows() );
  int j=0, k=0;

  for( int i=0; i<A.numRows(); i++ )
  {
    A( i, i ) = 1;

    if( j > 0 )
      A( i, map( j-1, k, n ) ) = -h;
    else
      b[i] += T_func( lower, k );

    if( k > 0 )
      A( i, map( j, k-1, n ) ) = -h;
    else
      b[i] += T_func( j, lower );

    if( j < n-2 )
      A( i, map( j+1, k, n ) ) = -h;
    else
      b[i] += T_func( upper, k );

    if( k < n-2 )
      A( i, map( j, k+1, n ) ) = -h;
    else
      b[i] += T_func( j, upper ); 

    j++;
    if( j == n-1 )
    {
      j = 0;
      k++;
    }
  }

  // multiply all of b by h
  for( int i=0; i<A.numRows(); i++ )
    b[i] *= h;

  cout << A << endl;
} 

// Map from k, j to column number
template <class T, double T_func(double, double)>
inline int FinDiff<T,T_func>::map( const int j, const int k, const int n ) 
{
  return j+k*(n-1); // we have n-1 cuts per y, and n-1 cuts for each of those
}
