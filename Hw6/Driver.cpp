//////////////////////////////////////////////////////////////////////
/// @file Driver.cpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement a parameterized matrix
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include "ParamMatrix.h"
#include "UpperMatrix.h"
#include "LowerMatrix.h"
#include "DiagonalMatrix.h"
#include "SymmetricMatrix.h"
#include "TridiagonalMatrix.h"
#include "LinearVector.h"
#include "Cholesky.h"
#include "Thomas.h"
#include <iomanip>

int main (int argc, char *argv[])
{
  int dimension;
  TridiagonalMatrix<double> triMatrix;
  SymmetricMatrix<double> symMatrix;
  LinearVector<double> triVector;
  LinearVector<double> symVector;
  Cholesky<double> cholesky;
  Thomas<double> thomas;
  
  if(argc < 2)
    std::cout << "You did not include a file name in the command line arguments. Please execute the program again with the file name." << std::endl;
  else 
  {
    std::ifstream file(argv[1]);

    if (file.is_open())
    {
      file >> dimension;

      triMatrix.setSize(dimension,dimension);
      triVector.setSize(dimension);

      file >> triMatrix;
      file >> triVector;     

      file >> dimension;

      symMatrix.setSize(dimension, dimension);
      symVector.setSize(dimension);

      file >> symMatrix;
      file >> symVector;

      file.close();

      thomas(triMatrix,triVector);
      cholesky(symMatrix, symVector);   
    }
    else 
      std::cout<<"Could not open file" << std::endl;
  }
}
