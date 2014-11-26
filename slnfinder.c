#include <stdlib.h>
#include <stdio.h>

#include "integrator.h"
#include "analyzer.h"

int main(int argc, char *argv[]) {
	FILE *out;
	float tmax, timestep, numIterations;
	float *theta1, *theta2, *theta3, *omega1, *omega2, *omega3;
	float threshold = 0.5;
	char filename[256];
	if ( argc != 5 ) {
		printf("Invalid input, for usage:\n\t slnfinder tmax timestep numIterations output\n");
		printf("Example: slnfinder 10 0.01 1000 data/\n Will conduct a simulation for ten seconds with a timestep of 0.01 seconds of 1000 pseduorandom 3 pendulum systems and save potential stable solutions to the data/ directory.\n");
		exit(0);
	}
	tmax = atof(argv[1]);
	timestep = atof(argv[2]);
	numIterations = atof(argv[3]);

	int size = (int) (tmax/timestep);
	int i=0;
	int num=0;

	for (i; i<numIterations; i++) {
			
		theta1 = (float *) calloc (sizeof (float), size);
		theta2 = (float *) calloc (sizeof (float), size);
		theta3 = (float *) calloc (sizeof (float), size);

		omega1 = (float *) calloc (sizeof (float), size);
		omega2 = (float *) calloc (sizeof (float), size);
		omega3 = (float *) calloc (sizeof (float), size);

		integrate(tmax,timestep,theta1,theta2,theta3,omega1,omega2,omega3);
		if ( analyze(theta2,omega2,threshold,size) != 0 ) {
			sprintf(filename, "%s/%d.dat",argv[4],num);
			num += 1;
			out = fopen(filename, "w");
			if (out == NULL) {
				printf("Couldnt open file\n");
				exit(0);
			}
			fprintf(out, "%d\n", size);
			fprintf(out, "%f %f %f\n", theta1[0], theta2[0], theta3[0]);

			int n=0;

			for (n; n<size; n++){
				fprintf(out,"%.5f %.5f \t %.5f %.5f \t %.5f %.5f \n",theta1[n],omega1[n],theta2[n],omega2[n],theta3[n],omega3[n]);
			}

			fclose(out);
		}

		free (theta1);
		free (theta2);
		free (theta3);
		free (omega1);
		free (omega2);
		free (omega3);
			
		
		
	printf("There were %d possible stable solutions found\n", num);
	return 0;

}
}	
