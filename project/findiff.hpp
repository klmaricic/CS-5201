//////////////////////////////////////////////////////////////////////
/// @file findiff.h
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement Gaussian Elimination
//FIXME
//////////////////////////////////////////////////////////////////////

template <class T, class T_func>
void FinDiff<T,T_func>::operator()( const T lower, const T upper, const int n )
{
  T h = 1/n;
  ParamMatrix<T> A( (n-1)*(n-1), (n-1)*(n-1) );

    for( int k=0; k<n; k++ )
    {
      for( int j=0; j<n; j++ ) // j: [1,n-1]
      {
        int row = map( j, k, n );

        A( row, row ) = 1;
        A( row, map( j-1, k, n ) ) = -h;
        A( row, map( j, k-1, n ) ) = -h;
        A( row, map( j+1, k, n ) ) = -h;
        A( row, map( j, k+1, n ) ) = -h;
      }

      cout << endl;
    }

  cout << A << endl;
} 

// Map from k, j to column number
template <class T, class T_func>
inline int FinDiff<T,T_func>::map( const int k, const int j, const int n ) 
{

  cerr << j+k*(n-1) << endl; // we have n-1 cuts per y, and n-1 cuts for each of those
  return j+k*(n-1); // we have n-1 cuts per y, and n-1 cuts for each of those
}
