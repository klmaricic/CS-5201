//////////////////////////////////////////////////////////////////////
/// @file driver.cpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement a parameterized matrix
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include "parammatrix.h"
#include "uppermatrix.h"
#include "lowermatrix.h"
#include "symmetricmatrix.h"
#include "linearvector.h"
#include "cholesky.h"
#include "findiff.h"
#include "boundfunction.h"

int main(int argc, char *argv[])
{
  FinDiff<double, BoundFunction<double> > tester;
  
  tester(0, M_PI, 5, BoundFunction<double>());
  /*
  int dimension;
  SymmetricMatrix<double> symMatrix;
  LinearVector<double> symVector;
  Cholesky<double> cholesky;
  
  if(argc < 2)
    std::cout << "You did not include a file name in the command line arguments. Please execute the program again with the file name." << std::endl;
  else 
  {
    std::ifstream file(argv[1]);

    if (file.is_open())
    {
      file >> dimension;

      symMatrix.setSize(dimension, dimension);
      symVector.setSize(dimension);

      file >> symMatrix;
      file >> symVector;

      file.close();

      cholesky(symMatrix, symVector);   
    }
    else 
      std::cout<<"Could not open file" << std::endl;
  }
  */

  return 0;
}
