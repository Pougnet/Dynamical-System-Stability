/**
 * @file
 * @author Richard J Pougnet <pougnerj@mcmaster.ca>
 * @version 1.0
 * @brief File contains function implementing leapfrog integrator
 */
#include "odes.h"
#include <math.h>
#include <stdlib.h>
#include "integrator.h"
/**
 * @brief Solve the time evolution of the three pendulums with 
 * random initial conditions.
 * @param tmax Time to evolve the sysetm for.
 * @param timestep Timestep for integration.
 * @param *theta1 Pointer to array of angular positions for the first pendulum.
 * @param *theta2 Pointer to array of angular positions for the second pendulum.
 * @param *theta3 Pointer to array of angular positions for the third pendulum.
 * @param *omega1 Pointer to array of angular accelerations for the first pendulum.
 * @param *omega2 Pointer to array of angular accelerations for the second pendulum.
 * @param *omega3 Pointer to array of angular accelerations for the third pendulum.
 */
void integrate(float tmax, float timestep, float *theta1, float *theta2, float *theta3, float *omega1, float *omega2, float *omega3 ) {
	float alpha1i,alpha2i,alpha3i;
/*! \var thetamax
		\brief Maximum angular position of each pendulum.
*/
	float thetamax=180;
	float timestep2=timestep*timestep;
// Set initial conditions to random number with absolute value less than thetamax.
	theta1[0]=thetamax*((float)rand()/(float)RAND_MAX-0.5);
	theta2[0]=thetamax*((float)rand()/(float)RAND_MAX-0.5);
	theta3[0]=thetamax*((float)rand()/(float)RAND_MAX-0.5);
	
	int i=0;
	for (i;i<(int)(tmax/timestep);i++) {
		alpha1i=alpha1(theta1[i],theta2[i]);
		alpha2i=alpha2(theta1[i],theta2[i],theta3[i]);
		alpha3i=alpha3(theta2[i],theta3[i]);

		theta1[i+1] = theta1[i] + omega1[i]*timestep + 0.5*alpha1(theta1[i],theta2[i])*timestep2;
		theta2[i+1] = theta2[i] + omega2[i]*timestep + 0.5*alpha2(theta1[i],theta2[i],theta3[i])*timestep2;
		theta3[i+1] = theta3[i] + omega3[i]*timestep + 0.5*alpha3(theta2[i], theta3[i])*timestep2;

		omega1[i+1] = omega1[i] + 0.5*(alpha1i+alpha1(theta1[i+1],theta2[i+1]))*timestep;
		omega2[i+1] = omega2[i] + 0.5*(alpha2i+alpha2(theta1[i+1],theta2[i+1],theta3[i+1]))*timestep;
		omega3[i+1] = omega3[i] + 0.5*(alpha3i+alpha3(theta2[i+1],theta3[i+1]))*timestep;


			}
}
