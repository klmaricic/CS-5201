//////////////////////////////////////////////////////////////////////
/// @file driver.cpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement vector analysis
//////////////////////////////////////////////////////////////////////

#include<iostream>
#include <fstream>
#include <string>
#include "CylindricalCoord.h" ###################################################################################################
#include "Norm.h"				###################################################################################################
#include <vector>
#include <iomanip>

int main (int argc, char *argv[])
{
  ifstream file;
  int dimensions;
  
  if (argc != 2)
    std::cout << "You did not include a file name in the command line arguments. Please execute the program again with the file name." << std::endl;
  else 
  {
    file(argv[1]);

    if (file.is_open())
	{
      file >> dimensions;
  
      for(std::string line; std::getline(inFile, line); )   //read stream line by line
      {
        std::istringstream in(line);

        std::string type;

        inFile >> r >> theta >> z;
	    vect.push_back(CylindricalCoord<double> (r,theta, z));
      }
	
    inFile.close(); 
    }	 
    else 
	  std::cout<<"Could not open file" << std::endl;

    // the_file is closed implicitly here
  }
}