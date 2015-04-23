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
#include "LinearVector.h"
#include "GaussianSolver.h"
#include <iomanip>

int main (int argc, char *argv[])
{
  int dimension;
  ParamMatrix<double> denseMatrix;
  BaseMatrix<double>* upperMatrix;
  BaseMatrix<double>* lowerMatrix;
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

      denseMatrix.setSize(dimension,dimension);
      vector.setSize(dimension);

      file >> denseMatrix;
      file >> vector;     

      file.close();

      upperMatrix = new UpperMatrix<double>(denseMatrix);
      lowerMatrix = new LowerMatrix<double>(denseMatrix);
std::cout<<(*dynamic_cast<LowerMatrix<double>*>(lowerMatrix))(1,0)<<std::endl;
      std::cout << std::endl << "Given the following matrix:" <<std::endl;
      std::cout << denseMatrix;

      std::cout << std::endl << "And the following vector:" <<std::endl;
      std::cout << vector << std::endl << std::endl;

      std::cout << "The upper and lower triangular representation of it is:" <<std::endl << std::endl;

      std::cout << "Upper triangular portion: " <<std::endl;
      std::cout << *dynamic_cast<UpperMatrix<double>*>(upperMatrix) << std::endl;

      std::cout << "Lower triangular portion: " <<std::endl;
      std::cout << *dynamic_cast<LowerMatrix<double>*>(lowerMatrix) << std::endl;


      std::cout << "denseMatrix+upperMatrix:" << std::endl;
      std::cout << denseMatrix+(*dynamic_cast<UpperMatrix<double>*>(upperMatrix)) << std::endl;

      std::cout << "denseMatrix-lowerMatrix:" << std::endl;
      std::cout << denseMatrix-(*dynamic_cast<LowerMatrix<double>*>(lowerMatrix)) << std::endl;

      std::cout << "lowerMatrix-upperMatrix:" << std::endl;
      std::cout << (*dynamic_cast<LowerMatrix<double>*>(lowerMatrix))-(*dynamic_cast<UpperMatrix<double>*>(upperMatrix)) << std::endl;

      std::cout << "upperMatrix+lowerMatrix:" << std::endl;
      std::cout << (*dynamic_cast<UpperMatrix<double>*>(upperMatrix))+(*dynamic_cast<LowerMatrix<double>*>(lowerMatrix)) << std::endl;

      try     
      { 
        std::cout << "upperMatrix*upperMatrix:" << std::endl;
        std::cout << (*dynamic_cast<UpperMatrix<double>*>(upperMatrix))*(*dynamic_cast<UpperMatrix<double>*>(upperMatrix)) << std::endl;

        std::cout << "upperMatrix*lowerMatrix:" << std::endl;
        std::cout << (*dynamic_cast<UpperMatrix<double>*>(upperMatrix))*(*dynamic_cast<LowerMatrix<double>*>(lowerMatrix)) << std::endl;

        std::cout << "upperMatrix*vector:" << std::endl;
        std::cout << (*dynamic_cast<UpperMatrix<double>*>(upperMatrix))*vector << std::endl;

        std::cout << "upperMatrix*denseMatrix:" << std::endl;
        std::cout << (*dynamic_cast<UpperMatrix<double>*>(upperMatrix))*denseMatrix << std::endl;

        std::cout << "denseMatrix*upperMatrix:" << std::endl;
        std::cout << denseMatrix*(*dynamic_cast<UpperMatrix<double>*>(upperMatrix)) << std::endl;

        std::cout << "denseMatrix*lowerMatrix:" << std::endl;
        std::cout << denseMatrix*(*dynamic_cast<LowerMatrix<double>*>(lowerMatrix)) << std::endl;

        std::cout << std::endl << "denseMatrix*denseMatrix.transpose():" <<std::endl;
        std::cout << denseMatrix*denseMatrix.transpose() <<std::endl;

        std::cout << "lowerMatrix*lowerMatrix:" << std::endl;
        std::cout << (*dynamic_cast<LowerMatrix<double>*>(lowerMatrix))*(*dynamic_cast<LowerMatrix<double>*>(lowerMatrix)) << std::endl;

        std::cout << "lowerMatrix*upperMatrix:" << std::endl;
        std::cout << (*dynamic_cast<LowerMatrix<double>*>(lowerMatrix))*(*dynamic_cast<UpperMatrix<double>*>(upperMatrix)) << std::endl;

        std::cout << "lowerMatrix*vector:" << std::endl;
        std::cout << (*dynamic_cast<LowerMatrix<double>*>(lowerMatrix))*vector << std::endl;

        std::cout << "lowerMatrix*denseMatrix:" << std::endl;
        std::cout << (*dynamic_cast<LowerMatrix<double>*>(lowerMatrix))*denseMatrix << std::endl;

        gauss(denseMatrix,vector);
      }
      catch(std::invalid_argument& e)
      {
        std::cerr << e.what() << std::endl << std::endl;
      }

      delete upperMatrix;
      delete lowerMatrix;  
    }
    else 
      std::cout<<"Could not open file" << std::endl;
  }
}
