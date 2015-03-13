//////////////////////////////////////////////////////////////////////
/// @file Driver.cpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement a parameterized matrix
//////////////////////////////////////////////////////////////////////

#include<iostream>
#include <fstream>
#include <string>
#include "ParamMatrix.h"
//#include "GaussSeidel.h"//////////////////////
#include <iomanip>

int main (int argc, char *argv[])
{
  int dimension;
  int numEntries = 0;
  ParamMatrix<double> matrix;
  
  if (argc < 2)
    std::cout << "You did not include a file name in the command line arguments. Please execute the program again with the file name." << std::endl;
  else 
  {
    std::ifstream file(argv[1]);

    if (file.is_open())
	{
      file >> matrix;
	
      file.close();
	  
	  std:: cout << matrix << std::endl;
	}
	else 
	  std::cout<<"Could not open file" << std::endl;
  }
}