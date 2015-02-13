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
  std::string file,cartCoord;
  std::stringstream stream;
  int numPairs;
  bool compare;
  std::vector<CylindricalCoord<double> > vect;
  double r, theta, z;
  Norm<double> norm;
  CylindricalCoord<double> p1, p2;
 
  std::cout<<"Please enter the file name (including extension)"<< std::endl;
  std::cin>>file;
  
  std::ifstream inFile (file.c_str());
  
  if (inFile.is_open())
  {
    inFile >> numPairs;
  
    for(std::string line; std::getline(inFile, line); )   //read stream line by line
    {
      std::istringstream in(line);

      std::string type;

      inFile >> r >> theta >> z;
	  vect.push_back(CylindricalCoord<double> (r,theta, z));
    }
	
    inFile.close();
	std::cout << "Num points: " << vect.size() << std::endl;
	
	if(vect.size() < 5)
    {
	  std::cout << "There are not enough entries in the file to do all of the desired calculations. Will perform " 
	            << vect.size()-1 << " of the calculations and apply the 1-norm over the set." << std::endl;
				
	  if(vect.size() >= 1)
	  {
	    p1 = -vect.at(0);
		std::cout << "The polar reflection of the first point is: " << p1 << std::endl;
	  }
	  if(vect.size() >= 2)
	  {
	    p2 = !vect.at(1);
		std::cout << "The reflection of the second point through the z-axis is: " << p2 << std::endl;
	  }
	  if(vect.size() == 3)
	  {
	    std::cout << "There are not enough points given to do the comparison of two points, so will instead perform the Cartesian conversion." << std::endl;
		cartCoord = vect.at(2).cartesianCoord();
		std::cout << "The Cartesian conversion of the last point is: (" << cartCoord << std::endl;
	  }
	  if(vect.size() > 3)
	  {
	    compare = vect.at(2) > vect.at(3);
	    std::cout << std::boolalpha << "The statement \"" << vect.at(2) << " > " << vect.at(3) << "\" returned " << compare << std::endl;
	  }
	}
	else
	{
	  p1 = -vect.at(0);
      std::cout << "The polar reflection of the first point is: " << p1 << std::endl;
	  
	  p2 = !vect.at(1);
	  std::cout << "The reflection of the second point through the z-axis is: " << p2<< std::endl;
	  
	  compare = vect.at(2) > vect.at(3);
	  std::cout << std::boolalpha << "The statement \"" << vect.at(2) << " > " << vect.at(3) << "\" returned " << compare << std::endl;
	  
	  cartCoord = vect.at(4).cartesianCoord();
	  std::cout << "The Cartesian conversion of the fifth point is: " << cartCoord << std::endl;
	}

    std::cout << "The 1-norm applied to the set is: " << norm(vect) << std::endl;

  }

  else std::cout << "Unable to open file" << std::endl; 
  
}