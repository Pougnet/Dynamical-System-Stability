/**
 * @file
 * @author Richard J Pougnet <pougnerj@mcmaster.ca>
 * @version 1.0 
 * @brief File containing ODEs for pendulms.
 * @section DESCRIPTION
 *
 * This file contains the set of 2nd order ODEs that the system obeys.
 * It contains functions for the angular acceleration of each pendulum.
 */
#include "odes.h"
/*! \var g
    \brief Gravitational Constant
*/
#define g 9.80665
/*! \var lengthPendulum
    \brief Length of the pendulms (m)
*/
#define lengthPendulum 1.0
/*! \var gOverL
    \brief Gravitational Constant divided by the pendulum length
*/
float gOverL=g/lengthPendulum;
/**
 * @brief Angular acceleration of the first pendulum
 * @param theta1 Angular position of the first pendulum.
 * @param theta2 Angular position of the second pendulum.
 * @return Angular acceleration of the first pendulum.
*/
float alpha1(float theta1, float theta2)
{
	float alpha1 = gOverL*(2.*theta2-3.*theta1);
	return alpha1;
}

/**
 * @brief Angular acceleration of the second pendulum
 * @param theta1 Angular position of the first pendulum.
 * @param theta2 Angular position of the second pendulum.
 * @param theta3 Angular position of the third pendulum.
 * @return Angular acceleration of the second pendulum.
*/

float alpha2(float theta1, float theta2, float theta3)
{
	float alpha2 = gOverL*(3.*theta1-4.*theta2+theta3);
	return alpha2;
}

/**
 * @brief Angular acceleration of the third pendulum
 * @param theta2 Angular position of the second pendulum.
 * @param theta3 Angular position of the third pendulum.
 * @return Angular acceleration of the third pendulum.
*/

float alpha3(float theta2, float theta3)
{
	float alpha3 = gOverL*(theta2-theta3);
	return alpha3;
}
