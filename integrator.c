#include "odes.h"
#include <math.h>
#include <stdlib.h>
#include "integrator.h"

void integrate(float tmax, float timestep, float *theta1, float *theta2, float *theta3, float *omega1, float *omega2, float *omega3 ) {
	//FILE *fp;
	//float theta1,theta2,theta3;
	//float omega1,omega2,omega3;
	float alpha1i,alpha2i,alpha3i;
	float thetamax=190;
	//int i=0;
	//float numberoftrials=1000;
	//float tmax=10.;
	//char filename[256];
	float timestep2=timestep*timestep;

	//for (i;i<numberoftrials;i++) {

	theta1[0]=thetamax*((float)rand()/(float)RAND_MAX-0.5);
	theta2[0]=thetamax*((float)rand()/(float)RAND_MAX-0.5);
	theta3[0]=thetamax*((float)rand()/(float)RAND_MAX-0.5);
	//omega1=0.;
	//omega2=0.;
	//omega3=0.;
	
	//sprintf(filename, "data/%d.dat",i);
	//fp = fopen(filename, "w");
	//if (fp == NULL) {
	//	printf("Couldnt open file\n");
	//	exit(0);
	//}
	//fprintf(fp, "%d\n", (int)(tmax/timestep));
	//fprintf(fp, "%f %f %f\n", theta1,theta2,theta3);
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

		//fprintf(fp,"%.5f %.5f \t %.5f %.5f \t %.5f %.5f \n",theta1,omega1,theta2,omega2,theta3,omega3);


			}
		//fclose(fp);
	//	}
	//return 0;
}
