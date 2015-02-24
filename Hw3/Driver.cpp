//////////////////////////////////////////////////////////////////////
/// @file Driver.cpp
/// @author Kelsey Maricic CS 5201 A
/// @brief Write a templated class to implement vector analysis
//////////////////////////////////////////////////////////////////////

#include<iostream>
#include <fstream>
#include <string>
#include "LinearVector.h"
//#include "Norm.h"				###################################################################################################
#include <vector>
#include <iomanip>

int main (int argc, char *argv[])
{
  int dimensions;
  std::vector<LinearVector<double> > vect;
  
  if (argc < 2)
    std::cout << "You did not include a file name in the command line arguments. Please execute the program again with the file name." << std::endl;
  else 
  {
    std::ifstream file(argv[1]);

    if (file.is_open())
	{
      file >> dimensions;
  
      for(std::string line; std::getline(file, line); )   //read stream line by line
      {
        std::istringstream in(line);

		vect.push_back(LinearVector<double> (dimensions));
		
		for(int i = 0; i < dimensions; i++)
          file >> (vect.back())[i];
      }
	
      file.close(); 
	  
	  //for(int i = 0; i < dimensions; i++)
	    //std::cout << vect.at(i) << std::endl;
    
	/**
	  if(dimensions == 1)
	    std::cout << "There is only one vector given, so the vector calculations cannot be done and the set is linearly independent." << std::endl;
	  else
	  {
	    std::cout << vect.at(0) << " + " << vect.at(1) << " = " << (vect.at(0)+vect.at(1)) << std::endl;
		std::cout << vect.at(0) << " - " << vect.at(1) << " = " << (vect.at(0)-vect.at(1)) << std::endl;
		std::cout << vect.at(0) << " * " << vect.at(1) << " = " << (vect.at(0)*vect.at(1)) << std::endl;
	  }
	  
	  std::cout << "The output stream operator performed on the first vector returns: " << vect.at(0) << std::endl;
	  std::cout << "v1[0] returns: "" << (vect.at(0))[0] << std::endl;
	  
	  if(dimensions != 1)
	  {
	    //linear dependence stuff
	  }
	*/
	}	 
    else 
	  std::cout<<"Could not open file" << std::endl;
  }
}