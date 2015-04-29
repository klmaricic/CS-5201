//////////////////////////////////////////////////////////////////////
/// @file findiff.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement Gaussian Elimination
//FIXME
//////////////////////////////////////////////////////////////////////

template <class T, class T_func>
void FinDiff<T,T_func>::operator()( const T lower, const T upper, const int n )
{
  T h = 1.f/n;
  ParamMatrix<T> A( (n-1)*(n-1), (n-1)*(n-1) );
  int j=0, k=0;

  for( int i=0; i<A.numRows( ); i++ )
  {
    cerr << "=====" << endl << "New loop:\tj: " << j << "k: " << k << endl << "=====" << endl;

    A( i, i ) = 1;
    if( j > 0 )
      A( i, map( j-1, k, n ) ) = -h;
    if( k > 0 )
      A( i, map( j, k-1, n ) ) = -h;
    if( j < n-2 )
      A( i, map( j+1, k, n ) ) = -h;
    if( k < n-2 )
      A( i, map( j, k+1, n ) ) = -h;

    j++;
    if( j == n-1 )
    {
      j = 0;
      k++;
    }
  }

  cout << A << endl;
} 

// Map from k, j to column number
template <class T, class T_func>
inline int FinDiff<T,T_func>::map( const int j, const int k, const int n ) 
{
  cerr << "j: " << j << "\tk: " << k << "\t\t" << j+k*(n-1) << endl; // we have n-1 cuts per y, and n-1 cuts for each of those
  return j+k*(n-1); // we have n-1 cuts per y, and n-1 cuts for each of those
}
