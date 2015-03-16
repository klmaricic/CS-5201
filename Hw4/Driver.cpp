//////////////////////////////////////////////////////////////////////
/// @file Driver.cpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement a parameterized matrix
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include "ParamMatrix.h"
#include "LinearVector.h"
#include "GaussianSolver.h"
#include <iomanip>

int main (int argc, char *argv[])
{
  int dimension;
  ParamMatrix<double> matrix;
  LinearVector<double> vector;
  GaussianSolver<double> gauss;
  
  if(argc < 2)
    std::cout << "You did not include a file name in the command line arguments. Please execute the program again with the file name." << std::endl;
  else 
  {
    std::ifstream file(argv[1]);

    if (file.is_open())
    {
      file >> dimension;

      matrix.setSize(dimension,dimension);
      vector.setSize(dimension);

      file >> matrix;
      file >> vector;
	
      file.close();
      
      std::cout << "The multiplication of the given matrix and its transpose is equal to:" <<std::endl; 

      try
      {       
        std::cout << matrix*matrix.transpose() << std::endl <<std::endl;
        gauss(matrix,vector);
      }
      catch(std::string e)
      {
        std::cout << e << std::endl;
      }
    }
    else 
      std::cout<<"Could not open file" << std::endl;
  }
}
