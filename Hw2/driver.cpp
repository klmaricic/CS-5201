//////////////////////////////////////////////////////////////////////
/// @file driver.cpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement cylindrical coordinates
//////////////////////////////////////////////////////////////////////

#include<iostream>
#include <fstream>
#include <string>
#include "CylindricalCoord.h"

int main() 
{
/*
  string file;
  int numPairs;
  #vector<CylindricalCoord<double> > vect;
  float r, theta, z;
  
  cout<<"Please enter the file name (including extension)"<<endl;
  cin>>file;
  
  ifstream inFile (file);
  
  if (inFile.is_open())
  {
    inFile >> numPairs;
  
    for(std::string line; std::getline(inFile, line); )   //read stream line by line
    {
      std::istringstream in(line);      //make a stream for the line itself

      std::string type;

      inFile >> r >> theta >> z;       //now read the whitespace-separated floats
    }
	
    inFile.close();
  }

  else cout << "Unable to open file"; 
  */
  
  #CylindricalCoord<double> p(5, -7.192, 1);
  #std::cout << (!p)[1] << std::endl;
  return 0;
}