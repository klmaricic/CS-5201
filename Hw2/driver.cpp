//////////////////////////////////////////////////////////////////////
/// @file driver.cpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement cylindrical coordinates
//////////////////////////////////////////////////////////////////////

#include<iostream>
#include <fstream>
#include <string>
#include "CylindricalCoord.h"
#include "Norm.h"
#include <vector>
#include <iomanip>


int main() 
{
  std::string file;
  std::stringstream stream;
  int numPairs;
  std::vector<CylindricalCoord<double> > vect;
  double r, theta, z;
  Norm<double> norm;
 
  std::cout<<"Please enter the file name (including extension)"<< std::endl;
  std::cin>>file;
  
  std::ifstream inFile (file.c_str());
  
  if (inFile.is_open())
  {
    inFile >> numPairs;
  
    for(std::string line; std::getline(inFile, line); )   //read stream line by line
    {
      std::istringstream in(line);      //make a stream for the line itself

      std::string type;

      inFile >> r >> theta >> z;       //now read the whitespace-separated floats
	  vect.push_back(CylindricalCoord<double> (r,theta, z));
    }
	
    inFile.close();
    std::cout << norm(vect) << std::endl;

  }

  else std::cout << "Unable to open file" << std::endl; 
  
}