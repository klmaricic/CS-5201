###############################################################################
# -->Makefile<--
###############################################################################

###############################################################################
#
# Programmer :  Kelsey Maricic
# Assignment :  Program 2
# Instructor :  Clayton Price
# Course     :  CS5201 Spring 2015
# Semester   :  Spring 2015
# Filename   :  makefile
#
###############################################################################

###############################################################################
# This makefile will build an executable for the assignment.
###############################################################################

# Generic GNU g++ compiler flags
CXX = /usr/bin/g++
CXXFLAGS = -g -Wall -W -pedantic-errors 

OBJECTS = driver.o


.SUFFIXES: .cpp
                                        
.cpp.o: $<
	${CXX} -c ${CXXFLAGS} $< -o $@

default: all

all: driver

driver: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o $@

clean:
	-@rm -f core > /dev/null 2>&1
	-@rm -f driver > /dev/null 2>&1
	-@rm -f ${OBJECTS} > /dev/null 2>&1


# Dependency lists 
driver.o:  driver.cpp CylindricalCoord.h CylindricalCoord.hpp Norm.h Norm.hpp