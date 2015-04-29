###############################################################################
## -->Makefile<--
###############################################################################

###############################################################################
##
# Programmer :  Kelsey Maricic
# Assignment :  Program 6
# Instructor :  Clayton Price
# Course     :  CS5201 Spring 2015
# Semester   :  Spring 2015
# Filename   :  makefile
##
###############################################################################

###############################################################################
## This makefile will build an executable for the sixth assignment.
###############################################################################

# Generic GNU g++ compiler flags
CXX = /usr/bin/clang++
CXXFLAGS = -g -Wall -W -pedantic-errors

MATRICES = $(wildcard *matrix.h *matrix.hpp)

OBJECTS =  driver.o

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
# Dependency lists for the various source files
driver.o:  driver.cpp linearvector.h linearvector.hpp cholesky.h cholesky.hpp gaussiansolver.hpp \
					 gaussiansolver.h findiff.hpp findiff.h $(MATRICES)
