/**
 * @file
 * @author Richard J Pougnet <pougnerj@mcmaster.ca>
 * @version 1.0
 * @brief File contains function to analyze phase-space data
 * @section DESCRIPTION
 * 
 * The file analyzes the phase space data of a specific pendulum
 * in a many pendula system. It implements the Pougnet Algorithm
 * to test if a set of initial conditions may lead to a stable 
 * solution. It does so by creating a 2-tuple out of the pendulums 
 * phase space, and sorting this by theta values. In the presence 
 * of a stable solution, ie, an orbit, there will simultaneuosly 
 * be repetition in the angular position and angular acceleration
 * of the pendulum. This algorithm searches for such repetition.
 */
#include "sorter.h"
#include "analyzer.h"
/**
 * @brief Analyze the phase-space of the pendulum, using Pougnet Algorithm.
 * @param *theta Pointer to array of angular positions of the pendulum.
 * @param *omega Pointer to array of angular acceleration of the pendulum.
 * @param threshold The neighbourhood around points to search for repetition.
 * @param size The number of datapoints.
 * @return The number of intersections in phase space.
 */
int analyze(float *theta, float *omega, float threshold, int size) {	

	int matches = 0;

	QuickSort(theta, omega, size);
 
	int i=0;

	for ( i; i<size-1; i++ ) {
		if ((fabsf(theta[i+1]-theta[i])<threshold)&&
				(fabsf(omega[i+1]-omega[i])<threshold)){
			matches += 1;
		}
	}

	return matches;
}
