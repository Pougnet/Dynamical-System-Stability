#include <stdio.h>
#include <stdlib.h>
#include "sorter.h"
#include "analyzer.h"

//int main(int argc, char *argv[]) {
int analyze(float *theta, float *omega, float threshold, int size) {	
	//float *theta, *omega;	

	//FILE *in;
	//int size;

	float theta1i, theta2i, theta3i;
	//float threshold;
	int matches = 0;

	/*if ( argc != 3 ) {
		printf("Invalid input, please try again\n");
		return 1;
	}

	if ( (in = fopen (argv[1], "r")) == NULL ) {
		printf("Cant read %s.\n", argv[1]);
		return 1;
	}

	threshold =atof(argv[2]);
	
	fscanf(in, "%f %f %f", &thetai, &theta2i, &theta3i);

	fscanf(in, "%d", &size);
	
	theta = (float *) calloc (sizeof (float), size);
	omega = (float *) calloc (sizeof (float), size);

	int i=0;

	for ( i; i<size; i++ ) {
		fscanf(in, "%f %f", &theta[i], &omega[i]);
	}
	*/
	QuickSort(theta, omega, size);
 
	int i=0;

	for ( i; i<size-1; i++ ) {
		if ((fabsf(theta[i+1]-theta[i])<threshold)&&(fabsf(omega[i+1]-omega[i])<threshold)){
			matches += 1;
		}
	}

	/*if (matches>=minimumMatches) {
		printf("%d %s\n",matches,argv[1]);
	}

	free(theta);
	free(omega);
	*/
	return matches;
}
